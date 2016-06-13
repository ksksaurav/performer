#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void insert(struct node **,int);

void postorder(struct node **ref_root)
{
	//printf("GOOD\n");
	if(*ref_root != NULL)
	{
		postorder(&(*ref_root)->left);
		postorder(&(*ref_root)->right);
		printf("%d ",(*ref_root)->data );

	}
}
int main()
{
	
	//printf("HELLO WORLD\n");
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		struct node *root=NULL;
		int n;
		scanf("%d",&n);
		int arr[n],i=0,num;
		while(n>0)
		{
			scanf("%d",&num);
			insert(&root,num);
			//printf("%d\n",root->data );
			n--;
			//i++;
		}
		//printf("%d\n",root->data );
		postorder(&root);
		printf("\n");


		t--;
	}

	return 0;
}

void insert(struct node **ref_root,int num)
{
	if(*ref_root == NULL)
	{
		struct node *new_node;
		new_node = malloc(sizeof(struct node *));
		new_node->data = num;
		new_node->left = new_node->right=NULL;
		*ref_root = new_node;
	}
	else if((*ref_root)->data >= num)
	{
		insert(&(*ref_root)->left,num);
	}
	else
	{
		insert(&(*ref_root)->right,num);	
	}
}