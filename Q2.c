#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int node;
    struct node *next;
    struct node *previous;
}node;
void insert(node *pointer, int data)
while(pointer->next!=NULL)
{
    pointer=pointer->next;
}
pointer->next=(node *)malloc(sizeof(node));
(pointer->next)->prev=pointer;
pointer=pointer->next;
pointer->data=data;
pointer->next=NULL;
}
void delete(node*pointer,int data)
while(pointer->next!=NULL && (pointer->next)->data!=data
{
pointer=pointer->next;
}
if(pointer->next==NULL)
{
    printf("Element is not present in the list:");
    return;
}
void print(node *pointer)
{
    if(pointer==NULL)
    {
        return;
    }
    printf("%d", pointer->data);
    printf(pointer->next);
    }
}

int main()
{
node *start,*temp;
start=(node *)malloc(sizeof(node));
temp=start;
node->next=NULL;
node->previous=NULL;
printf("1.Insert\n");
printf("2.Delete\n");
while(1)
{
int query;
scanf("%d",&query);
if(query==1)
{
int data;
scanf("%d",&data);
insert(start,data);
}
else if(query==2)
{
int data;
scanf("%d",&data);
delete(start,data);
}
}


