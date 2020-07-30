#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "queue.h"

int main(){
    char per='y',jno[3];
    int bt,c1=0,c2=0;
    int wt1=0,wt2=0,count=0;
    float owt1=0,owt2=0;
    while(per=='y' || per=='Y'){
        printf("Enter job number and burst time: ");
        scanf("%s %d",jno,&bt);
        if(wt1<=wt2){
            enqueue(wt1,wt2,jno,bt);
            wt1+=bt;
            if(count!=0)
              owt1+=bt;
            c1++;
        }
        else{
            enqueue(wt1,wt2,jno,bt);
            wt2+=bt;
            if(count!=1)
              owt2+=bt;
            c2++;
        }
        count++;
        printf("Would you like to add job(y/n): ");
        scanf(" %c",&per);
    }
    printf("\n\n------------------------------------------------------\n");
    display();
    printf("Average time for  Queue 1 is %.2f\n",owt1/c1);
    printf("Average time for  Queue 2 is %.2f\n",owt2/c2);

}

/*OUTPUT
Enter job number and burst time: J1 6
Would you like to add job(y/n): y
Enter job number and burst time: J2 5
Would you like to add job(y/n): y
Enter job number and burst time: J3 2
Would you like to add job(y/n): y
Enter job number and burst time: J4 3
Would you like to add job(y/n): y
Enter job number and burst time: J5 7
Would you like to add job(y/n): y
Enter job number and burst time: J6 3
Would you like to add job(y/n): y
Enter job number and burst time: J7 7
Would you like to add job(y/n): y
Enter job number and burst time: J8 2
Would you like to add job(y/n): y
Enter job number and burst time: J9 3
Would you like to add job(y/n): y
Enter job number and burst time: J10 7
Would you like to add job(y/n): n


------------------------------------------------------
                Queue 1(Job No, Burst Time)
(J1, 6)
(J4, 3)
(J6, 3)
(J7, 7)
(J10, 7)

------------------------------------------------------
                Queue 2(Job No, Burst Time)
(J2, 5)
(J3, 2)
(J5, 7)
(J8, 2)
(J9, 3)

------------------------------------------------------
Average time for  Queue 1 is 4.00
Average time for  Queue 2 is 2.80
*/