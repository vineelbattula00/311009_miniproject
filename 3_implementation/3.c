#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.h"
#include<time.h>
#include "4.h"
#include "2.h"


struct tm deliver_time()    //used to deliver current time to the structure bill (it's a function returning type struct tm *
{
    time_t times = time(NULL);
    struct tm tmp = *localtime(&times);
    return tmp;
};

struct bill create_new_bill()
{
	
    
    struct bill new_bill;
    struct bill *ptr;
    ptr=&new_bill;
    printf("Please enter customer name : ");
    scanf("%s",new_bill.customer_name);
    printf("Please enter mobile number : ");
    scanf("%ld",&new_bill.mobile_num);
    new_bill.total_qty = 0;
    new_bill.total_sales = 0;
    new_bill.total_unique_qty = 0;
    int add_more = 1;
    item_number=0;
    while(add_more == 1)
    {
        printf("Enter product name: ");
        scanf("%s",new_bill.items[item_number].item_name);
        printf("Enter qty: ");
        scanf("%d", &(new_bill.items[item_number].item_qty));
        qty_update(ptr,new_bill.items[item_number].item_qty,new_bill.items[item_number].item_name);
        
	if((new_bill.items[item_number].item_qty)!=0)
	{        
		new_bill.items[item_number].item_price_total = (new_bill.items[item_number].item_qty)*(new_bill.items[item_number].item_price);
        	new_bill.total_qty = new_bill.total_qty + new_bill.items[item_number].item_qty;
        	new_bill.total_sales = new_bill.total_sales + new_bill.items[item_number].item_price_total;
        	item_number = item_number + 1;
        	new_bill.total_unique_qty = item_number;
	}
        printf("Do you want to add more (1/0) ? ");
        scanf("%d",&add_more);
    }
    FILE *fp;
    fp=fopen("store.txt","wb");
    fwrite(arr,sizeof(product),10,fp);
    fclose(fp);

    FILE *file_ptr;
    file_ptr = fopen("data.txt","ab");
    new_bill.time_now = deliver_time();
    fseek(file_ptr,0,SEEK_END);
    new_bill.bill_no = get_bill_num();
    fwrite(&new_bill,sizeof(struct bill),1,file_ptr);
    fclose(file_ptr);
    return new_bill;
}

void display_bill(struct bill printing_bill)
{
    int i;
    printf("\n\n");
    int j = 205;
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }
    printf("\n");
printf("\t\t\t vineel's Grocery Store,No 311009, Plot No10, watertank road thummalapalem, vijayawada,andhra pradesh\n\t\t\t\t\t\t\tPhone: 0866-2881308 \n\t\t\t\t\t\tOpen 7 days a week from 11 am to 9pm\n");
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }
    printf("\n");
    printf("                                GROCERY BILL NUMBER : %d\n", printing_bill.bill_no);
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }
    printf("\n");
    printf("\tITEM NUMBER\t\t\tITEM NAME\t\t\tITEM QUANTITY\t\tITEM PRICE\t\tTOTAL PRICE          \n");
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }
    printf("\n");
    for(i = 0; i < printing_bill.total_unique_qty; i++)
    {
        printf("\t%d\t\t\t%14s\t\t\t\t%d\t\t\t%0.2lf\t\t\t\t%0.2lf\n",i+1,printing_bill.items[i].item_name,printing_bill.items[i].item_qty,printing_bill.items[i].item_price,
            printing_bill.items[i].item_price_total);
    }
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }
    printf("\n");
    printf("\tTime Stamp : %d-%d-%d  ",printing_bill.time_now.tm_mday,printing_bill.time_now.tm_mon+1,printing_bill.time_now.tm_year+1900);
    printf("%d:%d:%d\t\t\t",printing_bill.time_now.tm_hour, printing_bill.time_now.tm_min, printing_bill.time_now.tm_sec);
    printf("\t\t\t\t\t\tTotal Sales : %0.2lf\n", printing_bill.total_sales);
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }
    printf("\n");
    printf("\tCustomer Name : %s\t\t\tCustomer Mobile Number : %ld\n", printing_bill.customer_name, printing_bill.mobile_num);
    for(i = 0; i < 152; i++)
    {
        printf("=");
    }   
    printf("\n\n");
    printf("THANKS FOR shopping");
    printf("\n\n");
}
