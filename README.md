# SFML Testing w/RVO2

## Building

Build using CMake.

The dependencies include the following:

* RVO2 <https://github.com/snape/RVO2>
* SFML <https://www.sfml-dev.org/>

Primary testing is with Windows 10 and Visual Studio Code.
Win32 specific stuff might have leaked in.

## Pathfinding

One step above mesh pathfinding.
Such as local avoidance, Reciprocal Velocity Obstacles: <https://arongranberg.com/astar/docs/local-avoidance.php>

Velocity Obstacle examples:

* [Cooperative VO (2001)](https://ieeexplore.ieee.org/document/977147) - Early work for entity cooperation
* [Reciprical VO (2008)](https://ieeexplore.ieee.org/document/4543489) - Basic reciprical
* [Parallelize RVO (2009)](https://dl.acm.org/citation.cfm?doid=1599470.1599494) - Optimized for doing a bunch of stuff in parallel, called CleaPath
* [Hybrid Recprical VO (2011)](http://gamma.cs.unc.edu/HRVO/) - Improving RVO to avoid osscilations
* [Generalized VO (2009)](https://ieeexplore.ieee.org/document/5354175) - Customized VO to work with car-like objects

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
