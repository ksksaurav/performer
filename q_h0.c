#include<stdio.h>
#include<stdlib.h>

void build_max_heap(int a[], int i, int hs)
{
	int l, r, largest, temp;
	l = (2*i) + 1;
	r = (2*i) + 2;
	if((l <= hs) && (a[l] > a[i]))
		largest = l;
	else
		largest = i;
	if((r <= hs) && (a[r] > a[largest]))
		largest = r;
	if(largest != i)
	{
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		build_max_heap(a, largest, hs);
	}
}

void build_heap(int n, int a[n])
{
	int i;
	for(i = (n-1)/2;i >= 0;i--)
	{
		build_max_heap(a, i, n-1);
	}
}
int main()
{
	int n, i, f, l, r = 0;
	do
	{
		scanf("%d", &n);
	}while((n < 1) || (n > 10000));
	int a[n];
	for(i = 0;i < n;i++)
	{
		do
		{
			scanf("%d", &a[i]);
		}while((n < 1) || (n > 1000000));	
	}
	for(i = 0;i <= n/2-1;i++)
	{
		l = (2*i)+1;
		r = (2*i)+2;
		if(l > n-1)
			break;
		else if(r > n-1)
			r = l;
		//printf("%d %d %d\n", a[i], a[l], a[r]);
		if((a[l] > a[i]) || (a[r] > a[i]))
		{
			f = -1;
			break;
		}
		else
			f++;	
	}
	
	if(f != -1)
	{
		printf("YES\n");
	}
	else
	{
		build_heap(n, a);
		for(i = 0;i < n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
