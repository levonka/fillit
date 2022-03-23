# Fillit

Fillit is a School 42 project. The purpose of this project is to create program that forms the smallest possible square from a list of tetriminos.

[`fillit.en.pdf`](/fillit.en.pdf) is the task file.

## Usage

Compile the program:

```shell
$ make
```

Run program with file:

```shell
$ ./fillit [file]
```


## Final score

100/100 (max)

![](screenshots/score.png)

## How does it work

Fillit receives a map text file like this one with pieces:

```text
$ cat sample.fillit
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....
```

It finds the smallest possible square the pieces can be arranged in and prints out the square like this:

```text
$ ./fillit sample.fillit
DDAA
CDDA
CCCA
BBBB
```
