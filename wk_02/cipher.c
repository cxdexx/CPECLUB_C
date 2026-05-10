/*
 * cipher.c
 * Simple Substitution Cipher (Caesar / ROT-n)
 *
 * Uses a POINTER to walk through the string's contiguous
 * memory block, dereferencing (*ptr) to read and modify
 * each character until the null terminator (\0) is reached.
 *
 * Encryption: shift each ASCII value forward by key
 * Decryption: shift each ASCII value backward by key
 *
 * Usage: ./cipher <e|d> <key> <message>
 *   e.g. ./cipher e 3 "Hello World"
 *        ./cipher d 3 "Khoor Zruog"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG 256

/* Encrypt: walk the string via pointer, shift each byte forward */
void encrypt(char *msg, int key) {
    char *ptr = msg;                /* ptr holds the ADDRESS of the first char */

    while (*ptr != '\0') {         /* dereference ptr to read the current char */
        if (*ptr >= 'A' && *ptr <= 'Z') {
            /* Wrap within uppercase alphabet using modulo */
            *ptr = (char)((*ptr - 'A' + key) % 26 + 'A');
        } else if (*ptr >= 'a' && *ptr <= 'z') {
            /* Wrap within lowercase alphabet */
            *ptr = (char)((*ptr - 'a' + key) % 26 + 'a');
        }
        /* Non-alpha characters (spaces, punctuation) are left unchanged */
        ptr++;                     /* advance the pointer to the next address */
    }
}

/* Decrypt: reverse the shift (subtract key, wrap with modulo) */
void decrypt(char *msg, int key) {
    char *ptr = msg;

    while (*ptr != '\0') {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr = (char)((*ptr - 'A' - key % 26 + 26) % 26 + 'A');
        } else if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = (char)((*ptr - 'a' - key % 26 + 26) % 26 + 'a');
        }
        ptr++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <e|d> <key> <message>\n", argv[0]);
        fprintf(stderr, "  e = encrypt,  d = decrypt\n");
        return 1;
    }

    char mode    = argv[1][0];
    int  key     = atoi(argv[2]);
    char msg[MAX_MSG];

    /* Copy the message argument into a local mutable buffer */
    strncpy(msg, argv[3], MAX_MSG - 1);
    msg[MAX_MSG - 1] = '\0';

    if (key < 0) {
        fprintf(stderr, "Error: key must be a non-negative integer.\n");
        return 1;
    }

    printf("Mode    : %s\n", mode == 'e' ? "Encrypt" : "Decrypt");
    printf("Key     : %d\n", key);
    printf("Input   : %s\n", msg);

    if (mode == 'e') {
        encrypt(msg, key);
        printf("Output  : %s\n", msg);
    } else if (mode == 'd') {
        decrypt(msg, key);
        printf("Output  : %s\n", msg);
    } else {
        fprintf(stderr, "Error: mode must be 'e' (encrypt) or 'd' (decrypt).\n");
        return 1;
    }

    return 0;
}