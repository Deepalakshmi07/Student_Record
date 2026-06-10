#include "header.h"
int node_count(ST *ptr)
{
	int c=0;
	while(ptr!=0)
	{
		c++;
		ptr=ptr->next;
	}
	return c;

}
void sort_record(ST *hptr)
{
	if(hptr == 0)
	{
		printf("No record found to sort\n");
		return ;
	}
	char ch;
	int i=0,size=sizeof(ST)-8,c=node_count(hptr);
	sort_menu();
	printf("Enter your option:");
	scanf(" %c",&ch);
	ST* ptr;
	ptr=hptr;
	ST **p=(ST**)malloc((c+1)*sizeof(ST*));
	ST *temp=(ST*)malloc(sizeof(ST));

	while(ptr!=0)
	{
		p[i++]=ptr;
		ptr=ptr->next;
	}
	if((ch == 'n')||(ch=='N'))
	{
		ptr=hptr;
		for(int j=0;j<i-1;j++)
		{
			for(int k=j+1;k<i;k++)
			{
				if(strcmp(p[j]->name,p[k]->name)>0)
				{
					temp=p[j];
					p[j]=p[k];					
					p[k]=temp;
				}
			}
		}
		printf("student record is successfully sorted based on the name\n");
		printf(" --------- ---------------------- ------------ \n");
                printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
                printf(" --------- ---------------------- ------------ \n");
		for(int j=0;j<i;j++)
		{
			printf("| %-7d | %-20s | %-10.2f |\n",p[j]->rollno,p[j]->name,p[j]->mark);
		}
		  printf(" --------- ---------------------- ------------ \n");
	   
	}
	else if((ch == 'p')||(ch=='P'))
	{
		ptr=hptr;
		for(int j=0;j<i-1;j++)
		{
			for(int k=j+1;k<i;k++)
			{
				if(p[j]->mark>p[k]->mark)
				{
					temp=p[j];
					p[j]=p[k];
					p[k]=temp;

				}
			}
		}
		printf("student record is successfully sorted based on the percentage\n");
		 printf(" --------- ---------------------- ------------ \n");
                printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
                printf(" --------- ---------------------- ------------ \n");
                for(int j=0;j<i;j++)
                {
                        printf("| %-7d | %-20s | %-10.2f |\n",p[j]->rollno,p[j]->name,p[j]->mark);
                }
                  printf(" --------- ---------------------- ------------ \n");
	}
	else
		printf("Invalid choice\n");
	 }

