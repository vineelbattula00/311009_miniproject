#include<stdio.h>
#include<string.h>

int display_menu()
{
	printf("\n");
	FILE *fp;
	char data[100];
	int user_option;
	fp = fopen("display_menu.txt","r");
	if( fp == NULL)
	{
		return 1;
	}
	while(fgets(data,100,fp)!= NULL)
	{
		printf("%s",data);
	}
	printf("\nEnter Your Choice:");
	scanf("%d",&user_option);
	fclose(fp);
	return user_option;
}
