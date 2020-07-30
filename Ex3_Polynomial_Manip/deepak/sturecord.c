#include<stdio.h>
#include<string.h>
typedef struct{
            int rollno;
            char name[20];
            int marks[5];
              }record;
 void shift(record stu[],int size);  
 void display(record stu[],int start,int end); 
 int insert(record stu[],int key,int size);          
int main()
{
  record stu[15];
  int i=0,size,start=0,key,store;
  char perr='y';
  while(perr=='y')
  {
    printf("Enter rollno,firstname,marks of 5 subjects with spaces\n");
    scanf("%d %s %d %d %d %d %d",&stu[i].rollno,stu[i].name,&stu[i].marks[0],&stu[i].marks[1],&stu[i].marks[2],&stu[i].marks[3],&stu[i].marks[4]);
    printf("Would you like to add data press y for yes ");
    scanf(" %c",&perr);  
    i++;
  }
  size=i++;
  char ch;
  do
  {
    int choice;
    printf("Press\n0)for insert in beginning\n1)for insert at end\n2)insert after given rollno\n3)search a record on name basis\n4)delete a record5)display all record\n6)show previous and next record\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 0:shift(stu,size);
             printf("Enter rollno,firstname,marks of 5 subjects with spaces\n");
             scanf("%d %s %d %d %d %d %d",&stu[0].rollno,stu[0].name,&stu[0].marks[0],&stu[0].marks[1],&stu[0].marks[2],&stu[0].marks[3],&stu[0].marks[4]);
             size++;
             break;
      case 1:printf("Enter rollno,firstname,marks of 5 subjects with spaces\n");
             scanf("%d %s %d %d %d %d %d",&stu[size].rollno,stu[size].name,&stu[size].marks[0],&stu[size].marks[1],&stu[size].marks[2],&stu[size].marks[3],&stu[size].marks[4]);
             size++;
             break;
      case 2:printf("Enter the rollno ");
             scanf("%d",&key);
             store=insert(stu,key,size);
             printf("Enter rollno,firstname,marks of 5 subjects with spaces\n");
             scanf("%d %s %d %d %d %d %d",&stu[store].rollno,stu[store].name,&stu[store].marks[0],&stu[store].marks[1],&stu[store].marks[2],&stu[store].marks[3],&stu[store].marks[4]);
             size++;
             break;
    }
    display(stu,start,size);
    printf("Would you like to continue press y for yes");
    scanf(" %c",&ch);
  }
  while(ch=='y');
  
}
void shift(record stu[],int size)
{
	int i;
	for(i=size-1;i>=0;i--)
	{
	  stu[i+1].rollno=stu[i].rollno;
	  strcpy(stu[i+1].name,stu[i].name);
	  stu[i+1].marks[0]=stu[i].marks[0];
	  stu[i+1].marks[1]=stu[i].marks[1];
	  stu[i+1].marks[2]=stu[i].marks[2];
	  stu[i+1].marks[3]=stu[i].marks[3];
	  stu[i+1].marks[4]=stu[i].marks[4];
	}
}
int insert(record stu[],int key,int size)
{
	int i,temp;
	for(i=0;i<size;i++)
	{
		if(stu[i].rollno==key)
		{
			temp=i;
			break;
		}
	}
	for(i=size;i>temp;i--)
	{
	  stu[i+1].rollno=stu[i].rollno;
	  strcpy(stu[i+1].name,stu[i].name);
	  stu[i+1].marks[0]=stu[i].marks[0];
	  stu[i+1].marks[1]=stu[i].marks[1];
	  stu[i+1].marks[2]=stu[i].marks[2];
	  stu[i+1].marks[3]=stu[i].marks[3];
	  stu[i+1].marks[4]=stu[i].marks[4];
	}
	return temp+1;
}
void display(record stu[],int start,int end)
{
	int i;
	for(i=start;i<end;i++)
	{
		printf("%d %s %d %d %d %d %d\n",stu[i].rollno,stu[i].name,stu[i].marks[0],stu[i].marks[1],stu[i].marks[2],stu[i].marks[3],stu[i].marks[4]);
	}
}