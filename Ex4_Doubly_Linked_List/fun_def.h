Node *CreateEmptyList(){
	Node *hd,*tail;
	hd = (Node *)malloc(sizeof(Node));
	tail = (Node *)malloc(sizeof(Node));
	hd->next = tail;
	tail->prev = hd;
	return hd;
}

void add_beg(Node *hd,char Name[]){
	Node *temp,*p;
	temp = (Node *)malloc(sizeof(Node));
	strcpy(temp->name,Name);
	temp->next = hd->next;
	temp->prev = hd;
	hd->next->prev = temp;
	hd->next = temp;
}

void add_end(Node *tail,char Name[]){
	Node *temp,*p;
	temp = (Node *)malloc(sizeof(Node));
	strcpy(temp->name,Name);
	temp->next = tail;
	temp->prev = tail->prev;
	tail->prev->next = temp;
	tail->prev = temp;
}

Node *position(char Name[], Node *hd,int *ind){
	int i=1;
	Node *pos;
	pos = hd->next;
	while(pos != NULL && strcmp(pos->name,Name) != 0 ){
		pos = pos->next;
		i++;
	}
    if(pos==NULL)
        return pos;
    *ind = i;
	return pos;
}

void insert(char Name[],Node *p){
	Node *temp = (Node *)malloc(sizeof(Node));
	strcpy(temp->name,Name);
	temp->next = p->next;
	temp->prev = p;
	temp->next->prev = temp;
	p->next = temp;
}

void delete(Node *p){
	if(p==NULL){
		printf("Element is not present!!");
		return;
	}
	Node *temp = p;
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	free(temp);
	return;
}

void display(Node *hd){
	Node *t = hd->next;
	while(t != NULL){
		printf("%s\n", t->name);
		t = t->next;
	}
}

int alpha_ord_display(Node *hd,char *arr[]){
	int i=0;
	char temp[30];
	for(Node *t = hd->next ; t != NULL ; t = t->next , i++){
		arr[i]=(char *)malloc(strlen(t->name)*sizeof(char));
		strcpy(arr[i],t->name);
	}
	int len=i;
	for(int j = 0 ; j < len-1 ; j++){
		for(int k = 0; k < len-1 ; k++){
			if(strcmp(arr[k],arr[k+1])>0){
				strcpy(temp,arr[k]);
				strcpy(arr[k],arr[k+1]);
				strcpy(arr[k+1],temp);
			}
		}
	}
	return len;
}