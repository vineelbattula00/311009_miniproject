// CREATED BY ANKIT AGRAWAL IMT2019010 //

#include <stdio.h>
#include <time.h>
#include "structures.h"
//-------------------------------------------------------------------------------------------------//

void line_printer(int x, int y, int z) //x is number of times, y is ASCII code of character to be printed and z is number of spaces to be printed
{
    char c = y;  //we convert ASCII code to the character corresponding to that code
    for(int i = 0 ; i < z; i++) //first we will print space
    {
        printf(" ");        //printing spaces
    }
    for(int i = 0 ; i < x ; i++)        //next we print the constituent character of the line
    {
        printf("%c",c); //print the character
    }
} //end of the function

//------------------------------------------------------------------------------------------------//

void display_master_record()   //used to display whole of master record
{
    FILE *file_ptr; //this will open master_record.txt
    file_ptr = fopen("master_record.txt","rb"); //opening master_record
    if(file_ptr == NULL)    //if there is error reading file
    {
        printf("\nOOPS! CANNOT OPEN MASTER RECORDS FILE\n\n");      //display the error message
    }
    else    //if file is opened successfully
    {
        printf("\n");   //go to a new line
        line_printer(95,61,10);     //print a new line
        printf("\n");       //go to new line
        printf("\t\t\t\t\t\tMASTER RECORD VIEWER"); //display heading text
        printf("\n");   //go to new line
        line_printer(95, 61, 10);       //print a new line
        printf("\n");       //go to new line
        printf("\t\tDATE OF RECORD\tTOTAL SALES\tTOTAL QTY SOLD\tTOTAL CUSTOMERS SERVED");  //print a new sub heading
        printf("\n");   //go to new line
        line_printer(95, 61, 10);   //print a new line
        printf("\n");   //go to new line
        struct master_record record_traveller;  //this is used to traverse through all records stored in master_record.txt
        fread(&record_traveller,sizeof(struct master_record),1,file_ptr);   //we read the first record
        while(!feof(file_ptr))      //we read the file till we have not reached its end
        {
            printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year); //display date,month and year of record
            printf("\t%0.2lf", record_traveller.total_sales);  //display total sales of the record
            printf("\t\t%d", record_traveller.total_qty_sold);  //display total quantity sold for the record
            printf("\t\t%d", record_traveller.total_customers);     //display total customers served
            printf("\n");   //go to a new line
            fread(&record_traveller,sizeof(struct master_record),1,file_ptr);       //read a new record
        }   //continue loop process
        line_printer(95, 61, 10);   //print a new line
        fclose(file_ptr);   //close the file
        printf("\n\n");     //go to new line twice
    }


}   //end of the function

//----------------------------------------------------------------------------------------------//

void basic_print()	//basic_print is used to display the framework or design when a record is to be printed
{

        printf("\n");
        line_printer(95,61,10);	//print a line
        printf("\n");
        printf("\t\t\t\t\t\tVIEW SALES AFTER DATE");	//this is the header text
        printf("\n");
        line_printer(95, 61, 10);	//again print a line
        printf("\n");
        printf("\t\tDATE OF RECORD\tTOTAL SALES\tTOTAL QTY SOLD\tTOTAL CUSTOMERS SERVED");  //the column text for display of the record is being printed
        printf("\n");
        line_printer(95, 61, 10);	//again print a line
        printf("\n");
}

