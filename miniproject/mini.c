#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "prototypes.h"
#include "fun_def.h"

int main()
{
  node *head;
  tree *root;
  head=emptylist();
  char choice;
  int choice1,ansch,count=0;
  float x,y,z;
  srand(time(0));
  x=rand()%11+10;
  y=x+30; 
  z=rand()%8+1;
  printf("****Welcome to the game of quiz****\n");
  printf("\nHere are Rules of Game...\n1) Quiz consist of 5 questions\n2) Each correct question contains 10 marks\n3) NO negative marking\n3) Your total score will count to your rank\n\n**Required....Basic Knowlwdge of Computer and DataStructure\n");
  printf("Like to continue press y for yes ");
  scanf("%c",&choice);
  if((choice == 'y') || (choice == 'Y'))
  {
    printf("Press\n1 for Maths Quiz\n2 for Science Quiz\n3 for Data Structure Quiz\n4 for General Quiz\n");
    scanf("%d",&choice1);
    switch(choice1)
    {
      case 1:push(1);
             push(3);
             push(2);
             push(4);
             push(3);
             count=0;
             float ans;
             printf("Q.1\nValue Of the expression %0.0f*%0.0f+%0.0f/%0.0f is...\n",x,(x+5),(x-3),(x+2));
             ans=x*(x+5)+(x-3)/(x+2);
             printf("Choose one option\n1)%f\n2)%f\n3)%f\n4)%f\n",x*(x+5)+(x-2)/(x+2),x*(x+4)+(x-3)/(x+2),ans,x*(x+5)+(x-3)/(x+7));
             scanf("%d",&ansch);
             if(ansch==top->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             pop();
             printf("Q.2\nValue Of the log(%.0f) is...\n",x);
             ans=log(x);
             printf("Choose one option\n1)%f\n2)%f\n3)%f\n4)%f\n",log(x+10),log(x-5),log(x+100),ans);
             scanf("%d",&ansch);
             if(ansch==top->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             pop();
             printf("Q.3\nValue Of the sin(30) is...\n");
             ans=0.5;
             printf("Choose one option\n1)0.414\n2)0.5\n3)1\n4)0.67\n");
             scanf("%d",&ansch);
             if(ansch==top->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             pop();
             printf("Q.4\nSmallest prime no is...\n");
             ans=2;
             printf("Choose one option\n1)1\n2)3\n3)2\n4)5\n");
             scanf("%d",&ansch);
             if(ansch==top->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             pop();
             printf("Q.5\nSum of all natural nos till %.0f is...\n",x);
             ans=x*(x+1)/2;
             printf("Choose one option\n1)%.0f\n2)%.0f\n3)%.0f\n4)%.0f\n",ans,(x*(x+2)/2)*2,ans+1,ans-1);
             scanf("%d",&ansch);
             if(ansch==top->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             pop();
             printf("Your total score is %d out of 50\n",count*10);
             break;
      case 2:insertb(head,1);
             insert(head,4);
             insert(head,2);
             insert(head,3);
             insert(head,2);
             head=head->next;
             count=0;
             printf("Q.1\nConvert %0.0f celcius into fahrenheit\n",y);
             ans=(y*9/5)+32;
             printf("Choose one option\n1)%.2f\n2)%.2f\n3)%.2f\n4)100\n",ans,ans+10,ans+273.15);
             scanf("%d",&ansch);
             if(ansch==head->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             head=head->next;
             printf("Q.2\nNeutral pH is\n");
             ans=7;
             printf("Choose one option\n1)8\n2)0\n3)14\n4)%.0f\n",ans);
             scanf("%d",&ansch);
             if(ansch==head->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             head=head->next;
             printf("Q.3\nIf 5 resistors of %f resistence in connected in series,total resistence is\n",y);
             ans=y*5;
             printf("Choose one option\n1)%.0f\n2)%.0f\n3)%.0f\n4)%.0f\n",ans+10,ans,ans/5,y);
             scanf("%d",&ansch);
             if(ansch==head->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             head=head->next;
             printf("Q.4\nV=IR is\n");
             ans=3;
             printf("Choose one option\n1)Dalton's Law\n2)Newton's Law\n3)Ohm's law\n4)Einstein's Law\n");
             scanf("%d",&ansch);
             if(ansch==head->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             head=head->next;
             printf("Q.5\nA body of mass %f kg will experience a force of(take g=9.8)\n",y);
             ans=y*9.8;
             printf("Choose one option\n1)%.2f\n2)%.2f\n3)%.2f\n4)%.2f\n",y*10,ans,ans+5,y*4.6);
             scanf("%d",&ansch);
             if(ansch==head->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             head=head->next;
             printf("Your total score is %d out of 50\n",count*10);
             break;
      case 3:enqueue(3);
             enqueue(2);
             enqueue(4);
             enqueue(4);
             enqueue(1);
             count=0;
             printf("Q.1\nA full BST with height %0.0f has how many nodes \n",z);
             ans=pow(2,z+1)-1;
             printf("Choose one option\n1)%.0f\n2)%.0f\n3)%.0f\n4)%.0f\n",ans-1,ans+1,ans,ans-2);
             scanf("%d",&ansch);
             if(ansch==qf1->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             qf1=qf1->next;
             printf("Q.2\nA doubly linked list with %0.0f nodes has how many pointers \n",z+3);
             ans=(z+3)*2;
             printf("Choose one option\n1)%.0f\n2)%.0f\n3)%.0f\n4)%.0f\n",ans-2,ans,ans+2,ans+1);
             scanf("%d",&ansch);
             if(ansch==qf1->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             qf1=qf1->next;
             printf("Q.3\nPostfix expression of ((A+B)*C-(D-E)^(F+G)) is\n");
             printf("Choose one option\n1)^–*+ABC–DE+FG\n2)AB*C+DEFG--+^\n3)ABC+*DE–F-G+^\n4)AB+C*DE––FG+^\n");
             scanf("%d",&ansch);
             if(ansch==qf1->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             qf1=qf1->next;
             printf("Q.4\nTotal no of Binary Search trees possible for %.0f nodes are\n",z);
             ans=fact(2*z)/(fact(z+1)*fact(z));
             printf("Choose one option\n1)%.0f\n2)%.0f\n3)%.0f\n4)%.0f\n",ans-1,2*z,ans+1,ans);
             scanf("%d",&ansch);
             if(ansch==qf1->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             qf1=qf1->next;
             printf("Q.5\nStack Data Structure is\n");
             printf("Choose one option\n1)Last In First Out\n2)First In First Out\n3)Random\n4)Not a Data Structure\n");
             scanf("%d",&ansch);
             if(ansch==qf1->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             qf1=qf1->next;
             printf("Your total score is %d out of 50\n",count*10);
             break; 
      case 4:root=newnode(2);
             root->left=newnode(3);
             root->right=newnode(1);
             root->left->left=newnode(3);
             root->left->right=newnode(4);
             count=0;
             printf("Q.1\nKeyboard has how many keys\n");
             printf("Choose one option\n1)110\n2)100\n3)105\n4)95\n");
             scanf("%d",&ansch);
             if(ansch==root->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             printf("Q.2\nWorld's biggest country in terms of area is\n");
             printf("Choose one option\n1)Canada\n2)China\n3)Russia\n4)India\n");
             scanf("%d",&ansch);
             if(ansch==root->left->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             printf("Q.3\nPM of india is\n");
             printf("Choose one option\n1)Narendra Modi\n2)Manmohan Singh\n3)Donald Trump\n4)Yogi Gi\n");
             scanf("%d",&ansch);
             if(ansch==root->right->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             printf("Q.4\nFirst indian person to win nobel prize\n");
             printf("Choose one option\n1)C.V Raman\n2)Mother Teresa\n3)Rabindranath Tagore\n4)Amartya Sen\n");
             scanf("%d",&ansch);
             if(ansch==root->left->left->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             printf("Q.5\nCEO of google is\n");
             printf("Choose one option\n1)Larry Page\n2)Sergey Brin\n3)Satya Nadella\n4)Sundar Pichai\n");
             scanf("%d",&ansch);
             if(ansch==root->left->right->data)
             {
               printf("Correct Answer!!!\n");
               count=count+1;
             }
             else
               printf("Wrong Answer!!!\n");
             printf("Your total score is %d out of 50\n",count*10);
             break;                      
    }
  }
}
