#include <time.h>

struct bill_item
{
    char item_name[100];
    int item_qty;
    double item_price;
    double item_price_total;
};

struct bill
{
    char customer_name[100];
    long int mobile_num;
    struct bill_item items[100];
    int total_unique_qty;
    int bill_no;
    int total_qty;
    double total_sales;
    struct tm time_now;
};

struct master_record
{
    double total_sales;
    int total_customers;
    int year;
    int month;
    int date;
    int total_qty_sold;
};

typedef struct product
{
    char pname[100];
    int qty;
    float price;
}product;
product arr[10];
int item_number;
