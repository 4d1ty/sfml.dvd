# sfml.dvd

Bouncing dvd writte in sfml


## Quick start
This is a CMake project so building it should be a straight forward task.

I use Visual Studio 2022 with MSVC and C++ Toolchain, and it comes with CMake.


### Command line

1. Install [Git](https://git-scm.com/downloads) and [CMake](https://cmake.org/download/). Use your system's package manager if available.
3. Fork it and/or clone repo and open the repo in your text editor of choice.
7. If you use Linux, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
   ```
   sudo apt update
   sudo apt install \
       libxrandr-dev \
       libxcursor-dev \
       libxi-dev \
       libudev-dev \
       libfreetype-dev \
       libflac-dev \
       libvorbis-dev \
       libgl1-mesa-dev \
       libegl1-mesa-dev \
       libfreetype-dev
   ```
8. Configure and build your project. Most popular IDEs support CMake projects with very little effort on your part.

   - [VS Code](https://code.visualstudio.com) via the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
   - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)
   - [CLion](https://www.jetbrains.com/clion/features/cmake-support.html)
   - [Qt Creator](https://doc.qt.io/qtcreator/creator-project-cmake.html)

   Using CMake from the command line is straightforward as well.
   Be sure to run these commands in the root directory of the project you just created.

   ```
   cmake -B build
   cmake --build build
   ```

9. Enjoy!

**Note:** There is a windows executable in the release tab, you can check that instead of building this yourself.


## License

The source code is dual licensed under Public Domain and MIT -- choose whichever you prefer.

`dvd.png` from https://www.vhv.rs/dpng/f/15-159814_dvd-logo-png.png