void display_sales_after()
{
    FILE *file_ptr;	//this is used to open the file master_record.txt
    file_ptr = fopen("master_record.txt","rb");		//opening master_record.txt
    if(file_ptr == NULL)	//if there is an error in reading the file
    {
        printf("OOPS ! ERROR READING FILE");	//display the error message
    }
    else	//if file has been read successfully
    {
        struct master_record record_traveller;	 //this will traverse through records in master_record.txt
        int user_date,user_month,user_year;	//user_date, user_month and user_year stores the date,month and year before which the user wants to see records
        printf("Please enter date : ");	//ask user for date
        scanf("%d",&user_date);	//enter date from the user
        printf("Please enter month : "); //ask user for month
        scanf("%d",&user_month);	//enter month from the user
        printf("Please enter year : ");	//ask user for year
        scanf("%d",&user_year);	//enter year from the user
        int print_it = 1;	//this variable is used to ensure that basic_print is called only once
        fread(&record_traveller,sizeof(struct master_record),1,file_ptr);  //we start reading with first record
        while(!feof(file_ptr))	//we read file till we reach end of the file
        {
            if(user_year < record_traveller.year)//if user_year is less than year of record, we can print the record
            {
                if(print_it == 1)	//check if the record is the first record to be printed in the screen
                {
                basic_print();	//if yes, print the basic design of the record
                print_it = 0;	//once the basic framework has been displayed, we need not display it again and again
                }
                printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year);	//display date,month and year of record
                printf("\t%0.2lf", record_traveller.total_sales);	//display total sales of the record
                printf("\t\t%d", record_traveller.total_qty_sold);	//display total quantity sold of the record
                printf("\t\t%d", record_traveller.total_customers);	//display total customers served
                printf("\n");	//go to a new line for the next record
            }
            else if(user_year == record_traveller.year && user_month < record_traveller.month)//if user_year equals year of record but user_month is less than month of record, we can print the record
            {
                if(print_it == 1)	//check if the record is the first record to be printed in the screen
                {
                    basic_print();	//if yes, print the basic design of the record
                    print_it = 0;	//once the basic framework has been displayed, we need not display it again and again
                }
                printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year);	//display date,month and year of record
                printf("\t%0.2lf", record_traveller.total_sales);	//display total sales of the record
                printf("\t\t%d", record_traveller.total_qty_sold);	//display total quantity sold of the record
                printf("\t\t%d", record_traveller.total_customers);	//display total customers served
                printf("\n");
            }
            else if(user_year == record_traveller.year && user_month == record_traveller.month && user_date < record_traveller.date)//if user_year equals year of record and user_month is equal to month of record but user_date is less than date of the record, we can print the record
            {
                if(print_it == 1)	//check if the record is the first record to be printed in the screen
                {
                    basic_print();	//if yes, print the basic design of the record
                    print_it = 0;	//once the basic framework has been displayed, we need not display it again and again
                }
                printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year);//display date,month and year of record
                printf("\t%0.2lf", record_traveller.total_sales);	//display total sales of the record
                printf("\t\t%d", record_traveller.total_qty_sold);	//display total quantity sold of the record
                printf("\t\t%d", record_traveller.total_customers);	//display total customers served
                printf("\n");
            }
            fread(&record_traveller,sizeof(struct master_record),1,file_ptr); //continue reading other records
        }
        if(print_it == 1)	//if the basic structure was not printed even once
        {
            printf("\n");
            printf("** NO RECORD FOUND FOR SALES AFTER DATE : %d-%d-%d **",user_date,user_month,user_year);	//display that no matching records were found
        }
        else if(print_it == 0)	//if the basic structure was printed
        {
            line_printer(95, 61, 10);	//we print a line to finish the basic structure of the record display
            printf("\n");
        }
        fclose(file_ptr);	//close the file
    }
}	//end of the function


//------------------------------------------------------------------------------------------------------------------------//


void basic_print_1()   //basic_print_1 is used to display the framework or design when a record is to be printed
{

        printf("\n");
        line_printer(95,61,10);  //print a line
        printf("\n");
        printf("\t\t\t\t\t\tVIEW SALES BEFORE DATE"); //this is the header text
        printf("\n");
        line_printer(95, 61, 10); //again print a line
        printf("\n");
        printf("\t\tDATE OF RECORD\tTOTAL SALES\tTOTAL QTY SOLD\tTOTAL CUSTOMERS SERVED"); //the column text for display of the record is being printed
        printf("\n");
        line_printer(95, 61, 10); //again print a line
        printf("\n");
}

