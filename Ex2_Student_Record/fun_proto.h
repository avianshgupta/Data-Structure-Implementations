typedef struct{
	int regno;
	char name[20];
	int marks[5];
}Student;

void insert_first(Student std[],int size,Student data);
void insert_last(Student std[],int size,Student data);
void insert(Student std[],int id,int size,Student data);
void display(Student std[],int size);
void delete(Student std[],int size,int id);
void displayPN(Student std[],int size,int id);
void search_name(Student std[],int size,char Name[]);