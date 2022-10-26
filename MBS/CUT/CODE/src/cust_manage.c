/*****************************************************************************************************************
 *  *FILENAME          : cust_manage.c
 *
 *  *DESCRIPTION       : This file defines the function that would be used by the admin. The file includes the functions like add, edit, delete, view, report minimum balance and daily transactions.
 *
 *
 *
 *  Revision History   : 
 *
 *    Date            Name         Reason
 *  20 oct 2022       -----        -------
 *
 *
 ****************************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include <ctype.h>
#include "mbs_header.h"
/*****************************************************************
 * *FUNCTION NAME : add_data
 *
 * *DESCRIPTION   : This function adds the details of the customer.
 *
 * *RETURNS       : No return
 *
 ******************************************************************/
int add_data()
{
	cr *new,*ptr,*prev;
	system("clear");
	if((new=(cr*)calloc(1,sizeof(cr)))==NULL)
	{
		printf("\n\t\t\t Memory does not allocated for customer management database\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("\n\t\t\tEnter Aadhar Number-  ");
		scanf("%s",new->aadhar_no);
		if(strlen(new->aadhar_no) != 12)
		{
			printf("\n\t\t\tAadhar number must be of 12 digits please try again...\n");
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
		printf("\n\t\t\tEnter your First Name-  ");
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
		printf("\n\t\t\tEnter your Last Name-  ");
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
		printf("\n\t\t\tEnter your Phone Number-");
		scanf("%s",new->phn_no);
		if(strlen(new->phn_no)!= 10)
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
			printf("\n\t\t\tInvalid Length\n");
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
		{
			break;
		}
		else
		{
			printf("\n\t\t\tInvalid Email-Id\n");
		}
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
					printf("\n\t\t\tDay is Invalid.\n");
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
			printf("\n\t\t\tYear isInvalid.\n");
			continue;
		}
		sprintf(new->dob,"%d/%d/%d",dd,mm,yy);
		break;
	}

	while(1)
	{
		printf("\n\t\t\tEnter your Father Name- ");
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
		printf("\n\t\t\tChoose the type of account that you want\n");
		printf("\n\t\t\t1. Saving Account \n\t\t\t2. Current Account\n");
		printf("\n\t\t\tEnter your choice- ");
		scanf("%d",&choice);
		if(choice<=0 || choice >=3)
		{
			printf("\n\t\t\tInvalid choice Enter valid choice\n");
			continue;
		}
		if(choice ==1)
		{
			strcpy(new->account_type,"Saving Account");
			break;
		}
		if(choice ==2)
		{
			strcpy(new->account_type, "Current Account");
			break;
		}
		break;
	}
	while(1)
	{
		long int acc_no = rand_no();
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
		char pass[16];
		int i,number,special,capital,small;
		number=special=capital=small=0;
		printf("\n\t\t\tEnter Password>> ");
		scanf("%s",new->passwd);
		strcpy(pass,new->passwd);
		if(strlen(pass)<8)
		{
			printf("\n\t\t\tLength of password should be greater than 8\n");
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
	else if(strcmp(new->account_no,start->account_no)!=2)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && strcmp(new->account_no,ptr->account_no)!=2;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}
	free(new);
	system("read a");
	return EXIT_SUCCESS;
}
/**************************************************************************
 * *FILENAME      : edit_data
 *
 * *DESCRIPTION   : This function edits the personal details of the customer.
 *
 * *RETURNS       : No return
 ***************************************************************************/
int edit_data()
{
	cr *ptr;
	system("clear");
	if(!start)
	{
		printf("\n\t\t\tEmpty List\n");
		return EXIT_FAILURE;
	}
	char macc_no[9];
	while(1)
	{
		printf("\n\t\t\tEnter Account number for editing-  ");
		scanf("%s",macc_no);
		if(strlen(macc_no) != 8)
		{
			printf("\n\t\t\tAccount number must be of 8 digits please try again...\n");
			continue;
		}
		if(check_digits(macc_no))
		{
			printf("\n\t\t\tAccount number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}

	for(ptr=start;(ptr) && strcmp(macc_no,ptr->account_no)!=0;ptr=ptr->next);

	if(!ptr)
	{
		printf("\n\t\t\tAccount number %s is not found\n",macc_no);
		return EXIT_FAILURE;
	}
	printf("\n-------------------------Customer Details Before Editing------------------------\n");
	printf("\n\t\t\tOld Details are:-\n\t\t\t First Name - %s\n\t\t\t Last Name - %s\n\t\t\tPhone NUmber - %s\n\t\t\t Address -%s \n\t\t\tEmail Id - %s\n\t\t\t Date of Birth - %s\n\t\t\t Father Name - %s\n\t\t\tPassword - %s\n",ptr->f_name,ptr->l_name,ptr->phn_no,ptr->address,ptr->email_id,ptr->dob,ptr->father_name,ptr->passwd);
	while(1)
	{
		printf("\n\t\t\tEnter your First Name-  ");
		scanf("%s",ptr->f_name);
		if(check_alpha(ptr->f_name))
		{
			printf("\n\t\t\tName should contain only characters\n");
			continue;
		}
		else 
		{
			break;
		}
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Last Name-  ");
		scanf("%s",ptr->l_name);
		if(check_alpha(ptr->l_name))
		{
			printf("\n\t\t\tName should contain only characters\n");
			continue;
		}
		else 
		{
			break;
		}
	}

	while(1)
	{
		printf("\n\t\t\tEnter your Phone Number-  ");
		scanf("%s",ptr->phn_no);
		if(strlen(ptr->phn_no) != 10)
		{
			printf("\n\t\t\tPhone number must be of 10 digits please try again...\n");
			continue;
		}
		if(check_digits(ptr->phn_no))
		{
			printf("\n\t\t\tPhone number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Address-  ");
		scanf("%s",ptr->address);
		if(strlen(ptr->address)>50)
		{
			printf("\n\t\t\tInvalid Length \n");
			continue;
		}
		else
			break;
	}

	while(1)
	{

		printf("\n\t\t\tEnter your E-mail Id-  ");
		scanf("%s",ptr->email_id);
		int ap,dp;
		char emailid[20];
		strcpy(emailid,ptr->email_id);
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
			printf("\n\t\t\tInvalid Email-Id\n");
	}
	while(1)
	{
		int dd,mm,yy;
		printf("\n\t\t\tEnter date date of birth-  ");
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
		scanf("%s",ptr->father_name);
		if(check_alpha(ptr->father_name))
		{
			printf("\n\t\t\tFather Name should contain only characters\n");
			continue;
		}
		else 
		{
			break;
		}
	}
	printf("\n-------------------------Customer Details After Editing------------------------\n");
	printf("\n\t\t\tAfter Editing the details are :-\n\t\t\tFirst Name - %s\n\t\t\tLast Name - %s\n\t\t\tPhone NUmber - %s\n\t\t\tAddress - %s\n\t\t\tEmail Id - %s\n\t\t\tDate of Birth - %s\n\t\t\tFather Name - %s\n\t\t\tPassword - %s\n",ptr->f_name,ptr->l_name,ptr->phn_no,ptr->address,ptr->email_id,ptr->dob,ptr->father_name,ptr->passwd);
	system("read a");

	return EXIT_SUCCESS;

}
/**************************************************************************
 * *FILENAME      : delete_data
 *
 * *DESCRIPTION   : This function deletes the account of the customer.
 *
 * *RETURNS       : No return
 ***************************************************************************/
int delete_data()
{
	cr *ptr,*prev;
	system("clear");
	if(!start)
	{
		printf("\n\t\t\tEmpty List\n");
		return EXIT_FAILURE;
	}
	char acc_nmb[9];

	while(1)
	{
		printf("\n\t\t\tEnter Account number for deleting-  ");
		scanf("%s",acc_nmb);
		if(strlen(acc_nmb) != 8)
		{
			printf("\n\t\t\tAccount number must be of 8 digits please try again...\n");
			continue;
		}
		if(check_digits(acc_nmb))
		{
			printf("\n\t\t\ttAccount number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}
	if(strcmp(acc_nmb,start->account_no)==0)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && strcmp(ptr->account_no,acc_nmb)!=0;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\n\t\t\tAadhar number %s not foundfor deletion \n",acc_nmb);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);
	}
	printf("\n\t\t\tAccount Deleted Successfully\n");
	system("read a");
	return EXIT_SUCCESS;
}
/***********************************************************************************
 * *FILENAME      : view_data
 *
 * *DESCRIPTION   : This function displays the details of the account to the customer.
 *
 * *RETURNS       : No return
 ************************************************************************************/
int view_data()
{
	cr *ptr;
	system("clear");
	int i=1;
	if(!start)
	{
		printf("\n\t\t\tEmpty List\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		printf("\n\t\t\t\tRecord %d",i);
		printf("\nFirst Name :   %s\t\t\t\t\tLast Name :   %s\nFather Name :    %s\t\t\t\t\tAddress :    %s\nEmail Id :    %s\t\t\t\tAccount Type :  %s\nRD Number : %s\t\t\t\t\t\tFD Number :  %s\nPassword :   %s\t\t\t\tAccount Number : %s\nAadhar Number :  %s\t\t\t\tDOB :       %s\nPhone Number :  %s\t\t\t\tBalance :   %.2lf\nRD Balance :   %.lf\t\t\t\t\tFD Balance :   %.2lf\n",ptr->f_name,ptr->l_name,ptr->father_name,ptr->address,ptr->email_id,ptr->account_type,ptr->rd_no,ptr->fd_no,ptr->passwd,ptr->account_no,ptr->aadhar_no,ptr->dob,ptr->phn_no,ptr->balance,ptr->rd_bal,ptr->fd_bal);
		i=i+1;
	}
	printf("\n");
	system("read a");
	return EXIT_SUCCESS;
}

int report_min_bal()
{
	cr *ptr;
	int n=0;
	system("clear");
	printf("\n-------------------------REPORT MINIMUM BALANCE-------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		if(ptr->balance < 500)
		{
			printf("\n\t\t\tYour account %s  has minimum balance %.2lf\n",ptr->account_no,ptr->balance);
			n=n+1;
		}
	}
	if(n>=1)
	{
		printf("\n\t\t\tRemainder is sent successfully\n");
	}
	else
	{
		printf("\n\t\t\tNo records found with minimum balance\n");
	}
	system("read a");
	return EXIT_SUCCESS;
}

/******************************************************************************************
 * *FILENAME      : daily_trans
 *
 * *DESCRIPTION   : This function displays the daily transactions of the customers to admin.
 *
 * *RETURNS       : No return
 ******************************************************************************************/
int daily_trans()
{
	tr *ptr1;
	char date1[11];
	system("clear");
	while(1)
	{
		int dd,mm,yy;
		printf("\n\t\t\tEnter date DD MM YYYY format-  ");
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
					printf("\n\t\t\tDay is Invalid.\n");
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
		sprintf(date1,"%d/%d/%d",dd,mm,yy);
		break;
	}
	printf("\n\t Account No \t First Name \t Date\t\tDeposited \t Withdrawn \t Balance \n");
	for(ptr1=start2;(ptr1);ptr1=ptr1->next)
	{
		if(strcmp(date1,ptr1->date)==0)
		{
			printf("\n %s \t %s \t %s\t\t%.2lf \t %.2lf \t %.2lf \n",ptr1->acc_no,ptr1->fname,ptr1->date,ptr1->withdraw,ptr1->deposit,ptr1->balance);
		}
	}
	system("read a");
	return EXIT_SUCCESS;
}

