#include <stdio.h>

int Fibo(int data, int a, int b)
{
	if(data == 0) return b ; 
	printf("%d\n",b);
	a = a+b ; 
	b = a-b ; 
	Fibo(data-1, a, b) ; 
}

int main()
{
	int data ; 
	scanf("%d",&data);
	int f = Fibo(data, 1, 0) ; 
	printf("\nthe last pos of %d in ifbo = %d\n", data, f);
}
