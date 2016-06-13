# include<stdio.h>
 #include <math.h>

int main(void){
	int n,i,x=0,j,cb,count=0;
	scanf("%d",&n);
	j=cb,i=0;
	if(n>1729){
	for(x=1729;x<=n;x++){
		cb=cbrt(x);
		//printf("x=%d cb=%d\n",x,cb);
		//	printf("count=%d\n",count);

		while(i<=cb && count<2){
			int b = x-(i^3);
			if(iscube(b)==1){
				count++;
			}
			if(count==2){
				printf("%d\n",x);
			}
			i++;
		}
	}
	}
	return 0;
}
int iscube(int i){
	int k=2;
	for(k=2;k<=i/2;k++){
		if((k^3)==i){
			return 1;
		}
	}
	return 0;
}