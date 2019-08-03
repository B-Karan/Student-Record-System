#define clear system("cls");
#define newline printf("\n");
void index()
{
	printf("\t\t\tStudent Record System\n");
	printf("\t\tCapital College and Research System\n");
	printf("\t\t\tKathmandu, Nepal");
	newline newline
	printf("1. Add Student Record\n\n");
	printf("2. Search Student Record\n\n");
	printf("3. Modify Student Record\n\n");
	printf("4. Delete Student Record\n\n");
	printf("5. Exit\n");
}
typedef struct{
	char s_name[25];
	int Regno;
	char course[20];
	struct{
		char month[15];
		int day,year;
	}dob;
	int batch;
	char address[25];
	char c_no[15];
	char email[25];
}record;

record read()
{
	record *tem=(record*)malloc(sizeof(record));
	printf("Enter Name :");
	scanf(" %[^\n]",tem->s_name);
	printf("Enter Registration Number :");
	scanf(" %d",&tem->Regno);
	printf("Enter Course :");
	scanf(" %[^\n]",tem->course);
	printf("Enter Birth Year :");
	scanf(" %d",&tem->dob.year);
	printf("Enter Birth Month :");
	scanf(" %s",tem->dob.month);
	printf("Enter Birth day :");
	scanf(" %d",&tem->dob.day);
	printf("Enter Batch No. :");
	scanf(" %d",&tem->batch);
	printf("Enter Permanet Address :");
	scanf(" %[^\n]",tem->address);
	printf("Enter Contact Number :");
	scanf(" %[^\n]",tem->c_no);
	printf("Enter email Id :");
	scanf(" %[^\n]",tem->email);
	return *tem;
	free(tem);
}

void show(record *x)
{
	printf("Name :%s\nRegistration No. :%d\nCourse :%s\nDate of Birth :%dth %s %d\nBatch :%d\nPermanent Address :%s\nContact No. :%s\nEmail Id :%s\n",x->s_name,x->Regno,x->course,x->dob.day,x->dob.month,x->dob.year,x->batch,x->address,x->c_no,x->email);
}
