/*************************************************************************************************************
 * *FILENAME	      : reg_process.c
 *
 * *DESCRITION        : This file defines the functions that are used by new user to open the new bank account. 
 *
 *
 * Revision History   :	       
 *
 * 	Date			Name			Reason
 *
 *   22 oct 2022		----			-----
 *
 *
 ***************************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<ctype.h>

#include "mbs_header.h"
/*************************************************************************************
 * *FUNCTION NAME	      : reg_process
 *
 * *DESCRITION                : This function is used by the new user for registration.
 *
 * *RETURNS		      : account_no - returns account number.
 *
 *
 **************************************************************************************/

int reg_process()
{
	cr *new,*ptr,*prev;
	system("clear");
	if((new=(cr*)calloc(1,sizeof(cr)))==NULL)
	{
		printf("\n\t\t\tMemory does not allocated for customer management database\n");
		return EXIT_FAILURE;
	}
	printf("\n-------------------REGISTRATION------------------------\n");
	while(1)
	{
		printf("\n\t\t\tEnter Aadhar Number-  ");
		scanf("%s",new->aadhar_no);
		if(strlen(new->aadhar_no) != 12)
		{
			printf("\n\t\t\t Aadhar number must be of 12 digits please try again...\n");
			continue;
		}
		if(check_digits(new->aadhar_no))
		{
			printf("\n\t\t\tAadhar number should contain only digits\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter your First Name- ");
		scanf("%s",new->f_name);
		if(check_alpha(new->f_name))
		{
			printf("\n\t\t\tName should contain only characters\n");
			continue;
		}
		break;	
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Last Name- ");
		scanf("%s",new->l_name);
		if(check_alpha(new->l_name))
		{
			printf("\n\t\t\tName should contain only characters\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Phone Number- ");
		scanf("%s",new->phn_no);
		if(strlen(new->phn_no) != 10)
		{
			printf("\n\t\t\tPhone number must be of 10 digits please try again...\n");
			continue;
		}
		if(check_digits(new->phn_no))
		{
			printf("\n\t\t\tPhone number should contain only digits\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Address- ");
		scanf("%s",new->address);
		if(strlen(new->address)>50)
		{
			printf("\n\t\t\tInvalid Length \n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter your E-mail Id-  ");
		scanf("%s",new->email_id);
		int ap,dp;
		char emailid[20];
		strcpy(emailid,new->email_id);
		for(int i=0;emailid[i]!='\0';i++)
		{

			if(emailid[i]=='@')
			{
				ap=i;
			}
			if(emailid[i]=='.')
			{
				dp=i;
			}
		}
		if(ap>3 && (dp-ap)>3)
			break;
		else
			printf("\n\t\t\tInvalid Email Id\n");
	}
	while(1)
	{
		int dd,mm,yy;
		printf("\n\t\t\tEnter date of birth-  ");
		scanf("%d %d %d",&dd,&mm,&yy);
		if(yy>=1900 && yy<=9999)
		{
			if(mm>=1 && mm<=12)
			{
				if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
				{
				}
				else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
				{
				}
				else if((dd>=1 && dd<=28) && (mm==2))
				{
				}
				else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
				{
				}
				else
				{
					printf("\n\t\t\tDay is invalid.\n");
					continue;
				}
			}
			else
			{
				printf("\n\t\t\tMonth is Invalid.\n");
				continue;
			}
		}
		else
		{
			printf("\n\t\t\tYear is Invalid.\n");
			continue;
		}
		sprintf(ptr->dob,"%d/%d/%d",dd,mm,yy);
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Father Name-  ");
		scanf("%s",new->father_name);
		if(check_alpha(new->father_name))
		{
			printf("\n\t\t\tFather Name should contain only characters\n");
			continue;
		}
		break;
	}
	while(1)
	{
		int choice;
		printf("\n\t\t\t1. Saving Account\n\t\t\t2. Current Account\n");
		scanf("%d",&choice);
		if(choice<=0 || choice >=3)
		{
			printf("\n\t\t\tInvalid choice Enter valid choice\n");
			continue;
		}
		if(choice == 1 )
		{
			strcpy(new->account_type,"Saving Account");
			break;
		}
		if(choice == 2)
		{
			strcpy(new->account_type,"Current Account");
			break;
		}
		break;
	}
	while(1)
	{
		long int acc_no = rand_no();
		int len;
		sprintf(new->account_no, "%ld" , acc_no);
		if(strlen(new->account_no) != 8)
		{
			printf("\n\t\t\tAccount number must be of  8 digits please try again...\n");
			continue;
		}
		if(check_digits(new->account_no))
		{
			printf("\n\t\t\tAccount number should contain only digits\n");
			continue;
		}
		break;
	}
	strcpy(new->rd_no,"NA");
	strcpy(new->fd_no,"NA");
	while(1)
	{
		char pass[20],ch;
		int i,number,special,capital,small;
		number=special=capital=small=0;
		printf("\n\t\t\tEnter Password-  ");
		scanf("%s",new->passwd);
		strcpy(pass,new->passwd);
		if(strlen(pass)<8)
		{
			printf("\n\t\t\tLength of password should be greater than 8 characters\n");
			continue;
		}
		for(i=0;pass[i]!='\0';i++)
		{
			if(pass[i]>='0' && pass[i]<='9')
				number=1;
			if(pass[i]>='a' && pass[i]<='z')
				small=1;
			if(pass[i]>='A' && pass[i]<='Z')
				capital=1;
			if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='*')
				special=1;
		}
		if(number==0 || special==0 || capital==0 || small==0){
			printf("\n\t\t\tInvalid Password\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter amount to deposit-  ");
		scanf("%lf",&new->balance);
		if(new->balance <500)
		{
			printf("\n\t\t\tMinimun deposit should be greater than or equal to 500\n");
			continue;
		}
		break;
	}
	printf("\n\t\t\tYour account number is - %s\n\t\t\tYour password is - %s\n",new->account_no,new->passwd);
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->account_no < start->account_no)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->account_no < new->account_no;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=NULL;
	}
	system("read a");
	return EXIT_SUCCESS;
}

