		/********** This Binary Search is applied for only Sorted arrays **********/

#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[],int size,int element)
{
	int low,mid,high;
	low = 0;
	high = size-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(arr[mid]==element)
		{
			return mid;
		}
		else if(arr[mid]<element)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	printf("Element not found\n");
	exit(1);
}
					
int main()
{
	int arr[] = {7,19,23,40,56,74,81,90,105};
	int element = 81;
	int size = sizeof(arr)/sizeof(int);
	int index = binary_search(arr,size,element);
	printf("%d is found at index %d",element,index);
}