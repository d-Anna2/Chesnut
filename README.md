# Chestnut

## Exercise 1 – Game Engine
### Implement your Game Engine Setup
- [x] Create a public github repository
- [x] Create your engine
- [x] name your engine
- [x] engine should be a dll
- [x] write an entry point for your game
- [x] Create a game for testing – engine and game should be seperated
- [x] name your game
- [x] call your game engine
### Questions
#### 1. What is the difference between git and github?
git is a version control tool (software), github is an online hosting service to manage git repositories (service)
#### 2. Name 3 benefits of a version control system:
- branching, merging (feature branches, test and production branches)
- keep track of every change that has been done (history)
- efficiency (teams)
#### 3. Name 3 alternatives to git:
-  IBM Configuration Management Version Control (CMVC)
-  Apache Subversion
-  Concurrent Versions System (CVS)
-  mercurial
#### 4. Name 2 differences between git and other version control systems:
 - git has a distributed architecture, while SVN f.e. is centralized
 - SVN is based on a directory structure, and branches are created as directories inside the repository / Git branches are only references to a specific commit
#### 5. Name known issues related to game engines (Unreal, Unity) and version control systems:
- teams involve many people (not all with experience in version control)
- binary assets, large projects
- merge conflicts 
## Exercise 2 – Game Engine
### Implement a Logging System
- [x] implement a logging system or use an existing library with an abstraction layer in between (facade pattern, adapter pattern, ...)
- [x] provide a build system for your project
- [x] push your results on github
## Questions
### 1. Describe a logging system with your own words:
A logging system provides possibilities to log all kind of information. It is usefull for troubleshooting, monitoring, and security purposes, and provides a detailed record of what happened and when.
### 2. What is the difference between git submodules and git subtrees?
submodules are al link to a single commit in a subproject, subtrees store the whole subproject including history
### 3. What is a build system in C++? Name 3 build systems:
- premake 
- make, cmake
- ninja
### 4. What is a package manager in C++? Name 3 package manager:
a package manager automates the process of installing, upgrading, configurate and remove packages
- conan
- bucharoo
- hunter
- vcpkg

