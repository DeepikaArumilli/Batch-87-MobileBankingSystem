/***************************************************************************************************************
 * FILENAME         : trans_file
 *
 *
 * DESCRIPTION      : This file defines the function that opens the file and returns the address of the file and
 *                    stores in file pointer.
 *
 *
 * Revision History :
 *
 *
 *   Date	                              Name 		       Reason
 *                                              
 *21 oct 2022                                ------                   --------
 *
 * *************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mbs_header.h"

/***************************************************************************************************
 * *FUNCTION NAME    : file_list_trans
 *
 *
 * *DESCRIPTION      : This function allocates memory for the transaction file to open and read the file 
 * 		       from beginning till end of file and put each transaction into the list
 *
 *
 * *RETURNS         : No Returns
 *******************************************************************************************************/
int file_list_trans()
{
	FILE *p;
	trf r1;
	tr *new;
	if((p=fopen("transaction_database","rb"))==NULL)
	{
		printf("\n File is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&r1,sizeof(trf),1,p);
	while(!feof(p))
	{
		if((new=(tr *)calloc(1,sizeof(tr)))==NULL)
		{
			printf("\n Memory allocation is failed\n");
			return EXIT_FAILURE;
		}

		strcpy(new->fname,r1.fname);
		strcpy(new->date,r1.date);
		strcpy(new->acc_no,r1.acc_no);
		new->deposit=r1.deposit;
		new->withdraw=r1.withdraw;
		new->balance=r1.balance;
		if(!start2)
		{
			start2=last=new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&r1,sizeof(trf),1,p);
	}
	fclose(p);
	return EXIT_SUCCESS;

}
/***************************************************************************************************
 * *FUNCTION NAME    : list_file_trans
 *
 *
 * *DESCRIPTION      : This function is used to write transaction data into the file
 * 		       by traversing the list.
 *
 *
 * *RETURNS         : No Returns
 *
 *
 * **************************************************************************************************/

int list_file_trans()
{
	FILE *p;
	trf r2;
	tr *fptr;
	if(!start2)
	{
		printf("\n List is empty \n");
		return EXIT_FAILURE;
	}
	if((p=fopen("transaction_database","wb"))==NULL)
	{
		printf("\n File is not there to write from\n");
		return EXIT_FAILURE;
	}
	for(fptr=start2 ; fptr!=NULL ; fptr = fptr->next)
	{
		strcpy(r2.fname,fptr->fname);
		strcpy(r2.date,fptr->date);
		strcpy(r2.acc_no,fptr->acc_no);
		r2.deposit=fptr->deposit;
		r2.withdraw=fptr->withdraw;
		r2.balance=fptr->balance;
		fwrite(&r2,sizeof(trf),1,p);
	}
	for(fptr=start2;(fptr);fptr=fptr->next)
	{
		free(fptr);
	}
	fclose(p);
	return EXIT_SUCCESS;

}
