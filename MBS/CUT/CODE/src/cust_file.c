/**************************************************************************************************
 * *FILENAME	      : cust_file.c
 *
 * *DESCRITION        : This file defines the function that opens the file and returns the address
 * 			of file and stores in file type pointer.
 *
 *
 * Revision History   :	       
 *
 * 	Date			Name			Reason
 *
 *    21 oct 2022		----			-----
 *
 *
 *******************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mbs_header.h"
/*****************************************************************************************************
 * *FUNCTION NAME : file_list_cust 
 *
 * *DESCRIPTION   : This function allocate memory for the customer file to open and read the file 
 * 		    from beginning till end of file and put each customer into the list.
 *
 * *RETURNS       : No Returns 
 *
 *
 *
 ******************************************************************************************************/
int file_list_cust()
{
	FILE *p;
	cf c1;
	cr *new,*last;
	if((p=fopen("customer_database","rb"))==NULL)
	{
		printf("\n File is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&c1,sizeof(cf),1,p);
	while(!feof(p))
	{
		if((new=(cr *)calloc(1,sizeof(cr)))==NULL)
		{
			printf("\n Memory allocation is failed\n");
			return EXIT_FAILURE;
		}
		strcpy(new->aadhar_no,c1.aadhar_no);
		strcpy(new->f_name,c1.f_name);
		strcpy(new->l_name,c1.l_name);
		strcpy(new->phn_no,c1.phn_no);
		strcpy(new->address,c1.address);
		strcpy(new->email_id,c1.email_id);
		strcpy(new->dob,c1.dob);
		strcpy(new->father_name,c1.father_name);
		strcpy(new->account_type,c1.account_type);
		strcpy(new->account_no,c1.account_no);
		strcpy(new->fd_no,c1.fd_no);
		strcpy(new->rd_no,c1.rd_no);
		strcpy(new->passwd,c1.passwd);
		new->fd_bal = c1.fd_bal;
		new->rd_bal = c1.rd_bal;
		new->balance = c1.balance;
		if(!start)
		{
			start=last=new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&c1,sizeof(cf),1,p);
	}
	fclose(p);
	return EXIT_SUCCESS;
}
/*****************************************************************************
 * *FUNCTION NAME : list_file_cust 
 *
 * *DESCRIPTION   : This function is used to write customer data into the file
 * 		    by traversing the list.
 *
 * *RETURNS       : No Returns 
 *
 *
 *
 *******************************************************************************/
int list_file_cust()

{

	FILE *p;
	cf c2;
	cr *ptr;
	if(!start)
	{
		printf("\n List is empty \n");
		return EXIT_FAILURE;
	}
	if((p=fopen("customer_database","wb"))==NULL)
	{
		printf("\n File is not there to write \n");
		return EXIT_FAILURE;
	}
	for(ptr=start ; ptr!=NULL ;ptr=ptr->next)
	{

		strcpy(c2.aadhar_no,ptr->aadhar_no);
		strcpy(c2.f_name,ptr->f_name);
		strcpy(c2.l_name,ptr->l_name);
		strcpy(c2.phn_no,ptr->phn_no);
		strcpy(c2.address,ptr->address);
		strcpy(c2.email_id,ptr->email_id);
		strcpy(c2.dob,ptr->dob);
		strcpy(c2.father_name,ptr->father_name);
		strcpy(c2.account_type,ptr->account_type);
		strcpy(c2.account_no,ptr->account_no);
		strcpy(c2.fd_no,ptr->fd_no);
		strcpy(c2.rd_no,ptr->rd_no);
		strcpy(c2.passwd,ptr->passwd);
		c2.fd_bal = ptr->fd_bal;
		c2.rd_bal = ptr->rd_bal;
		c2.balance = ptr->balance;
		fwrite(&c2,sizeof(cf),1,p);
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		free(ptr);
	}
	fclose(p);
	return EXIT_SUCCESS;
}
