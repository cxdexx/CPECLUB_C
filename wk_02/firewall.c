/*
 * firewall.c
 * Mini Firewall Packet Priority Filter
 *
 * Reads packets from a file, each with a serial number and priority level,
 * sorts them: highest priority (lowest number) first,
 * ties broken by lowest serial number.
 *
 * Usage: ./firewall packets.txt
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PACKETS 10

/* A single network packet */
typedef struct {
    int serial;
    int priority;
} Packet;

/* Comparator for qsort:
 *   Primary   — ascending priority value (1 = highest, 10 = lowest)
 *   Secondary — ascending serial number (ties go to the lower serial) */
int compare_packets(const void *a, const void *b) {
    const Packet *pa = (const Packet *)a;
    const Packet *pb = (const Packet *)b;

    if (pa->priority != pb->priority) {
        return pa->priority - pb->priority;   /* lower number = higher priority */
    }
    return pa->serial - pb->serial;           /* tie-break: lower serial first */
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <packets_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    Packet packets[MAX_PACKETS];
    int count = 0;

    /* Read up to MAX_PACKETS lines; each line: serial, priority */
    while (count < MAX_PACKETS &&
           fscanf(fp, "%d , %d", &packets[count].serial,
                                 &packets[count].priority) == 2) {
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No packets found in file.\n");
        return 0;
    }

    /* Sort in-place using the standard library quicksort */
    qsort(packets, count, sizeof(Packet), compare_packets);

    printf("=== Firewall: Filtered Packet Order ===\n");
    printf("%-10s  %-10s\n", "Serial No", "Priority");
    printf("%-10s  %-10s\n", "---------", "--------");

    for (int i = 0; i < count; i++) {
        printf("%-10d  %-10d\n", packets[i].serial, packets[i].priority);
    }

    return 0;
}