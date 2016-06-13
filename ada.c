

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int freq;
	int Array[10000000];
	int code;
}node;

node Heap[100000000];  // Heap Min


typedef struct chars
{
	char name[100000];
	int Coding[10000000];
	int end=0;
}chars;

chars Symbol[10000000];  // Symbols array
int Heap[100];// NOTE : Our heap is 1 based indexing so childrens are 2i & 2i+1
int last=0;  // will be used to keep track of the position of last element in heap

void swap(int i,int j)
{
	int temp=Heap[i];
	Heap[i]=Heap[j];
	Heap[j]=temp;
}

int min(i,j)  // function to find which index has a lesser data in the Heap
{
	if(Heap[i]>Heap[j])
	{
		return j;
	}
	else
	{
		return i;
	}
}


void percolateUp(int last)  // // Function to fit a value to its correct position dragging from bottom to Top
{
	int i=last;
	while(i>1)
	{
		if(Heap[i]<Heap[i/2]) // checking equality with its parent 
		{
			swap(i,i/2);  //if it is less than parent then swap
			i=i/2; // move current location to its swaped position and check up to the root
		}
		else
		{
			return;
		}

	}
}

void percolateDown(int i)  // Function to fit a value to its correct position dragging from top to bottom
{
	if(i==last)  // if this index is the last position in heap then no swapping needed
	{
		return ;
	}
	else if(2*i==last)  // If this index has only one child i.e left child 
	{
		if(Heap[2*i]<Heap[i])  // and if data in child is lesser than its own data then swap
		{
			swap(i,2*i);
			percolateDown(2*i);  // still find its correct position
		}
		else
		{
			return ;
		}
	}
	else if(2*i+1<=last)  // If Heap have enogh childs and enough positions
	{
		int m=min(2*i,2*i+1);  // first check which child in smallest 
		if(Heap[m]<Heap[i])  // then check the eqaulity of smallest child data with its own data ,then swap
		{
			swap(i,m);
			percolateDown(m);
		}
		else
		{
			return ;
		}
	}
}


void insert(int data)
{
	Heap[++last]=data;  // add data to heap at last position
	percolateUp(last);
}

int deleteMin()  // function to delete the root(As root is minimum in Min Heap)
{
	int element=Heap[1];
	printf("min is %d\n",element );
	swap(1,last);  // swap root with last position 
	last--;
	percolateDown(1);  // and find the correct position of new root
	return element;
}
int main()
{
	int i,d;
	int n;
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&d);
		insert(d);
	}
	for (i = 1; i <= last; ++i)
	{
		printf("%d ",Heap[i] );
	}
	printf("\n");
	printf("\nDeleting the min now\n");
	for (i = 0; i < n-1; ++i)
	{
		int small=deleteMin();
		int nextSmall=deleteMin();	
		insert(small+nextSmall);
	}
	for (i = 1; i <= last; ++i)
	{
		printf("%d ",Heap[i] );
	}
	printf("\n");
	
	
	return 0;
}
