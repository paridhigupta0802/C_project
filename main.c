#include<stdio.h>
#include<string.h>
#include "header.h"

int main()
{
    int r,role;
    char mp[20];

    printf("\n========================================\n");
    printf("       CAFETERIA BILLING SYSTEM\n");
    printf("========================================\n");

    printf("\nSelect User Role\n");
    printf("1. Manager\n");
    printf("2. Admin\n");
    printf("----------------------------------------\n");
    printf("Enter choice: ");
    scanf("%d",&role);
    
    if(role==1)
    {
        printf("\nEnter Manager Password: ");
        scanf("%s",mp);

        if(strcmp(mp,"123")!=0)
        {
            printf("\nAccess Denied!\n");
            return 0;
        }

        do
        {
            r=login();

            if(r==1)
            {
                manager_driver();
            }

            else
            {
                printf("\nTry again :)\n");
            }

        }
        while(r!=1);
    }



    else if(role==2)
    {
        printf("\nEnter Admin Password: ");
        scanf("%s",mp);

        if(strcmp(mp,"admin123")!=0)
        {
            printf("\nAccess Denied!\n");
            return 0;
        }

        do
        {
            r=login();

            if(r==1)
            {
                admin_driver();
            }

            else
            {
                printf("\nTry again :)\n");
            }

        }
        while(r!=1);
    }



    else
    {
        printf("\nInvalid role selection\n");
    }

    return 0;
}