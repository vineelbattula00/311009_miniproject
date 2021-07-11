#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "3.h"

//LOGIN
typedef struct cashier_details
{
     char uname[10];
     char pword[10];
}cashier;
char name[3][10]={"rohan",
                                "rahul",
                                "rachit",
                            };
char pass[3][10]={"spk12",
                                "duck@123",
                                "hitman_45",
                            };

void login()
{
    int i=0;
    system("clear");
    while(i<3)
    {
        cashier c1;
        printf("Username:");
        scanf("%s",c1.uname);
        printf("Password: ");
        scanf("%s",c1.pword);
        int k=0;
        while(k<3)
        {
                 if((strcmp(c1.uname,name[k]))==0)
                 {

                            if(strcmp(c1.pword,pass[k])==0)
                             {
				system("clear");
                                printf("LOGIN SUCCESSFULL AS CASHIER No. %d\n",k+1);
                                return;
                             }

                 }

                 k++;
        }
        i++;
        system("clear");
	printf("Invalid Username or Password. Try Again!!\n\n");
    }
    system("clear");
    printf("LOGIN UNSUCCESSFULL AFTER THREE TRIES\n");
    printf("\nRE-RUN YOUR PROGRAM AND TRY AGAIN\n\n");
    exit(0);
}

//INVENTORY
void qty_update(struct bill *ptr, int x,char name[])
{
    x = x/1;
    fflush(stdin);
    if(x>0)
    {
        int i=0;
        while(i<10)
        {
            if(!strcmp(arr[i].pname,name))
            {
                if(arr[i].qty>=x)
                 {
                     arr[i].qty-=x;
                     (*ptr).items[item_number].item_price = arr[i].price;
                     return;
                 }
                 else if (arr[i].qty<x)
                 {
                     if(arr[i].qty==0)
                     {
                         printf("This item is OUT OF STOCK\n");
                         (*ptr).items[item_number].item_qty=0;
                         return;
                     }
                     printf("Only %d items of %s are available in our store\n",arr[i].qty,name);
                     printf("Press 1 if you want to buy these many items,otherwise 0:");
                     int option;
                     scanf("%d",&option);
                     switch(option)
                     {
                         case 1:
				    (*ptr).items[item_number].item_qty = arr[i].qty;
                                	arr[i].qty=0;
					    (*ptr).items[item_number].item_price = arr[i].price;
                                
                                    return;
                         case 0:
                                    (*ptr).items[item_number].item_qty = 0;
                                    return;
                     }
                 }

            }
            else if(i==9)
            {
                printf("There is no product named %s in our store\n",name);
                (*ptr).items[item_number].item_qty = 0;
            }
            i++;
        }
    }
    else
    {
        printf("Enter quantity greater than zero\n");
        printf("Enter quantity again: ");
        scanf("%d",&((*ptr).items[item_number].item_qty));
        qty_update(ptr,(*ptr).items[item_number].item_qty,(*ptr).items[item_number].item_name);
    }
}

//DELETE_BILL
void delete_bill(int bill_no)
{
    FILE *fp1,*fp2;
    char arr1[]="data.txt";
    fp1 = fopen(arr1,"rb");
    fp2 = fopen("data_2.txt","wb");
    struct bill b1;
    int check=0;
    while(fread(&b1,sizeof(struct bill),1,fp1))
    {
        if(b1.bill_no == bill_no)
        {
            check=1;
	    int i=0;
	    while(i<10)
	    {
		    
		    int k=0;
		    while(k<(b1.total_unique_qty))
		    {
			    
			    if(!strcmp(b1.items[k].item_name,arr[i].pname))
			    {
				    
				    arr[i].qty+=(b1.items[k].item_qty);
			    }
			    k++;
		    }
		    i++;
	    }
	    FILE *fp;
    	    fp=fopen("store.txt","wb");
            fwrite(arr,sizeof(product),10,fp);
    	    fclose(fp);
            continue;

        }
        else
        {
            fwrite(&b1,sizeof(struct bill),1,fp2);
        }
    }
    if(check==0)
    {
	printf("Bill does not exist\n");
    }
    fclose(fp1);
    fclose(fp2);
    remove(arr1);
    rename("data_2.txt",arr1);
    
}
//View Inventory
void view_inventory()
{
	FILE *fp;
	fp=fopen("store.txt","rb");
        int l=0;
	for(int i=0;i<=152;i++)
	{
		printf("=");
	}
	printf("\nProduct name\tQuantity\tPrice\n");    
	for(int i=0;i<=152;i++)
	{
		printf("=");
	}
	printf("\n");
	while(fread(&arr[l],sizeof(product),1,fp))
    {
            printf("%s           %d            %.2f\n",arr[l].pname,arr[l].qty,arr[l].price);
            l++;
    }
	fclose(fp);
	for(int i=0;i<=152;i++)
	{
		printf("=");
	}
	printf("\n");
}
