#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

void menu_management()
{
    int ch;
    do
    {
        printf("\n========================================\n");
        printf("        CAFETERIA MENU MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add New Menu Items\n");
        printf("2. Update Item Details\n");
        printf("3. Delete Item\n");
        printf("4. Display Menu\n");
        printf("5. Exit\n");

        printf("----------------------------------------\n");
        printf("Enter choice: ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                new();
                break;

            case 2:
                update();
                break;

            case 3:
                del();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nWrong choice!\n");
        }

    }
    while(ch!=5);
}




void new()
{
    struct cafe m[50];
    struct cafe temp;

    int i,n,found,pr,count=0;

    FILE *f;
    char nm[20];

    printf("\n----------------------------------------\n");
    printf("          ADD NEW MENU ITEMS\n");
    printf("----------------------------------------\n");

    printf("Enter number of records: ");
    scanf("%d",&n);


    for(i=0;i<n;i++)
    {
        found=0;

        printf("\n------------ Item %d ------------\n",i+1);

        printf("Enter item name: ");
        scanf(" %[^\n]",nm);


        f=fopen("menu.txt","rb");

        if(f!=NULL)
        {
            while(fread(&temp,sizeof(struct cafe),1,f))
            {
                if(strcmp(nm,temp.nm)==0)
                {
                    found=1;
                }
            }

            fclose(f);
        }


        if(found==0)
        {
            strcpy(m[count].nm,nm);

            printf("\nSelect Category\n");
            printf("1.Snacks\n");
            printf("2.Full Meals\n");
            printf("3.Beverages\n");
            printf("4.Add-ons\n");
            printf("5.Smart Combos\n");
            printf("Choice: ");

            scanf("%d",&m[count].cuisine);


            printf("Enter price (Rs.): ");
            scanf("%d",&pr);


            if(pr<=0)
            {
                printf("\nInvalid price\n");
                i--;
                continue;
            }

            m[count].price=pr;

            count++;
        }

        else
        {
            printf("\nItem already exists in menu.\n");
            i--;
        }

    }


    f=fopen("menu.txt","ab");

    fwrite(m,sizeof(struct cafe),count,f);

    fclose(f);


    printf("\nItem added successfully!\n");
    printf("========================================\n");
}





void update()
{
    struct cafe m[50];

    FILE *f;

    char name[20];

    int pr,i,found=0,n=0;


    printf("\n----------------------------------------\n");
    printf("          UPDATE ITEM PRICE\n");
    printf("----------------------------------------\n");


    f=fopen("menu.txt","rb");

    while(fread(&m[n],sizeof(struct cafe),1,f))
    {
        n++;
    }

    fclose(f);


    printf("Enter item name to update: ");
    scanf(" %[^\n]",name);

    printf("Enter new price: ");
    scanf("%d",&pr);


    for(i=0;i<n;i++)
    {
        if(strcmp(name,m[i].nm)==0)
        {
            m[i].price=pr;

            found=1;
            break;
        }
    }


    if(found==0)
    {
        printf("\nNo such food item found.\n");
        return;
    }


    f=fopen("menu.txt","wb");

    fwrite(m,sizeof(struct cafe),n,f);

    fclose(f);


    printf("\nPrice updated successfully!\n");
}





void del()
{
    struct cafe m[50];

    char name[20];

    int i,n=0,j,found=0;

    FILE *f;


    printf("\n----------------------------------------\n");
    printf("             DELETE ITEM\n");
    printf("----------------------------------------\n");


    f=fopen("menu.txt","rb");


    while(fread(&m[n],sizeof(struct cafe),1,f))
    {
        n++;
    }

    fclose(f);


    printf("Enter item name to delete: ");
    scanf(" %[^\n]",name);


    for(i=0;i<n;i++)
    {
        if(strcmp(name,m[i].nm)==0)
        {
            for(j=i;j<n-1;j++)
            {
                m[j]=m[j+1];
            }

            n--;

            found=1;

            break;
        }
    }


    if(found==0)
    {
        printf("\nNo such item.\n");
        return;
    }


    f=fopen("menu.txt","wb");

    fwrite(m,sizeof(struct cafe),n,f);

    fclose(f);


    printf("\nItem deleted successfully!\n");
    printf("========================================\n");
}




void display()
{
    struct cafe m[50];

    int i,idx,n=0;

    FILE *f;


    f=fopen("menu.txt","rb");

    while(fread(&m[n],sizeof(struct cafe),1,f))
    {
        n++;
    }

    fclose(f);


    printf("\n========================================\n");
    printf("             CAFETERIA MENU\n");
    printf("========================================\n");



    printf("\n========== SNACKS ==========\n");

    idx=0;

    for(i=0;i<n;i++)
    {
        if(m[i].cuisine==1)
        {
            idx++;

            printf("%d. %-25s Rs.%d\n",
            idx,
            m[i].nm,
            m[i].price);
        }
    }



    printf("\n======= FULL MEALS =======\n");

    idx=0;

    for(i=0;i<n;i++)
    {
        if(m[i].cuisine==2)
        {
            idx++;

            printf("%d. %-25s Rs.%d\n",
            idx,
            m[i].nm,
            m[i].price);
        }
    }



    printf("\n======= BEVERAGES =======\n");

    idx=0;

    for(i=0;i<n;i++)
    {
        if(m[i].cuisine==3)
        {
            idx++;

            printf("%d. %-25s Rs.%d\n",
            idx,
            m[i].nm,
            m[i].price);
        }
    }



    printf("\n========= ADD-ONS =========\n");

    idx=0;

    for(i=0;i<n;i++)
    {
        if(m[i].cuisine==4)
        {
            idx++;

            printf("%d. %-25s Rs.%d\n",
            idx,
            m[i].nm,
            m[i].price);
        }
    }



    printf("\n======= SMART COMBOS =======\n");

    idx=0;

    for(i=0;i<n;i++)
    {
        if(m[i].cuisine==5)
        {
            idx++;

            printf("%d. %-25s Rs.%d\n",
            idx,
            m[i].nm,
            m[i].price);
        }
    }

}