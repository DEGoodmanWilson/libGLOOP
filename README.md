libGLOOP 1.1
============

This is version 1.1 beta of libGLOOP
GLOOP is Liquid Object Oriented Particles.

changes:

Since Brian Sharp's initial release, D.E. Goodman-Wilson has added variable
particle field stregnth.

0.8b to 1.0:
Fixed the goddamn Marching Cubes Lookup Table...found a public domain
replacement that /works/!

1.0 to 1.1:
Added UNIX makefiles. Thanks to Jeffrey B Mcbeth of the Morphogenesis Project!

todo for 1.2:
Add color interpolation. Some code for this has been added already, but
not much... If I ever get around to dealing with this, it's going to be 
a real bitch. Expect it to take some time. Sorry. But it's not like what we
have here isn't functional or anything...

Most of the code here is from Brian Sharp, and all of it is public domain.
The original URL is http://www.manaical.org/implicits.html, but I think
it's only available from gamasutra.com now.

This project turns Brian Sharp's public domain meta-particle rendering demo
(http://www.maniacal.org/implicits.html) into a minimal library for rendering
implicit surfaces. Everything else has been stripped out (physics, UI, the
specific demos): the focus is strictly on rendering implicit surfaces with an
optimized marching cubes algorithm.
The purpose: I have been unable to find code for this at all. I personaly am
interested in rendering realistic fluids in computer games, but I am not
interested in having to implement the marching cubes algorithm on my own.
Brian Sharp produced this demo for Games Developer Magazine, and has released
the code into the public domain. The problem: its hard to extract the Golden
Nugget from the layers of other stuff needed to make the demo work. Thus this
project: to turn this code into a reusable library to facilitate
experimentation with implicit surfaces, and to give game coders a
tool to produce yummy eye candy.

If you use libGLOOP in a commercial or any other product, it would be nice
if you gave credit where it is due (namely Brian Sharp, and Jeffery Mcbeth
...and well, yeah, me too).  If you make any neat modifications
or improvements to libGLOOP, I would greatly appreciate a copy of the
improved code or at least a source patch. Of course, this is all public domain,
so do with it as you see fit.

D.E. Goodman-Wilson

Comments, questions, &c:
dgoodman@railstars.com

[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/DEGoodmanWilson/libgloop/trend.png)](https://bitdeli.com/free "Bitdeli Badge")
