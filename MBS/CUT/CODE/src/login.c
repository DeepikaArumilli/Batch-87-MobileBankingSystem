/***************************************************************************************************
 * *FILE NAME        :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *Revision History :
 *  
 *    Date                           Name                                    Reason
 *
 *                                  ------                                   --------
 * ************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include <ctype.h>
#include <math.h>

#include "mbs_header.h"


int view_acc()
{
	cr *ptr;
	char acc[9];
	char pass[16];
	system("clear");
	if(!start)
	{
		printf("\n\t\t\tEmpty List\n");
		return EXIT_FAILURE;
	}
	while(1)
	{

		printf("\n\t\t\tEnter Account Number to view the account-  ");
		scanf("%s",acc);
		if(strlen(acc)!=8)
		{
			printf("\n\t\t\tAccount number should be of 8 digits\n");
			continue;
		}
		if(check_digits(acc))
		{
			printf("\n\t\t\tAccount number should contaion only digits\n");
			continue;
		}
		break;
	}

	for(ptr=start;(ptr) && strcmp(acc,ptr->account_no)!=0;ptr=ptr->next);
	if(!ptr)
	{
		printf("\n\t\t\tInvalid account number\n");
	}
	int i=1;
	printf("\n\t\t\tEnter the password-  ");
	scanf("%s",pass);
	if(ptr)
	{
		i=strcmp(ptr->passwd,pass);
	}
	if(i==0)
	{
		printf("\n-------------------------Customer Details-------------------------\n");
		printf("\n\t\t\tFirst Name : \t%s\n\t\t\tLast Name :\t%s\n\t\t\tFather Name : \t%s\n\t\t\tAddress :   \t%s\n\t\t\tEmail Id :   \t%s\n\t\t\tAccount Type : %s\n\t\t\tRD Number :  \t%s\n\t\t\tFD Number :  \t%s\n\t\t\tPassword :   \t%s\n\t\t\tAccount Number :%s\n\t\t\tAadhar Number :%s\n\t\t\tDate Of Birth :%s\n\t\t\tPhone Number : \t%s\n\t\t\tBalance Amount :%.2lf\n\t\t\tRD Balance : \t%.2lf\n\t\t\tFD Balance : \t%.2lf\n",ptr->f_name,ptr->l_name,ptr->father_name,ptr->address,ptr->email_id,ptr->account_type,ptr->rd_no,ptr->fd_no,ptr->passwd,ptr->account_no,ptr->aadhar_no,ptr->dob,ptr->phn_no,ptr->balance,ptr->rd_bal,ptr->fd_bal);
		system("read a");
	}
	else
	{
		printf("\n\t\t\tInvalid Password");
	}

	printf("\n");
	return EXIT_SUCCESS;

}

/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/

int open_rd()
{
	(void)system("clear");
	cr *ptr;
	double bal;
	char acc_nmb[9];
	while(1)
	{
		printf("\n-------------------------Opening RD Account-------------------------\n");
		printf("\n\t\t\tEnter Account Number-  ");
		scanf("%s",acc_nmb);
		for(ptr=start;(ptr) && strcmp(acc_nmb,ptr->account_no)!=0;ptr=ptr->next);
		if(!ptr)
		{
			printf("\n\t\t\tInvalid Account Number");
			system("clear");
			continue;	
		}
		break;
	}
	if(ptr)
	{

		long int rd_nmb = rand_no();
		sprintf(ptr->rd_no, "%ld" , rd_nmb);
		printf("\n\t\t\tRD Account Opened Successfully\n");
		printf("\n\t\t\tEnter the amount-  ");
		scanf("%lf",&bal);
		ptr->rd_bal=bal;
	}
	return EXIT_SUCCESS;

}

/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/



int open_fd()
{
	cr *ptr;
	double bal;
	char acc_nmb[9];
	system("clear");
	while(1)
	{
		printf("\n-------------------------Opening FD Account-------------------------\n");
		printf("\n\t\t\tEnter Account Number-  ");
		scanf("%s",acc_nmb);
		for(ptr=start;(ptr) && strcmp(acc_nmb,ptr->account_no)!=0;ptr=ptr->next);
		if(!ptr)
		{
			printf("\n\t\t\tInvalid Account Number\n");
			continue;	
		}
		break;
	}
	if(ptr)
	{

		long int fd_nmb = rand_no();
		sprintf(ptr->fd_no, "%ld" , fd_nmb);
		printf("\n\t\t\tFD Account Opened Successfully\n");
		printf("\n\t\t\tEnter the Amount-  ");
		scanf("%lf",&bal);
		ptr->fd_bal=bal;
	}
	return EXIT_SUCCESS;

}
/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/

int interest_rate()
{
	int choice=0;
	system("clear");
	printf("\n-------------------------Annual Interest Rates-------------------------\n");	
	printf("\n\t\t\t1. RD Account \n\t\t\t2. FD Account \n\t\t\t3. Saving Account \n");
	printf("\n\t\t\tEnter your Choice-  ");
	scanf("%d",&choice);
	while(choice !=4)
	{
		switch(choice)
		{
			case 1: 
				printf("\n\t\t\tInterest Rate of RD Account ----   8.0 \n");
				break;
			case 2:
				printf("\n\t\t\tInterest Rate of FD Account ----   6.0 \n");
				break;
			case 3: 
				printf("\n\t\t\tInterest Rate of Saving ACcount -- 3.0 \n");
				break;
			case 4:
				break;
			default:
				printf("\n\t\t\tInvalid choice \n");
		}
		break;

	}
	system("read a");
	return EXIT_SUCCESS;
}
/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/

int close_rd()
{
	double balance;
	cr *ptr;
	char rd[9];
	system("clear");
	printf("\n-------------------------Closing RD Account-------------------------\n");	
	printf("\n\t\t\tEnter RD Account Number-  ");
	scanf("%s",rd);
	for(ptr=start;(ptr) && strcmp(ptr->rd_no,rd)!=0;ptr=ptr->next);

	if(!ptr)
	{
		printf("\n\t\t\tRD Account is Not Found\n");
		return EXIT_FAILURE;
	}
	if(ptr)
	{
		strcpy(ptr->rd_no,"NA");
		balance=ptr->rd_bal;
		ptr->balance=balance+ptr->balance;
		ptr->rd_bal=0;
		printf("\n\t\t\tRD Account is Successfully Closed\n");
	}
	system("read a");
	return EXIT_SUCCESS;
}
/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/
int close_fd()
{
	double balance;
	cr *ptr;
	char fd[9];
	system("clear");
	printf("\n-------------------------Closing FD Account-------------------------\n");	
	printf("\n\t\t\tEnter FD Account Number-  ");
	scanf("%s",fd);
	for(ptr=start;(ptr) && strcmp(ptr->fd_no,fd)!=0;ptr=ptr->next);
	if(!ptr)
	{
		printf("\n\t\t\tFD Account is Not Found\n");
		return EXIT_FAILURE;
	}
	if(ptr)
	{
		strcpy(ptr->fd_no,"NA");
		balance=ptr->fd_bal;
		ptr->balance=ptr->balance+balance;
		ptr->fd_bal=0;
		printf("\n\t\t\tFD Account is Successfully Closed\n");
	}
	system("read a");
	return EXIT_SUCCESS;
}

/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/

int req_chequebook()
{
	cr *ptr;
	char acc_no[9];
	system("clear");
	while(1)
	{
		printf("\n-------------------------Requesting Cheque Book-------------------------\n");	
		printf("\n\t\t\tEnter Account Number to request for chequebook-  ");
		(void)scanf("%s",acc_no);
		int len = strlen(acc_no);
		if(len != 8)
		{
			printf("\n\t\t\tAccount Number must be of 8 digits please try again...\n");
			continue;
		}
		if(check_digits(acc_no))
		{
			printf("\n\t\t\tAccount number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}
	for(ptr=start;(ptr) && strcmp(ptr->account_no,acc_no)!=0 ; ptr=ptr->next);
	if(ptr)
	{
		printf("\n\t\t\tChequebook Request has been Submitted\n");
	}
	system("read a");
	return EXIT_SUCCESS;
}

/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/

int edit_details()
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
			printf("\n\t\t\tAccount Number must be of 8 digits please try again...\n");
			continue;
		}
		if(check_digits(macc_no))
		{
			printf("\n\t\t\tAccount Number should contain only digits...\n");
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
		printf("\n\t\t\tAccount Number %s not found\n",macc_no);
		return EXIT_FAILURE;
	}
	printf("\n-------------------------Customer Details Before Editing-------------------------\n");
	printf("\n\t\t\tFirst Name : \t%s\n\t\t\tLast Name :\t%s\n\t\t\tFather Name : \t%s\n\t\t\tAddress :   \t%s\n\t\t\tEmail Id :   \t%s\n\t\t\tPassword :   \t%s\n\t\t\tDate Of Birth :%s\n\t\t\tPhone Number : \t%s\n\t\t\t\n",ptr->f_name,ptr->l_name,ptr->father_name,ptr->address,ptr->email_id,ptr->passwd,ptr->dob,ptr->phn_no);
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
		(void)scanf("%s",ptr->l_name);
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
			printf("\n\t\t\tPhone Number must be of 10 digits please try again...\n");
			continue;
		}
		if(check_digits(ptr->phn_no))
		{
			printf("\n\t\t\tPhone Number should contain only digits\n");
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
			printf("\n\t\t\tInvalid Email Id\n");
	}

	while(1)
	{
		int dd,mm,yy;
		printf("\n\t\t\tEnter date DD MM YYYY format:  ");
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
		sprintf(ptr->dob,"%d/%d/%d",dd,mm,yy);

		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter your Father's Name-  ");
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
	printf("\n-------------------------Customer Details After Editing-------------------------\n");
	printf("\n\t\t\tFirst Name : \t%s\n\t\t\tLast Name :\t%s\n\t\t\tFather Name : \t%s\n\t\t\tAddress :   \t%s\n\t\t\tEmail Id :   \t%s\n\t\t\tPassword :   \t%s\n\t\t\tDate Of Birth :%s\n\t\t\tPhone Number : \t%s\n\t\t\t\n",ptr->f_name,ptr->l_name,ptr->father_name,ptr->address,ptr->email_id,ptr->passwd,ptr->dob,ptr->phn_no);
	(void)system("read a");

	return EXIT_SUCCESS;

}

/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/
int deposit()
{
	cr *ptr1;
	tr *new;
	system("clear");
	double amount;
	printf("\n\t------------------DEPOSIT------------------\n");
	while(1)
	{
		char acc_nmb[9];
		printf("\n\t\t\tEnter Account Number-  ");
		scanf("%s",acc_nmb);
		for(ptr1=start;(ptr1) && strcmp(acc_nmb,ptr1->account_no)!=0;ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\n\t\t\tInvalid Account Number\n");
			continue;	
		}
		break;
	}
	if(ptr1)
	{
		printf("\n\t\t\tEnter Deposit Amount:  ");
		scanf("%lf",&amount);
		if(amount<=0)
			printf("\n\t\t\tAmount deposited should be greater than zero\n");

		else
		{

			if((new=(tr *)calloc(1,sizeof(tr)))==NULL)
			{
				printf("\n\t\t\tInvalid Memory\n");
				return EXIT_FAILURE;
			}
			while(1)
			{
				int dd,mm,yy;
				printf("\n\t\t\tEnter Date  DD MM YYYY format: ");
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
				sprintf(new->date,"%d/%d/%d",dd,mm,yy);
				break;
			}
			strcpy(new->acc_no,ptr1->account_no);
			strcpy(new->fname,ptr1->f_name);
			ptr1->balance = ptr1->balance+ amount;
			printf("\n\t\t\tYou have Deposited rs. %.2lf\n",amount);
			printf("\n\t\t\tYour Current Balance is rs.  %.2lf\n",ptr1->balance);
			new->deposit=amount;
			new->withdraw=0;
			new->balance=ptr1->balance;
		}

	}
	if(!start2)
	{
		start2=last=new;
		new->next=NULL;
	}
	if(start2)
	{
		last->next=new;
		last=new;
		new->next=NULL;
	}
	free(new);
	system("read a");
	return EXIT_SUCCESS;

}
/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/
int withdraw()
{
	cr *ptr1;
	tr *new;
	(void)system("clear");
	double amount;
	char acc_nmb[9];
	char pass[16];
	printf("\n\t------------------WITHDRAW------------------\n");
	while(1)
	{
		printf("\n\t\t\tEnter Account Number-  ");
		scanf("%s",acc_nmb);
		for(ptr1=start;(ptr1) && strcmp(acc_nmb,ptr1->account_no)!=0;ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\n\t\t\tInvalid Account Number\n");
			continue;	
		}
		break;
	}
	printf("\n\t\t\tEnter the Password-  ");
	scanf("%s",pass);
	int i=1;
	if(ptr1)
	{
		i = strcmp(ptr1->passwd,pass);
		if(i==0)
		{
			while(1)
			{
				printf("\n\t\t\tEnter Withdrawl Amount-  ");
				scanf("%lf",&amount);
				if(ptr1->balance < amount)
				{
					printf("\n\t\t\t --------\n");
					continue;
				}
				break;
			}
			if(amount>ptr1->balance)
				printf("\n\t\t\tSorry Insufficient Balance");
			else 
			{
				if(ptr1->balance > amount)
				{
					if((new=(tr *)calloc(1,sizeof(tr)))==NULL)
					{
						printf("\n\t\t\tInvalid Memory\n");
						return EXIT_FAILURE;
					}
					while(1)
					{
						int dd,mm,yy;
						printf("\n\t\t\tEnter Date DD MM YYYY format-  ");
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
						sprintf(new->date,"%d/%d/%d",dd,mm,yy);
						break;
					}
					if(ptr1->balance < amount)
					{
						printf("\n\t\t\tInsufficient balance\n");
					}
					strcpy(new->acc_no,ptr1->account_no);
					strcpy(new->fname,ptr1->f_name);
					ptr1->balance = ptr1->balance - amount;
					printf("\n\t\t\tYou have Withdrawn rs. %.2lf\n",amount);
					new->deposit=0;
					new->withdraw=amount;
					new->balance=ptr1->balance;
				}	
				printf("\n\t\t\tYour Current Balance is- %.2lf\n",ptr1->balance);
			}
		}
		else
		{
			printf("\n\t\t\tInvalid Password\n");
		}

	}
	if(!start2)
	{
		start2=last=new;
		new->next=NULL;
	}
	if(start2)
	{
		last->next=new;
		last=new;
		new->next=NULL;
	}
	free(new);
	system("read a");
	return EXIT_SUCCESS;

}
/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/
int trans_hist()
{
	tr *ptr;
	char acc_nmb[9];
	system("clear");
	printf("\n-------------------------TRANSACTION HISTORY-------------------------\n");
	printf("\n\t\t\tEnter Account Number-  ");
	(void)scanf("%s",acc_nmb);
	printf("\nFirst Name\t Date\t\tAccount Number \t Balance \t Withdraw \t Deposit\n");
	for(ptr=start2;(ptr);ptr=ptr->next)
	{
		if(strcmp(ptr->acc_no,acc_nmb)==0)
		{
			printf("\n%s\t %s\t\t%s \t %.2lf \t %.2lf \t %.2lf\n",ptr->fname,ptr->date,ptr->acc_no,ptr->balance,ptr->withdraw,ptr->deposit);
		}
	}
	system("read a");
	return EXIT_SUCCESS;
}
/***************************************************************************************************
 * *FUNCTION NAME    :
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/
int last_10_trans()
{
	tr *ptr1;
	char acc[9];
	int count=0,n=0,i=1;
	system("clear");
	printf("\n-------------------------LAST 10 TRANSACTIONS-------------------------\n");
	while(1)
	{
		printf("\n\t\t\tEnter Account Number-  ");
		scanf("%s",acc);
		if(strlen(acc) != 8)
		{
			printf("\n\t\t\tAccount Number must be of 8 digits please try again...\n");
			continue;
		}
		if(check_digits(acc))
		{
			printf("\n\t\t\tAccount Number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}
	printf("\n Account No \t First Name \t Date\t\tDeposited \t Withdrawn \t Balance \n");
	for(ptr1=start2;(ptr1);ptr1=ptr1->next)
	{
		if(strcmp(ptr1->acc_no,acc)==0)
		{
			count=count+1;
		}
	}
	n=count-10;
	for(ptr1=start2;(ptr1);ptr1=ptr1->next)
	{
		if(strcmp(ptr1->acc_no,acc)==0)
		{
			if(i<n)
			{
				i=i+1;
			}
			else
			{
				printf("\n %s \t %s \t %s\t\t%.2lf \t %.2lf \t %.2lf \n",ptr1->acc_no,ptr1->fname,ptr1->date,ptr1->withdraw,ptr1->deposit,ptr1->balance);
			}
		}
	}
	system("read a");
	return EXIT_SUCCESS;


}

/***************************************************************************************************
 * *FUNCTION NAME    : transfer
 *
 *
 * *DESCRIPTION      :
 *
 *
 * *RETURNS           :
 *
 *
 * ************************************************************************************************/
