# About

simpleWMuse is a C++ library with high level abstraction of some Windows.h mouse functions. Simplifying the need of additional code to just compute essential properties of the screen.

# Compiling

## Using Eclipse

There's two created configurations you can build

* lib - compile the code as a Static Library (`lib*.a`)
* shared - compile the code as a Dynamic Library (`lib*.dll`)

For doing it, click with left mouse on your imported project on Eclipse, Go to `Build Configuration`, and choose the build you want or `Build all`

## Using make

- Inside the downloaded folder

`
cd lib
make
`
or
`
cd shared
make all
`

## Using Static (MinGW)

- After the compiling, move `/include/` and `/lib/` to your new project folder
`Right Click > Properties > C/C++ Build > Settings > GCC C++ Compiler > Includes` and then add your `/include/` folder to `Include Paths (-l)`
- Then go to `MinGW C++ Linker > Libraries`
- Chose `lib` folder on `Library search path (-l)`
- Insert `simpleWMouse` in the field above, on `Libraries (-l)`



## Using Dynamic (MinGW)

- After the compiling, move `/include/` and `/shared/` to your new project folder
`Right Click > Properties > C/C++ Build > Settings > GCC C++ Compiler > Includes` and then add your `/include/` folder to `Include Paths (-l)`
- Then go to `MinGW C++ Linker > Libraries`
- Chose `shared` folder on `Library search path (-l)`
- Insert `simpleWMouse` in the field above, on `Libraries (-l)`
- Put `libsimpleWMouse.dll` file in the same folder as the generated executable
