# Git

## Git general

Git is CLI utility that keeps track of your code. Although it's integrated well with most of IDEs (VisualStudio, Exlipse, etc.) it still remains CLI under t he hood. It's good to start using Git as CLI in order to understand _what happens there._

How exactly Git keeps track of your code? It remembers the _"how it was"_ state and _"how it is now"_ state. Actually Git tracks all the differences between two consequent states. For instance, let's think about `hello_world.cpp`:

State of **yesterday** (with line numbers):

```c++
 1: #include <iostream>
 2:
 3: int main() {}
```

**Today** we added the body of `main()` so the code looks like

```c++
 1: #include <iostream>
 2:
 3: int main() {
 4:   std::cout << "Hello world!" << std::endl;
 5: }
```

So Git tracks the difference in lines `:3-5` because that what you did today. Pay attention, lines `:1-2` were not changed so Git does not track them as today's change.

Git philosophy considers any file of your project as the list of changes. So you always can check out back how this file looked yesterday or previous Monday.

The atomic change that Git tracks is called **"commit".** See below for more explanation. Git does not track every single folder with the code but only the folders that you explicitly ask for. Such folders/projects are **"under (Git) version control".**

Git can also tie the code on your local machine with some storage in the Internet **(code repository).** That allows you perform the work locally but push it to the storage. When your code is in Git repository, you can easily share the code, work on 2+ machines (e.g. at your work and at home).

The concept of storage allows multiple people working on the same project. This happens in 95% of all the big projects. Tracking back the history of `some_file.cpp` you'll see commits that belong to different teammates.

## How to use Git

### Set up the project

First we need to ask Git explicitly to track current project (folder and all its content including subfolders). There are several ways here:

1. Existing project at your machine: perform `git init` command in the root folder of the project.
1. New project: create a project folder and perform `git init` there.
1. Somebody's project: `git clone <path-to-somebodys-repo>`.

We are going to use 3rd way (as I have already created the repository).

Whilst 1st and 2nd ways require setting up the repository afterwards, the 3rd way delivers the project which is _already aware about its repo._ So it's 100% ready to go.

### Making first changes

There is a very basic Git command `git status` which shows how Git sees your project at the moment. Expected output should look like this:

```
On branch master
Your branch is up to date with 'origin/master'.

nothing to commit, working tree clean
```

Now you do your work and update some file. After you saved your changes you re-do the `git status`:

