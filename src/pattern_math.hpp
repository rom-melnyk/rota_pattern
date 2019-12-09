#ifndef __PATTERN_MATH_HPP_INCLUDED__
#define __PATTERN_MATH_HPP_INCLUDED__

#include <cmath>
#include <vector>

#include "interfaces.hpp"

struct Circle {
  Position center;
  double radius;
  double alpha = 0.0;
};

class Pattern {
public:
  Pattern(double dout, double din, double pen, double padding);
  std::vector<Position> create();

private:
  const double FULL_CIRCLE = 2 * std::acos(-1); // 2 * pi

  Circle outer_circle;
  Circle inner_circle;

  double pen_radius;
  Position pen;

  void normalize_alpha(double &alpha);
  bool is_around_zero(double alpha, double treshold);
  void rotate(double inc_alpha);
};

Pattern::Pattern(double dout, double din, double pen, double padding) {
  outer_circle.center.x = dout / 2 + padding;
  outer_circle.center.y = dout / 2 + padding;
  outer_circle.radius = dout / 2;

  inner_circle.radius = din / 2;

  pen_radius = (din / 2) * (pen / 100);
}

std::vector<Position> Pattern::create() {
  std::vector<Position> result;
  double step = FULL_CIRCLE / 360 / 60;
  double treshold = step / 2;

  do {
    rotate(step);
    result.push_back(pen);
  } while (!is_around_zero(outer_circle.alpha, treshold) || !is_around_zero(inner_circle.alpha, treshold));
  
  return result;
}

void Pattern::normalize_alpha(double &alpha) {
  if (alpha > FULL_CIRCLE) {
    alpha -= FULL_CIRCLE;
  }
  if (alpha < 0) {
    alpha = FULL_CIRCLE + alpha;
  }
}

bool Pattern::is_around_zero(double alpha, double treshold) {
  return (alpha < treshold) || (FULL_CIRCLE - alpha < treshold);
}

void Pattern::rotate(double alpha_step) {
  outer_circle.alpha += alpha_step;
  normalize_alpha(outer_circle.alpha);

  inner_circle.center.x = outer_circle.center.x + std::round((outer_circle.radius - inner_circle.radius) * std::sin(outer_circle.alpha));
  inner_circle.center.y = outer_circle.center.y + std::round((outer_circle.radius - inner_circle.radius) * std::cos(outer_circle.alpha));

  inner_circle.alpha -= alpha_step * outer_circle.radius / inner_circle.radius;
  normalize_alpha(inner_circle.alpha);

  pen.x = inner_circle.center.x + std::round(pen_radius * std::sin(inner_circle.alpha));
  pen.y = inner_circle.center.y + std::round(pen_radius * std::cos(inner_circle.alpha));
}

#endif
