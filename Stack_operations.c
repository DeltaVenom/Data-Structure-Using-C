#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *link;
}*top = NULL;
void push(int item);
int pop();
int peek();
int isempty();
void display();

int main()
{
	int choice,item;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display top element\n4.Display all elements\n5.Terminate process\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 1:
				printf("Enter the item\n");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				item = pop();
				printf("Popped item is : %d\n",item);
				break;
			case 3:
				printf("Item at the top is %d\n",peek());
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

void push(int item)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Stack Overflow\n");
		return ;
	}
	ptr->info = item;
	ptr->link = top;
	top = ptr;
	printf("%d is pushed in stack\n",item);
}

int pop()
{
	struct node *ptr;
	int item;
	if(isempty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	ptr = top;
	item = ptr->info;
	top = top->link;
	free(ptr);
	return item;
}

int peek()
{
	if(isempty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return top->info;
}

int isempty()
{
	if(top==NULL)
		return 1;
	else 
		return 0;
}

void display()
{
	struct node *ptr;
	ptr = top;
	if(isempty())
	{
		printf("Stack is empty\n");
		return ;
	}
	printf("Elements are:\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr = ptr->link;
	}
	printf("\n");
}