void display_sales_before()
{
    FILE *file_ptr;   //this is used to open the file master_record.txt
    file_ptr = fopen("master_record.txt","rb"); //opening master_record.txt
    if(file_ptr == NULL)	//if there is an error in reading the file
    {
        printf("OOPS ! ERROR READING FILE");		//display the error message
    }
    else			//if file has been read successfully
    {
        struct master_record record_traveller;  //this will traverse through records in master_record.txt
        int user_date,user_month,user_year;	//user_date, user_month and user_year stores the date,month and year before which the user wants to see records
        printf("Please enter date : ");		//ask user for date
        scanf("%d",&user_date);		//enter date from the user
        printf("Please enter month : ");		//ask user for month
        scanf("%d",&user_month);		//enter month from the user
        printf("Please enter year : ");	//ask user for user
        scanf("%d",&user_year);		//enter year from the user
        int print_it = 1; 	//this variable is used to ensure that basic_print_1 is called only once
        fread(&record_traveller,sizeof(struct master_record),1,file_ptr);	//we start reading with first record
        while(!feof(file_ptr))		//we read file till we reach end of the file
        {
            if(user_year > record_traveller.year)//if user_year is greater than year of record, we can print the record
            {
                if(print_it == 1)		//check if the record is the first record to be printed in the screen
                {
                    basic_print_1();	//if yes, print the basic design of the record
                    print_it = 0;		//once the basic framework has been displayed, we need not display it again and again
                }
                printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year);  //display date,month and year of record
                printf("\t%0.2lf", record_traveller.total_sales);	//display total sales of the record
                printf("\t\t%d", record_traveller.total_qty_sold);	//display total quantity sold of the record
                printf("\t\t%d", record_traveller.total_customers);	//display total customers served
                printf("\n");		//go to a new line for the next record
            }

            else if(user_year == record_traveller.year && user_month > record_traveller.month) //if user_year equals year of record but user_month is greater than month of record, we can print the record
            {
                if(print_it == 1)	//check if the record is the first record to be printed in the screen
                {
                    basic_print_1();	//if yes, print the basic design of the record
                    print_it = 0;	//once the basic framework has been displayed, we need not display it again and again
                }
                printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year);	//display date,month and year of record
                printf("\t%0.2lf", record_traveller.total_sales);	//display total sales of the record
                printf("\t\t%d", record_traveller.total_qty_sold);	//display total quantity sold of the record
                printf("\t\t%d", record_traveller.total_customers);	//display total customers served
                printf("\n");
            }
            else if(user_year == record_traveller.year && user_month == record_traveller.month && user_date > record_traveller.date) //if user_year equals year of record and user_month is equal to month of record but user_date is greater than date of the record, we can print the record
            {
                if(print_it == 1)			//check if the record is the first record to be printed in the screen
                {
                    basic_print_1();		//if yes, print the basic design of the record
                    print_it = 0;			//once the basic framework has been displayed, we need not display it again and again
                }
                printf("\t\t%d-%d-%d", record_traveller.date,record_traveller.month,record_traveller.year);	//display date,month and year of record
                printf("\t%0.2lf", record_traveller.total_sales);	//display total sales of the record
                printf("\t\t%d", record_traveller.total_qty_sold);	//display total quantity sold of the record
                printf("\t\t%d", record_traveller.total_customers);	//display total customers served
                printf("\n");
            }
            fread(&record_traveller,sizeof(struct master_record),1,file_ptr);  //continue reading other records
        }
        if(print_it == 1)  //if the basic structure was not printed even once
        {
            printf("\n");
            printf("** NO RECORD FOUND FOR SALES BEFORE DATE : %d-%d-%d **",user_date,user_month,user_year);	//display that no matching records were found
        }
        else if(print_it == 0)		//if the basic structure was printed
        {
            line_printer(95, 61, 10);		//we print a line to finish the basic structure of the record display
            printf("\n");
        }
        fclose(file_ptr);		//close the file
    }
}		//end of the function


//------------------------------------------------------------------------------------------------------------------------//

struct tm deliver_time_now()    //used to deliver current time to the structure bill (it's a function returning type struct tm *
{
    time_t times = time(NULL);
    struct tm tmp = *localtime(&times);
    return tmp;
};

