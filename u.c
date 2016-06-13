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
            for(i=0;i<strlen(arr) +1;i++)
            {
                if(arr[i]=='(' || arr[i]==')' || arr[i]=='*' || arr[i]=='/' || arr[i]=='^' || arr[i]=='+' || arr[i]=='-')
                {

                    if( t>=0 &&  priority(arr[i])<priority(stack[t]) && arr[i]!=')' && arr[i]!='(' && stack[t]!=')' && stack[t]!='(')
                    {
                    //printf("pl %c\n",stack[t]);
                        while(t>=0 && priority(arr[i])<priority(stack[t]) && stack[t]!='(')
                        {
                            printf("%c",stack[t]);
                            t--;
                        }
                        if(stack[t]=='(')
                        {
                            t--;
                        }
                        stack[t+1] = arr[i];
                        t++;
                    }
                    else if(arr[i]==')')
                    {
                        while(stack[t]>=0 && stack[t]!='(')
                        {
                            printf("%c",stack[t]);
                            t--;

                        }
                        /*if(stack[t]=='(')
                        {
                            t--;
                        }*/
                        

                    }
                    else
                    {
                        stack[t+1] = arr[i];
                        t++;
                    }
                }

                else if(arr[i]!='\0')
                {
                    printf("%c",arr[i]);
                }
                else
                {
                    while(t>=0)
                    {
                        printf("%c",stack[t]);
                        t--;
                    }
                }
            }
printf("\n");
       }

    }



