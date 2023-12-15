 <h1 align="center">GET_NEXT_LINE</h1>

## Description
`get_next_line` is a function that reads a line from a file descriptor and returns it. Repeated calls to this function allow reading a text file, one line at a time. The function returns the read line or `NULL` if there is nothing else to read or an error occurs.

## Files
- `get_next_line.c`: Implementation of the `get_next_line` function.
- `get_next_line_utils.c`: Helper functions used by `get_next_line`.
- `get_next_line.h`: Header file containing the prototype of `get_next_line` function.


### Bonus Part
 - In this bonus part, we are gonna develop a get_next_line() function that uses only one static variable. It presents an intriguing challenge where your get_next_line() should possess the ability to manage multiple file descriptors simultaneously. For example, picture the scenario where you can read from file descriptors 3, 4, and 5. The objective is to ensure that calling get_next_line() on each file descriptor doesn't disrupt the reading thread of others or lead to returning a line from the wrong file descriptor. This implies that your implementation should seamlessly enable you to switch between reading from fd 3, fd 4, fd 5, and so on, all while maintaining the integrity of each reading thread.

### Bonus Part Files
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`
- `get_next_line_bonus.h`

## Prototype
```c
char *get_next_line(int fd);
```
## Usage

Repeated calls to `get_next_line` should be used in a loop to read a text file pointed to by the file descriptor, one line at a time. The returned line includes the terminating `\n` character, except if the end of the file was reached and does not end with a `\n` character.

### Example

```c
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        // Process the line
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
### Compiling
Compile the program using the specified `flags` and preprocessor directive:
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out
```
