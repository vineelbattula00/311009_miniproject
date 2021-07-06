#include <stdio.h>
#include<stdlib.h>
#include "structures.h"
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"

//DO NOT FORGET TO UPDATE MASTER RECORD FOR FUNCTIONS 2 AND 3 <-------------------- IMPORTANT-----------------------------------

int main()
{
    login();
    int to_continue = 1;
    while(to_continue != 0)
    {
        to_continue = display_menu();
        if(to_continue == 1)
        {
	    struct bill temp_bill;
            system("clear");
	    FILE* fp2;
            fp2 = fopen("store.txt","rb");
            int m=0;
            while(fread(&arr[m],sizeof(product),1,fp2))
            {
                m++;
            }
            fclose(fp2);
	    temp_bill = create_new_bill();
            if(temp_bill.total_qty == 0)
	    {
	       delete_bill(temp_bill.bill_no);
	    }
            else
	    {
	       display_bill(temp_bill);
               update_master_record();
	    }
        }
	else if(to_continue == 2)
	{
	    system("clear");
	    FILE* fp2;
            fp2 = fopen("store.txt","rb");
            int m=0;
            while(fread(&arr[m],sizeof(product),1,fp2))
            {
                m++;
            }
            fclose(fp2);
	    
	    int bill_to_delete;
	    printf("Enter bill number to delete : ");
	    scanf("%d",&bill_to_delete);
	    delete_bill(bill_to_delete);
	    update_master_record();
	}
	else if(to_continue == 3)
        {
	    system("clear");
            int bill_to_find;
            printf("Please enter bill number to search for : ");
            scanf("%d",&bill_to_find);
            int is_found = find_bill(bill_to_find);
   	    if(is_found == -2)
	    {
		continue;
	    }	
            if(is_found == -1)
            {
                printf("\nBill with bill number %d does not exist !\n",bill_to_find);
            }
            else
            {
                display_bill(read_bill(is_found));
            }
        }
        else if(to_continue == 4)
        {
	    system("clear");
            char cust_name[50];
            printf("\nPlease enter customer name to search for : ");
            scanf("%s",cust_name);
            search_bill_by_name(cust_name);
        }
        else if(to_continue == 5)
        {
	    system("clear");
            find_max_sales();
        }
        else if(to_continue == 6)
        {
	    system("clear");
            find_min_sales();
        }
        else if(to_continue == 7)
        {
	    system("clear");
            display_sales_before();
        }
        else if(to_continue == 8)
        {
	    system("clear");
            display_sales_after();
        }
        else if(to_continue == 9)
        {
	    system("clear");
            display_sales_today();
        }
        else if(to_continue == 10)
        {
	    system("clear");
            display_master_record();
        }
	else if(to_continue == 11)
	{
	    system("clear");
	    view_inventory();
	}
        else if(to_continue==0)
        {
            break;
        }
    	else
	{
	    system("clear");
	    printf("\nInvalid Option!! \nRe-enter your Option\n\n");
	    continue;
	}
    }
    system("clear");	
    printf("\n\nThanks for using this Program !\n\n");
    return 0;
}
