# get_next_line 42 Madrid
The objective of the project is to read a complete line from a file descriptor.

## Installation
Clone the repo
```bash
git clone https://github.com/danielfdez17/get_next_line.git
cd get_next_line
```
## Build
### Mandatory
```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -fsanitize=address -o a.out
```

### Bonus
```bash
cc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -fsanitize=address -o a.out
```

## Usage
### Mandatory
To read from stdin, just execute the program. Press Ctrl+C or Ctrl+D to exit.
```bash
./a.out
```

To readx from a file, just redirect the content of the file to the stdin.
```bash
./a.out < README.md
```

### Bonus
Just change the two files that will be open to read from various file descriptors.
```bash
./a.out
```