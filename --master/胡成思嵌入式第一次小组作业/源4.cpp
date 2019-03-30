#include<stdio.h>
#include<math.h>
//long long power(int n)
//{
//	int s;
//	(n > 2 ? s = power(n - 2) + power(n - 1) : s = n);//，每一次只有两个分支
//		return s;
//}
//
//int main()
//{
//	int a;
//	scanf_s("%d", &a);	
//    printf("%lld\n", power(a));
//
//	return 0;
//}

long long power(long long n)
{
	long long s;
	(n > 2 ? s = power(n - 2) + power(n - 1) : s = n);
		return s;
}

int main()
{
	long long a;
	scanf_s("%lld", &a);	
    printf("%lld\n", power(a));
	while (1);
	return 0;
}





