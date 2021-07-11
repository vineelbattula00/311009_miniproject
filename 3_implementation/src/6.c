#include<stdio.h>
#include<stdlib.h>
#include "2.h"
struct tm
{
	int year;
	int month;
	int date;
};
struct data
{
	double total_sale;
	int total_customers;
	struct tm day;
	double total_qty_sold;
};
void find_max_sales()
{
	double max=0;
	FILE *infile;
	infile=fopen("master_record.txt","rb");
	if( infile == NULL)
	{
		printf("Database is Empty\n");
		return;
	}
	struct data inp;
	while(fread(&inp,sizeof(struct data),1,infile))
	{
		if(inp.total_sale>max)
			max=inp.total_sale;
	}

	fseek(infile,0,SEEK_SET);

	printf("\n");
	line_printer(95,61,10);
	printf("\n");
	printf("\t\t\t\t\t\tDAY(s) OF MAX. SALES");
	printf("\n");
	line_printer(95,61,10);
	printf("\n");
	printf("\t\tDATE OF RECORD\t\t\t\t\t\t\tTOTAL SALE\n");
	line_printer(95,61,10);
	printf("\n");

	while(fread(&inp,sizeof(struct data),1,infile))
	{
			if(max == inp.total_sale)
				printf("\t\t%d-%d-%d\t\t\t\t\t\t\t%.2lf\n",inp.day.date,inp.day.month,inp.day.year,inp.total_sale);
	}
	line_printer(95,61,10);
	printf("\n");
	fclose(infile);
}

void find_min_sales()
{
	double min=0;
	FILE *infile;
	infile=fopen("master_record.txt","rb");
	if( infile == NULL)
	{
		printf("Database is Empty\n");
		return;
	}	
	struct data inp;

	fread(&inp,sizeof(struct data),1,infile);
	min=inp.total_sale;

	fseek(infile,0,SEEK_SET);
	 printf("\n");
        line_printer(95,61,10);
        printf("\n");
        printf("\t\t\t\t\t\tDAY(s) OF MIN. SALES");
        printf("\n");
        line_printer(95,61,10);
        printf("\n");
        printf("\t\tDATE OF RECORD\t\t\t\t\t\t\tTOTAL SALE\n");
        line_printer(95,61,10);
        printf("\n");


	while(fread(&inp,sizeof(struct data),1,infile))
	{
		if(inp.total_sale<min)
			min=inp.total_sale;
	}

	fseek(infile,0,SEEK_SET);

	while(fread(&inp,sizeof(struct data),1,infile))
	{
			if(min == inp.total_sale)
				printf("\t\t%d-%d-%d\t\t\t\t\t\t\t%.2lf\n",inp.day.date,inp.day.month,inp.day.year,inp.total_sale);
	}
	line_printer(95,61,10);
	printf("\n");
	fclose(infile);
}
