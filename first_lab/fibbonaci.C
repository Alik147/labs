#include <stdlib.h>
#include <cstdio>
int fib(int a, int* b, bool* flag){
	if (a==0 || a==1){
		return 1;
	}
	int box = fib(a-1,b,flag);
	if (a-1==*b && *flag ==false)
	{
		*b = box;
		*flag = true;
	}
	return (box+fib(a-2,b,flag));
}
int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d %d",&a,&b);
	if (a<b)
	{
		b=a+b;
		a=b-a;
		b=b-a;
	}
	bool flag =false;
	int sum=fib(a,&b, &flag)+b;
	printf("%d",sum);
	return 0;
}
// 1 1 2 3 5 8 13 21 34 55