int transfer()
{
	cr *tptr,*tptr1;
	tr *new;
	double amt;
	system("clear");
	char source_acc[9],dest_acc[9],date[11];
	printf("\n\t------------------TRANSFER------------------\n");
	while(1)
	{

		printf("\n\t\t\tEnter Account Number from which money is transferred-  ");
		scanf("%s",source_acc);
		if(strlen(source_acc)!=8)
		{
			printf("\n\t\t\tAccount Number should be of 8 digits\n");
			continue;
		}
		if(check_digits(source_acc))
		{
			printf("\n\t\t\tAccount Number should contaion only digits\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\n\t\t\tEnter Account Number to which money is transferred-  ");
		scanf("%s",dest_acc);

		if(strlen(dest_acc)!=8)
		{
			printf("\n\t\t\tAccount Number should be of 8 digits\n");
			continue;
		}
		if(check_digits(dest_acc))
		{
			printf("\n\t\t\tAccount Number should contaion only digits\n");
			continue;
		}

		if(strcmp(source_acc,dest_acc)==0)
		{
			printf("\n\t\t\tSource and Destination Accounts are same...check again and try...\n");
			continue;
		}
		for(tptr=start;(tptr) && strcmp(source_acc,tptr->account_no)!=0;tptr=tptr->next);
		for(tptr1=start;(tptr1) && strcmp(dest_acc,tptr1->account_no)!=0;tptr1=tptr1->next);
		if(!tptr)
		{
			printf("\n\t\t\tInvalid Account Number please try again....\n");
			continue;
		}
		if(!tptr1)
		{
			printf("\n\t\t\tInvalid Account Number please try again....\n");
			continue;
		}
		break;
	}
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
		sprintf(date,"%d/%d/%d",dd,mm,yy);
		break;
	}

	printf("\n\t\t\tEnter Amount to Transfer-  ");
	scanf("%lf",&amt);
	if(tptr->balance<amt)
		printf("\n\t\t\tYou do not have sufficient balance to transfer...try again\n");
	if(tptr->balance > amt)
	{
		tptr->balance=tptr->balance-amt;
		tptr1->balance=tptr1->balance+amt;
		printf("\n\t\t\tAmount Transferred successfully\n\t\t\tYou have transferred %.2lf amount to %s successfully\n",amt,dest_acc);
		printf("\n\t\t\tThe remaining Balance is rs. %.2lf\n",tptr->balance);
		if((new=(tr *)calloc(1,sizeof(tr)))==NULL)
		{
			printf("\n\t\t\tInvalid Memory\n");
			return EXIT_FAILURE;
		}
		strcpy(new->acc_no,tptr->account_no);
		strcpy(new->fname,tptr->f_name);
		new->balance = tptr->balance;
		strcpy(new->date,date);
		new->deposit=0;
		new->withdraw=amt;
		if(!start2)
		{
			start2=last=new;
			new->next=NULL;
		}
		if(start2)
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		if((new=(tr *)calloc(1,sizeof(tr)))==NULL)
		{
			printf("\n\t\t\tInvalid Memory\n");
			return EXIT_FAILURE;
		}
		strcpy(new->acc_no,tptr1->account_no);
		strcpy(new->fname,tptr1->f_name);
		new->balance = tptr1->balance;
		strcpy(new->date,date);
		new->deposit=amt;
		new->withdraw=0;
		if(!start2)
		{
			start2=last=new;
			new->next=NULL;
		}
		if(start2)
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
	}
	free(new);
	system("read a");
	return EXIT_SUCCESS;

}

//Random Number Generation
static long rand_no()
{
	srand(time(NULL));
	long int acc = (rand() % (99999999 + 1));
	return acc;
}

//Alphabet Checking Function
int check_alpha(char *a)
{
	while(*a !='\0')
	{
		if(!(isalpha(*a)))
		{
			return 1;
		}
		a++;
	}
	return 0;
}

//Digits Checking Function
int check_digits(char *a)
{ 
	char *p;
	for(p=a;*p!='\0';p++)
	{
		if(!isdigit(*p))
			return 1;
	}
	return 0;
}
