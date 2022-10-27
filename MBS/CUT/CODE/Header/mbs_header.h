#ifndef MBS_HEADER_H
#define MBS_HEADER_H
#pragma pack (1)
typedef struct customer
{
	char aadhar_no[13];
	char f_name[20];
	char l_name[20];
	char phn_no[11];
	char address[50];
	char email_id[20];
	char dob[11];
	char father_name[20];
	char account_type[20];
	char account_no[9];
	char fd_no[9];
	char rd_no[9];
	char passwd[16];
	double fd_bal;
	double rd_bal;
	double balance;
	struct customer *next;
}cr;

cr *start; //global variable for customer structure
typedef struct customer_file
{
	char aadhar_no[13];
	char f_name[20];
	char l_name[20];
	char phn_no[11];
	char address[50];
	char email_id[20];
	char dob[11];
	char father_name[20];
	char account_type[20];
	char account_no[9];
	char fd_no[9];
	char rd_no[9];
	char passwd[16];
	double fd_bal;
	double rd_bal;
	double balance;
}cf;


typedef struct transaction
{
	char fname[20];
	char date[11];
	char acc_no[9];
	double balance;
	double deposit;
	double withdraw;
	struct transaction *next;
}tr;

tr *start2,*last;  //global variables for transaction structure

typedef struct transaction_file
{
	char fname[20];
	char date[11];
	char acc_no[9];
	double deposit;
	double withdraw;
	double balance;
}trf;

//functions from main.c

int cust_manage();//This Function gives the details of cutomer  mangement 

int login();      //This function is used to login

int reg_process();//This function is used for new registration


// functions from cust_manage.c

int add_data();

int edit_data();

int delete_data();

int view_data();

int report_min_bal();

int daily_trans();



//functions from login file 

int view_acc();

int open_fd();

int open_rd();

int close_fd();

int close_rd();

int interest_rate();

int req_chequebook();

int edit_details();

int transfer();

int deposit();

int withdraw();

int trans_hist();

int last_10_trans();



//Filehandling functions


int file_list_trans();

int list_file_trans();

int file_list_cust();

int list_file_cust();

//Validation functions


static long rand_no();

static long rand_no1();

int check_alpha(char * );

int check_digits(char * );

/*int check_alpha1(char * );

int check_digits1(char * );

int check_alpha2(char *);

int check_digits2(char *);*/

#endif