void display_sales_today()
{
    FILE *file_ptr;	//this is used to open the file master_record.txt
    file_ptr = fopen("master_record.txt","rb");	//opening master_record.txt
    if(file_ptr == NULL)	//if there is an error in reading the file
    {
        printf("CANNOT OPEN MASTER RECORD FILE");	//display the error message
    }
    else	//if file has been read successfully
    {
        fseek(file_ptr,0,SEEK_END);  //we go to the end of the file, since all records are stored serial wise in the file master_record.txt
        int curr_position = ftell(file_ptr);  //curr_position stores the current position of the file pointer
        curr_position = curr_position - sizeof(struct master_record);   //we then store the starting position where the last record has been stored
        fseek(file_ptr,curr_position,SEEK_SET);  //by this, we move to the last record stored in master_record.txt
        struct master_record record_traveller;  //this will store the last record of master_record.txt
        struct tm time_now;		//this will store today's date,time, month and year
        fread(&record_traveller,sizeof(struct master_record),1,file_ptr);	//we read the last record from the master record
        time_now = deliver_time_now(); 	//we get today's date,month,year and time from the system
        if((record_traveller.date != time_now.tm_mday) || (record_traveller.month != (time_now.tm_mon + 1) || (record_traveller.year != (time_now.tm_year + 1900))))  //if the last record does not have today's date
        {
            printf("NO RECORD EXISTS FOR TODAY !");	//so no record exists for today
        }
        else //else, if record for today exists
        {
            printf("\n");
            printf("Total Sales today : %0.2lf",record_traveller.total_sales); //display today's total sales
            printf("\n");
            printf("Total Quantity Sold today : %d",record_traveller.total_qty_sold);  //display today's total quantity sold
            printf("\n");
            printf("Total Customer Served today : %d",record_traveller.total_customers); //display total customers served today
            printf("\n");
            printf("Today's date : %d-%d-%d",record_traveller.date,record_traveller.month,record_traveller.year); //display today's date,month and year
            printf("\n");
        }
    	fclose(file_ptr);  //close the file
    }
}		//end of the function


//-----------------------------------------------------------------------------------------------------------------//

struct number
{
	int x;
};

int get_bill_num()
{

    struct number new_number;
    FILE *file_ptr_1;
    file_ptr_1 = fopen("bill_num.txt","rb");
    if(file_ptr_1 == NULL)
    {
        //fclose(file_ptr_1);   **EDITED**
        file_ptr_1 = fopen("bill_num.txt","wb");
        new_number.x = 2;
        fwrite(&new_number,sizeof(struct number),1,file_ptr_1);
        fclose(file_ptr_1);
        return 1;
    }
    else
    {
        fclose(file_ptr_1);
        file_ptr_1 = fopen("bill_num.txt","rb");
        fseek(file_ptr_1,0,SEEK_SET);
        int new_bill_num;
        fread(&new_number,sizeof(struct number),1,file_ptr_1);//fscanf(file_ptr_1,"%d",&new_bill_num);
        new_bill_num = new_number.x;
        fclose(file_ptr_1);
        file_ptr_1 = fopen("bill_num.txt","wb");
        new_number.x += 1;
        fwrite(&new_number,sizeof(struct number),1,file_ptr_1);//fprintf(file_ptr_1,"%d",next_bill_num);
        fclose(file_ptr_1);
        return new_bill_num;
    }
}

//-------------------------------------------------------------------------------------------------------------------//

struct bill read_bill(int position)
{
    struct bill bill_read;
    FILE *file_ptr;
    file_ptr = fopen("data.txt","rb");
    fseek(file_ptr,0,SEEK_END);
    if(position == -1)
    {
        printf("Oops! No Data to Read");
        fclose(file_ptr);
    }
    else
    {
        fseek(file_ptr,position,SEEK_SET);
        fread(&bill_read,sizeof(struct bill),1,file_ptr);
        fclose(file_ptr);
        return bill_read;
    }

}

//--------------------------------------------------------------------------------------------------------------------//

