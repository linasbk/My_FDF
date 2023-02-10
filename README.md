<h1 align="center">
	📖 FDF
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/linasbk/get_next_line?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/linasbk/get_next_line?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/linasbk/get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/linasbk/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/linasbk/get_next_line?color=green" />
</p>
---

## About

FdF is a project in which we convert a file with a grid of height values into a 3d wireframe using a simple graphics library called MiniLibX.

## Installation

The program can be build with a simple `make all`

## Examples

### Simple example of functionality
The following is an example of a .fdf file we use as an input for our program:
```
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1
```
### Example of rotation, translation, zoom, flattening and perspective changes

![fdf480](https://user-images.githubusercontent.com/21006147/190404352-288d7bf1-5f43-4e2d-8033-f16bca534ca6.gif)

### Example with large map
<img width="1910" alt="Screen Shot 2022-09-15 at 2 38 15 PM" src="https://user-images.githubusercontent.com/21006147/190406149-d0d13cb6-c3eb-4594-abf8-d22c5b005485.png">
