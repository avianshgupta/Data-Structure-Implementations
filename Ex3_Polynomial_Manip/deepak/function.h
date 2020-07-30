node* add(node *h1,node *h2)
{
    int i=0,c,e;
    node *p,*q,*f,*temp;
    f=emptylist();
    p=h1->next;
    q=h2->next;
    temp=(node *)malloc(sizeof(node));
    while((p!=NULL) && (q!=NULL))
    {

        if(p->exp>q->exp)
        {
            temp->constt=p->constt;
            temp->exp=p->exp;
            if(i==0)
                insertb(f,temp->constt,temp->exp);
            else
                insert(f,temp->constt,temp->exp);
            i++;
            p=p->next;

        }
        else if(q->exp>p->exp)
        {
            temp->constt=q->constt;
            temp->exp=q->exp;

            if(i==0)
                insertb(f,temp->constt,temp->exp);
            else
                insert(f,temp->constt,temp->exp);
            i++;
            q=q->next;
        }
        else
        {
            if((p->constt+q->constt)!=0)
            {
               temp->constt=p->constt+q->constt;
               temp->exp=q->exp;
               if(i==0)
                  insertb(f,temp->constt,temp->exp);
               else
                  insert(f,temp->constt,temp->exp);
               i++;
               q=q->next;
               p=p->next;
            }
            else{
                p=p->next;
               q=q->next;}
        }
    }
    if(p!=NULL)
    {
        while(p!=NULL)
        {
            temp->constt=p->constt;
            temp->exp=p->exp;
            if(i==0)
                insertb(f,temp->constt,temp->exp);
            else
                insert(f,temp->constt,temp->exp);
            i++;
            p=p->next;
        }
    }
    if(q!=NULL)
    {
        while(q!=NULL)
        {
            temp->constt=q->constt;
            temp->exp=q->exp;
            if(i==0)
                insertb(f,temp->constt,temp->exp);
            else
                insert(f,temp->constt,temp->exp);
            i++;
            q=q->next;
        }
    }
    return f;
}
node *(node *h1,node *h2)
{
    int i=0,c,e;
    node *p,*q,*f;
    f=emptylist();
    p=h1->next;
    q=h2->next;
    for(t=h1->next;t!=NULL;t=t->next)
    {
        if(i==0)
        {
            insertb()
        }
    }
}