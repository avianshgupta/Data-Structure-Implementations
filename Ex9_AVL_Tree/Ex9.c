#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avltree.h"

int main(){
    Tree *avltree = NULL;
    elementtype *arr;
    arr = (elementtype *)malloc(sizeof(elementtype));
    char *english[15]={"Algorithm","Animation","Bit","Browser","Clipboard","Compiler","Digital","Printer","Encoding","Gateway","Hardware","Internet","Memory","Monitor","Password"};
    char *tamil[15]={"நெறிமுறை","அசைவூட்டம்","நுண்மி","உலாவி","மறைப்பலகை","தொகுப்பி","எண்மின்","அச்சுப்பொறி","குறியாக்கம்","நுழைவாயில்","வன்பொருள்","இணையம்","நினைவகம்","கணித்திரை","கடவுச்சொல்"};
    char *hindi[15]={"कलन विधि","एनीमेशन","बिट","ब्राउज़र","कर्तन पट्ट","संकलक","डिजिटल","छापनेवाला यंत्र","संकेतीकरण","प्रवेशद्वार","हार्डवेयर","अंतराजाल","याददाश्त","मॉनिटर","संकेत-शब्द"};
    for(int i=0;i<15;i++){
        arr->english = (char *)malloc(strlen(english[i])*sizeof(char));
        arr->tamil = (char *)malloc(strlen(tamil[i])*sizeof(char));
        arr->hindi = (char *)malloc(strlen(hindi[i])*sizeof(char));
        strcpy(arr->english,english[i]);
        strcpy(arr->tamil,tamil[i]);
        strcpy(arr->hindi,hindi[i]);
        avltree = insert(arr,avltree);
    }
	printf("\n\nDictionary Created Successfully\n\n");	
	char word[25];
	while(1){
		printf("Enter the word(To stop enter \"stop\"): ");
		scanf("%s", word);
		if(strcmp(word,"stop")==0)
			break;
		Tree *meaning = find(word,avltree);
		if(meaning == NULL){
			printf("Word Not Found!!\n");
			continue;
		}		
		printf("---------------------------\n");
		printf("English: %s\nHindi: %s\nTamil: %s\n",meaning->element->english,meaning->element->hindi,meaning->element->tamil);
		printf("---------------------------\n");
	}
}