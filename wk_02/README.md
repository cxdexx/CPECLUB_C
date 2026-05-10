# CPEHUB — Week 2 Projects

> **Learning Programming Through Project-Based Tasks**  
> Three C programs covering structs, pointers, sorting, and memory manipulation.

---

## Project 1: Mini Firewall (Packet Filtering) — `firewall.c`

Reads up to 10 network packets from a file (each with a `SerialNo` and `Priority`),
then outputs them sorted by:

1. **Highest priority first** (priority value `1` = highest, `10` = lowest)
2. **Lowest serial number first** when priorities tie

**Build & run:**
```bash
gcc firewall.c -o firewall
./firewall packets.txt
```

**Input file format (`packets.txt`):**
```
1 , 5
10 , 1
3 , 3
...
```

**Example output:**
```
Serial No   Priority
---------   --------
7           1
10          1
2           2
...
```

---

## Project 2: Shell Phonebook — `phonebook.c`

An interactive CLI contact manager backed by a fixed-size `Contact` struct array.
All mutation functions receive a **pointer** to a `Contact` (not a copy), reinforcing
pointer semantics and null-terminated character arrays.

**Build & run:**
```bash
gcc phonebook.c -o phonebook
./phonebook
```

**Menu:**
```
1) Add    2) Search    3) Delete    4) List all    5) Quit
```

**Key concepts demonstrated:**
- `struct` with fixed-size `char[]` fields (strings as null-terminated arrays)
- Passing `&contact` (address) to functions instead of copying the struct
- `strncpy` with forced null-termination for safe string copying
- Returning `Contact *` (pointer) from a search function

---

## Project 3: Substitution Cipher Tool — `cipher.c`

Encrypts and decrypts messages using a Caesar shift cipher. Uses a **pointer**
to walk the string's contiguous memory block — dereferencing `*ptr` to modify
each character until the null terminator `\0` is reached.

**Build & run:**
```bash
gcc cipher.c -o cipher
./cipher e <key> "<message>"   # encrypt
./cipher d <key> "<message>"   # decrypt
```

**Examples:**
```
./cipher e 3  "Hello World"     →  Khoor Zruog
./cipher d 3  "Khoor Zruog"     →  Hello World
./cipher e 13 "Attack at dawn"  →  Nggnpx ng qnja
```

**Key concepts demonstrated:**
- Pointer iteration through a string (`char *ptr = msg; while (*ptr != '\0')`)
- Dereferencing (`*ptr`) to read and modify memory in place
- Modulo arithmetic to wrap the alphabet during shift
- `argv` for command-line argument parsing

---

## Requirements

- GCC (C99 or later)
- Standard library only (`<stdio.h>`, `<stdlib.h>`, `<string.h>`) — no dependencies

## Compile All

```bash
gcc firewall.c  -o firewall  -Wall -Wextra
gcc phonebook.c -o phonebook -Wall -Wextra
gcc cipher.c    -o cipher    -Wall -Wextra
```