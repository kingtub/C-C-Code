#include<stdio.h>

main()
{
	const int NUM = 10;
	// NUM = 3;  compiled Error
	// const���ε����飬�����ÿһ��Ԫ�ض������޸� 
	const char s[] = "Hello";
	printf("%s \n", s);
	// s[0] = 'A'; compiled Error
	int a[] = {1, 2, 3};
	a[0] = 5;
	// const���ε����飬�����ÿһ��Ԫ�ض������޸� 
	const int *p = a;
	//p[1] = 6; compiled Error
	a[1] = 6;
	int i = 0;
	while(i < 3)
	{
		printf("%d \n", p[i++]);
	}
	return 0;
} 
