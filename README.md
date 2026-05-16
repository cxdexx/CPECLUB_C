# CPECLUB_C

A collection of small C projects and exercises from CPE Hub (week folders).

This repository contains simple terminal-based programs demonstrating basic C concepts: I/O, control flow, arrays, structs, and file handling.

## Tree (top-level)

- `LICENSE`
- `wk_01/` — basic exercises (calculator, even/odd, linear algebra)
- `wk_02/` — small utilities (cipher, firewall, phonebook)
- `wk_04/` — Student Information Management System (SIMS)


## Quick build & run

Each C program is self-contained. To compile a program from its folder, run (example):

```bash
# compile a file
gcc wk_01/calculator.c -o wk_01/calculator -Wall -Wextra
# run it
./wk_01/calculator
```

Adjust filenames and output names as needed. For the SIMS project use the `wk_04` folder:

```bash
cd wk_04
gcc sims.c -o sims -Wall -Wextra
# ensure students.txt exists if you plan to Bulk Import
./sims
```

The programs typically read or write small text files in their working directory (see each folder's README for details).


## Folder summaries

- wk_01/
  - `calculator.c` — simple calculator examples.
  - `even_odd.c` — checks even/odd numbers.
  - `Linear_Algebra.c` — basic linear algebra routines.
  - `README.md` — short notes for week 01.

- wk_02/
  - `cipher` and `cipher.c` — simple cipher examples.
  - `firewall/` contains `firewall.c` and `firewall_packets.txt` for a small packet-filter exercise.
  - `phonebook` and `phonebook.c` — a basic phonebook program.
  - `README.md` — notes for week 02.

- wk_04/
  - `sims.c` — Student Information Management System (SIMS). Provides manual add, bulk import from `students.txt`, export to `database_backup.txt`, search, update, and delete.
  - `README.md` — detailed instructions and student data format for SIMS.


## Notes

- These projects are educational examples. Review the code before running and provide input files where required (for example `students.txt` for SIMS).
- Use `-Wall -Wextra` when compiling to see useful warnings.
