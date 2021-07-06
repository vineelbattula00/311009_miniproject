#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "2.h"
#include "3.h"
#include "structures.h"

int find_bill(int bill_num)
{
  int i=0;	
  FILE *file_ptr;
  file_ptr = fopen("data.txt","rb");
  struct bill tmp_bill;
  if(file_ptr==NULL)
  {
    printf("FILE NOT OPENED\n");
    return -2; 
  }
  
  else
  {	  
    fread(&tmp_bill,sizeof(struct bill),1,file_ptr);
    while(!feof(file_ptr))
    { 
     if(tmp_bill.bill_no==bill_num)
     {
       fclose(file_ptr);
       return (ftell(file_ptr) - sizeof(struct bill));   
     }
     fread(&tmp_bill,sizeof(struct bill),1,file_ptr);
    }
  }
  fclose(file_ptr);
  return -1;
}

void search_bill_by_name(char* cust_name)
{
  char* name=(char*)calloc(100,sizeof(char));	
  int i = 0;
  FILE *file_ptr;
  file_ptr = fopen("data.txt","rb");
  struct bill tmp_bill;
  if(file_ptr==NULL)
  {
    printf("\nFILE NOT OPENED\n");
  }

  else
  { 
    int* arr1=(int*)calloc(10,sizeof(int));
    fread(&tmp_bill,sizeof(struct bill),1,file_ptr);
    while(!feof(file_ptr))
    {
     if(strcmp(tmp_bill.customer_name,cust_name)==0)
     {
       arr1[i]=tmp_bill.bill_no;
       i++;  
     }
     fread(&tmp_bill,sizeof(struct bill),1,file_ptr);
    }
    if(i==0)
    {
      fclose(file_ptr);
      printf("\nNot Found\n");
    }
    else
    {
      fclose(file_ptr);
      for(int j=0;j<i;j++)
      {
        display_bill(read_bill(find_bill(arr1[j])));
      }
    
    }
  }
  
}
	

                                                                                                                                                    
