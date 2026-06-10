#include "header.h"

void save_record(ST *hptr)
{
	if(hptr==0)
	{
		printf("No record Available to save:Record is empty\n");
		return;
	}
	FILE *fp=fopen("student.dat","w");
	fprintf(fp," --------- ---------------------- ------------ \n");
        fprintf(fp,"| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
        fprintf(fp," --------- ---------------------- ------------ \n");
	while(hptr!=0)	   
	{
		fprintf(fp,"| %-7d | %-20s | %-10.2f |\n",hptr->rollno,hptr->name,hptr->mark);
		hptr=hptr->next;
	}
	fprintf(fp," --------- ---------------------- ------------ \n");
	fclose(fp);
	printf("Student Record are successfully saved\n");
}
