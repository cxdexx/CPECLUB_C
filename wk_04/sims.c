#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constants
#define MAX_STUDENTS 200
#define IMPORT_FILE "students.txt"
#define EXPORT_FILE "database_backup.txt"
#define COURSES 5
#define NAME_LEN 50

//Data structure for a student
struct sinfo {
    char fname[NAME_LEN];
    char lname[NAME_LEN];
    float cgpa;
    int roll;
    int cid[COURSES];
};

//global storage for students
struct sinfo students[MAX_STUDENTS];
int student_count = 0;  //number of students currently stored


//forward declarations
void print_record(const struct sinfo *s, int index);
void print_divider(void);
int find_student_by_roll(int roll);
void add_student(void);
void bulk_import(void);
void download_all(void);
void find_by_roll_menu(void);
void find_by_name_menu(void);
void delete_by_roll(void);
void update_by_roll(void);
void show_menu(void);
void flush_input(void);

//utility function to print a student record

//discard everything left on stdin after the scanf
void flush_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void print_divider(void) {
    printf("  %-62s\n", "--------------------------------------------------------------");
}

//pretty print a student record
void print_record(const struct sinfo *s, int index) {
    print_divider();
    printf("  #%-4d  %s %s\n", index + 1, s->fname, s->lname);
    printf("         Roll: %-6d  CGPA: %.2f\n", s->roll, s->cgpa);
    printf("         Courses: %d  %d  %d  %d  %d\n",
           s->cid[0], s->cid[1], s->cid[2], s->cid[3], s->cid[4]);
}


//returns index of student with given roll, or -1 if not found
int find_student_by_roll(int roll) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll == roll) {
            return i;
        }
    }
    return -1;
}

//add a new student record by taking input from user
void add_student(void) {
    if (student_count >= MAX_STUDENTS) {
        printf("  Error: Student database is full (%d records). Cannot add more students.\n", MAX_STUDENTS);
        return;
    }

    struct sinfo *s = &students[student_count];

    printf("\n ---- Add New Student ----\n");
    printf("  First Name: "); scanf("%49s", s->fname);
    printf("  Last Name: "); scanf("%49s", s->lname);
    printf("  Roll Number: "); scanf("%d", &s->roll);

    //reject if roll number already exists
    if (find_student_by_roll(s->roll) != -1) {
        printf("  Error: A student with roll number %d already exists. Cannot add duplicate.\n", s->roll);
        flush_input();
        return;
    }

    printf("  CGPA: "); scanf("%f", &s->cgpa);
    printf("  5 Course IDs (space-separated): ");
    for (int i = 0; i < COURSES; i++) {
        scanf("%d", &s->cid[i]);
    }

    flush_input();
    student_count++;
    printf("  [✓] Student added successfully! Total students: %d\n", student_count);
}

//bulk import students from a file
void bulk_import(void) {
    FILE *fp = fopen(IMPORT_FILE, "r");
    if (!fp) {
        printf("  Error: Cannot open file '%s'. Make sure it exists and is readable.\n", IMPORT_FILE);
        return;
    }

    int imported_count = 0;
    int skipped = 0;

    while (student_count < MAX_STUDENTS) {
        struct sinfo tmp;
        int result = fscanf(fp, "%49s %49s %d %f %d %d %d %d %d",
                   tmp.fname, tmp.lname, &tmp.roll, &tmp.cgpa,
                   &tmp.cid[0], &tmp.cid[1], &tmp.cid[2], &tmp.cid[3], &tmp.cid[4]);

        if (result != 9) {
            break;  // EOF or malformed line
        }

        //check for duplicate roll number
        if (find_student_by_roll(tmp.roll) != -1) {
            printf("  Warning: Skipping student with duplicate roll number %d (%s %s)\n",
                   tmp.roll, tmp.fname, tmp.lname);
            skipped++;
            continue;
        }

        students[student_count++] = tmp;
        imported_count++;
    }

    fclose(fp);
    printf("  Import complete: %d students imported, %d skipped due to duplicates. Total students: %d\n",
           imported_count, skipped, student_count);
}


//download all student records to a file
void download_all(void) {
    if (student_count == 0) {
        printf("  No students to export. Database is empty.\n");
        return;
    }

    FILE *fp = fopen(EXPORT_FILE, "w");
    if (!fp) {
        printf("  Error: Cannot create file '%s' for writing.\n", EXPORT_FILE);
        return;
    }

    for (int i = 0; i < student_count; i++) {
        struct sinfo *s = &students[i];
        fprintf(fp, "%s %s %d %.2f %d %d %d %d %d\n",
                s->fname, s->lname, s->roll, s->cgpa,
                s->cid[0], s->cid[1], s->cid[2], s->cid[3], s->cid[4]);
    }

    fclose(fp);
    printf("  Export complete: %d students written to '%s'\n", student_count, EXPORT_FILE);
}

//find and print student by roll number
void find_by_roll_menu(void) {
    int roll;
    printf("\n ---- Find Student by Roll Number ----\n");
    printf("  Enter Roll Number: "); scanf("%d", &roll);
    flush_input();

    int index = find_student_by_roll(roll);
    if (index == -1) {
        printf("  No student found with roll number %d.\n", roll);
    } else {
        printf("  Student found:\n");
        print_record(&students[index], index);
        print_divider();
    }
}

