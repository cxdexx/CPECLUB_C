/*
 * phonebook.c
 * Custom Shell-Based Phonebook
 *
 * Manages a contact database using a fixed-size struct array.
 * All mutation functions receive a POINTER to a Contact — never
 * a copy — reinforcing that a pointer stores a memory address.
 *
 * Commands (interactive menu):
 *   1. Add contact
 *   2. Search by name
 *   3. Delete by name
 *   4. Display all
 *   5. Quit
 */

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 50
#define NAME_LEN     50
#define PHONE_LEN    20

/* Fixed-size character arrays — strings in C are null-terminated char arrays */
typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

/* ── Helper: clear stdin after scanf ── */
static void flush_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ── Add a new contact via pointer ── */
void add_contact(Contact *c, const char *name, const char *phone) {
    /* strncpy copies at most N-1 chars, then we force-null-terminate */
    strncpy(c->name,  name,  NAME_LEN  - 1);
    strncpy(c->phone, phone, PHONE_LEN - 1);
    c->name[NAME_LEN   - 1] = '\0';
    c->phone[PHONE_LEN - 1] = '\0';
}

/* ── Print a single contact via pointer ── */
void print_contact(const Contact *c) {
    printf("  Name : %s\n", c->name);
    printf("  Phone: %s\n", c->phone);
    printf("  ---\n");
}

/* ── Search: returns pointer to matched contact, or NULL ── */
Contact *find_contact(Contact *book, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            return &book[i];   /* return the ADDRESS of the matching element */
        }
    }
    return NULL;
}

/* ── Delete by shifting elements left ── */
int delete_contact(Contact *book, int *count, const char *name) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            /* Overwrite slot i with everything after it */
            for (int j = i; j < *count - 1; j++) {
                book[j] = book[j + 1];
            }
            (*count)--;
            return 1;   /* found and deleted */
        }
    }
    return 0;   /* not found */
}

int main(void) {
    Contact book[MAX_CONTACTS];
    int count = 0;
    int choice;

    printf("=== Shell Phonebook ===\n");

    while (1) {
        printf("\n1) Add  2) Search  3) Delete  4) List all  5) Quit\n> ");
        if (scanf("%d", &choice) != 1) break;
        flush_input();

        if (choice == 1) {
            if (count >= MAX_CONTACTS) {
                printf("Phonebook full.\n");
                continue;
            }
            char name[NAME_LEN], phone[PHONE_LEN];
            printf("Name  : ");
            fgets(name,  NAME_LEN,  stdin);
            name[strcspn(name, "\n")] = '\0';    /* strip trailing newline */
            printf("Phone : ");
            fgets(phone, PHONE_LEN, stdin);
            phone[strcspn(phone, "\n")] = '\0';

            add_contact(&book[count], name, phone);   /* pass ADDRESS */
            count++;
            printf("Contact saved.\n");

        } else if (choice == 2) {
            char name[NAME_LEN];
            printf("Search name: ");
            fgets(name, NAME_LEN, stdin);
            name[strcspn(name, "\n")] = '\0';

            Contact *result = find_contact(book, count, name);
            if (result) {
                printf("Found:\n");
                print_contact(result);            /* pass ADDRESS */
            } else {
                printf("No contact named '%s'.\n", name);
            }

        } else if (choice == 3) {
            char name[NAME_LEN];
            printf("Delete name: ");
            fgets(name, NAME_LEN, stdin);
            name[strcspn(name, "\n")] = '\0';

            if (delete_contact(book, &count, name)) {
                printf("Deleted '%s'.\n", name);
            } else {
                printf("No contact named '%s'.\n", name);
            }

        } else if (choice == 4) {
            if (count == 0) {
                printf("Phonebook is empty.\n");
            } else {
                printf("--- %d contact(s) ---\n", count);
                for (int i = 0; i < count; i++) {
                    print_contact(&book[i]);      /* pass ADDRESS */
                }
            }

        } else if (choice == 5) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}