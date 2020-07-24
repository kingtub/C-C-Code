#include<stdio.h>

void test1();
void test2();
void test3();
void test4();
void test5(); 
main()
{
	//test1();
	
	//int i = 3.5f;
	//printf("%d \n", i) ;
	
	// test2();
	
	//test3();
	
	//test4();
	
	test5();
	
	return 0;
}


void test1()
{
    char c = '\0';
	if(c == 0)
	{
		printf("ÊÇ0\n");
	} 
	else
	{
	    printf("²»ÊÇ0\n");	
	}
}

void test2()
{
   printf("1&3==%d\n", 1&3);	
   printf("1&2==%d\n", 1&2);
   
   printf("1|2==%d\n", 1|2);
}

void test3()
{
	float *p = NULL;
	printf("NULL == %d \n", NULL);
}

void test4()
{
	int r;
	scanf("input a int %d:", &r);
	printf("square is: %d\n", r*r);
}

void test5()
{
	printf("sizeof \"a\" is %d\n", sizeof("a"));
	printf("sizeof \"ab\" is %d\n", sizeof("ab"));
	
	char c[] = {'e'};
	printf("sizeof c is %d\n", sizeof(c));
	printf("sizeof int is %d\n", sizeof(int));
	printf("sizeof long is %d\n", sizeof(long));
	
	char *p = 0;
	printf("sizeof p is %d\n", sizeof(p));
	char *p2 = "abcde";
	char p3[] = "abcde";
	char p4[8];
	int ia[] = {
		1, 2, 3
	};
	printf("sizeof p2 is %d\n", sizeof(p2));
	printf("sizeof p3 is %d\n", sizeof(p3));
	printf("sizeof p4 is %d\n", sizeof(p4));
	printf("sizeof ia is %d\n", sizeof(ia));
}



