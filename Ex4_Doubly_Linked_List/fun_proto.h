struct dl_list{
	char name[30];
	struct dl_list *next;
	struct dl_list *prev;
};

typedef struct dl_list Node;

Node *CreateEmptyList();
void add_beg(Node *hd,char Name[]);
void add_end(Node *tail,char Name[]);
Node *position(char Name[], Node *hd,int *ind);
void insert(char Name[],Node *p);
void delete(Node *p);
void display(Node *hd);
int alpha_ord_display(Node *hd,char *arr[]);