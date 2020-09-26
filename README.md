# Clashing Countries

This is a turn-based multiplayer strategy game, extensible using scripting.

## Dependencies

Requires:
- Lua 5.3
- SFML 2.5
- sol2 (version 3)
- nlohmann-json

## Building

Make sure your current directory is the src folder and you have the dependencies listed above installed and `pkg-config`.
Then, simply run make. 
```bash
cd src
make
```
You can type the name of each module as an argument to make to rebuild that specific module, or `clean` to remove all contents in the project's `bin` and `obj` directories.
For example:
```bash
make clean # remove all binaries and object files
make graphics # rebuilding graphics library
```

## Project Structure

### Submodules
- Graphics (`graphics`)
- Core Utilities (`core_util`)
- Game Logic (`game`)
- Main Application (`client`)

## Concepts used
- Object oriented programming
    - Inheritance
    - Polymorphism
- Code organization
- Multithreading (to be implemented soon)
- Embedded scripting (currently in a primitive state in the form of config files)
- Build systems (specifically Make)