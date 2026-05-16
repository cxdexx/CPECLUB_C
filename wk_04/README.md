# Student Information Management System (SIMS)

A terminal-based Student Information Management System written in C for managing student records using structs, arrays, and file handling.

This project supports manual student entry, bulk import from a text file, exporting student records to a backup file, searching, updating, and deleting student records.

---

## Project Overview

The Student Information Management System allows a user to manage student data directly from the terminal.

Each student record contains:

- First name
- Last name
- Roll number
- CGPA
- Five course IDs

The system stores records in memory during program execution and can read from or write to external `.txt` files for bulk data management.

---

## Features

1. Add student details manually
2. Bulk import students from `students.txt`
3. Export all student records to `database_backup.txt`
4. Find student by roll number
5. Find student by first name
6. Delete student by roll number
7. Update student details by roll number
8. Exit the program

---

## Technologies Used

- C programming language
- GCC compiler
- Standard C libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`

---

## File Structure

```txt
project-folder/
│
├── sims.c
├── students.txt
├── database_backup.txt
└── README.md
Student Data Format

The students.txt file must follow this exact format:

FirstName LastName RollNumber CGPA Course1 Course2 Course3 Course4 Course5

Example:

Billo Doe 101 4.2 10 11 12 13 14
Amara Smith 102 4.8 10 15 16 17 18
Emmanuel Okon 103 3.9 11 12 19 20 21
Precious Nnamdi 104 4.5 10 13 14 22 23

Each value must be separated by a space.

Data Structure Used
struct sinfo {
    char fname[50];
    char lname[50];
    float cgpa;
    int roll;
    int cid[5];
};

This structure stores one student record.

How to Compile

Open your terminal in the project folder and run:

gcc sims.c -o sims -Wall -Wextra

This creates an executable file named sims.

How to Run

After compiling, run:

./sims
Menu Options

When the program runs, the following menu is displayed:

1. Add Student
2. Bulk Import
3. Download All
4. Find by Roll Number
5. Find by First Name
6. Delete by Roll Number
7. Update by Roll Number
8. Exit

Enter a number from 1 to 8 to perform an action.

Bulk Import

To import students, create a file named:

students.txt

Add student records using the required format.

Then select option:

2. Bulk Import

The program will read the records and store them in memory.

Duplicate roll numbers are skipped.

Export / Download All Students

To export all current student records, select:

3. Download All

The program creates or overwrites:

database_backup.txt

All student records currently in memory will be saved there.

Search System

The program supports two search methods:

Search by Roll Number

Searches for one specific student using their unique roll number.

Search by First Name

Searches for all students with the matching first name.

Delete System

Students can be deleted using their roll number.

Before deletion, the program asks for confirmation.

If confirmed, the student is removed from memory and the remaining records are shifted correctly.

Update System

Students can be updated using their roll number.

The program allows updating:

First name
Last name
CGPA
Course IDs

Pressing Enter keeps the previous value unchanged.

Important Notes
The program stores data in memory while running.
Imported or manually added records are not permanently saved unless exported.
Always use the correct format in students.txt.
Roll numbers should be unique.
The program supports a maximum of 200 students.
Sample Compilation and Execution
gcc sims.c -o sims -Wall -Wextra
./sims
Author

Chisom
CPE Hub Week 04 Project
Student Information Management System

License

This project is for educational purposes.


This README matches your project requirements: terminal-based CRUD, `.txt` import/export, strict student data format, and the menu features from the assignment spec. :contentReference[oaicite:0]{index=0}