# Task distribution

## [ ] Parse CLI arguments (see [README](./README.md#cli) for more info).  

   - The CLI arguments of format `--dout=800` should be parsed into 2 parts (before `=` and after it).
   - Those arguments should set up appropriate constants which affect whole application: they define image size and pattern parameters.
   - The arguments should have default values if not set correctly or if omitted.
   - There should be friendly message in case the argument was ser incorrect.
   - There should be help screen if app is called with one of arguments: `--help`, `-h`, `/?`, `h`, `?`, `help`.

**The result** of this task should be a class instantiated with CLI arguments (received as parameters of `int main(...)`). The class should have public fields containing values of `dout`, `din`, `pen`, etc.

[ ] Write TGA file of given dimesion (`dout + 20` x `dout + 20`). See [README](./README.md#tga-format).

**The result** should be a class. It should have method for writing the file of given name with given payload.

---

TBD from this point on.

## [ ] Create Pixel class. It shoud contain color information.

## [ ] Create image payload (canvas) as array/vector of pixel elements.

   - It should have method for initial canvas filling (fill whole canvas with pixels of default color).
   - It should have method for putting pixel at given `x, y` position. Under the hood it should plant the pixel at proper place in the array/vector.
   - The coordinate system (where should be `0, 0`) is up to discussion.

## [ ] Implement pattern creator.

**Assignee:** Roman Melnyk.
