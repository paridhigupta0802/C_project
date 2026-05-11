#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"



void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int login()
{
   
    int ch,res;
    do
    {
        printf("\n====================================\n");
         printf("     *** USER AUTHENTICATION ***\n");
        printf("=====================================\n");
        printf("1.Register\n");
        printf("2.Login\n");
        printf("3.Exit\n");
        printf("------------------------------------\n");
        printf("Enter choice: ");

        scanf("%d",&ch);
        clear_input_buffer(); 

        switch(ch)
        {
            case 1:
            regis();
            break;

            case 2:
            return log_user();
            break;

            case 3:
            printf("\nExiting...\n");
            exit(0);

            default:
            printf("\nInvalid choice. Try again :)\n");
        }

    }
    while(ch!=3);
}


void regis()
{
    FILE *f;
    char usernm[20];
    struct user u;
    int found=0;

    printf("\n------------------------------------\n");
    printf("    *** NEW REGISTRATION ***\n");
    printf("------------------------------------\n");

    printf("Enter Username: ");
    scanf("%s",usernm);

    f=fopen("login.txt","rb");
    while(fread(&u,sizeof(struct user),1,f))
    {
        if(strcmp(u.usernm,usernm)==0)
        {
            found=1;
        }
    }
    fclose(f);

    if(found==0)
    {
        strcpy(u.usernm,usernm);

        printf("Enter Password: ");
        scanf("%s",u.psswd);
    
        f=fopen("login.txt","ab");   
        fwrite(&u,sizeof(struct user),1,f);
        fclose(f);

        printf("\nRegistration Successful!!\n");
        printf("------------------------------------\n");
    }
    else
    {
        printf("\nUsername already exists. Try another.\n");
        printf("------------------------------------\n");
        regis();
    }

   
}

int log_user()
{
    FILE *f;
    struct user u;
    char nm[20],passwd[20];
    int found=0;

    printf("\n------------------------------------\n");
    printf("              LOGIN\n");
    printf("------------------------------------\n");

    printf("Enter Username: ");
    scanf("%s",nm);

    printf("Enter Password: ");
    scanf("%s",passwd);

    f=fopen("login.txt","rb");

    while(fread(&u,sizeof(struct user),1,f))
    {
        if(strcmp(nm,u.usernm)==0)
        {
          if(strcmp(passwd,u.psswd)==0)
        
          {
            found=1;
            printf("\nLogin Successful!!\n");
            printf("------------------------------------\n");
            break;
          }
        }
    }

    fclose(f);

    if(found==1)
        return 1;
    else
    {
        printf("\nNo such record found.\n");
        printf("------------------------------------\n");
        return 0;
    }
}