# Week 04 C Projects

This folder contains two C programs for Week 04:

- `sims.c` — Student Information Management System (SIMS)
- `mul_grid.c` — Dynamic Multiplication Grid generator

---

## Project 1: Student Information Management System (SIMS)

A terminal-based student record manager written in C. It supports manual entry, bulk import from a text file, exporting records, searching, updating, and deleting student records.

### Features

- Add student details manually
- Bulk import students from `students.txt`
- Export all student records to `database_backup.txt`
- Find student by roll number
- Find student by first name
- Delete student by roll number
- Update student details by roll number
- Exit the program

### Student Data Format

The `students.txt` file must use this space-separated format:

`FirstName LastName RollNumber CGPA Course1 Course2 Course3 Course4 Course5`

Example:

```txt
name name  101 4.2 10 11 12 13 14
name name  102 4.8 10 15 16 17 18
name name  103 3.9 11 12 19 20 21
name name 104 4.5 10 13 14 22 23
```

### Data Structure

```c
struct sinfo {
  char fname[50];
  char lname[50];
  float cgpa;
  int roll;
  int cid[5];
};
```

### Compile and Run

```bash
gcc sims.c -o sims -Wall -Wextra
./sims
```

### Notes

- Records exist in memory only while the program runs.
- Use option 2 to import from `students.txt`.
- Use option 3 to export records to `database_backup.txt`.
- Roll numbers should be unique.
- The program supports a maximum of 200 students.

---

## Project 2: Multiplication Grid Generator (`mul_grid.c`)

A dynamic terminal-based multiplication grid generator with optional highlighting and export support.

### Features

- Generate an `n × n` multiplication grid, where `n` is between 1 and 20
- Highlight multiples of a selected number
- Export the last generated grid to `multiplication_grid.txt`

### Compile and Run

```bash
gcc mul_grid.c -o mul_grid -Wall -Wextra
./mul_grid
```

### Notes

- The program asks for grid size and highlight value.
- Highlighted multiples are marked with `*` in the printed table.
- Exported grid file is written to `multiplication_grid.txt`.

---

## File Structure

```txt
mul_grid.c
multiplication_grid.txt
README.md
sims.c
```

## Technologies Used

- C programming language
- GCC compiler
- Standard C libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`

## Author

Chisom

CPE Hub Week 04 Projects

## License

This project is for educational purposes.
