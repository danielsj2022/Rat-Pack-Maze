# Rat-Pack-Maze
Coded in C++.

Implemented a self-created Stack as a generic adaptor class template. The goal is to find and list the coordinates to get from Start to Goal. The maze is described as a two dimensional rectangular array of square cells where the user inputs number of rows and columns, followed by the rows of code, then the start and goal row and column. The maze is made of binary codes that have to be translated from decimal numbers. These codes represent which direction the rat can go. The path the rat can take is put into a Stack from start to goal. To print the coordinates in order a temporary stack is used.

To run: Used Unix to compile. To create executable, run 'makefile' to produce executable.
