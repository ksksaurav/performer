#include<stdio.h>
#include<stdlib.h>

main()
{

printf("%d",add(16,3));


}

int add(int y,int k)
{


return (y+((y>>31)&((1<<k)+~0)))>>k;


}
