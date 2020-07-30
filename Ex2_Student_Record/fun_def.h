void display(Student std[],int size){
	for(int i=0;i<size;i++){
		printf("%d\t%s\t", std[i].regno,std[i].name);
		for(int j=0;j<5;j++)
			printf("%d ", std[i].marks[j]);
		printf("\n");
	}
}

void insert_first(Student std[],int size,Student data){
	for(int i=size;i>0;i--)
		std[i]=std[i-1];	
	std[0]=data;
}

void insert_last(Student std[],int size,Student data){
	std[size]=data;
}

void insert(Student std[],int id,int size,Student data){
	int ind;
	for(int i=0;i<size;i++){
		if(std[i].regno==id){
			ind=i;
			break;
		}
	}
	for(int i=size;i>ind;i--)
		std[i]=std[i-1];
	std[ind+1]=data;
}

void search_name(Student std[],int size,char Name[]){
	int ind;
	for(int i=0;i<size;i++){
		if(strcmp(std[i].name,Name)==0){ 
			ind=i;
			break;
		}
	}
	printf("%d\t%s\t", std[ind].regno,std[ind].name);
	for(int j=0;j<5;j++)
		printf("%d ", std[ind].marks[j]);
	printf("\n");
}

void displayPN(Student std[],int size,int id){
	int ind;
	for(int i=0;i<size;i++){
		if(std[i].regno==id){
			ind=i;
			break;
		}
	}
	for(int i=ind-1;i<ind+2;i+=2){
		printf("%d\t%s\t", std[i].regno,std[i].name);
		for(int j=0;j<5;j++)
			printf("%d ", std[i].marks[i]);
		printf("\n");
	}
}

void delete(Student std[],int size,int id){
	int ind;
	for(int i=0;i<size;i++){
		if(std[i].regno==id){
			ind=i;
			break;
		}
	}
	for(int i=ind;i<size-1;i++)
		std[i]=std[i+1];
}