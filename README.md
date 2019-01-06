# SFML Testing w/RVO2

## Building

Build using CMake.

The dependencies include the following:

* RVO2 <https://github.com/snape/RVO2>
* SFML <https://www.sfml-dev.org/>

Primary testing is with Windows 10 and Visual Studio Code.
Win32 specific stuff might have leaked in.

## Using RVO2

All RVO2 is adjust velocities based of possible collisions to avoid them.
It should be used by setting preferred velocities, and then seeing what happens post step.
It's kind of like the simulation sandbox, you set obstacles, agents and guide them, and let it figure out the details.

## TODO

* SimVis
  * Want to be able to assign entities to groups, for special colors
  * All purpose drawer, include obstacles
* 'Improvements'
  * See how A* pathing works when setting up preferred velocity
* More Scenarios
  * Define quick language for setting up scenario
  * Try out two groups walking towards each other
  * Try single group going down funnel
* Dream Ideas
  * Concept of cooperative vs obstructive groups?
