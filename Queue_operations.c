#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
}*front = NULL,*rear = NULL;
void insert(int item);
int delete();
int peek();
int isempty();
void display();

int main()
{
	int choice,item;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Display front element\n4.Display all elements\n5.Terminate process\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 1:
				printf("Enter the element\n");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				printf("Deleted element is %d\n",delete());
				break;
			case 3:
				printf("Element at the front is %d\n",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
}

void insert(int item)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Space unavailable in memory\n");
		return;
	}
	ptr->info = item;
	ptr->link = NULL;
	if(front==NULL)
		front = ptr;
	else
		rear->link = ptr;
	rear = ptr;
	printf("%d is inserted\n",item);
}

int delete()
{
	struct node *ptr;
	int item;
	if(isempty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	ptr = front;
	item = ptr->info;
	front = front->link;
	free(ptr);
	return item;
}

int peek()
{
	if(isempty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front->info;
}

int isempty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void display()
{
	struct node *temp;
	temp = front;
	if(isempty())
	{
		printf("Queue is empty\n");
		return ;
	}
	printf("Elements are :\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp = temp->link;
	}
}