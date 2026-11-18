*This project has been created as part of the 42 curriculum by aliissa.*

# Libft

## Description

**Libft** is the first major project in the 42 curriculum. The goal of this project is to create a personal C library containing a collection of useful functions that can be reused in future C projects.

The project consists of recreating several standard C library functions, implementing additional utility functions, and developing functions for manipulating linked lists.

By completing this project, I gained a deeper understanding of:
- Memory allocation and deallocation.
- Pointers and pointer manipulation.
- String manipulation.
- Memory management.
- Data structures, particularly linked lists.
- Writing reusable and well-structured C code.

The resulting library, `libft.a`, can be compiled and linked with other C programs.

## Instructions

### Compilation

To compile the library, clone the repository and navigate to its root directory:

```bash
git clone <repository-url>
cd libft
```

Compile the mandatory functions using:

```bash
make
```

### Makefile Rules

The Makefile provides the following rules:

| Rule | Description |
|---|---|
| `make` | Compiles the functions into `libft.a`. |
| `make clean` | Removes object files (`.o`). |
| `make fclean` | Removes object files and the library. |
| `make re` | Recompiles the entire library from scratch. |

### Using the Library

To use Libft in another C project, include the header file:

```c
#include "libft.h"
```

Compile your source files together with the library:

```bash
cc main.c -L. -lft -I. -o program
```

Run the executable:

```bash
./program
```

## Library Contents

The library is divided into several categories of functions.

### 1. Character Checking and Conversion

Functions used to identify character types and convert between uppercase and lowercase letters.

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is an alphabetic letter. |
| `ft_isdigit` | Checks whether a character is a digit (0–9). |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII character set. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

### 2. String Manipulation

Functions for measuring, comparing, searching, and manipulating strings.

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_strlcpy` | Copies a string into a destination buffer with size limitation. |
| `ft_strlcat` | Appends a string to another with size limitation. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specified number of characters. |
| `ft_strnstr` | Locates a substring within a string, searching up to a specified length. |
| `ft_strdup` | Creates a dynamically allocated duplicate of a string. |
| `ft_substr` | Extracts a substring from a string. |
| `ft_strjoin` | Concatenates two strings into a newly allocated string. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter. |
| `ft_strmapi` | Applies a function to each character of a string to create a new string. |
| `ft_striteri` | Applies a function to each character of a string by reference. |

### 3. Memory Manipulation

Functions for handling memory blocks and performing memory operations.

| Function | Description |
|---|---|
| `ft_memset` | Fills a memory area with a specified byte. |
| `ft_bzero` | Sets a memory area to zero. |
| `ft_memcpy` | Copies a memory block from one location to another. |
| `ft_memmove` | Copies memory while safely handling overlapping regions. |
| `ft_memchr` | Searches for a byte in a memory block. |
| `ft_memcmp` | Compares two memory blocks. |
| `ft_calloc` | Allocates memory and initializes it to zero. |

### 4. Conversion and Output

Functions for converting strings to integers and writing characters, strings, and numbers to file descriptors.

| Function | Description |
|---|---|
| `ft_atoi` | Converts a string into an integer. |
| `ft_itoa` | Converts an integer into a dynamically allocated string. |
| `ft_putchar_fd` | Writes a character to a specified file descriptor. |
| `ft_putstr_fd` | Writes a string to a specified file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a specified file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a specified file descriptor. |

### 5. Linked List Manipulation

This part introduces singly linked lists and functions for creating, traversing, modifying, and deleting list elements.

The linked list structure is defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Each node contains:
- `content`: A pointer to the data stored in the node.
- `next`: A pointer to the next node in the list.

The following functions are implemented:

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node. |
| `ft_lstadd_front` | Adds a node to the beginning of a list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstdelone` | Deletes a single node using a specified deletion function. |
| `ft_lstclear` | Deletes an entire list and frees its allocated memory. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

## Resources

The following resources were useful during the development of this project:

- [42 School](https://42.fr/) – Project requirements and curriculum.
- [C Standard Library Documentation](https://en.cppreference.com/w/c/header.html) – Reference for standard C library functions.
- [Linux Manual Pages](https://man7.org/linux/man-pages/) – Documentation for C functions and system calls.

### AI Usage

AI tools, including ChatGPT, were used as learning and development assistance throughout this project.

They were used for:
- Understanding the behavior and expected functionality of standard C library functions.
- Clarifying pointer manipulation, memory allocation, and linked list concepts.
- Debugging assistance and understanding unexpected behavior.
- Interpreting compiler errors and test results.
- Reviewing edge cases and improving code reliability.
- Assisting with the organization and documentation of this README.

The implementation and development process involved writing, testing, and debugging the functions while using AI as a supporting learning resource.