# Quick Introduction to Git/GitHub

This documentation will give you a brief introduction to Git and GitHub.

Git is a "version-control system for tracking changes in source code during software development. It is designed for coordinating work among programmers, but it can be used to track changes in any set of files". Git is local to your computer.

GitHub is a "Git repository hosting service" with added features. GitHub stores your repository on "the cloud" rather than on your computer.

## Introduction to Git
Git comes pre-installed in most computers. However, if Git is not installed onto your computer, you can install it [here](https://git-scm.com/downloads). While installing Git from this website also gives you a nice graphical user interface, this tutorial will only use terminal to access Git.

After you have installed Git, you need to set up your Git environment. You only need to do this the first time you install Git on your computer.
```console
git config --global user.name "Your Name"
git config --global user.email "youremail@email.com"
```
By including `--global`, all repositories that you make on your computer will be under the name and email that you have provided. If, for example, you want one repository to be under different credentials, then after you have create your repository (which will be shown next), you can type
```console
git config --local user.name "Different Name"
git config --local user.email "differenemail@email.com"
```

Now that we have provided our name and email, we want to create a local repository on your computer. As a reminder, to navigate around your computer, the following provides some common and useful bash commands:
```console
pwd # gives working directory
ls # lists contents in directory
cd directoryname # change directory
cd .. # change one directory up
mkdir directoryname # make directory
touch filename.extension # create file without any content
```

### Basic Git Commands
Navigate your way to the directory you would like to make your repository, and initialize git by typing
```console
git init
```
in your terminal. A hidden folder called `.git` will be made in the directory. Congratulations, you have started your first repository!

Since your folder is probably empty, it is not that interesting to use Git. Let us create a file from the terminal by typing
```console
touch hello.cpp
```
This creates a file called `hello.cpp` in the working directory. Open this file using your favourite text editor and copy and paste the following.
```c++
#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Hello World\n";
  return 0;
}
```
Now, we want to "save" this file to Git. Rather than using the term "save", we will use the preferred terminology "commit". Before committing your file, we first need to *add* your file to the so-called *staging area*. It indicates to Git that you want to include the updates to the particular file in the next commit. There are many options to add your files to Git:
```console
git add .
```
means to stage all changes for the next commit,
```console
git add *.ext
```
means to stage all changes in all files with that particular extension for the next commit,
```console
git add <file>
```
to stage all changes in <file> for the next commit, and lastly,
```console
git add <directory>
```
to stage all changes in <directory> for the next commit. If you want to add a lot of files but want to ignore a few, you can create a file called `.gitignore` and include those particular files that you do not want to add. Similar to `git add`, you are able to filter files by extensions, by the file name, or by directory.

After we have stages our changes, we can use the command
```console
git status
```
to take a look at the state of the working directory and the staging area. It lets you see which changes have been stages, which haven't, and which files aren't being tracked by Git. This command is extremely handy when staging for your next commit.

Once you have successfully added all the files that you desire to the staging area, we are ready to commit the files. To commit, the preferred command is
```console
git commit -m "Enter changes here"
```
If we had just typed `git commit`, Git will take you to a text editor on your terminal, such as Nano or Vim, for you to write a commit message. Not only does this take more time, if you are unfamiliar with these particular programs, you may not be able to commit anything to Git. (If by chance you accidentally typed `git commit`, to exit Vim, type `:wq`, to exit Nano, type `Ctrl+x`).

Congratulations, you have successfully performed your first commit!

To view your commit history, we use the command
```console
git log
```
To exit from this, type `q`. You can also view a condensed version of this by adding a parameter. The command to see a condensed version of your commit history is
```console
git log --oneline
```

### Branching and Merging
Branching means that you diverge from the main line of development and continue to do work without messing with that main line. Typically, we use branches when we want to add new features or fix a bug in our program.

<p align="center">
  <img src="https://wac-cdn.atlassian.com/dam/jcr:746be214-eb99-462c-9319-04a4d2eeebfa/01.svg?cdnVersion=633" width="500">
</p>

## Introduction to GitHub
