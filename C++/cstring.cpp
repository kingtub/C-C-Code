#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char s1[] = "abc";
	char s2[] = "ade";
	printf("sl=%s\n", s1);
	printf("s2=%s\n", s2);
	printf("strlen(s1)=%d\n", strlen(s1));
	printf("strcmp(s1, s2)=%d\n", strcmp(s1, s2));
	
	printf("strcat(s1, s2)=%s\n", strcat(s1, s2));
	char *s3 = strcat(s1, s2);
	printf("s3=%s\n", s3);
	printf("(s3==s1)=%s\n", (s3 == s1 ? "true":"false"));
	char a[10];
	strcpy(a, s2);
	
	printf("a=%s\n", a);
	
	return 0;
}
