#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>

#ifndef Calculator_H
#define Calculator_H


void Calculator(void) {
    char choice;
    do {
        printf(" ==============\n");
        printf("  ~CALCULATOR~\n");
        printf(" ==============\n");

        char choice2[1000];
        printf("What would you like to do? Type \nany other key for basic math,\n'circle',\n'sqrt',\n'round',\n'pow': ");
        scanf("%s", choice2);
        if (strcmp(choice2, "circle") == 0) {
            const double PI = 3.14159;
            double radius;
            double circumference;
            double area;

            printf("\nEnter the radius of the circle: ");
            scanf("%lf", &radius);

            circumference = 2 * PI * radius;
            area = PI * radius * radius;

            printf("\nthe Circumference is: %lf", circumference);
            printf("\nthe area is: %lf\n", area);
        } else if (strcmp(choice2, "pow") == 0) {
            double pow1;
            double pow2;
            printf("enter first number: ");
            scanf("%lf", &pow1);

            printf("enter the number you're gonna raise that number by: ");
            scanf("%lf", &pow2);

            double powresult = pow(pow1, pow2);

            printf("Result is %.1lf\n", powresult);

        } else if (strcmp(choice2, "sqrt") == 0) {
                double sqrt1;
                printf("enter the number you want to find the sqaure root of: ");
                scanf("%lf", &sqrt1);

                double sqrtR = sqrt(sqrt1); 

                printf("the square root of %.1lf is [%.1lf]\n", sqrt1, sqrtR);
        } else if (strcmp(choice2, "round") == 0) {
            double Rnum;
            printf("enter a number you would like to round to the nerest interger: ");
            scanf("%lf", &Rnum);

            double RR = round(Rnum);
            printf("it is %.2lf\n", RR);
        
                  
        
        } else {
            char OP;
            printf("What operator do you want to use ['+', '-', '*', '/']: ");
            scanf(" %c", &OP);

            double one, two;
            printf("Enter the first number: ");
            scanf("%lf", &one);

            printf("Enter the second number: ");
            scanf("%lf", &two);

            double result;

            switch (OP) {
                case '+':
                    result = one + two;
                    printf("The result is %.1lf\n", result);
                    break;
                case '-':
                    result = one - two;
                    printf("The result is %.1lf\n", result);
                    break;
                case '*':
                    result = one * two;
                    printf("The result is %.1lf\n", result);
                    break;
                case '/':
                    if (two != 0) {
                        result = one / two;
                        printf("The result is %.1lf\n", result);
                    } else {
                        printf("Error: Cannot divide by zero.\n");
                    }
                    break;
                default:
                    printf("Error: Invalid operator.\n");
                    break;
            }
        }

        printf("Do you want to run the program again? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');

    printf("Program exiting.\n");
    

}



#endif
