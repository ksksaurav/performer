#include <stdio.h>
#include <stdlib.h>

void test_case(int cases)
{
	int i,j,k,N,m,n;
	int l=0;
	 
	for(i=0; i<cases; i++)
	{
		printf("Enter the value of N: ");
		scanf("%d", &N);
		int* A = (int*)malloc(sizeof(int)*N);
		int* B = (int*)malloc(sizeof(int)*N);
		for(j=0; j<N; j++)
		{	
			printf("Enter the min and max values: ");
			scanf("%d %d", (A+j), (B+j));
		}
		for(k=0; k<N; k++)
		{
			int sum=0;
			while(l<N)
			{
				if(*(B+k) > *(A+l))
					sum = sum+1;
			}
			*(B+k) = sum;
		}
		int max = *(B);
		for(m=1; m<N; m++)
		{
			if(*(B+m) > max)
				max = *(B+m); 
		}
		*(A+i) = max;
		printf("Max no of overlaps for case %d is %d\n", i,*(A+i));
	}
	

}

int main()
{
	int cases;
	printf("Enter the no of test cases: ");
	scanf("%d", &cases);
	test_case(cases);
	return 0;
}

