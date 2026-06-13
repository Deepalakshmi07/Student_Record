#include "header.h"

void modify_roll(ST**,int);
void modify_name(ST**,char*);
void modify_percentage(ST**,float);
void modify_record(ST **);
void modify (ST**,char);

void modify_record(ST **hptr)
{
	
	if(*hptr==0)
	{
		printf("No record found\n");
		return ;
	}
	int roll;
	char op,ch[50];
	mod_menu();
	printf("Enter your choice:");
	scanf(" %c",&op);
	if(*hptr == 0)
	{ 
	 	printf("Database is empty:insert any record\n");
		return ;
	}	
	if((op=='r')||(op=='R'))
	{

		printf("Enter roll no:");
		scanf("%d",&roll);
		modify_roll(&(*hptr),roll);
	}
	else if((op =='n')||(op=='N'))
	{
		printf("Enter name:");
		scanf(" %[^\n]s",ch);
		modify_name(&(*hptr),ch);
	}
	else if((op=='p')||(op=='P'))
	{
		float f;
		printf("Enter percentage:");
		scanf("%f",&f);
		modify_percentage(&(*hptr),f);

	}
	else
		printf("Wrong Option\n");
}
void modify_name(ST** hptr,char *p)
{
	ST *ptr;
	ptr=*hptr;
	int c=0,roll;
	while(ptr!=0)
	{
		if(strcmp(ptr->name,p)==0)
			c++;
		ptr=ptr->next;
	}

	     if(c>1)
	     {
		     printf("\n%d Data available with the same name\n",c);
		     printf(" --------- ---------------------- ------------ \n");
		     printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
		     printf(" --------- ---------------------- ------------ \n");
		     ptr=*hptr;
		     while(ptr!=0)
		     {
			     if(strcmp(ptr->name,p)==0)
			     {
				     printf("| %-7d | %-20s | %-10.2f |\n",ptr->rollno,ptr->name,ptr->mark);
			     }
			     ptr=ptr->next;
		     }
		     printf(" --------- ---------------------- ------------ \n");
		     printf("Enter roll no:");
		     scanf("%d",&roll);
		     modify_roll(&(*hptr),roll);
	     }
	else if (c==1)
	{
		
		ST *ptr1;
		char op1;
		ptr1=*hptr;
		if((*hptr!=0)&&(strcmp((*hptr)->name,p)==0))
		{
			printf("\nStudent Record Found\n");
			printf(" --------- ---------------------- ------------ \n");
			printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
			printf(" --------- ---------------------- ------------ \n");
			printf("| %-7d | %-20s | %-10.2f |\n",ptr1->rollno,ptr1->name,ptr1->mark);
			printf(" --------- ---------------------- ------------ \n");

			mod_roll_menu();
			printf("Enter your choice:");
			scanf(" %c",&op1);
			modify(&(*hptr),op1);	
		}
		else
		{
			while((ptr1->next!=0)&&(strcmp(ptr1->next->name,p)!=0))
				ptr1=ptr1->next;
			ptr1=ptr1->next;
			mod_roll_menu();
			printf("Enter your choice:");
			scanf(" %c",&op1);
			modify(&ptr1,op1);	
		}
	}
	else
	{
		printf("%s Student Record not found\n",p);
	}

}
void modify_percentage(ST** hptr,float mark)
{
	ST *ptr;
	ptr=*hptr;
	int c=0,roll;
	while(ptr!=0)
	{
		if(ptr->mark == mark)
			c++;
		ptr=ptr->next;
	}

	    if(c>1)
	    {
		    printf("\n%d records available with the same percentage\n",c);
		    printf(" --------- ---------------------- ------------ \n");
		    printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
		    printf(" --------- ---------------------- ------------ \n");
		    ptr=*hptr;
		    while(ptr!=0)
		    {
			    if(ptr->mark == mark)
			    {
				    printf("| %-7d | %-20s | %-10.2f |\n",ptr->rollno,ptr->name,ptr->mark);
			    }
			    ptr=ptr->next;
		    }
		    printf(" --------- ---------------------- ------------ \n");
		    printf("Enter roll no:");
		    scanf("%d",&roll);
		    modify_roll(&(*hptr),roll);
	}
	else if (c==1)
	{
		
		ST *ptr1;
		char op1;
		ptr1=*hptr;
		if((*hptr!=0)&&((*hptr)->mark==mark))
		{
			printf("\nStudent Record Found\n");
			printf(" --------- ---------------------- ------------ \n");
			printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
			printf(" --------- ---------------------- ------------ \n");
			printf("| %-7d | %-20s | %-10.2f |\n",ptr1->rollno,ptr1->name,ptr1->mark);
			printf(" --------- ---------------------- ------------ \n");

			mod_roll_menu();
			printf("Enter your choice:");
			scanf(" %c",&op1);
			modify(&(*hptr),op1);	
		}
		else
		{
			while((ptr1->next!=0)&&(ptr1->next->mark !=mark))
				ptr1=ptr1->next;
			ptr1=ptr1->next;
			mod_roll_menu();
			printf("Enter your choice:");
			scanf(" %c",&op1);
			modify(&ptr1,op1);	
		}
	}
	else
	{
		printf("No student record found at %f percentage \n",mark);
	}
}

void modify_roll(ST **hptr,int roll)
{
    ST *ptr;
    char op;

    ptr=*hptr;

    while(ptr!=0)
    {
        if(ptr->rollno==roll)
        {
            printf("\nStudent Record Found\n");
            printf(" --------- ---------------------- ------------ \n");
	    printf("| %-7s | %-20s | %-10s |\n","ROLL NO","NAME","PERCENTAGE");
	    printf(" --------- ---------------------- ------------ \n");
            printf("| %-7d | %-20s | %-10.2f |\n",ptr->rollno,ptr->name,ptr->mark);
            printf(" --------- ---------------------- ------------ \n");

            mod_roll_menu();

            printf("Enter your choice : ");
            scanf(" %c",&op);

            modify(&ptr,op);
	    sort_percentage_desc(*hptr);

            return;
        }

        ptr=ptr->next;
    }

    printf("Record not found\n");
}

void modify (ST** ptr,char op)
{
	char ch[50];
	float mark;
	if((op == 'n')||(op == 'N'))
	{
	  	printf("Enter name:");
	  	scanf(" %[^\n]s",ch);
	  	strcpy((*ptr)->name,ch);
		printf("Roll no %d name is modified successfully\n",(*ptr)->rollno);
	}
	else if((op == 'p')||(op == 'P'))
	{
		printf("Enter percentage:");
		scanf("%f",&mark);
		(*ptr)->mark=mark;
		printf("Roll no %d percentage is modified successfully\n",(*ptr)->rollno);
	}
	else if((op == 'b')||(op == 'B'))
	{
	  	printf("Enter name:");
	  	scanf(" %[^\n]s",ch);
		printf("Enter percentage:");
		scanf("%f",&mark);
	  	strcpy((*ptr)->name,ch);
		(*ptr)->mark=mark;
		printf("Roll no %d name and percentage is modified successfully\n",(*ptr)->rollno);
	}
	else
	{
		printf("Invalid Option\n");
	}

}
