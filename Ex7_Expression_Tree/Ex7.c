#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Stack.h"
#include "ExpressionTree.h"

int main(){
    char infix[30];
    char *postfix;
    printf("Enter the expression: ");
    scanf("%[^\n]%*c", infix);
    do{
        postfix = (char *)malloc(strlen(infix)*sizeof(char));
        if(balanced_parenthesis(infix)){
            printf("Expression is Balanced\n\n");
            infixTopostfix(infix,postfix);
            printf("Postfix Expresion: ");
            for(int i=0;i<strlen(postfix);i++)
                printf("%c",postfix[i]);
            printf("\n\n");
            Tree *ExpT = constructTree(postfix); 
            printf("Expression Tree Constructed\n\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("\t\t\t\tTREE TRAVERSAL\n");
            printf("Prorder: ");
            preorder(ExpT);
            printf("\n\nInorder: ");
            inorder(ExpT);
            printf("\n\nPostorder: ");
            postorder(ExpT);
            printf("\n\n");
            printf("---------------------------------------------------------------------------------\n");
        }
        else{
            printf("Expression is unbalanced!!\n");
        }
        printf("Enter the expression(to stop enter -1): ");
        scanf("%[^\n]%*c", infix);
    }while(strcmp(infix,"-1"));
}

/*OUTPUT
Enter the expression: (2+5)*(3-6)/(7*8)
Expression is Balanced

Postfix Expresion: 25+36-*78*/

//Expression Tree Constructed
/*
---------------------------------------------------------------------------------
                                TREE TRAVERSAL
Prorder: /*+25-36*78

Inorder: 2+5*3-6/7*8

Postorder: 25+36-*78*/
/*
---------------------------------------------------------------------------------
Enter the expression(to stop enter -1): 7-(((3+2)*(6+1))/(5+6))
Expression is Balanced

Postfix Expresion: 732+61+*56+/-

Expression Tree Constructed

---------------------------------------------------------------------------------
                                TREE TRAVERSAL
Prorder: -7/*+32+61+56

Inorder: 7-3+2*6+1/5+6

Postorder: 732+61+*56+/-

---------------------------------------------------------------------------------
Enter the expression(to stop enter -1): ((3+2)*(2+5))
Expression is Balanced

Postfix Expresion: 32+25+*

Expression Tree Constructed

---------------------------------------------------------------------------------
                                TREE TRAVERSAL
Prorder: *+32+25

Inorder: 3+2*2+5

Postorder: 32+25+*

---------------------------------------------------------------------------------
Enter the expression(to stop enter -1): -1
*/
