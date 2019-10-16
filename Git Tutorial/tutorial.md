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
Now, we want to "save" this file to Git. Rather than using the term "save", we will use the preferred terminology "commit". You can think of commit as a two stage process: we first need to *add* your file to something called the *staging area* before committing the file.
