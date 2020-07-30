#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Stack.h"

int main(){
    char infix[30];
    char *postfix;
    printf("Enter the expression: ");
    scanf("%[^\n]%*c", infix);
    postfix = (char *)malloc(strlen(infix)*sizeof(char));
    if(balanced_parenthesis(infix)){
        printf("Expression is Balanced\n\n");
        infixTopostfix(infix,postfix);
        printf("Postfix Expresion: ");
        for(int i=0;i<strlen(postfix);i++)
            printf("%c",postfix[i]);
        printf("\n");
        int res = postfixEvaluation(postfix);
        printf("\nResult= %d\n",res);
    }
    else{
        printf("Expression is unbalanced!!\n");
    }
}