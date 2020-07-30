#include <stdio.h>
int li_search(int arr[],int size,int data);
int bi_search(int arr[],int size,int data);
void sort(int arr[],int size);
int main(){
	int arr[20],size;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	printf("Enter the elemments: ");
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}
	int data,choice,index;
	printf("Enter the element(To STOP enter -999): ");
	scanf("%d", &data);
	do{
		printf("Enter the search type\n1: Linear\n2: Binary\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: index=li_search(arr,size,data);
				break;
			case 2: index=bi_search(arr,size,data);
					sort(arr,size);
					printf("Sorted array: ");
					for(int i=0;i<size;i++)
						printf("%d ",arr[i]);
					printf("\n");
				break;
		} 
		if(index==-1)
			printf("Element Not Found!!\n");
		else
			printf("index of %d is %d\n", data,index);
		printf("Enter the element(To STOP enter -999): ");
		scanf("%d", &data);
	}while(data!=-999);
}

int li_search(int arr[],int size,int data){
	int i=0;
	while(arr[i]!=data){
		i++;
		if(i>size)
			return -1;
	}

	return i;
}
void sort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

		}

	}
}
int bi_search(int arr[],int size,int data){
	int start=0,pos;
	int end=size-1;
	sort(arr,size);
	while(start<=end){
		int mid=(start+end)/2;
		if(arr[mid]==data){
			pos=mid;
			return pos;
		}
		else if(data>arr[mid]){
			start=mid+1;
		}
		else{
			end=mid-1;
		}

	}
	return -1;
}

/*OUTPUT
Enter the size of the array: 6
Enter the elemments: 7 8 9 6 5 1
Enter the element(To STOP enter -999): 9
Enter the search type
1: Linear
2: Binary
1
index of 9 is 2
Enter the element(To STOP enter -999): 8
Enter the search type
1: Linear
2: Binary
2
Sorted array: 1 5 6 7 8 9
index of 8 is 4
Enter the element(To STOP enter -999): 10
Enter the search type
1: Linear
2: Binary
1
Element Not Found!!
Enter the element(To STOP enter -999): -999 */