*This project has been created as part of the 42 curriculum by mtrukhin.*

### Description
The goal of this project is to implement a function `get_next_line` that reads and returns one line at a time from a file descriptor. Each call to the function returns the next line, including the newline character if present, until the end of the file is reached.

The main challenge is managing buffered input efficiently and preserving state between function calls using static variables.

---

### Instructions
Write a `main` and either put fd as 0 for stdin or use `read()` to get the fd and pass it into `get_next_line()` and iterate over the result, it's a string.

There's also a way to specify the buffer size (see below). For compilation, use:
```bash
cc -Wall -Wextra -Werror (-D BUFFER_SIZE=<your_buffer_value>) get_next_line.c get_next_line_utils.c
```

### Resources
Mostly my brain, AI for bugs, ideas and manual stuff (ofc I've learnt a lot and not just copy-pasted) and a geekbrains article about `read()`
