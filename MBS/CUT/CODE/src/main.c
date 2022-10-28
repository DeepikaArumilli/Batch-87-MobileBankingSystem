/****************************************************************************
 * *FILENAME        :main.c
 *
 * *DESCRIPTION     :This file defines the functions that consists of various
 * 		     subfunctions to perform certain operations
 *
 *
 * Revision History :
 *
 *    Date                         Name				Reason

 * 20 Oct 2022                    -----                         -------
 *
 * **************************************************************************/
#include <stdio.h>
#include<string.h>

// Function Header Files 
#include "../src/login.c"
#include "../src/cust_manage.c"
#include "../src/reg_process.c"


// File handling Function

#include "../src/cust_file.c"
#include "../src/trans_file.c"

// Header file 
#include "../Header/mbs_header.h"

/*void gotoxy(int x, int y)
  {
  printf("%c[%d;%df", 0x1B, x, y);
  }*/


/****************************************************************************
 * *FILENAME        :main
 *
 * *DESCRIPTION     :This function calls the other functions to perform various
 *                   operations by taking choice option from the user.
 *
 * *RETURNS         :cust_manage function
 * 	             login function function
 * 		     reg_process function
 * 		     exit -exit the main function
 *
 * **************************************************************************/

int main()
{
	start = NULL;
	start2 = NULL; 

	int choice=0;

	system("clear");

	file_list_cust();
	file_list_trans();

	while(choice!=4)
	{
		printf("\n\t\t-------------------------MOBILE BANKING SYSTEM------------------------\n");
		printf("\n\t\t\t\t\t1. Banker Corner \n\t\t\t\t\t2. Login Corner (Existing User) \n\t\t\t\t\t3. New User Registration \n\t\t\t\t\t4. Exit\n");
	printf("\n\t\t\t\t\tEnter your choice-  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:cust_manage();
			       break;
			case 2:login();
			       break;
			case 3:reg_process();
			       break;
			case 4:break;
			default:printf("\n\t\t\t\t\tInvalid Choice\n");
		}
	}
	system("read a");

	list_file_cust();
	list_file_trans();
	system("clear");

	return EXIT_SUCCESS;
}
/**********************************************************************************************************
 * *FILENAME        :cust_manage
 *
 * *DESCRIPTION     :This function is used to manage customer details by taking choice option from the user.
 *
 * *RETURNS         :add_data	    - adding customer details
 * 		     edit_data 	    - editing customer details
 *                   delete_data    - deleting customer details
 *                   view_data      - viewing customer details
 *                   report_min_bal - reporting minimum balance
 *                   daily_trans    - viewing daily transactions
 *
 *
 * ********************************************************************************************************/

int cust_manage()
{
	int choice=0;

	system("clear");

	while(choice!=7)
	{
		printf("\n\t\t-------------------------BANKER MANAGEMENT------------------------\n");
		printf("\n\t\t\t\t\t1. Add Data \n\t\t\t\t\t2. Edit Data \n\t\t\t\t\t3. Delete Data \n\t\t\t\t\t4. View Data \n\t\t\t\t\t5. Report Minimum Balance \n\t\t\t\t\t6. View Daily Transactions \n\t\t\t\t\t7. Go Back to Main menu\n");
		printf("\n\t\t\t\t\tEnter your choice-  ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:add_data();
			       break;
			case 2:edit_data();
			       break;
			case 3:delete_data();
			       break;
			case 4:view_data();
			       break;
			case 5:report_min_bal();
			       break;
			case 6:daily_trans();
			       break;
			case 7:break;
			default:printf("\n\t\t\t\t\tInvalid Choice\n");
		}

		system("clear");
	}
	return EXIT_SUCCESS;
}

/********************************************************************************************************
 * *FILENAME        :login
 *
 * *DESCRIPTION     :Using this function customer can login into their account.
 *
 * *RETURNS         :view_acc      - customer can view their account details
 * 		     open_fd       - to open fixed deposit account
 * 		     open_rd       - to open recurring deposit account
 * 		     interest_rate - to get the interest rate
 * 		     close_rd      - to close recurring deposit account
 * 		     close_fd      - to close fixed deposit account
 * 		     req_chequebook- to request cheque book
 * 		     edit_details  - to edit customer details
 * 		     deposit       - to deposit amount
 * 		     withdraw      - to withdraw amount
 * 		     trans_hist    - to view the transaction history
 * 		     last_10_trans - to view last 10 transactions
 * 		     transfer      - to transfer money from one account to another account within same bank
 *
 *
 *
 * ********************************************************************************************************/
int login()
{		
	cr *ptr;
	char acc[9];
	char pass[16];

	system("clear");

	while(1)
	{
		printf("\n\t\t-------------------------Enter Your Login Details------------------------\n");
		printf("\n\t\t\t\t\tEnter the Account Number to login-  ");
		scanf("%s",acc);
		printf("\t\t\t\t\tEnter the password- >>  ");
		scanf("%s",pass);
		int i=1;
		for(ptr=start;(ptr) && strcmp(acc,ptr->account_no)!=0 ;ptr=ptr->next);
		if(!ptr)
		{
			printf("\n\t\t\t\t\tInvalid Account Number or Password\n");
			system("read a");
			system("clear");
			continue;
		}
		if(ptr)
		{
			i = strcmp(pass,ptr->passwd);
		}
		if(i == 0)
		{
			int choice=0;
			while(choice!=14)
			{
				system("clear");

				printf("\n\t\t--------------------------CUSTOMER PROFILE-------------------------\n");
				printf("\n\t\t\t\t\t1. View Account \n\t\t\t\t\t2. Open FD Account \n\t\t\t\t\t3. Open RD Account \n\t\t\t\t\t4. Interest Rates \n\t\t\t\t\t5. Close RD Account \n\t\t\t\t\t6. Close FD Account\n\t\t\t\t\t7. Request Cheque Book \n\t\t\t\t\t8. Change/Update Personal Details \n\t\t\t\t\t9. Deposit  \n\t\t\t\t\t10. Withdraw  \n\t\t\t\t\t11. View Transactions \n\t\t\t\t\t12. View Last 10 Transactions\n\t\t\t\t\t13. Transfer Amount \n\t\t\t\t\t14. Go Back to Main menu\n");
				printf("\n\t\t\t\t\tEnter your choice-  ");
				scanf("%d",&choice);

				switch(choice)
				{
					case 1:view_acc();
					       break;
					case 2:open_fd();
					       break;
					case 3:open_rd();
					       break;
					case 4:interest_rate();
					       break;
					case 5:close_rd();
					       break;
					case 6:close_fd();
					       break;
					case 7:req_chequebook();
					       break;
					case 8:edit_details();
					       break;
					case 9:deposit();
					       break;
					case 10:withdraw();
						break;
					case 11:trans_hist();
						break;
					case 12:last_10_trans();
						break;
					case 13:transfer();
						break;
					case 14:break;

					default:printf("\n\t\t\t\t\tInvalid Choice\n");
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t\t\t\tInvalid Password.....Please try again...\n");

			system("read a");
			system("clear");
		}
	}
	return EXIT_SUCCESS;
}


