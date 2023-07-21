#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

/*
* @C_P62_2023_7_19_动态内存_malloc

int main()
{
	int arr[10];
	int* p = (int*)malloc(10*sizeof(int));//动态内存开辟一片连续的空间
	if (p == NULL)
	{
		perror("main");
		return 0;
	}
	int i = 0;
	for (i=0;i<10;i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf(" %d ", p[i]);
	}
	free(p);//把这一片空间还给操作系统
	p = NULL;//手动把p指针改成NULL
	return 0;
}
*/

/*
* @C_P62_2023_7_19_动态内存_calloc_realloc

int main()
{
	int* p =(int *)calloc(10,sizeof(int)) ;
	if (p == NULL)
	{
		perror("main");
		return 1;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		//printf(" %d ", p[i]);
		*(p + i) = 5;
	}
	int* p1= (int *)realloc(p, 20 * sizeof(int));
	if (p != NULL)
	{
		p = p1;
	}
	free(p);
	p = NULL;
	return 0;
}
*/

/*
* @C_P155(新版2021版)_2023_7_20_18点41分_对空指针的解引用操作
* 代码为错误代码

int main()
{
	int* p = (int*)malloc(1000000000);
	int i = 0;
	for (i = 0; i < 10; i++)//i++先使用再进行自加   ++i先自加在进行使用
	{
		*(p + i) = i;//如果p的值为NULL，就会出现问题
	}
	free(p);
	p=NULL;
	return 0;
}
*/

/*
*@C_P155(新版2021版)_2023_7_20_18点50分_对动态开辟空间的越界访问
* 代码为错误代码
int main()
{
	int* p = (int*)malloc(sizeof(int) * 10);
	if (p !=NULL)
	{
		return 0;
	}
	int i;
	for (i = 0; i < 12; i++)//i++先使用再自加   ++i先自加再使用 
	{
		*(p + i) = i;
	}
	free(p);
	p = NULL;
	return 0;
}
*/

/*
* @C_P155(新版2021版)_2023_7_20_18点57分_对非动态开辟内存空间使用free函数
* 代码为错误代码
* 会卡死，不要运行
* 会卡死，不要运行
* 会卡死，不要运行
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	free(p);
	p = NULL;
	return 0;
}
*/

/*@C_P155(新版2021版)_2023_7_20_19点06分_用free释放一块动态内存的一部分
* 代码为错误代码
* 会卡死，不要运行
* 会卡死，不要运行
* 会卡死，不要运行
int main()
{
	int* p = (int*)malloc(sizeof(int) * 10);
	if (p !=NULL)
	{
		return 1;
	}
	int i;
	for (i = 0; i < 5; i++)
	{
		*p++ = i;
	}
	return 0;
}
*/

/*
* @C_P155(新版2021版)_2023_7_20_20点24分_对同一块内存多次释放
* 错误代码
int main()
{
	int* p = (int*)malloc(100);
	if (p != NULL)
	{
		return 1;
	}
	int i;
	for (i = 0; i < 25; i++)
	{
		*(p + i) = i;
	}
	free(p);
	free(p);
	p = NULL;
	return 0;
}
*/

/*
* @C_P155(新版2021版)_2023_7_20_20点34分_动态内存开辟忘记释放
* 可能会造成内存泄漏,如果程序占用内存空间足够大，有可能导致内存问题
* 错误代码
void test()
{
	int* p = (int*)malloc(sizeof(int) * 10);
	if (p == NULL)
	{
		return;
	}
	//未进行释放操作
}
int main()
{
	test();
	return 0;
}
*/

/*
*@C_P157(新版2021版)_2023_7_21_17点52分_笔试题1

*/

void GetMemory(char* p)
{
	p = (char*)malloc(1000);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "Hello World");
	printf(str);
}
int main()
{
	Test();
	return 0;
}


