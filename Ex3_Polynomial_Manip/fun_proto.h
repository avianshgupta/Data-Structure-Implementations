struct l_list{
	int coeff;
	int power;
	struct l_list *next;
};

typedef struct l_list Node;

void insert_node(Node *hd, int coe,int exp);
Node *CreateEmptyList();
Node *add_poly(Node *hd1,Node *hd2);
Node *multip_poly(Node *hd1,Node *hd2,int size1,int size2);