#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "funcs.h"

int main()
{
	clear
	index();
	int ch;
	scanf(" %d",&ch);
	switch(ch){
		default :{
			clear
			printf("Invalid Choice.\n");
			break;
		}
		case 1:{
			clear
			int n;
			printf("Enter How many records you want to store :");
			scanf(" %d",&n);
			record *s=(record*)calloc(n,sizeof(record));
			int i;
			for(i=0; i<n; i++)
			{
				s[i]=read();
				clear
			}
			FILE *fp;
			if((fp=fopen("record.txt","a"))==NULL){
				printf("Unable to open file.");
				exit(0);
			}
			if((fwrite(s,sizeof(record),n,fp))!=0){
				printf("Written Succesfully.\n");
			}
			fclose(fp);
			break;
		}
		case 2:{
			int regn;
			clear
			printf("Enter Registration Number :");
			scanf(" %d",&regn);
			clear
			FILE *fp;
			if((fp=fopen("record.txt","r"))==0){
				printf("Unable to fetch data.");
				exit(0);
			}
			fseek(fp,0L,2);
			int n=ftell(fp);
			rewind(fp);
			int n_records =(int)n/sizeof(record);
			int i,f=0;
			record *a=(record*)malloc(sizeof(record));
			for(i=1; i<=n_records; i++)
			{
				fread(a,sizeof(record),1,fp);
				if(a->Regno==regn){
					show(a);
					f=1;
				}
			}
			if(f==0){
				printf("Wrong Registration Number.\n");
			}
			fclose(fp);
			free(a);
			break;
		}
		case 3:{
			clear
			int regn;
			printf("Enter Registration No. of Whose Reocord You Want to Modify :");
			scanf(" %d",&regn);
			clear
			FILE *fp;
			if((fp=fopen("record.txt","r"))==0){
				printf("Unable to fetch data.");
				exit(0);
			}
			fseek(fp,0L,2);
			int n=ftell(fp);
			rewind(fp);
			int n_records =(int)n/sizeof(record);
			int i,f=0;
			record *a=(record*)malloc(sizeof(record));
			FILE *tem;
			if((tem=fopen("tem.txt","w"))==0){
				printf("unable to create file.");
				exit(0);
			}
			for(i=1; i<=n_records; i++)
			{
				fread(a,sizeof(record),1,fp);
				if(a->Regno==regn){
					printf("Enter New Data \n");
					*a=read();
					f=1;
				}
				fwrite(a,sizeof(record),1,tem);
			}
			if(f==0){
				printf("Wrong Registration Number.\n");
			}
			fclose(fp);
			fclose(tem);
			fp=fopen("record.txt","w");
			tem=fopen("tem.txt","r");
			for(i=1; i<=n_records; i++)
			{
				fread(a,sizeof(record),1,tem);
				fwrite(a,sizeof(record),1,fp);
			}
			fclose(fp);
			fclose(tem);
			break;
		}
		case 4:{
			clear
			int regn;
			printf("Enter Registration No. of Whose Reocord You Want to Delete :");
			scanf(" %d",&regn);
			clear
			FILE *fp;
			if((fp=fopen("record.txt","r"))==0){
				printf("Unable to fetch data.");
				exit(0);
			}
			fseek(fp,0L,2);
			int n=ftell(fp);
			rewind(fp);
			int n_records =(int)n/sizeof(record);
			int i,f=0;
			record *a=(record*)malloc(sizeof(record));
			FILE *tem;
			if((tem=fopen("tem.txt","w"))==0){
				printf("unable to create file.");
				exit(0);
			}
			for(i=1; i<=n_records; i++)
			{
				fread(a,sizeof(record),1,fp);
				if(a->Regno!=regn){
					fwrite(a,sizeof(record),1,tem);
					f=1;
				}
				
			}
			if(f==1){
				printf("Wrong Registration Number.\n");
			}
			fclose(fp);
			fclose(tem);
			fp=fopen("record.txt","w");
			tem=fopen("tem.txt","r");
			for(i=1; i<=n_records; i++)
			{
				fread(a,sizeof(record),1,tem);
				fwrite(a,sizeof(record),1,fp);
			}
			fclose(fp);
			fclose(tem);
			break;
		}
		case 5:{
			exit(0);
			break;
		}
	}
	return 0;
}
