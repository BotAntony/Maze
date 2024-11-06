Test asignment for my uni.

Basic C program that creates mazes using [Depth-First Search algorithm](https://en.wikipedia.org/wiki/Depth-first_search) and a game.

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
Prints a maze with 63 rows (-r) and 63 columns (-c)
foo@bar~$: ./print_maze -s 123456
Prints a maze using the seed (-s)
```
### maze
```console
foo@bar~$: ./maze
Start a game with default settings
foo@bar~$: ./maze -h
Prints "help" page
foo@bar~$: ./maze -m
Displays a minimap during the game (`8` - a wall, `!` - player's position, `O` - final room)
foo@bar~$: ./maze -r 63 -c 63
Creates a maze with 63 rows (-r) and 63 columns (-c)
foo@bar~$: ./maze -s 123456
Creates a maze using the seed (-s)
```
