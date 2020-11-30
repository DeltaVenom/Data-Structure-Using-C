#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *create(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addBeg(struct node *start,int data);
struct node *addEnd(struct node *start,int data);
struct node *addafter(struct node *start,int data,int after);
struct node *addatindex(struct node *start,int data,int index);
struct node *delete(struct node *start,int data);

int main()
{
	struct node *start = NULL;
	int after,index,data,choice;
	while(1)
	{
		printf("1.Create\n2.Display\n3.Count\n4.Search\n5.Add at beginning\n6.Add at End\n7.Add after a Node\n8.Add at index\n9.Delete\n.10.Terminate Process\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		printf("\n\n");

		switch(choice)
		{
			case 1:
				start = create(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				count(start);
				break;
			case 4:
				printf("Enter the element to search\n");
				scanf("%d",&data);
				search(start,data);
				break;
			case 5:
				printf("Enter the element \n");
				scanf("%d",&data);
				start = addBeg(start,data);
				break;
			case 6:
				printf("Enter the element\n");
				scanf("%d",&data);
				start = addEnd(start,data);
				break;
			case 7:
				printf("Enter the element\n");
				scanf("%d",&data);
				printf("Enter the element after which to insert\n");
				scanf("%d",&after);
				start = addafter(start,data,after);
				break;
			case 8:
				printf("Enter the element\n");
				scanf("%d",&data);
				printf("Enter the index ");
				scanf("%d",&index);
				start  = addatindex(start,data,index);
				break;
			case 9:
				printf("Enter the element\n");
				scanf("%d",&data);
				start = delete(start,data);
				break;
			case 10:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
}

struct node *create(struct node *start)
{
	int n,data;
	printf("Enter number of nodes");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
		return start;
	printf("Enter the elements to be inserted\n");
	scanf("%d",&data);
	start = addBeg(start,data);
	for(int i = 2;i<=n;i++)
	{
		printf("Enter the element \n");
		scanf("%d",&data);
		start = addEnd(start,data);
	}
	return start;
}

void display(struct node *start)
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is empty\n");
		return ;
	}
	ptr = start;
	printf("Elements are :\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr = ptr->link;
	}
}
void count(struct node *start)
{
	struct node *t;
	int ct = 0;
	t = start;
	while(t!=NULL)
	{
		t = t->link;
		ct++;
	}
	printf("Total elements present in list are %d\n",ct);
}

void search(struct node *start,int data)
{
	struct node *ptr = start;
	int i = 1;
	while(ptr!=NULL)
	{
		if(ptr->info == data)
		{
			printf("Element %d is found at index %d\n",data,i);
			return ;
		}
		ptr = ptr->link;
		i++;
	}
	printf("Element not found\n");
}

struct node *addBeg(struct node *start,int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->info = data;
	ptr->link = start;
	start = ptr;
	return start;
}
	
struct node *addEnd(struct node *start,int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *t;
	ptr->info = data;
	t = start;
	while(t->link!=NULL)
	{
		t = t->link;
	}
	t->link = ptr;
	ptr->link = NULL;
	return start;
}

struct node *addafter(struct node *start,int data,int after)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *t = start;
	while(t!=NULL)
	{
		if(t->info == after)
		{
			ptr->info = data;
			ptr->link = t->link;
			t->link = ptr;
			return start;
		}
		t = t->link;
	}
	printf("Element not found");
	return start;
}

struct node *addatindex(struct node *start,int data,int index)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *t;
	ptr->info = data;
	if(index==1)
	{
		ptr->link = start;
		start = ptr;
		return start;
	}
	t = start;
	for(int i = 1; i < index-1 && t!=NULL;i++)
		t = t->link;
	if(t==NULL)
		printf("There are less than %d elements\n",index);
	else
	{
		ptr->link = t->link;
		t->link = ptr;
	}
	return start;
}

struct node *delete(struct node *start,int data)
{
	struct node *ptr,*t;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info == data)
	{
		ptr = start;
		start = start ->link;
		free(ptr);
		return start;
	}
	t = start;
	while(t->link!=NULL)
	{
		if(t->link->info==data)
		{
			ptr = t->link;
			t->link = ptr->link;
			free(ptr);
			return start;
		}
		t = t->link;
	}
	printf("Element not found\n");
	return start;
}