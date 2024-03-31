#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* @C_P62_2023_7_19_��̬�ڴ�_malloc

int main()
{
	int arr[10];
	int* p = (int*)malloc(10*sizeof(int));//��̬�ڴ濪��һƬ�����Ŀռ�
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
	free(p);//����һƬ�ռ仹������ϵͳ
	p = NULL;//�ֶ���pָ��ĳ�NULL
	return 0;
}
*/

/*
* @C_P62_2023_7_19_��̬�ڴ�_calloc_realloc

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
* @C_P155(�°�2021��)_2023_7_20_18��41��_�Կ�ָ��Ľ����ò���
* ����Ϊ�������

int main()
{
	int* p = (int*)malloc(1000000000);
	int i = 0;
	for (i = 0; i < 10; i++)//i++��ʹ���ٽ����Լ�   ++i���Լ��ڽ���ʹ��
	{
		*(p + i) = i;//���p��ֵΪNULL���ͻ��������
	}
	free(p);
	p=NULL;
	return 0;
}
*/

/*
*@C_P155(�°�2021��)_2023_7_20_18��50��_�Զ�̬���ٿռ��Խ�����
* ����Ϊ�������
int main()
{
	int* p = (int*)malloc(sizeof(int) * 10);
	if (p !=NULL)
	{
		return 0;
	}
	int i;
	for (i = 0; i < 12; i++)//i++��ʹ�����Լ�   ++i���Լ���ʹ�� 
	{
		*(p + i) = i;
	}
	free(p);
	p = NULL;
	return 0;
}
*/

/*
* @C_P155(�°�2021��)_2023_7_20_18��57��_�ԷǶ�̬�����ڴ�ռ�ʹ��free����
* ����Ϊ�������
* �Ῠ������Ҫ����
* �Ῠ������Ҫ����
* �Ῠ������Ҫ����
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	free(p);
	p = NULL;
	return 0;
}
*/

/*@C_P155(�°�2021��)_2023_7_20_19��06��_��free�ͷ�һ�鶯̬�ڴ��һ����
* ����Ϊ�������
* �Ῠ������Ҫ����
* �Ῠ������Ҫ����
* �Ῠ������Ҫ����
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
* @C_P155(�°�2021��)_2023_7_20_20��24��_��ͬһ���ڴ����ͷ�
* �������
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
* @C_P155(�°�2021��)_2023_7_20_20��34��_��̬�ڴ濪�������ͷ�
* ���ܻ�����ڴ�й©,�������ռ���ڴ�ռ��㹻���п��ܵ����ڴ�����
* �������
void test()
{
	int* p = (int*)malloc(sizeof(int) * 10);
	if (p == NULL)
	{
		return;
	}
	//δ�����ͷŲ���
}
int main()
{
	test();
	return 0;
}
*/

/*
*@C_P157(�°�2021��)_2023_7_21_17��52��_������1
//�������
void GetMemory(char* p)
{
	p = (char*)malloc(1000);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(str);//ֵ����
	strcpy(str, "Hello World");
	printf(str);
}
//��̬������ڴ�δ�ͷţ�������ڴ�й©
int main()
{
	Test();
	return 0;
}
//�޸ĺ���ȷ�Ĵ���_1
char* GetMemory(char* p)
{
	p = (char*)malloc(1000);
	return p;
}

void Test(void)
{
	char* str = NULL;
	str=GetMemory(str);
	strcpy(str, "Hello World");
	printf(str);
	free(str);
	str = NULL;
}
int main()
{
	Test();
	return 0;
}
//�޸ķ�ʽ_2
void GetMemory(char** p)//�ö���ָ�������յ�ַ��������
{
	*p = (char*)malloc(1000);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str);//��ַ����
	strcpy(str, "Hello World");
	printf(str);
	free(str);
}
int main()
{
	Test();
	return 0;
}
*/

/*
* C_P157(�°�2021)_2023_7_24_������2_ջ�ϵ��ڴ��������
* �������
char* GetMemory(void)
{
	char p[] = "Hello World";
	return p;
//��ջ�ϴ�����һ�����飬�ں����������������٣��ڴ��ͷţ��ռ䷵��������ϵͳ�����ǵ�ַ������
}
void Test(void)
{
	char* str = NULL;
	str = GetMemory();
//ͨ�����صĵ�ַȥ�����飬��Ϊ�ڴ��Ѿ����ͷţ��ͻ���ɷǷ����ʣ�
	printf(str);//��ӡ���Ϊ�����
}

int main()
{
	Test();
	return 0;
}
*/

/*
* C_P157(�°�2021)_2023_7_24_������3
* �������
void GetMemory(char** p,int num)
{
	*p = (char*)malloc(num);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str,100);
	strcpy(str, "Hello");
	printf(str);
	//û���ͷſռ䣬�����޴�
}
int main()
{
	Test();
	return 0;
}

*/

/*
* C_P157(�°�2021)_2023_7_24_������4
* �������

void Test(void)
{
	char* str = (char*)malloc(100);
	strcmp(str, "Hello World");
	free(str);
	//û�ж��ͷŵĿռ�����ÿ�ָ�봦��
	//str=NULL;
	if (str != NULL)
	{
		strcmp(str, "World");
		printf(str);
	}
}
int main()
{
	Test();
	return 0;
}

*/