```
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   src/rota_pattern.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

Indeed, you modified the `src/rota_pattern.cpp`. What exactly has been changed? `git diff` answers this question:

```diff
diff --git a/src/rota_pattern.cpp b/src/rota_pattern.cpp
index 5a10081..80f2964 100644
--- a/src/rota_pattern.cpp
+++ b/src/rota_pattern.cpp
@@ -8,6 +8,7 @@


 int main(int argc, char* argv[]) {
+  std::cout "Here I am\n";
   Arguments arguments(argc, argv);
   unsigned short padding = 20;

@@ -17,8 +18,8 @@ int main(int argc, char* argv[]) {
   std::cout << "Rotation pattern v1.0.0.\n";
   std::vector<Position> drawing = pattern.create();
   std::cout << "A pattern out of " << drawing.size() << " pixels generated\n";
-  std::vector<char> canvas = tga_file.create_canvas(drawing);
-  tga_file.write(canvas);
+  std::vector<char> payload = tga_file.create_canvas(drawing);
+  tga_file.write(payload);
   std::cout << "Created \"" << arguments.filename << "\"\n";

   return 0;
```

Indeed; the line `std::cout "Here I am\n";` was added and it's shown in green and prefixed with `+`.
The variable `canvas` was renamed to `payload` so that's reflected as well with red lines prefixed with `-` (think "removed") and green lines prefixed with `+` (think "added").

At this point Git **only sees changes but does not track them!** Let's make Git track them.

### Staging ang commits

First we should **stage these changes for commit** via `git add <path/to/file>`. Why this is important? Because we might have multiple files changed but prefer to commit only severla of them. So we stage for commit only those file(-s) we are going to commit now.

After adding the file the output of `git status` looks different:

```
On branch rom-pattern-math
Your branch is up to date with 'origin/rom-pattern-math'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   src/rota_pattern.cpp
```

Now you can actually commit your changes: `git commit -m "The commit message: what has been done"`:

```
[master 77f4399] <Your commit message here>
 1 file changed, 3 insertions(+), 2 deletions(-)
```

The commit message describes shortly what has been done. It's useful to track the history of the changes in human-friendly way. Remember, Git keeps tract of _changes_ (commits)? Let's see how the file from my project has been developed:

```
$ git log --oneline server/api/mpi/assign_pop_height_units.ts

1ecae0aea GF-2208 working stubbed tests
040c0e445 GF-2208 WIP
5036cd218 Merged in GF-2081-apply-sorting-for-cables (pull request #1112)
5824b2931 (origin/GF-2081-apply-sorting-for-cables) GF-2081 refactoring
eb418c15e (origin/GF-2084-set-occupied-height-units) GF-2084 Separate out determining which height units are occupied
1f42d8938 GF-2084 Set occupied height units
120732514 GF-2081 Apply sorting when assigning ODF positions for cables
e12f8f5c2 (origin/GF-1949-use-list-of-available-pop-height-units-02, GF-1949-use-list-of-available-pop-height-units-02) GF-1949 Use assignPopHeightUnits()
efeccab5d GF-1949 Implement assignPopHeightUnits()
```

Even without digging deep it's (more or less) clear what has been done in this or that commit.

Pay attention at the first sequence of symbols (e.g., `1ecae0aea`) in that notation. It's the **commit hash** (the unique "address" of the commit). Every single commit can be referenced (e.g., viewed, picked or reverted) by its hash.

### Local work and remote repository

After committing is done the `git status` shows following:

```
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

Indeed, we performed one change and introduced that to Git (we made Git keep track of that change). But that was done _on local environment_ (`master`). The repository does not know anything about your local changes: "Your branch is ahead of 'origin/master' by 1 commit." where `origin/master` means "the reflection of your local environment in the repository".

`git push` delivers your changes to the repository. So other participants can benefit from your work.

This works other way around as well: after somebody did `git push` on their side you can perform `git pull` in order to fetch their updates.

### Working with history

At this point it makes sense to look at the history of the project:

- `git show` shows the very last commit (in extended way).
- `git show <commit hash>` shows the given commit.
- `git log -n 5` shows short version of 5 last commits. You can look deeper in any of those by its hash.
- `git log path/to/your/file` restricts the output of `git log` to commits which touched that particular file.

### Branches

#### Creating a new branch

Another pretty powerful concept of Git is **branching** and **merging.** Imagine you'd like to work on different parts of the project _on the same machine_ without messing things up. That's possible. Imagine your current state is a tree trunc. The "current state" means that there is nothing changed and nothing to commit; your last commit is `a3a3` and the history looks like this:

```
--- a1a1 --- a2a2 --- a3a3 (current state)
```

So you create _a branch_ out of current state and continue your work in that branch without messing up with the tree trunc:

```
                      `git checkout -b my-new-branch`
--- a1a1 --- a2a2 --- a3a3
                        \
                         + ---> `git status` shows that you are in new branch
```

Now you can perform changes, stage (`git add ...`) and commit them (`git commit -m "..."`). Your changes will reside _in your branch_ but not on the trunc:

```
--- a1a1 --- a2a2 --- a3a3
                        \
                         + --- b1b1 --- b2b2 (2 commits were performed)
```

#### Working with different branches

The `git status` shows that we are on `my-new-branch`. Looking at the code we can ensure our latest changes (from commits `b1b1` and `b2b2`) are in.

Let's switch to `master`: `git checkout master`. **Pay attention,** `git checkout -b` creates new branch out of current state; `git checkout` without `-b` switches the branch.

Check out the code: it looks like `a3a3`; no trails of commits `b1b1` and `b2b2` there! So we can implement multiple ideas without messing them each other.

#### Merging

Whilst we are on `master` we can **merge the branch** (think "fetch the work from other branch"). This should be done only when we are satisfied with what's currently in `my-new-branch`. The convention is that `master` should be always working and never broken; it should contain _complete features;_ until complete features should be developed in branches.

Make sure we are in master and thee working tree is clean (no pending changes; nothing staged for commit): `git status`. Fetch the code from the `my-new branch` by doing `git merge my-new-branch`:

```
--- a1a1 --- a2a2 --- a3a3 (master)
                        \
                         + --- b1b1 --- b2b2 (my-new-branch)

                    `git merge my-new-branch`

--- a1a1 --- a2a2 --- a3a3 --- b1b1 --- b2b2 (master)
                        \       :        :
                         + --- b1b1 --- b2b2 (my-new-branch)
```

Looking into code you can make sure thee commits `b1b1` and `b2b2` are in.

### Git workflow

1. Check out the latest `master` (`git checkout master` then `git pull`).
1. Create a new branch in order to develop feature X: `git checkout -b feature-x`.
1. Perform the changes; stage (`git add ...`) and `git commit` them.
   - Repeat until the feature X is ready.
1. Push _your branch_ to remote repo: `git push` (if Git complains follow its instructions).
1. Discuss your work in `feature-x` with colleagues.
   - When needed go back to _"Perform the changes..."_ step.
1. When the work in branch `feature-x` is considered as merge-able, merge it to `master`.

The last two points are done via so called **merge (pull) requests.** This is built-in feature of GitHub. After your branch is pushed you can go to GitHub UI and create new pull (merge) request "from `feature-x` to `master`". Other contributors discuss your change(-s), provide you with some feedback. Somebody (usually dedicated person) eventually merges your changes. Under the hood it's done as `git checkout master && git merge feature-x && git push`.

---

This is basically it. There are a lot of powerful features in Git; check them out on https://git-scm.com/book/en/v2.

Good luck!
