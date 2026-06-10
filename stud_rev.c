#include "header.h"

void reverse_record(ST *hptr)
{
	if(hptr==0)	
	{
		printf("No record found to reverse\n");
		return ;	
	}
	ST *ptr;
	int i,j,c=node_count(hptr);
	ST **p=(ST**)malloc((c+1)*sizeof(ST*));
	ST *temp=(ST*)malloc(sizeof(ST));
	ptr=hptr;
	for(i=0;i<c;i++)
	{
		p[i]=ptr;
		ptr=ptr->next;
	}
	for(int k=0,j=c-1;k<j;j--,k++)
	{
		temp=p[k];
		p[k]=p[j];
		p[j]=temp;
		
	}
	printf("Student record are reversed Successfully\n");
	  printf(" --------- ---------------------- ------------ \n");
                printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
                printf(" --------- ---------------------- ------------ \n");
                for(int j=0;j<i;j++)
                {
                        printf("| %-7d | %-20s | %-10.2f |\n",p[j]->rollno,p[j]->name,p[j]->mark);
                }
                  printf(" --------- ---------------------- ------------ \n");
}

