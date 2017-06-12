# About

simpleWMuse is a C++ library with a high level abstraction of some Windows.h mouse functions,  simplifying the need of additional code to just compute essential properties of the screen.

# Building from source

## With Eclipse

There's two created configurations you can build

* lib - compile the code as a Static Library (`lib*.a`)
* shared - compile the code as a Dynamic Library (`lib*.dll`)

For doing it, click with left mouse button on your imported project, Go to `Build Configuration`, and choose the build you want or `Build all`

## With make

Inside the downloaded folder

- For static 
```
cd lib
make
```

- For dynamic 
```
cd shared
make all
```

# How to use

## Static (Eclipse/MinGW)
- Build the static library 
- Move `/include/` and `/lib/` to your new project folder
`Right Click > Properties > C/C++ Build > Settings > GCC C++ Compiler > Includes` and then add your `/include/` folder to `Include Paths (-l)`
- Go to `MinGW C++ Linker > Libraries`
- Chose `lib` folder on `Library search path (-l)`
- Insert `simpleWMouse` on `Libraries (-l)`



## Dynamic (Eclipse/MinGW)
- Build the dynamic library
- Move `/include/` and `/shared/` to your new project folder
`Right Click > Properties > C/C++ Build > Settings > GCC C++ Compiler > Includes` and then add your `/include/` folder to `Include Paths (-l)`
- Go to `MinGW C++ Linker > Libraries`
- Chose `shared` folder on `Library search path (-l)`
- Insert `simpleWMouse` on `Libraries (-l)`
- Put `libsimpleWMouse.dll` file in the same folder as the generated executable
