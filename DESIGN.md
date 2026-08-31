# Spider-Man Simulator — Design Specification

## Project Status

**Phase:** Pre-production / mechanics design  
**Engine target:** Unreal Engine 5  
**Current focus:** Build and validate movement mechanics before creating the full 3D world.

## 1. Core Philosophy

Spider-Man Simulator is a movement-focused first-person Spider-Man experience. The player is given Spider-Man's physical abilities and must learn to use them through experimentation and practice.

This is not a traditional action game. Combat, XP, levels, skill trees, and artificial progression are not core systems.

The primary progression is the player's own skill.

> The simulator gives the player Spider-Man's capabilities. The player learns how to use them.

## 2. Movement Is the Game

The primary activity is freely traversing New York through swinging, climbing, wall-running, jumping, gliding, and acrobatics.

The city itself is the playground. A successful movement sequence may chain running, wall-running, jumping, web swinging, release, aerial tricks, Web Wings, and landing.

## 3. Player Abilities

### Ground Movement
- Walking
- Running
- Jumping
- Falling
- Air control
- Momentum preservation

### Wall Movement
- Wall climbing
- Wall running
- Ground/wall/aerial transitions

### Web Movement
- Web shooting
- Web attachment
- Swinging
- Releasing from a swing
- Momentum carried through release
- Chaining web movements
- Web trajectory visualization

### Aerial Movement
- Freefall
- Acrobatics
- Body orientation
- Web Wings/gliding
- Swing/freefall/gliding transitions

## 4. Web Technology

The initial prototype uses **organic webs**. Later, the system transitions to **mechanical web shooters**.

The first implementation intentionally avoids advanced anchor-point logic. The prototype only needs to prove that the player can aim, attach a web, swing, and release while retaining momentum.

## 5. Web Trajectory / Peter's Calculations

The HUD visualizes the projected path of a web shot. This represents Peter's spatial and scientific calculations rather than an automated gameplay assist.

The player still decides where to aim, when to fire, when to release, how to redirect momentum, and how to recover from mistakes.

## 6. Spider-Sense

Spider-Sense is a **warning system, not an automatic dodge system**.

When danger is detected, Spider-Sense alerts the player. The player must react. Possible feedback includes visual pulses, directional cues, audio cues, or subtle emphasis toward the threat.

If the player fails to react, the collision happens.

Intended progression:

`Warning → Player reaction → Successful avoidance`

The player gradually learns to interpret and react to Spider-Sense instinctively.

## 7. Impact and Regeneration

Spider-Man has cellular regeneration, but it is not intended to be Wolverine/Deadpool-level regeneration.

Its primary purpose is supporting traversal failure. Players will inevitably hit buildings, streets, cars, signs, and other objects while learning movement.

No detailed medical simulation is required.

- **Light impact:** brief stumble/camera feedback.
- **Moderate impact:** noticeable stagger or temporary slowdown.
- **Heavy impact:** obvious injury state, knockdown, or longer recovery.
- **Extreme impact:** temporary incapacitation.

Regeneration gradually returns the player to normal. The player should understand that they were hurt without needing a traditional health-bar system.

## 8. Camera Philosophy

The primary gameplay perspective is **first person**. The player experiences traversal directly through Spider-Man's eyes.

Third person is reserved for special presentation moments.

### Trick Showcase

When the player performs a notably cool or difficult maneuver, the game may briefly switch to a third-person cinematic view showing the maneuver, then return to first person without breaking movement flow.

## 9. Trick and Replay System

Recording is a mandatory core feature.

The simulator should maintain a rolling replay buffer so the player can save a maneuver after performing it without needing to predict that it would succeed.

Both successful and failed attempts must be reviewable.

### Successful Attempt
- Recognize notable movement where appropriate.
- Brief third-person showcase.
- Allow the player to save the replay.

### Failed Attempt

The player can immediately review the attempt to understand what went wrong, such as releasing too early/late, poor swing angle, insufficient momentum, bad web target, incorrect aerial timing, or poor landing approach.

The simulator provides evidence rather than automatically solving the mistake.

### Replay Views
- Original first-person view
- Third-person view
- Adjustable replay camera
- Multiple viewing angles
- Trick statistics
- Location information

The replay system is both a learning tool and a highlight system.

## 10. HUD / Mask Overlay

The HUD is presented as part of Spider-Man's mask interface rather than a conventional game HUD.

Initial HUD elements include:
- Compass
- Web trajectory visualization
- Spider-Sense feedback

The HUD should remain minimal and avoid cluttering the player's view.

For early mechanics prototypes, debug visualization can be used. Final mask presentation can be developed later without changing the underlying systems.

## 11. New York World Design

New York uses a **1:1 physical scale for overall size**, not a literal one-to-one recreation of every building or street.

### Initial Scope

Manhattan is the first major playable area. Other boroughs can be added later if useful.

### Streaming / Loading Boundaries

The rivers surrounding Manhattan can function as natural world-streaming boundaries. The player can still cross the water using Spider-Man's movement abilities; the water provides the transition/streaming space rather than an artificial loading screen such as a bridge.

### Important Landmarks

Recognizable landmarks should exist even though the entire city is not being recreated literally.

Initial examples:
- Empire State Building
- Madison Square Garden

## 12. Development Philosophy

Development proceeds from **mechanics to presentation**.

Do not begin with the full city.

### Prototype Order
1. Player movement
2. Jumping/falling and momentum
3. Wall climbing
4. Wall running
5. Basic web firing
6. Basic web attachment
7. Basic swinging
8. Web release and momentum preservation
9. Aerial movement
10. Spider-Sense
11. Impact/recovery
12. HUD
13. Trick detection
14. Replay/recording
15. Full world

The first test environment should use intentionally simple geometry. The first milestone is proving that Spider-Man movement feels right.

## 13. No Artificial Progression

The simulator does not use XP, levels, skill points, skill trees, combat progression, or unlock grinds.

The player's improvement comes from learning the movement systems.

> "I couldn't do this when I started. Now I can."

## 14. Technical Target

**Engine:** Unreal Engine 5

The eventual implementation should keep systems independent:

```text
Player
├── Movement
├── Wall Movement
├── Web System
├── Aerial Movement
├── Spider-Sense
├── Impact / Recovery
└── Camera

Web System
├── Targeting
├── Trajectory
├── Attachment
├── Swing Physics
└── Release

Presentation
├── Mask HUD
├── Trick Showcase Camera
└── Replay System
```

The architecture may change as implementation begins. This document is the current design authority, not a restriction against improving the design.

## 15. Current Development State

**No 3D implementation yet.**

The project is currently in the design/pre-production stage. Mechanics and systems are being defined before Unreal Engine development begins.
