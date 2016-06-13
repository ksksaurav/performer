#include<stdio.h>
#include<stdlib.h>

struct bmh{
	
	int data;
	struct bmh *left;
	struct bmh *right;
};

struct bmh *Getnewnode(int data)
{
	struct bmh *newnode = (struct bmh*)malloc(sizeof(struct bmh*));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}



struct bmh* heapinsert(struct bmh *root,int data)
{
	if(root == NULL)
	{
	root = Getnewnode(data);		
	root->data = data;
		
	}

	else
	{
		if(data <= root->data)
		{
			heapinsert(root->left,data);
		}
		else
			heapinsert(root->right,data);
	}

	return root;
}

/*void checkLevelOrder(int *a)
{
}*/

int main()
{
	struct bmh *root = (struct bmh*)malloc(sizeof(struct bmh*));
	int i,n,A[100];	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",A[i]);
		heapinsert(root,A[i]);	
	}
		
}







