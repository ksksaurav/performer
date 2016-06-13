#include<stdio.h>
#include<string.h>
struct _Element{
	char first_name[100];
	char last_name[100];
}Element;

struct _Element array[1000000];
long long int percolate_up(long long int);
void percolate_down(long long int);

long long int top=0;

void init_heap(char first_name[],char last_name[])
{
    
    top++;
	strcpy(array[top].first_name,first_name);
	strcpy(array[top].last_name,last_name);

}


long long int insert(char first_name[],char last_name[])
{
   
	long long int index;
	top++;
	strcpy(array[top].first_name,first_name);
	strcpy(array[top].last_name,last_name);
	index=percolate_up(top);
	return index;
	

}

long long int min(long long int i,long long int j)
{
    
	if(strcmp(array[i].first_name,array[j].first_name)>0)
	{
		return j;
	}
	else
	{
		return i;
	}
	
}

long long int percolate_up(long long int value)
{
   
	long long int i,index=top;
	i=value;
	char temp[100],temp2[100];
	while(strcmp(array[i].first_name,array[i/2].first_name)<0 || (strcmp(array[i].first_name,array[i/2].first_name)==0  && strcmp(array[i].last_name,array[i/2].last_name)<0))
	{



	strcpy(temp2,array[i].last_name);
	strcpy(array[i].last_name,array[i/2].last_name);
	strcpy(array[i/2].last_name,temp2);
	strcpy(temp,array[i].first_name);
	strcpy(array[i].first_name,array[i/2].first_name);
	strcpy(array[i/2].first_name,temp);
		index=i/2;
		i=i/2;
		
	}
	return index;

}
void percolate_down(long long int i)
{
   
	long long int next;
    int l=2*i+1;
    int r=l+1;
    char temp[100],temp2[100];
	if(l-1>top)
	{
		return ;
	}
	else if(l-1==top)
	{
		if(strcmp(array[i].first_name,array[l-1].first_name)<=0 || (strcmp(array[i].first_name,array[l-1].first_name)==0 && strcmp(array[i].last_name,array[l-1].last_name)<=0 ))
		{
			return;
		}
		else
		{

        strcpy(temp2,array[i].last_name);
        strcpy(array[i].last_name,array[l-1].last_name);
        strcpy(array[l-1].last_name,temp2);
        strcpy(temp,array[i].first_name);
        strcpy(array[i].first_name,array[l-1].first_name);
        strcpy(array[l-1].first_name,temp);

			return ;
		}
	}
	else if(strcmp(array[i].first_name,array[min(l,r)].first_name)<=0 || ( strcmp(array[i].first_name,array[min(l,r)].first_name)==0 && strcmp(array[i].last_name,array[min(l,r)].last_name)<=0))
	{
		return ;
	}
	else
	{
		next=min(l,r);

		strcpy(temp2,array[i].last_name);
        strcpy(array[i].last_name,array[next].last_name);
        strcpy(array[next].last_name,temp2);
        strcpy(temp,array[i].first_name);
        strcpy(array[i].first_name,array[next].first_name);
        strcpy(array[next].first_name,temp);
		percolate_down(next);
	}

}

void find_min()
{
	if(top==0)
	{
		printf("-1\n");

	}
	else
	{
		printf("%s %s\n",array[1].first_name,array[1].last_name);

	}
}


void delete_min()
{
    char temp[100],temp2[100];
	if(top==0)
	{
		printf("-1\n");

	}
	else
	{
		printf("%s %s\n",array[1].first_name,array[1].last_name);

		strcpy(temp2,array[1].last_name);
        strcpy(array[1].last_name,array[top].last_name);
        strcpy(array[top].last_name,temp2);
        strcpy(temp,array[1].first_name);
        strcpy(array[1].first_name,array[top].first_name);
        strcpy(array[top].first_name,temp);
		top--;
		percolate_down(1);
	}
}
void delete(long long int index)
{
    char temp[100],temp2[100];
	if(index<1)
	{
		printf("-1\n");
	}
	else if(top==0)
	{
		printf("-1\n");

	}
	else if(index>top)
	{
		printf("-1\n");

	}
	else
	{
		printf("%s %s\n",array[index].first_name,array[index].last_name);

		strcpy(temp2,array[index].last_name);
        strcpy(array[index].last_name,array[top].last_name);
        strcpy(array[top].last_name,temp2);
        strcpy(temp,array[index].first_name);
        strcpy(array[index].first_name,array[top].first_name);
        strcpy(array[top].first_name,temp);
		top--;
		percolate_down(index);
	}
}
int main()
{
	long long int index,t,n;
	char s1[100],s2[100],input[100];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",input);
		if(strcmp(input,"InitHeap")==0)
		{
			scanf("%s",s1);
			scanf("%s",s2);
			init_heap(s1,s2);
		}
		else if(strcmp(input,"Insert")==0)
		{
			scanf("%s",s1);
			scanf("%s",s2);
			index=insert(s1,s2);
			printf("%lld\n",index);
		}
		else if(strcmp(input,"DeleteMin")==0)
		{
			delete_min();
		}
		else if(strcmp(input,"Delete")==0)
		{
			scanf("%lld",&n);
			delete(n);
		}
		else if(strcmp(input,"FindMin")==0)
		{
			find_min();
		}


	}

	return 0;

}
