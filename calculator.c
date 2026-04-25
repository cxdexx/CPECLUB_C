
#include <stdio.h>

int main(void) {
    double num1, num2, result;
    char op;

    printf(" Mini Calculator \n");
    printf("Enter expression (e.g., 10 + 5): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    if (op == '+') {
        result = num1 + num2;
        printf("Result: %.2f\n", result);
    } else if (op == '-') {
        result = num1 - num2;
        printf("Result: %.2f\n", result);
    } else if (op == '*') {
        result = num1 * num2;
        printf("Result: %.2f\n", result);
    } else if (op == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero is undefined.\n");
        } else {
            result = num1 / num2;
            printf("Result: %.2f\n", result);
        }
    } else {
        printf("Error: Unknown operator '%c'. Use +, -, *, or /.\n", op);
    }

    return 0;
}
