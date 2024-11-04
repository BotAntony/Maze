Test asignment for my uni.

Basic C program that creates mazes using [Depth-First Search algorithm](https://en.wikipedia.org/wiki/Depth-first_search).

TBA: simple console-based maze game.

## Installing
1. Copy this repo
2. Use `make print_maze` command to create `print_maze` binary. Use `make maze` to compile the game. All binaries are compiled to the folder `bin`.
 1. Use `make debug` to compile binaries with `-g` flag and `make clean` to remove binaries and debug files.
3. Run using `bin/print_maze` (prints maze) or `bin/maze` (game).

## Usage
### print_maze
```console
foo@bar~$: ./print_maze
Prints maze with default settings
foo@bar~$: ./print_maze -h
Prints "help" page
foo@bar~$: ./print_maze -r 63 -c 63
Prints maze with 63 rows (-r) and 63 columns (-c)
foo@bar~$: ./print_maze -s 123456
Prints maze using the seed (-s)
```
