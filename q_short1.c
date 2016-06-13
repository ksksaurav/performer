#include<stdio.h>
#include<stdlib.h>

void sort(int n, int l, int m, int r, int a[n])
{
	int i, j, k, lpos = l, rpos = m+1;
	int b[(m - l)+1], c[(r - (m+1))+1], d[n];
	for(i = l;i <= m;i++)
		b[i] = a[i];
	for(j = m+1;i <= r;i++)
		c[i-(m+1)] = a[i];
	i = 0;
	j = 0;
	k = 0;
	while((i <= m) && (j <= r-(m+1)))
	{
		if(b[i] < c[j])
		{
			d[k] = b[i];
			i++;
		}
		else if(c[j] < b[i])
		{
			d[k] = c[j];
			j++;
		}
		k++;
	}
	
	while(i <= m)
	{
		d[k] = b[i];
		i++;
		k++;
	}
	while(j <= r-(m+1))
	{
		d[k] = c[j];
		j++;
		k++;
	}
	for(k = 0;k < n;k++)
		a[k] = d[k];
}

void merge(int n, int l, int r, int a[n])
{
	int m = (l+r)/2;
	merge(n, l, m, a);
	merge(n, m+1, r, a);
	sort(n, l, m, r, a);
}

void pv(int n, int a[n], int k)
{
	int pv, i, p = 0, o = 0;
	while(p != n)
	{
		pv = a[0] + (2*a[1]);
		a[0] = pv;
		for(i = 1;i < n;i++)
		{
			a[i] = a[i+1];
		}
		n--;
		merge(n, 0, n-1, a);
		for(i = 0;i < n;i++)
		{
			if(a[i] < k)
			{
				p = 0;
				break;
			}
			else
				p++;
		}
		o++;
	}
	printf("%d", o);
}

int main()
{
	int n, k, i, p = 0;
	scanf("%d %d", &n, &k);
	int a[n];
	for(i = 0;i < n;i++)
		scanf("%d", &a[i]);
	//merge(n, 0, n-1, a);
	pv(n, a, k);
	return 0;
}
