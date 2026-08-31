# Bare-Bones Player Movement

This folder contains the first C++ movement foundation for Spider-Man Simulator.

## Current goal

Get a basic character moving before adding any Spider-Man-specific mechanics.

Included:

- Walking
- Basic running speed
- Gravity
- Falling
- Jumping
- Air control
- Basic collision through Unreal's Character class

## Unreal setup

These files are intended to live under:

`Source/SpiderManSimulator/`

Files:

- `SpiderManCharacter.h`
- `SpiderManCharacter.cpp`

The project also needs the input axis mappings:

- `MoveForward`
- `MoveRight`

No wall-running, web swinging, Spider-Sense, replay system, or other advanced mechanics are included yet.

## Development rule

**Bare bones first.**

Make it work before making it pretty.
