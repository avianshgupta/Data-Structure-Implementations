struct elementtype{
	char name[20];
	int id;
	int salary;
};

typedef struct elementtype heapdatatype;

struct PQueue{
	int capacity;
	int size;
	heapdatatype *element;
};

typedef struct PQueue heap;
int isfull(heap *h){
	return h->capacity==h->size;
}

int isempty(heap *h){
	return h->size==0;
}

void display(int size,heap *h){
	printf("-----------------------------------------\n");
	for(int i=1;i<size+1;i++)
		printf("Name: %s\nId: %d\nSalary: %d\n\n",h->element[i].name,h->element[i].id,h->element[i].rt);
	printf("-----------------------------------------\n");
}
heap *init(int maxelements){
	heap *h;
	h=(heap *)malloc(sizeof(heap));
	if(h==NULL){
		printf("Out of space\n");
		return NULL;
	}
	h->element=(heapdatatype *)malloc((maxelements+1)*sizeof(heapdatatype));
	if(h->element==NULL){
		printf("Out of Space\n");
		return NULL;
	}
	h->capacity=maxelements;
	h->size=0;
	h->element[0].rt=MAXDATA;
	return h;
}

void insert(heapdatatype x,heap *h){
	int i;
	if(isfull(h)){
		printf("PQueue is full\n");
		return;
	}
	for(i=++h->size;h->element[i/2].rt < x.rt; i/=2)
		h->element[i] = h->element[i/2];
	h->element[i]=x;
	display(h->size,h);
}

heapdatatype deletemin(heap *h){
	int i, child;
	heapdatatype maxelement, lastelement;
	if(isempty(h)){
		printf("PQueue is empty\n");
		return h->element[0];
	}
	maxelement=h->element[1];
	lastelement=h->element[h->size--];
	for(i = 1 ; (i*2) <= h->size ; i = child){
		child=i*2;
		if(child!=h->size && h->element[child+1].rt > h->element[child].rt)
			child++;
		if(lastelement.rt < h->element[child].rt)
			h->element[i]=h->element[child];
		else
			break;
	}
	h->element[i]=lastelement;
	return maxelement;
}