int day_compare(struct bill bill_1,struct master_record bill_2)  //this function is used to compare whether dates of two different bills have same date or not
{
    int indicator = 1; //by default, we assume that both have EXACTLY Same Day
    if(bill_2.year != bill_1.time_now.tm_year + 1900)  //if the year of records differ
    {
        indicator = -1;		//so the dates are not same, indicator is set accordingly
    }
    if(bill_2.month != bill_1.time_now.tm_mon + 1)	//if the month of records differ
    {
        indicator = -1;	//so the dates are not same, indicator is set accordingly
    }
    if(bill_2.date != bill_1.time_now.tm_mday)	//if the day of records differ
    {
        indicator = -1;	//so the dates are not same, indicator is set accordingly
    }
    return indicator;  //return the value of indicator
}

void update_master_record()
{
    FILE *file_ptr_1;	//used to open data.txt file
    FILE *file_ptr_2;	//used to open master_record.txt
    file_ptr_1 = fopen("data.txt","rb");	//open data.txt file
    if(file_ptr_1 == NULL)
    {
	printf("\nBILL RECORDS DO NOT EXIST\n");
    }
    else
    {
    	file_ptr_2 = fopen("master_record.txt","wb");		//open master_record.txt file
    	struct bill bill_traveller;	//this will traverse through all bills in data.txt file
    	int i = 0;		//used to check if the loop is running for the first time
    	struct master_record record_holder;		//this stores the new record to be stored in master_record.txt
    	record_holder.total_sales = 0; 	//initially, total sales is 0
    	record_holder.total_customers = 0;	//initially, total customers is 0
    	record_holder.total_qty_sold = 0;		//initially, total quantity sold is 0
    	fread(&bill_traveller,sizeof(struct bill),1,file_ptr_1);  //we start reading the bills
    	while(!feof(file_ptr_1))	//we read the file data.txt until we reach end of it
    	{
        	if(i == 0)  //so first run of the loop
        	{
        	    record_holder.year = bill_traveller.time_now.tm_year + 1900; //since this is the first run of the loop, we create a year of the record in master_record
        	    record_holder.month = bill_traveller.time_now.tm_mon + 1;  //adding month to this record
        	    record_holder.date = bill_traveller.time_now.tm_mday; //adding date to this record
        	    i = -1;
        	}
       	 	if(day_compare(bill_traveller,record_holder) == -1)  //if dates of record to be written in master record and bill in the data.txt do not match, then that means we have to create a new record for master record
        	{
                fwrite(&record_holder,sizeof(struct master_record),1,file_ptr_2);  //first write the record in master_record.tct
                record_holder.year = bill_traveller.time_now.tm_year + 1900;  //assign new year to new record
                record_holder.month = bill_traveller.time_now.tm_mon + 1;  //assign new month to new record
                record_holder.date = bill_traveller.time_now.tm_mday;	//assign new date to new record
                record_holder.total_sales = bill_traveller.total_sales; //Initially, new sales in this new record is the sales in this bill
                record_holder.total_qty_sold = bill_traveller.total_qty; //Initially, new quantity in this new record is the sales in this bill
                record_holder.total_customers = 1; //Initially, new customer number is one for the new record
        	}
        	else
        	{
                record_holder.total_sales += bill_traveller.total_sales; 	// if we are continuing with the same record for the master record
                record_holder.total_qty_sold += bill_traveller.total_qty;  // we add total quantity to this existing record for master record
                record_holder.total_customers += 1;	//we increase total customer served by 1
            }
            fread(&bill_traveller,sizeof(struct bill),1,file_ptr_1);		//we read the next bill data.txt
        	if((feof(file_ptr_1) && i == -1) || (i == 0 && feof(file_ptr_1)))	//a special case, if end of file is reached, then we have to store the record in master_record.txt
        	{
                fwrite(&record_holder,sizeof(struct master_record),1,file_ptr_2);	//storing record in master_record.txt
        	}
    	}
        fclose(file_ptr_1);		//closing file data.txt
        fclose(file_ptr_2);		//closing file master_record.txt
    }
}	//end of the function


