*This project has been created as part of the 42 curriculum by [wgolbert].*

# ft_printf

## Description

**ft_printf** is a partial reimplementation of the C standard library function `printf`. The goal is to produce a function with the same prototype and behaviour as the real `printf`, handling a variable number of arguments through variadic functions and outputting formatted text to standard output.

The project covers the following conversion specifiers:

| Specifier | Output |
|-----------|--------|
| `%c`      | Single character |
| `%s`      | String of characters |
| `%p`      | Pointer address in hexadecimal |
| `%d`/`%i` | Signed decimal integer |
| `%u`      | Unsigned decimal integer |
| `%x`      | Unsigned hexadecimal integer (lowercase) |
| `%X`      | Unsigned hexadecimal integer (uppercase) |
| `%%`      | Literal percent sign |

The function returns the total number of characters printed, matching the behaviour of the real `printf`.

---

## Algorithm & Data Structure

### Parsing approach

`ft_printf` uses a **single-pass linear scan** over the format string:

1. Each character is read one at a time.
2. If the character is not `%`, it is written directly to stdout and the character counter is incremented.
3. If `%` is encountered, the next character is inspected to identify the conversion specifier.
4. A dispatcher (a chain of `if/else if` conditions, or equivalent) routes execution to the appropriate handler function for that specifier.
5. Each handler pulls the next argument from the variadic argument list via `va_arg`, formats it, writes it to stdout, and returns the number of bytes written.
6. The total count accumulates across all steps and is returned at the end.

### Why this approach?

- **No intermediate buffer** — characters are sent to stdout as they are processed, keeping memory usage O(1) with respect to output length.
- **Linear time** — the format string is scanned exactly once, O(n) where n is the length of the format string.
- **Modular handlers** — each specifier maps to its own helper function, making the code easy to read, test, and extend.
- **`va_list` / variadic macros** — `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` provide portable access to the variable argument list without any dynamic allocation.

A lookup table or function-pointer array would also be valid and slightly faster for dispatch, but the straightforward conditional chain is sufficient for the 8 specifiers required by the project and keeps the logic immediately readable.

---

## Instructions

### Compilation

```bash
# Clone the repository
git clone https://github.com/<your-github>/ft_printf.git
cd ft_printf

# Build the static library
make

# This produces libftprintf.a
```

Available `make` rules:

| Rule | Effect |
|------|--------|
| `make` / `make all` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libftprintf.a` |
| `make re` | `fclean` + `all` |

### Using the library in your project

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
./my_program
```

### Running the test main (see below)

```bash
make
gcc -Wall -Wextra -Werror main_test.c -L. -lftprintf -o test_printf
./test_printf
```

---

## Test Main

Save the following as `main_test.c` at the root of the repository:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret_ft;
    int ret_og;

    /* ---- %c ---- */
    printf("=== %%c ===\n");
    ret_ft = ft_printf("ft : [%c]\n", 'A');
    ret_og =    printf("og : [%c]\n", 'A');
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %s ---- */
    printf("=== %%s ===\n");
    ret_ft = ft_printf("ft : [%s]\n", "hello, 42");
    ret_og =    printf("og : [%s]\n", "hello, 42");
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %s NULL ---- */
    printf("=== %%s (NULL) ===\n");
    ret_ft = ft_printf("ft : [%s]\n", (char *)NULL);
    ret_og =    printf("og : [%s]\n", (char *)NULL);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %d / %i ---- */
    printf("=== %%d / %%i ===\n");
    ret_ft = ft_printf("ft : %d  %i\n",  42, -42);
    ret_og =    printf("og : %d  %i\n",  42, -42);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %d edge cases ---- */
    printf("=== %%d (INT_MIN / INT_MAX / 0) ===\n");
    ret_ft = ft_printf("ft : %d  %d  %d\n", -2147483648, 2147483647, 0);
    ret_og =    printf("og : %d  %d  %d\n", -2147483648, 2147483647, 0);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %u ---- */
    printf("=== %%u ===\n");
    ret_ft = ft_printf("ft : %u\n", 4294967295U);
    ret_og =    printf("og : %u\n", 4294967295U);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %x / %X ---- */
    printf("=== %%x / %%X ===\n");
    ret_ft = ft_printf("ft : %x  %X\n", 255, 255);
    ret_og =    printf("og : %x  %X\n", 255, 255);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %p ---- */
    printf("=== %%p ===\n");
    int n = 42;
    ret_ft = ft_printf("ft : %p\n", (void *)&n);
    ret_og =    printf("og : %p\n", (void *)&n);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- %% ---- */
    printf("=== %%%% ===\n");
    ret_ft = ft_printf("ft : 100%%\n");
    ret_og =    printf("og : 100%%\n");
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    /* ---- mixed ---- */
    printf("=== mixed ===\n");
    ret_ft = ft_printf("ft : %s is %d years old and scores %x in hex\n",
                        "wgolbert", 21, 255);
    ret_og =    printf("og : %s is %d years old and scores %x in hex\n",
                        "wgolbert", 21, 255);
    printf("return ft=%d  og=%d\n\n", ret_ft, ret_og);

    return (0);
}
```

Each test prints both the `ft_printf` output and the real `printf` output on adjacent lines, then compares their return values — making mismatches immediately visible.

---

## Resources

### Documentation & References

- [C Standard – `printf` specification (cppreference)](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic functions in C – `<stdarg.h>` (cppreference)](https://en.cppreference.com/w/c/variadic)
- [42 Docs – ft_printf subject](https://cdn.intra.42.fr/pdf/pdf/960/ft_printf.en.subject.pdf)
- [printf format string (Wikipedia)](https://en.wikipedia.org/wiki/Printf_format_string)
- [write(2) – Linux man page](https://man7.org/linux/man-pages/man2/write.2.html)

### AI Usage

Claude (Anthropic) was used during this project for the following tasks:

- **README generation** — the structure, wording, and test main in this file were drafted with Claude's assistance.
- **Concept clarification** — explaining the behaviour of `va_start` / `va_arg` / `va_end` and how the variadic argument list is consumed.
- **Debugging guidance** — discussing pointer arithmetic edge cases (e.g. `%p` with a NULL pointer, `INT_MIN` negation overflow) and how the real `printf` handles them.

All actual implementation code was written by the author. AI assistance was limited to explanation, design discussion, and documentation.
