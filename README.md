*This project has been created as part of the 42 curriculum by aliissa.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C standard library function `printf`, packaged as a static library, `libftprintf.a`.

The goal of the project is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`), how to parse a format string, and how to build formatted output while counting every character written, exactly as the real `printf` does.

**Supported conversions**

| Conversion | Output |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` for a NULL pointer) |
| `%p` | a pointer address in hexadecimal, prefixed with `0x` (`(nil)` for NULL) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned hexadecimal integer, in lowercase or uppercase |
| `%%` | a literal `%` |

**Bonus: flags, width and precision**

| Element | Effect |
|---|---|
| `-` | left-justify the output inside the field width |
| `0` | pad numbers with zeros instead of spaces (ignored with `-` or with a precision) |
| `.` precision | maximum number of characters for `%s`; minimum number of digits for integer conversions |
| width | minimum number of characters printed for one conversion |
| `#` | prefix `0x` / `0X` for non-zero `%x` / `%X` values |
| `+` | always show a sign for signed conversions |
| ` ` (space) | put a space in front of non-negative signed numbers (ignored with `+`) |

Like `printf`, `ft_printf` returns the number of characters printed, or `-1` if a write error occurs.

## Instructions

**Compilation**

```sh
make          # builds libftprintf.a (mandatory part)
make bonus    # builds libftprintf.a with flags, width and precision
make clean    # removes object files
make fclean   # removes object files and the library
make re       # rebuilds everything from scratch
```

The Makefile first builds the bundled `libft` with its own Makefile, then merges `libft.a` and the ft_printf objects into a single `libftprintf.a`, so programs only need to link against this one file.

**Usage**

Include the header and link with the library:

```c
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = ft_printf("[%-8s|%+05d|%#x|%p]\n", "hello", 42, 255, (void *)&n);
	ft_printf("%d characters printed\n", n);
	return (0);
}
```

```sh
cc main.c libftprintf.a -I. -Ilibft -o test
./test
```

## Algorithm and data structure

### Data structure: the conversion description (`t_flag`)

Every conversion (everything from a `%` up to its conversion letter) is described by a small struct:

| Field | Meaning | Default |
|---|---|---|
| `minus`, `zero`, `hash`, `plus`, `space` | one boolean per flag | 0 |
| `width` | minimum field width | 0 |
| `prec` | precision, where **-1 means "no precision given"** | -1 |
| `speci` | the conversion letter | `'\0'` |

A fresh struct is created and reset for every `%`, so nothing can leak from one conversion to the next. The struct is filled by the parser and only read by the printers, which keeps the two responsibilities separate.

Using `-1` for "no precision" was a deliberate choice. `printf` treats "no precision" and "precision 0" differently (`%d` prints `0` for the value 0, while `%.0d` prints nothing), so the two cases must be distinguishable.

### Algorithm, part 1: scanning the format string

The main loop walks through the format string one character at a time. Each iteration takes exactly one of three branches, and each branch moves the index by exactly the right amount:

1. a normal character: write it, move by 1
2. `%%`: write `%`, move by 2
3. `%` followed by anything else: parse the conversion, then print it (the parser itself moves the index past the conversion letter)

Because the loop condition stops at `'\0'`, the program never reads past the end of the format string, even for malformed input such as `"abc%"`.

### Algorithm, part 2: the parser

The parser is a small forward-only state machine that follows the fixed grammar of a conversion:

```
%  [flags]  [width]  [.precision]  conversion
```

Each phase consumes only the characters that belong to it and stops at the first character that does not, leaving it for the next phase:

1. **Flags:** loop while the character is one of `- 0 # + space`, setting the matching boolean.
2. **Width:** read consecutive digits into a number.
3. **Precision:** if the character is `.`, set the precision to 0, then read any following digits.
4. **Conversion:** if the character is a valid conversion letter, store it.

The order matters: a `0` is read as a flag only during the first phase. Once a non-zero digit has started the width, any further `0` is part of the number (as in `%10d`).

### Algorithm, part 3: compute first, then write in layers

Each printer first computes plain numbers, then writes the output in a fixed sequence of layers:

```
[left padding] [sign or 0x prefix] [zeros] [digits / characters] [right padding]
```

- precision zeros = precision − number of digits
- padding = width − (sign/prefix length + precision zeros + digits)
- the `-` flag moves the padding to the right; an active `0` flag turns the padding into zeros placed after the sign or prefix

Each layer is written with a helper that writes a character *N* times. When *N* is zero or negative, it simply writes nothing, so most special cases need no extra branch.

**Why this approach:** an earlier version built the output as strings with `malloc` and `strjoin`. That caused missing `'\0'` terminators, uninitialized pointers, memory leaks, and made `%c` with `'\0'` impossible to print. Writing directly, layer by layer, avoids all of these: no intermediate strings are allocated except the digit string, which is freed right after use.

### Number conversion

Integers are converted to a string of digits by one function, `ft_ltoa_base`, which takes an `unsigned long` and a digit set (`"0123456789"`, `"0123456789abcdef"` or `"0123456789ABCDEF"`). The same function serves `%d`, `%i`, `%u`, `%x`, `%X` and `%p`.

The sign is never put inside the digit string. For `%d` / `%i`, the value is first copied into a `long`, so that `INT_MIN` can be negated safely. The sign character is chosen separately, in priority order: `-` for negative numbers, otherwise `+`, otherwise a space, otherwise nothing.

### Return value and error handling

Every write goes through helpers that return the number of bytes written or `-1`. The results are accumulated with a "sticky" helper: once any write has failed, the total stays at `-1`. `ft_printf` therefore returns `-1` whenever an error occurred (for example when standard output is closed), like the real `printf`.

## Resources

**References**

- `man 3 printf` and `man 3 stdarg`, the Linux manual pages for `printf` and variadic functions: https://man7.org/linux/man-pages/man3/printf.3.html
- The GNU C Library manual, formatted output: https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html
- The behavior of the system `printf` (glibc on Linux), used as the reference to compare output and return values

**How AI was used**

An AI assistant (Claude) was used as a tutor and reviewer during this project:

- **Explanations:** the meaning of each flag, width and precision, and how they interact; how `va_list` / `va_arg` work; pointers versus the values they point to; signed/unsigned conversions.
- **Design guidance:** the overall architecture (main loop, parser, printers), the struct layout, and the compute-then-write approach, explained in words. The C code of the functions was written by me.
- **Code review:** the assistant reviewed my functions and pointed out bugs (index handling in the main loop, missing string terminators, uninitialized variables, memory leaks, wrong padding counts), explaining how to fix them without rewriting the code.
- **Testing:** the assistant generated test cases and ran comparison tests of my implementation against the real `printf` (output and return value), including checks with AddressSanitizer.
- **Makefile:** the Makefile was written with the assistant's help, then adapted to the project.
- **This README** was drafted with the assistant's help and reviewed by me.