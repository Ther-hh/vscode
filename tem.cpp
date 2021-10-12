/*#include<stdio.h> 
int main()
{
	int x,y;
	char a;
	scanf("%d %d %c",&x,&y,&a);//shuru
	printf("%d %d\n",x,y);
	//printf("hello world!\n");
	printf("%d%c",x + y,a);
}*/

#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b<=c && a+c<=b && b+c<=a){
		printf("non-triangle.\n");
	}
	else if(a == b||b == c){
		printf("equilateral triangle.\n");
	}
	else if(a == b){
	    printf("isoceles triangle.\n");
	}
	else if(b == c){
	    printf("isoceles triangle.\n");
	}
	else if(a == c){
	    printf("isoceles triangle.\n");
	}
	else{
	printf("triangle.\n"); 
	}
	//system("pause");
}
