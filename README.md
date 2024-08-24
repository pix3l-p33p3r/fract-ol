<h1 align="center">
    <b>fract'ol</b>
    <br>
    <img src="https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/fract-olm.png" alt="fract'ol">
</h1>


<h4 align=center>
	This project is meant to create graphically beautiful fractals
</h4>

<p align=center>
	In this repo you will find all the codes developed during the <i>fract'ol</i> project, both <b>mandatory</b>'s part and <b>bonus</b>.
</p>

---

<div align=center>
<h2>
	Final score
</h2>
<img src=https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/score_125.png />
<h4>Completed + Bonus</h4>
</div>

---

![Fract-ol mono-colored Mandelbrot](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Mandelbrot.png)


# Usage

---

Note that this project was tested on MacOS only. It may run on Linux with small adjustments to the Makefile, as described in hsmits and jvan-sni's [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).

---

## Installing and Compiling Fract-ol

Clone the repository, including the embedded MiniLibX repository:
```shell
git clone https://github.com/pix3l-p33p3r/fract-ol.git && cd fract-ol 
```

You will now be in the correct directory for compilation. Compile with ```make```. Fract-ol should now be ready!

## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:

```shell
./fractol <number>
```

Types are :
* ```1```: Mandelbrot fractal
* ```2```: Julia fractal
- Requires additional parameters for imaginary and real constants:
    - `<imaginary_constant>`: Imaginary part of the Julia set constant
    - `<real_constant>`: Real part of the Julia set constant
* ```3```: 4th Mandelbrot (Burning Ship) fractal

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0. For example:

```shell
./fractol 2 0.285 -0.01
```



## Fract-ol Controls

While Fractol is running, the following set of controls are available:

<table>
  <tr><td><strong>Controls</strong></td><td><strong>Action</strong></td></tr>
  <tr><td><kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Move</td></tr>
  <tr><td><kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out (zoom follows the actual mouse position)</td></tr>
  <tr><td><kbd>&nbsp;r&nbsp;</kbd>, <kbd>&nbsp;g&nbsp;</kbd>, <kbd>&nbsp;b&nbsp;</kbd></td><td>Change color scheme (r for red, g for green, b for blue)</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Quit fract-ol</td></tr>
</table>



# SRC_IMG

## Mandelbrot set

![Fract-ol purple and yellow striped Mandelbrot](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Mandelbrot-2.png)
![Fract-ol red bllue and green striped Mandelbrot](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Mandelbrot-3.png)
![Fract-ol sun crest purple Mandelbrot](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Mandelbrot-4.png)

## Julia set

![Fract-ol purple green and yellow Julia](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Julia.png)
![Fract-ol red swirl Julia](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Julia-2.png)
![Fract-ol blue snowflake Julia](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Julia-3.png)

## Burning ship set

![Fract-ol golden burning ship](https://github.com/pix3l-p33p3r/fract-ol/blob/main/SRC_IMG/Fractol-Burning-Ship.png)

