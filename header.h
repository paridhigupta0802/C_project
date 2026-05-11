#ifndef HEADER_H
#define HEADER_H

struct user
{
    char usernm[20];
    char psswd[20];
};

struct cafe
{
    char nm[30];
    int cuisine;
    int price;
};

struct order
{
    char name[30];
    int price;
    int qty;
    int total;
};

struct bill
{
    int bill_id;
    int grand_total;
    char date[20];
};

int login();
void main_driver();
void admin_driver();
void manager_driver();
void menu_management();
void order_processing();
void billing(struct order o[], int n);
void record_management();

void regis();
int log_user();

void display();
void new();
void update();
void del();

void view_records();
void search_record();
void daily_sales();

#endif
