# Movement Mechanics Specification

## Movement Reference

The movement target is an **Andrew Garfield-style Spider-Man**: athletic, acrobatic, flexible, fluid, and strongly driven by momentum.

This is a movement reference and design target, not a requirement to copy specific movie choreography.

## 1. Core Movement Philosophy

Spider-Man should feel like a highly capable human body with superhuman strength, agility, flexibility, and coordination.

Movement should be:

- Fluid
- Athletic
- Acrobatic
- Momentum-driven
- Responsive
- Physically readable
- Continuous across movement types

The player should feel like they are controlling a body rather than moving a floating camera.

## 2. Ground Movement

### Walking

Walking is available for normal exploration and setup.

The player should not instantly reach full walking speed. Movement should have a small amount of acceleration and deceleration so the body feels physical.

### Running

Running is the primary ground movement state.

Requirements:

- Gradual acceleration
- Natural deceleration
- Smooth directional changes
- Momentum preservation
- Responsive player control
- No tank-like turning

Spider-Man should be able to change direction quickly, but the change should still feel like an athletic body performing the movement.

### Turning

Turning should be smooth rather than an instant rotation.

The body should naturally follow the player's intended direction.

At higher speeds, sharp turns should require more space and should influence momentum.

## 3. Jumping

Jumping should inherit the player's current movement.

A running jump should carry forward momentum.

A stationary jump should behave differently from a running jump.

The player should be able to influence orientation and movement while airborne.

Basic sequence:

`Run → Jump → Air Control → Land`

The goal is for jumping to feel like the beginning of an acrobatic maneuver rather than a simple videogame jump.

## 4. Air Control

The player can influence Spider-Man's orientation and movement while airborne.

Air control should allow:

- Turning
- Body rotation
- Adjusting landing direction
- Beginning acrobatic movements
- Preparing for web attachment
- Recovering from imperfect jumps

Air control should not completely erase momentum.

The player is controlling an airborne body, not freely flying.

## 5. Acrobatics

Acrobatics are part of normal traversal rather than a separate progression system.

The player should eventually be able to naturally perform:

- Front flips
- Backflips
- Side rotations
- Spins
- Tucks
- Extensions
- Direction changes
- Combined rotations

The game should not require an XP unlock to perform these movements.

The player learns the movement system and develops the skill themselves.

## 6. Wall Interaction

Wall movement is a major component of traversal.

### Wall Detection

The system detects suitable surfaces near the player.

The first prototype can use simple collision/raycast detection. Advanced surface classification can be added later.

### Wall Climbing

When the player reaches a suitable wall, Spider-Man can attach to it and climb.

Climbing should feel deliberate and physical rather than like a magnetic character controller.

### Wall Running

Wall running allows Spider-Man to maintain forward movement across a vertical surface.

Target behavior:

`Run → Jump → Wall Contact → Wall Run → Launch`

Wall running should preserve appropriate momentum.

The player should be able to leave the wall naturally rather than being locked to it.

### Wall Launch

The player can launch away from a wall.

The launch direction and resulting momentum depend on the player's movement and orientation.

## 7. Movement Transitions

Transitions are critical.

The following should eventually be supported:

- Ground → Jump
- Jump → Wall
- Wall → Ground
- Wall → Wall
- Wall → Air
- Air → Ground
- Air → Web
- Web → Air
- Web → Wall

Transitions should avoid feeling like separate game modes.

The intended experience is continuous movement.

## 8. Momentum

Momentum is one of the most important systems in the simulator.

Movement should not constantly reset velocity when changing states.

Examples:

### Running → Jump

Forward running momentum carries into the jump.

### Wall Run → Jump

Wall-running momentum carries into the launch.

### Swing → Release

Swing momentum carries into freefall.

### Web Wings → Dive

Diving converts altitude into additional forward movement where appropriate.

The player should learn to manipulate momentum rather than fight a system that constantly removes it.

## 9. First-Person Presentation

The gameplay camera is first person.

The camera should communicate body movement without becoming disorienting.

Important feedback includes:

- Body lean
- Head movement
- Acceleration/deceleration
- Jumping
- Landing
- Impacts
- Rotations
- Web transitions

The player should feel Spider-Man's movement through the camera while retaining sufficient visual stability to control traversal.

## 10. Third-Person Trick Showcase

The normal camera remains first person.

When the player successfully performs a notably impressive maneuver, the game may briefly switch to a third-person camera to show the movement.

This is presentation only and does not replace the player's normal first-person experience.

## 11. Failure Is Expected

The movement system is designed around experimentation.

The player will:

- Miss jumps
- Misjudge walls
- Release webs incorrectly
- Lose momentum
- Hit buildings
- Hit streets
- Hit cars
- Miss landings

These failures are part of learning.

The movement system should make failure understandable rather than frustrating.

## 12. Initial Prototype

The first implementation should intentionally be simple.

### Prototype Environment

Use primitive geometry:

- Flat ground
- Simple walls
- Simple elevated platforms
- Basic vertical structures

### Prototype Goals

The first playable movement prototype must prove:

1. Running feels good.
2. Jumping preserves momentum.
3. Air control feels responsive.
4. Wall climbing works.
5. Wall running works.
6. Wall launches work.
7. Ground/wall/air transitions feel continuous.

Do not add the full city until these fundamentals feel right.

## 13. Development Order

### Phase 1 — Ground

`Walk → Run → Stop → Turn`

### Phase 2 — Jump

`Run → Jump → Air Control → Land`

### Phase 3 — Walls

`Jump → Wall Contact → Climb`

### Phase 4 — Wall Run

`Run → Wall → Wall Run → Launch`

### Phase 5 — Acrobatics

`Jump → Rotate → Recover → Land`

### Phase 6 — Integration

Combine all movement types into continuous traversal.

### Phase 7 — Webs

Add web movement without rebuilding the underlying player movement model.

## Design Rule

> **The player learns Spider-Man. The game does not level Spider-Man up.**

No XP, levels, skill points, or movement unlocks are required for the core movement system.
