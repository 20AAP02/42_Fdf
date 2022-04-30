<h1 align="center"> FDF | 42 School Project </h1>
<h4>This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.</h4>
<p>The perpose of the project was to read point coordenates from a file, and then throught the use of the school's library MiniLibX, draw the map froma specific viewpoint</p>
<p>The file would look something like this</p>

```
$>cat 42.fdf
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
$>
```

Each number represents a point in space:<br>
• The horizontal position corresponds to its axis.<br>
• The vertical position corresponds to its ordinate.<br>
• The value corresponds to its altitude.<br>

<p>And the program would have to create a window and print the image like so</p>

<p>Some files also came with color hexadecimal value of the points</p>

```
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```

-----

<h4>What I learned with this project?</h4>
<p>- How to manage a graphics window, draw inside it and hook keys to certain actions</p>
<p>- How to work with rgb colors and how to modify their values to make gradients and such</p>
<p>- Isometric projections</p>
<p>- Improved Makefile knowledge</p>

-----

<h4>Subject</h4>
https://github.com/20AAP02/42_Fdf/blob/main/en.subject.pdf

-----

<h4>Grade : %</h4>
<h6>Mandatory : /100</h6>
<h6>Bonus : /25</h6>

-----

<h4>How to use</h4>

<h5>Cloning and compiling</h5>

```
git clone https://github.com/20AAP02/42_Fdf.git
cd 42_Fdf/fdf_linux
```

<p>In mac</p>

```
make
```
<p>In linux</p>

```
make l
```

<h5>Use</h5>

```
./fdf map/test_maps/42.fdf
```

<p>There's many files you can use. You can also add your own files as long they are .fdf and have the same format</p>

<p>Once the window is opened, you can use:<br>
  • "m n" to zoom in and out.<br>
  • "z x" to change scale of the points altitude.<br>
  • "j l" to move the picture left and right.<br>
  • "i k" to move the picture up and down.</p>

<h4>References</h4>
https://github.com/qst0/ft_libgfx <br>
https://github.com/VBrazhnik/FdF/wiki <br>
https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html <br>
https://git.42l.fr/Fabien/fdf <br>
http://members.chello.at/~easyfilter/Bresenham.pdf <br>
https://github.com/42Paris/minilibx-linux <br>
https://qst0.github.io/ft_libgfx/man_mlx_loop.html <br>
https://harm-smits.github.io/42docs/libs/minilibx/events.html <br>
https://github.com/VBrazhnik/FdF/blob/master/fdf/sources/keyboard_controls.c <br>
https://github.com/Mohamed-Moumni/FDF <br>
https://github.com/VBrazhnik/FdF/wiki/How-to-handle-mouse-buttons-and-key-presses%3F <br>
https://www.kirupa.com/developer/actionscript/isometric_transforms.htm <br>
https://www.w3schools.com/colors/colors_mixer.asp <br>
https://github.com/Y-askour/fdf-42 <br>
https://github.com/VBrazhnik/FdF/wiki/How-to-perform-isometric-transformations%3F <br>
https://raw.githubusercontent.com/VBrazhnik/FdF/master/images/key_codes.png <br>
https://stackoverflow.com/c/42network/images/s/1a53fce9-5a0f-46b4-9eef-545d85fcccae.png <br>

<h3>This project was done according to the norminette form</h3>
