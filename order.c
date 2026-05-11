#include<stdio.h>
#include<string.h>
#include "header.h"

void order_processing()
{
    struct cafe m[50];
    struct order o[20];

    int n=0,i,idx=0,choice;
   
    FILE *f;
    f=fopen("menu.txt","r");

    while(fread(&m[n],sizeof(struct cafe),1,f))
    {
        n++;
    }

    fclose(f);

    printf("\n========================================\n");
    printf("          ORDER PROCESSING MODULE\n");
    printf("========================================\n");

    do
    {
        display();

        char name[30];
        int qty,found=0;

        printf("\n----------------------------------------\n");
        printf("Place Your Order\n");
        printf("----------------------------------------\n");

        printf("Enter item name: ");
        scanf(" %[^\n]",name);

        for(i=0;i<n;i++)
        {
            if(strcmp(name,m[i].nm)==0)
            {
                found=1;

                printf("Enter quantity: ");
                scanf("%d",&qty);

                strcpy(o[idx].name,m[i].nm);
                o[idx].price=m[i].price;
                o[idx].qty=qty;
                o[idx].total=qty*m[i].price;
                
                printf("\nItem added to order successfully!\n");

                idx++;
                break;
            }
        }

        if(found==0)
        {
            printf("\nItem not found in menu!\n");
        }

        printf("\n----------------------------------------\n");
        printf("Add more items?\n");
        printf("1. Yes\n");
        printf("0. Proceed to Billing\n");
        printf("Choice: ");

        scanf("%d",&choice);

    }while(choice==1);
   
    printf("\n========================================\n");
    printf("       Proceeding To Billing...\n");
    printf("========================================\n");

    billing(o,idx);
}