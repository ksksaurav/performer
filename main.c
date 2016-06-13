#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 1000005
#define V 100003

char opposite(char c)
{
    if(c =='r')return 'b';
    else if(c =='b')return 'r';
}

typedef struct nodex{
    long int val,dist,finish;
    char color,rb;
    //int color_value;
    struct nodex * next;
    struct nodex * parent;
}node;

long int queue[10001];
long int t1 =0, t2=0;
void enque(long int l)
{
    queue[t2]=l;
    t2++;
    //return queue[t2-1];
}
void deq()
{
    if(t1!=t2)
    {
        t1++;
    }
}

int bfs(node * adj_list[], long int s)
{
    char col = adj_list[s]->rb;
    if(col == 'x')
    {
        col = 'r';
    }
    node * v = adj_list[s]->next;
    enque(s);
    while(t1!=t2){
    while(v!=NULL)
    {
        if(adj_list[v->val]->rb=='x')
        {
            adj_list[v->val]->rb = opposite(col);
            enque(v->val);
        }
        else if(adj_list[v->val]->rb==col)
        {
            printf("NO\n");
            exit(0);
        }
        else
        {
            enque(v->val);
        }
        v = v->next;
    }
    deq(s);
    }
}


int main()
{
    ////////////////////////////////////////////////////////////////
    //Make graph

    //time = 0;
    long int n,i;
    scanf("%ld",&n);
    node * arr[n];
    node * arrt[n];
    for(i=0;i<n;i++)
    {
        node * x =  (node * )malloc(sizeof(node));
        x->val = i;
        x->next = NULL;
        node * y = (node * )malloc(sizeof(node));
        y->val = i;
        y->next = NULL;
        arr[i] =x ;
        arrt[i] = y;
    }
    long int q;
    scanf("%ld",&q);
    for(i=0;i<q;i++)
    {
        long int a,b;
        scanf("%ld%ld",&a,&b);
        a--;b--;
        node * temp1 = (node *)malloc(sizeof(node));
        node * temp2 = (node *)malloc(sizeof(node));
        temp1->next = NULL;
        temp2->next = NULL;
        temp1->val = a;
        temp2->val = b;
        temp1->color = 'w';
        temp2->color = 'w';
        node * t1 = arr[a]->next;
        //printf("%d",t1->val);



        arr[a]->next = temp2;
        temp2->next=t1;
        t1 = arr[b]->next;

        arr[b]->next = temp1;
        temp1->next = t1;

    }
    for(i=0;i<n;i++)
    {
        arr[i]->color='w';
        arr[i]->rb = 'x';
    }

            arr[i]->rb='r';
            bfs(arr,0);
            for(i=0;i<n;i++)
            {
                if(arr[i]->rb=='x')
                {
                    bfs(arr,i);
                }
            }

    printf("YES\n");

    return 0;
}


