#include <stdio.h>

int main()
{
    int choice, roll;
    int m1, m2, m3, m4, m5;
    int total, pass;
    int detailsEntered, resultReady;
    float avg;
    char grade;
    char name[30];

    total = 0;
    avg = 0;
    pass = 0;
    grade = 'F';
    detailsEntered = 0;
    resultReady = 0;

    do
    {
        printf("\nSTUDENT MARKS MANAGEMENT SYSTEM\n");
        printf("--------------------------------\n");
        printf("1. Enter Student Details\n");
        printf("2. Calculate Result\n");
        printf("3. Display Result\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("\nEnter Roll Number: ");
                scanf("%d", &roll);

                printf("Enter Student Name: ");
                scanf("%29s", name);

                printf("Enter Subject 1 Mark: ");
                scanf("%d", &m1);

                printf("Enter Subject 2 Mark: ");
                scanf("%d", &m2);

                printf("Enter Subject 3 Mark: ");
                scanf("%d", &m3);

                printf("Enter Subject 4 Mark: ");
                scanf("%d", &m4);

                printf("Enter Subject 5 Mark: ");
                scanf("%d", &m5);

                if(m1 < 0 || m1 > 100 ||
                   m2 < 0 || m2 > 100 ||
                   m3 < 0 || m3 > 100 ||
                   m4 < 0 || m4 > 100 ||
                   m5 < 0 || m5 > 100)
                {
                    printf("\nInvalid marks! Enter marks from 0 to 100.\n");
                    detailsEntered = 0;
                    resultReady = 0;
                    break;
                }

                total = m1 + m2 + m3 + m4 + m5;
                avg = total / 5.0;

                detailsEntered = 1;
                resultReady = 0;

                printf("\nStudent details entered successfully!\n");
                break;

            case 2:

                if(detailsEntered == 1)
                {
                    pass = 1;

                    if(m1 < 35 || m2 < 35 ||
                       m3 < 35 || m4 < 35 || m5 < 35)
                    {
                        pass = 0;
                    }

                    if(avg >= 90)
                        grade = 'A';
                    else if(avg >= 80)
                        grade = 'B';
                    else if(avg >= 70)
                        grade = 'C';
                    else if(avg >= 60)
                        grade = 'D';
                    else
                        grade = 'F';

                    resultReady = 1;

                    printf("\nResult calculated successfully!\n");
                }
                else
                {
                    printf("\nEnter student details first!\n");
                }

                break;

            case 3:

                if(resultReady == 1)
                {
                    printf("\nSTUDENT RESULT\n");
                    printf("--------------------\n");

                    printf("Roll Number : %d\n", roll);
                    printf("Name        : %s\n", name);
                    printf("Total       : %d\n", total);
                    printf("Average     : %.2f\n", avg);
                    printf("Grade       : %c\n", grade);

                    if(pass == 1)
                        printf("Result      : PASS\n");
                    else
                        printf("Result      : FAIL\n");
                }
                else
                {
                    printf("\nCalculate result first!\n");
                }

                break;

            case 4:

                printf("\nThank you!\n");
                break;

            default:

                printf("\nInvalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}