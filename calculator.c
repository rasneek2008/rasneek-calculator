#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, result;
    char op, again = 'y';

    printf("===== Simple Calculator =====\n");

    while (again == 'y' || again == 'Y') {
        printf("\nOperations: +  -  *  /  %%  ^ (or p for power)\n");
        printf("Enter expression (e.g. 5 + 3): ");

        if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
            printf("Invalid input! Please enter like: 5 + 3\n");
            while (getchar() != '\n');   /* clear bad input */
            continue;
        }

        switch (op) {
            case '+':
                result = a + b;
                printf("Result: %g\n", result);
                break;
            case '-':
                result = a - b;
                printf("Result: %g\n", result);
                break;
            case '*':
            case 'x':
                result = a * b;
                printf("Result: %g\n", result);
                break;
            case '/':
                if (b == 0)
                    printf("Error: Cannot divide by zero!\n");
                else
                    printf("Result: %g\n", a / b);
                break;
            case '%':
                if (b == 0)
                    printf("Error: Cannot take modulus by zero!\n");
                else
                    printf("Result: %g\n", fmod(a, b));
                break;
            case '^':
            case 'p':
            case 'P':
                printf("Result: %g\n", pow(a, b));
                break;
            default:
                printf("Error: Unknown operator '%c'\n", op);
        }

        printf("\nDo another calculation? (y/n): ");
        scanf(" %c", &again);
    }

    printf("Goodbye!\n");
    return 0;
}
