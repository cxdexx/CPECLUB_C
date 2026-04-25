#include <stdio.h>

int main(void) {
    double a, b, c, d, e, f;
    double D, Dx, Dy, x, y;

    printf(" Cramer's Rule: 2x2 Linear System Solver\n");
    printf("Solves the system:  ax + by = e\n");
    printf("                    cx + dy = f\n\n");


    printf("Enter coefficient a: ");
    scanf("%lf", &a);

    printf("Enter coefficient b: ");
    scanf("%lf", &b);

    printf("Enter coefficient c: ");
    scanf("%lf", &c);

    printf("Enter coefficient d: ");
    scanf("%lf", &d);

    printf("Enter constant    e: ");
    scanf("%lf", &e);

    printf("Enter constant    f: ");
    scanf("%lf", &f);


    D = (a * d) - (b * c);

    if (D == 0) {
        printf("\nNo unique solution exists (determinant is zero).\n");
    } else {

        Dx = (e * d) - (b * f);
        Dy = (a * f) - (e * c);

        x = Dx / D;
        y = Dy / D;

        printf("\nSolution:\n");
        printf("  x = %.2f\n", x);
        printf("  y = %.2f\n", y);
    }

    return 0;
}
