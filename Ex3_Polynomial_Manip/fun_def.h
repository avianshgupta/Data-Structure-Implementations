Node *CreateEmptyList(){
	Node *h;
	h=(Node*)malloc(sizeof(Node));
	h->next=NULL;
	return h;
}

void insert_node(Node *hd, int coe,int exp){
	Node *new,*temp;
	new=(Node *)malloc(sizeof(Node));
	new->coeff=coe;
	new->power=exp;
	new->next=hd->next;
	hd->next=new;
}

Node *add_poly(Node *hd1,Node *hd2){
	Node *res,*p,*q;
	res=CreateEmptyList();
	p=hd1->next;
	q=hd2->next;
	while(p!=NULL & q!=NULL){
		if(p->power>q->power){
			insert_node(res,p->coeff,p->power);
			p=p->next;
		}
		else if(q->power>p->power){
			insert_node(res,q->coeff,q->power);
			q=q->next;
		}
		else if(p->power==q->power){
			if(p->coeff + q->coeff != 0)
				insert_node(res,p->coeff + q->coeff,p->power);
			p=p->next;
			q=q->next;
		}
	}
	if(p != NULL){
		while(p != NULL){
			insert_node(res,p->coeff,p->power);
			p=p->next;
		}
	}
	if(q != NULL){
		while(q != NULL){
			insert_node(res,q->coeff,q->power);
			q=q->next;
		}
	}
	
	return res;
}

Node *multip_poly(Node *hd1,Node *hd2,int size1,int size2){
	Node *res,*p,*q,*res_h1,*res_h2;
	int t_size=size1 * size2;
	res=CreateEmptyList();
	p=hd1->next;
	while(p != NULL){
		q=hd2->next;
		while(q != NULL){
			insert_node(res,p->coeff * q->coeff,p->power + q->power);
			q=q->next;
		}
		p=p->next;
	}
	return res;
}