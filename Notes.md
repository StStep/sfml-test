# Implementation Notes

General notes about implementation

## C++ Libraries

* Velocity Objects: <https://github.com/snape/RVO2>
* Physics: <https://github.com/bulletphysics/bullet3>
* Linear Algebra: <http://eigen.tuxfamily.org/index.php?title=Main_Page>
* Pathfinding: <https://github.com/recastnavigation/recastnavigation>
* Rendering: <https://www.sfml-dev.org/>

## Pathfinding

Recast + Detour might be overkill...

Recastnavigation has mesh pathing, but doesn't care about local avoidance.
An example of local avoidance is Reciprocal Velocity Obstacles: <https://arongranberg.com/astar/docs/local-avoidance.php>

Velocity Obstacle (VO) papers:

* [Cooperative VO (2001)](https://ieeexplore.ieee.org/document/977147) - Early work for entity cooperation
* [Reciprical VO (2008)](https://ieeexplore.ieee.org/document/4543489) - Basic reciprical
* [Parallelize RVO (2009)](https://dl.acm.org/citation.cfm?doid=1599470.1599494) - Optimized for doing a bunch of stuff in parallel, called CleaPath
* [Hybrid Recprical VO (2011)](http://gamma.cs.unc.edu/HRVO/) - Improving RVO to avoid osscilations
* [Generalized VO (2009)](https://ieeexplore.ieee.org/document/5354175) - Customized VO to work with car-like objects

VO Examples:

* <https://www.youtube.com/watch?v=7v3760l7-m4>
* <https://www.youtube.com/watch?v=VStxrSna92I>
