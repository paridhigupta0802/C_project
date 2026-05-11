#include<stdio.h>
#include<string.h>
#include "header.h"


void record_management()
{
    int ch;

    do
    {
        printf("\n========================================\n");
        printf("          RECORD MANAGEMENT\n");
        printf("========================================\n");

        printf("1. View Records\n");
        printf("2. Search By Bill ID\n");
        printf("3. Daily Sales\n");
        printf("4. Exit\n");

        printf("----------------------------------------\n");
        printf("Enter choice: ");

        scanf("%d",&ch);


        switch(ch)
        {
            case 1:
                view_records();
                break;

            case 2:
                search_record();
                break;

            case 3:
                daily_sales();
                break;

            case 4:
                printf("\nReturning...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    }
    while(ch!=4);
}





void view_records()
{
    FILE *f;
    struct bill b;

    f=fopen("bill.txt","rb");

    if(f==NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n----------- BILL HISTORY -----------\n");

    while(fread(&b,sizeof(struct bill),1,f))
    {
        printf("ID:%d  Total:Rs.%d  Date:%s\n",
               b.bill_id,
               b.grand_total,
               b.date);
    }

    fclose(f);
}





void search_record()
{
    FILE *f;
    struct bill b;

    int id,found=0;

    printf("Enter Bill ID: ");
    scanf("%d",&id);


    f=fopen("bill.txt","rb");

    if(f==NULL)
    {
        printf("\nFile not found!\n");
        return;
    }


    while(fread(&b,sizeof(struct bill),1,f))
    {
        if(b.bill_id==id)
        {
            printf("\nRecord Found!\n");

            printf("--------------------------\n");
            printf("Bill ID : %d\n",b.bill_id);
            printf("Total   : Rs.%d\n",b.grand_total);
            printf("Date    : %s\n",b.date);
            printf("--------------------------\n");

            found=1;
            break;
        }
    }


    if(found==0)
    {
        printf("\nOrder not found!\n");
    }

    fclose(f);
}





void daily_sales()
{
    FILE *f;
    struct bill b;

    char dt[20];

    int total=0;
    int found=0;


    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s",dt);


    f=fopen("bill.txt","rb");

    if(f==NULL)
    {
        printf("\nFile not found!\n");
        return;
    }


    while(fread(&b,sizeof(struct bill),1,f))
    {
        if(strcmp(b.date,dt)==0)
        {
            total+=b.grand_total;
            found=1;
        }
    }


    if(found==1)
    {
        printf("\nTotal sales on %s = Rs.%d\n",
               dt,
               total);
    }

    else
    {
        printf("\nNo sales found on this date.\n");
    }

    fclose(f);
}