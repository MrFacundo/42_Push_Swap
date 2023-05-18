# Git submodules

git pull --recurse-submodules
git submodule update --init --recursive 
## Remove the submodule entry from .git/config
git submodule deinit -f path/to/submodule
## Remove the submodule directory from the superproject's .git/modules directory
rm -rf .git/modules/path/to/submodule
## Remove the entry in .gitmodules and remove the submodule directory located at path/to/submodule
git rm -f path/to/submodule
 
# Valgrind

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s <binary>

# Tester 1

make -C push_swap_averager

# for cmake to work

sudo apt-get install pkg-config
sudo apt-get install mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev\nsudo apt-get install libglew-dev libglfw3-dev libglm-dev\nsudo apt-get install libao-dev libmpg123-dev
sudo apt-get install -y libudev-dev
sudo apt-get install -y  libfreetype-dev