//find student by first name
void find_by_name_menu(void) {
    char name[NAME_LEN];
    printf("\n ---- Find Student by First Name ----\n");
    printf("  Enter First Name to search: "); scanf("%49s", name);
    flush_input();

    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].fname, name) == 0) {
            if (!found) {
                printf("  Students found with first name '%s':\n", name);
            }
            print_record(&students[i], i);
            print_divider();
            found++;
        }
    }

    if (!found) {
        printf("  No students found with first name '%s'.\n", name);
    } else {
        printf("  Total students found: %d\n", found);
    }
}

//delete student by roll number
void delete_by_roll(void) {
    int roll;
    printf("\n ---- Delete Student by Roll Number ----\n");
    printf("  Enter Roll Number to delete: "); scanf("%d", &roll);
    flush_input();

    int index = find_student_by_roll(roll);
    if (index == -1) {
        printf("  No student found with roll number %d. Cannot delete.\n", roll);
        return;
    }

    char confirm;
    printf("  Are you sure you want to delete student '%s %s' with roll number %d? (y/n): ",
           students[index].fname, students[index].lname, students[index].roll);
    scanf(" %c", &confirm);
    flush_input();

    if (confirm == 'y' || confirm == 'Y') {
        //shift all students after index left by one
        for (int i = index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("  Student with roll number %d deleted successfully. Total students: %d\n", roll, student_count);
    } else {
        printf("  Deletion cancelled.\n");
    }
}

//update student record by roll number
void update_by_roll(void) {
    int roll;
    printf("\n ---- Update Student by Roll Number ----\n");
    printf("  Enter Roll Number to update: "); scanf("%d", &roll);
    flush_input();

    int index = find_student_by_roll(roll);
    if (index == -1) {
        printf("  No student found with roll number %d. Cannot update.\n", roll);
        return;
    }

    struct sinfo *s = &students[index];
    printf("  Updating record for: %s %s (roll %d)\n",
       s->fname, s->lname, s->roll);
    printf("  Press Enter to keep the current value, or type a new one.\n\n");

    //first name
    char buf[NAME_LEN];
    printf("  First name [%s]: ", s->fname);
    fgets(buf, NAME_LEN, stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (buf[0] != '\0') {
        strncpy(s->fname, buf, NAME_LEN - 1);
        s->fname[NAME_LEN - 1] = '\0';
    }

    //last name
    printf("  Last name  [%s]: ", s->lname);
    fgets(buf, NAME_LEN, stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (buf[0] != '\0') {
        strncpy(s->lname, buf, NAME_LEN - 1);
        s->lname[NAME_LEN - 1] = '\0';
    }

    //CGPA
    printf("  CGPA       [%.2f]: ", s->cgpa);
    fgets(buf, NAME_LEN, stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (buf[0] != '\0') {
        s->cgpa = (float)atof(buf);
    }

    //Course IDs
    printf("  Course IDs [%d %d %d %d %d]:\n",
           s->cid[0], s->cid[1], s->cid[2], s->cid[3], s->cid[4]);

    for (int i = 0; i < COURSES; i++) {
        printf("    Course %d [%d]: ", i + 1, s->cid[i]);
        fgets(buf, NAME_LEN, stdin);
        buf[strcspn(buf, "\n")] = '\0';
        if (buf[0] != '\0') {
            s->cid[i] = atoi(buf);
        }
    }

    printf("  [✓] Record updated successfully.\n");
    print_record(s, index);
    print_divider();
}

//main display menu and handle user choices
void show_menu(void) {
    printf("\n");
    print_divider();
    printf("  STUDENT INFORMATION MANAGEMENT SYSTEM    [%d record(s) in memory]\n", student_count);
    print_divider();
    printf("  1. Add Student          (manual input)\n");
    printf("  2. Bulk Import          (read from %s)\n", IMPORT_FILE);
    printf("  3. Download All         (write to %s)\n", EXPORT_FILE);
    printf("  4. Find by Roll Number\n");
    printf("  5. Find by First Name\n");
    printf("  6. Delete by Roll Number\n");
    printf("  7. Update by Roll Number\n");
    printf("  8. Exit\n");
    print_divider();
    printf("Enter your choice (1-8): ");
}

//entry point of the program
int main(void) {
    int choice;

    printf("\n  Welcome to SIMS — A Project of CPE_CLUB\n");

    while (1) {
        show_menu();

        if (scanf("%d", &choice) != 1) {
            flush_input();
            printf("  [!] Invalid input. Enter a number from 1 to 8.\n");
            continue;
        }
        flush_input();

        switch (choice) {
            case 1: add_student();       break;
            case 2: bulk_import();       break;
            case 3: download_all();      break;
            case 4: find_by_roll_menu(); break;
            case 5: find_by_name_menu(); break;
            case 6: delete_by_roll();    break;
            case 7: update_by_roll();    break;
            case 8:
                printf("  Goodbye.\n\n");
                return 0;
            default:
                printf("  [!] Invalid option. Choose 1-8.\n");
        }
    }
}
