#include<stdio.h>
#include<string.h>
#include<time.h>
#include "header.h"

void billing(struct order o[], int n)
{
    int i,total=0;
    FILE *fp;

    struct bill b,temp;

    b.bill_id=1;

    fp=fopen("bill.txt","rb");

    if(fp!=NULL)
    {
        while(fread(&temp,sizeof(struct bill),1,fp))
        {
            b.bill_id=temp.bill_id+1;
        }

        fclose(fp);
    }

    time_t t;
    time(&t);

    struct tm *current=localtime(&t);

    sprintf(b.date,"%02d/%02d/%d",
    current->tm_mday,
    current->tm_mon+1,
    current->tm_year+1900);

    printf("\n=====================================\n");
    printf("            *** RECEIPT ***\n");
    printf("=====================================\n");

    printf("Bill ID : %d\n",b.bill_id);
    printf("Date : %s\n",b.date);

    printf("Time : %02d:%02d:%02d\n",
           current->tm_hour,
           current->tm_min,
           current->tm_sec);

    printf("-------------------------------------\n");

    printf("%-15s %5s %7s %10s\n",
           "ITEM","QTY","PRICE","TOTAL");

    printf("-------------------------------------\n");

    for(i=0;i<n;i++)
    {
        printf("%-15s %5d %7d %10d\n",
               o[i].name,
               o[i].qty,
               o[i].price,
               o[i].total);

        total+=o[i].total;
    }

    printf("-------------------------------------\n");
    printf("%-25s %10d\n","SUBTOTAL:",total);

    if(total>500)
    {
        int discount=total*0.1;

        printf("%-25s -%9d\n",
               "DISCOUNT (10%):",
               discount);

        total-=discount;
    }

    char coupon[20];
    int couponDiscount=0;

    printf("Enter coupon code (or NONE): ");
    scanf("%s",coupon);

    if(strcmp(coupon,"SAVE50")==0)
    {
        couponDiscount=50;

        printf("%-25s -%9d\n",
               "COUPON (SAVE50):",
               couponDiscount);
    }

    else if(strcmp(coupon,"DISC10")==0)
    {
        couponDiscount=total*0.1;

        printf("%-25s -%9d\n",
               "COUPON (DISC10):",
               couponDiscount);
    }

    else if(strcmp(coupon,"NONE")!=0)
    {
        printf("%-25s %10s\n",
               "COUPON:",
               "INVALID");
    }

    total-=couponDiscount;

    int gst=total*0.05;

    printf("%-25s %10d\n","GST (5%):",gst);

    b.grand_total=total+gst;

    printf("-------------------------------------\n");
    printf("%-25s %10d\n","TOTAL AMOUNT:",b.grand_total);
    printf("-------------------------------------\n");

    fp=fopen("bill.txt","ab");

    fwrite(&b,sizeof(struct bill),1,fp);

    fclose(fp);

    printf("\nBill stored successfully!\n");
    printf("\n       THANK YOU!\n");
    printf("=====================================\n");
}