#include<stdio.h>
#include<stdlib.h>
int linear_search(int arr[],int size,int element)
{
	int i;
	for(i =0;i<size;i++)
	{
		if(arr[i]==element)
			return i;
	}
	printf("Element not found\n");
	exit(1);
}
int main()
{
	int arr[] = {12,34,91,27,74,2,56,256,83};
	int element =76 ;
	int size = sizeof(arr)/sizeof(int);
	int index = linear_search(arr,size,element);
	printf("%d is found at index %d",element,index);
	
}