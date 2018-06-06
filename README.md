# Stair Dismount by Francisco Mabres
### Requirements

 - Git
 - CMake

**Steps to Clone:**

 Place the private key where you want to clone the repository
 and put this into console:
 
    eval `ssh-agent -s` && ssh-agent $(ssh-add privatekey; git clone --recursive git@bitbucket.org:pmabres/stairdismount.git)
 
 
 It should start cloning immediately.
 if you are on windows you might need to use git bash in order to do this.
 
For other GUI's:
    Importing a private key on Gitkraken:
        https://support.gitkraken.com/integrations/authentication
    Importing a private key on Sourcetree:
        https://confluence.atlassian.com/bitbucket/set-up-an-ssh-key-728138079.html#SetupanSSHkey-ssh3
            Check for section "Step 4. Install your private key on Pageant"


###Submodules

The project has 3 submodules:
 - Bullet3
 - glm
 - SFML

Because of complexity it wasn't possible to include also glew as a submodule.


If for any reason the modules have not been pulled on the initial clone then
you can pull them with the following command.

    cd vendor
    git submodule update --init --recursive

###Development Tools

It was originally developed with IntelliJ CLion but it
can be used with any editor/IDE that supports CMake projects.

### Build

For building it can be done directly through the IDE.
Also there are two scripts provided for Windows and Unix systems.

 - build.sh
 - build.bat

Both provide a default run on cmake that will get the project linked and compiled.
            
            
### Usage

Camera Controls:
JKLI to rotate, Up,right,down,left arrows to move the camara
             
TroubleShooting:

https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php

