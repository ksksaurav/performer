#include <stdio.h>

int a1[], a2[], a3[], a4[], a5[];

int main()
{
	int n, q, i;
	scanf("%d %d", &n, &q);
	int a1[n], a2[n], a3[n], a4[n], a5[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d", &a1[i], &a2[i], &a3[i], &a4[i], &a5[i]);
	}
	for (i = 0; i < q; i++)
	{
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		printf("%d", process(l, r, k));
	}
	//for (i = 0; i < n; i++) printf("%d %d %d %d %d\n", a1[i], a2[i], a3[i], a4[i], a5[i]);
	return 0;
}

int process(int l, int r, int k)
{
	int count = 0;
	int arr[k];
	while (count < k)
	{
		int m[5];
		int m[0] = median(*(a1 + l), r - l);
		int m[1] = median(*(a2 + l), r - l);
		int m[2] = median(*(a3 + l), r - l);
		int m[3] = median(*(a4 + l), r - l);
		int m[4] = median(*(a5 + l), r - l);
		qsort(m, 5, sizeof(int), compare);
		for (i = l; i < r; i++)
		{
			if (a1[i] < m[0]) 
			{
				truncate();
				count++;
			}
			else if (a1[i] > m[4])
			{
				truncate();
			}
		}
	}
}

int compare(const void * a, const void * b)
{
   return (*(int*)a - *(int*)b);
}

int median(int a[], int n)
{
	if (n % 2 == 0)
	{
		return (a[n/2] + a[(n/2) + 1])/2;
	}
	else
	{
		return a[n/2];
	}
}