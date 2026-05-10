
#include <stdio.h>

int main(void) {
    int number;

    printf("=== Even / Odd Checker ===\n");
    printf("Enter a whole number: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("%d is Even\n", number);
    } else {
        printf("%d is Odd\n", number);
    }

    return 0;
}
