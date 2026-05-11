#include<stdio.h>
#include "header.h"


void manager_driver()
{
    int ch;

    do
    {
        printf("\n========================================\n");
        printf("          MANAGER SYSTEM PANEL\n");
        printf("========================================\n");

        printf("1. Menu Management\n");
        printf("2. Order Processing\n");
        printf("3. Logout\n");

        printf("----------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nOpening Menu Management...\n");
                menu_management();
                break;

            case 2:
                printf("\nOpening Order Processing...\n");
                order_processing();
                break;

            case 3:
                printf("\nLogging out...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    }
    while(ch!=3);
}



void admin_driver()
{
    int ch;

    do
    {
        printf("\n========================================\n");
        printf("           ADMIN SYSTEM PANEL\n");
        printf("========================================\n");

        printf("1. Menu Management\n");
        printf("2. Order Processing\n");
        printf("3. Record Management\n");
        printf("4. Logout\n");

        printf("----------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nOpening Menu Management...\n");
                menu_management();
                break;

            case 2:
                printf("\nOpening Order Processing...\n");
                order_processing();
                break;

            case 3:
                printf("\nOpening Record Management...\n");
                record_management();
                break;

            case 4:
                printf("\nLogging out...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    }
    while(ch!=4);
}