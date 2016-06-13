#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long int t=-1;

int priority(char c)
{
    if(c=='(')
    {
        return 0;
    }
    else if(c=='+')
    {
        return 1;
    }
    else if(c=='-')
    {
        return 2;
    }
    else if(c=='*')
    {
        return 3;
    }
    else if(c=='/')
    {
        return 4;
    }
    else if(c=='^')
    {
        return 5;
    }
}



long int pop(long int stack[])
{
    if(t!=0)
    {
        t--;
        return stack[t];
    }
    else return -1;
}


void push(char stack[],char x,int n)
    {
        stack[t]=x;
        t++;
    }

void xk(char stack[],int n)
{
    if(t==0 || t==1)
    {
        return;
    }
    if(stack[t-1]=='(')return;
    if(stack[t-1]==')')
    {
        long int u = t-1;
        while(u>=1 && stack[u-1]!='(')
        {
            printf("%c",stack[u-1]);
            u--;
        }
        t = u-1;
        return;
    }
    else if(priority(stack[t-1])<priority(stack[t-2]))
    {
        long int u = t-1;
        while(u>=1 && priority(stack[u])<priority(stack[u-1]) && stack[u-1]!='(')
        {
            printf("%c",stack[u-1]);
            u--;
        }
        stack[u-1]=stack[t-1];
        t = u;
        return;
    }
    else return;
}

int main()
    {
       long int test;
       scanf("%ld",&test);
       while(test--)
       {

            long int i,j;
            char arr[101];
            scanf("%s",arr);
            int n= strlen(arr);
            char stack[101];
            t = -1;
            for(i=0;i<strlen(arr);i++)
            {
                if(arr[i]=='(' || arr[i]==')' || arr[i]=='*' || arr[i]=='/' || arr[i]=='^' || arr[i]=='+' || arr[i]=='-')
                {

                    if(arr[i]=='(')
                    {
                        stack[t+1]= arr[i];
                        t++;
                    }
                    else if(arr[i]==')')
                    {
                        while(stack[t]!='(')
                        {
                            printf("%c",stack[t]);
                            t--;
                        }
                        t--;
                    }
                    else
                    {
                        while(t>=0 && priority(arr[i])<=priority(stack[t]))
                        {
                            printf("%c",stack[t]);
                            t--;
                        }
                        stack[t+1]= arr[i];
                        t++;
                    }
                }
                else
                {
                    printf("%c",arr[i]);
                }

            }
            while(t!=-1)
            {
                printf("%c",stack[t]);
                t--;
            }
printf("\n");
       }

    }



