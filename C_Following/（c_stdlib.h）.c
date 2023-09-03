#define _CRT_SECURE_NO_WARNINGS
/*
1>exit(_exit)
void exit (int status);
�������(exit)������(_exit)��ֹ���ý���

ͨ��������Ȩ���ظ�����������������ֹ���̣�
����ִ���κ�������ֹ���̵ĳ������������纯����������������

���Ϊ 0 �����������������سɹ���ֹ״̬��
���Ϊ�� �����������������ز��ɹ�����ֹ״̬��

status  - ״̬����
���Ϊ �����ʾ�ɹ���
����� �����ʾʧ�ܡ�


// exit exampl
#include <stdio.h>      // printf, fopen
#include <stdlib.h>     // exit, EXIT_FAILURE

int main()
{
	FILE* pFile;
	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL)
	{
		printf("Error opening file");
		exit(EXIT_FAILURE);
	}
	else
	{
		// file operations here
		//exit(0);//����Ч��һ��
		exit(EXIT_SUCCESS);
	}
	return 0;
}
*/

/*
2>abort
void abort (void);
��ֹ��ǰ����(Abort current process)
��ֹ��ǰ���̲����ش������

�ú��������źţ����񱻵���һ������
���δ������ᵼ�³�����ֹ����������������������ƽ̨�Ĳ��ɹ���ֹ������롣
�����ڲ��ƻ��κζ���͵��ô��ݸ� �� ���κκ������������ֹ��

�޷���ֵ
Abort���Ὣ����Ȩ���ظ����ý��̡�Ĭ������£�����ֹ��ǰ���̲������˳���3

//abort example
#include<stdio.h>
#include<stdlib.h>

int main() {

	FILE* pFile;                 // ����һ��ָ�� FILE �ṹ�����͵�ָ����� pFile
	pFile = fopen("myfile.txt", "r");   // ��ֻ��ģʽ����Ϊ "myfile.txt" ���ļ����������ص��ļ�ָ�븳ֵ�� pFile
	if (pFile == NULL) {                 // ����ļ��Ƿ�ɹ���

		fputs("error opening file\n", stderr);   // �ڱ�׼�����������������Ϣ
		abort();                                 // ��ֹ�����ִ��,û��abort();����Ͳ�����ֹ
	}
	// regular process here�������ʾ�ļ��ɹ��򿪺�������������

	fclose(pFile);                     // �ر��ļ�
	return 0;                          // ��������ֵ 0����ʾ������������
}

*/

/*
3>abs
int abs (int n);  --fabs��double����
�������ֵ
���ز��� �� �� �ľ���ֵ��

// abs example
#include <stdio.h>      // printf
#include <stdlib.h>     // abs

int main()
{
	int n, m;
	n = abs(23);
	m = abs(-11);
	printf("n=%d\n", n);
	printf("m=%d\n", m);
	return 0;
}
//�����
//n = 23
//m = 11

*/


/*
4>at_quick_exit
int at_quick_exit (void (*func)(void));
���ÿ����˳�ʱִ�еĹ���
����ʱ�����Զ����� ָ��ĺ�����������������


����ֵ
��������ѳɹ�ע�ᣬ�򷵻���ֵ��
���ʧ�ܣ��򷵻ط���ֵ��

// at_quick_exit example
#include <stdio.h>      // puts
#include <stdlib.h>     // at_quick_exit, quick_exit, EXIT_SUCCESS

void fnQExit(void)
{
	puts("Quick exit function.");
}

int main()
{
	at_quick_exit(fnQExit);
	puts("Main function: Beginning");
	quick_exit(EXIT_SUCCESS);
	puts("Main function: End");  // never executed
	return 0;
}
//�����
//Main function : Beginning
//Quick exit function.

*/

/*
5>atexit
int atexit (void (*func)(void));

�����˳�ʱִ�еĹ���
������������ֹʱ�����Զ����� ָ��ĺ���������������
����Ըú����Ĳ�ͬ����ָ���˶�������������Ƕ����෴��˳����Ϊ��ջִ��
����ָ�������һ�����������˳�ʱִ�еĵ�һ����������
���Խ���������ע��Ϊ���˳�ʱ���ִ�С�

����ֵ
��������ѳɹ�ע�ᣬ�򷵻�0ֵ��
���ʧ�ܣ��򷵻ط�0ֵ��

// atexit example
#include <stdio.h>      // puts
#include <stdlib.h>     // atexit

void fnExit1(void)
{
	puts("Exit function 1.");
}

void fnExit2(void)
{
	puts("Exit function 2.");
}

int main()
{
	atexit(fnExit2);
	atexit(fnExit2);
	atexit(fnExit1);
	puts("Main function.");
	return 0;
}

//Main function.
//Exit function 1.
//Exit function 2.
//Exit function 1.

*/

/*
6>atof
double atof (const char* str);

���ַ���ת��Ϊ˫����
���� C �ַ������������ݽ���Ϊ��������������ֵ����Ϊ .

����ֵ
�ɹ��󣬸ú�����ת����ĸ�������Ϊֵ���ء�
����޷�ִ����Ч��ת������ú�������0������

// atof example: sine calculator -���Ҽ�����
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atof
#include <math.h>       // sin

int main()
{
	double n, m;                  // ������������Ϊ double �ı��� n �� m
	double pi = 3.1415926535;     // ����һ�� double ���͵ı��� pi������ֵΪԲ���ʵĽ���ֵ
	char buffer[256];             // ����һ������Ϊ 256 ���ַ����� buffer

	printf("Enter degrees: ");    // ��ʾ�û�����Ƕ�ֵ
	fgets(buffer, 256, stdin);    // �ӱ�׼���루���̣���ȡ�û����벢�洢�� buffer ������
	n = atof(buffer);             // ʹ�� atof ������ buffer �е��ַ���ת��Ϊ double ���͵���ֵ������ֵ�� n
	m = sin(n * pi / 180);        // ����Ƕ� n ��Ӧ������ֵ��������ڱ��� m ��
	printf("The sine of %f degrees is %f\n", n, m);   // �������������Ƕ�ֵ�Ͷ�Ӧ������ֵ
	return 0;                     // ��������ֵ 0����ʾ������������
}

//Enter degrees : 45
//The sine of 45.000000 degrees is 0.707101


*/

/*
7>atoi
int atoi (const char * str);

���ַ���ת��Ϊ����integer

����ֵ
�ɹ��󣬸ú�����ת�����������Ϊֵ���ء�
���ת�����ֵ���� �Ŀɱ�ʾֵ��Χ����ᵼ��δ�������Ϊ��


// atoi example
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atoi

int main()
{
	int i;                     // ����һ������Ϊ int �ı��� i
	char buffer[256];          // ����һ������Ϊ 256 ���ַ����� buffer

	printf("Enter a number: ");   // ��ʾ�û�����һ������
	fgets(buffer, 256, stdin);    // �ӱ�׼���루���̣���ȡ�û���������ݣ����洢�� buffer ������
	i = atoi(buffer);             // ʹ�� atoi ������ buffer �е��ַ���ת��Ϊ int ���͵���ֵ������ֵ�� i
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);    // �������������û������ֵ����������
	return 0;                    // ��������ֵ 0����ʾ������������
}

*/

/*
8>atol
long int atol ( const char * str );

���ַ���ת��Ϊ������long integer

����ֵ
�ɹ��󣬸ú�����ת�����������Ϊֵ���ء�
����޷�ִ����Ч��ת�����򷵻�0��

// atol example
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atol

int main()
{
	long int li;
	char buffer[256];
	printf("Enter a long number: ");
	fgets(buffer, 256, stdin);
	li = atol(buffer);// ʹ�� atol ������ buffer �е��ַ���ת��Ϊlong int ���͵���ֵ������ֵ�� li
	printf("The value entered is %ld. Its double is %ld.\n", li, li * 2);
	return 0;
}


//Enter a number : 567283
//The value entered is 567283. Its double is 1134566.

*/

/*
9>atoll
long long int atoll ( const char * str );

���ַ���ת��Ϊ������long long integer

����ֵ
�ɹ��󣬸ú�����ת�����������Ϊֵ���ء�
����޷�ִ����Ч��ת�����򷵻�0��

// atoll example
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atoll

int main()
{
	long long int lli;
	char buffer[256];
	printf("Enter a long number: ");
	fgets(buffer, 256, stdin);
	lli = atoll(buffer);// ʹ�� atoi ������ buffer �е��ַ���ת��Ϊlong long int ���͵���ֵ������ֵ�� lli
	printf("The value entered is %lld. Its double is %lld.\n", lli, lli * 2);
	return 0;
}

//Enter a number : 9275806
//The value entered is 9275806. Its double is 18551612.

*/

/*
10>bsearch
void* bsearch (const void* key, const void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

�����еĶ�������(Binary search in array)
�������������ִ�ж��ֲ��ҡ�


����
key
ָ�������������Ķ����ָ�룬����ת��Ϊ .void*
base
ָ��ִ������������ĵ�һ�������ָ�룬����ת��Ϊ .void*
num
�������� ָ���Ԫ������
���޷������͡�basesize_t
size
������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ����
���޷������͡�size_t
compar
ָ��Ƚ�����Ԫ�صĺ�����ָ�롣
�� �������ô˺������� �еĸ���Ԫ�ؽ��бȽϡ���Ӧ��ѭ����ԭ�ͣ�bsearchkeybase

int compar (const void* pkey, const void* pelem);
������ָ����Ϊ��������һ��ָ��ʼ��Ϊ ���ڶ���ָ��ָ�������һ��Ԫ�أ����߶�����ת��Ϊ �����ú���Ӧ���أ����ȶ��ʹ��ݵķ�ʽ����keyconst void*

//strcmp�ķ���ֵ���߼��ʹ˺���һ��
����ֵ	����
<0	    ָ���Ԫ�� ��ָ���Ԫ��֮ǰpkeypelem
0	    ָ���Ԫ�ص�Ч��pkeypelem
>0	    ָ���Ԫ����ָ���Ԫ��֮��pkeypelem

���ڿ���ʹ�ó����ϵ��������бȽϵ����ͣ����溯������������ʾ��compar


int compareMyType (const void * a, const void * b)
{
  if ( *(MyType*)a <  *(MyType*)b ) return -1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
}

����ֵ
ָ��������������ƥ�����Ŀ��ָ�롣
����ж��ƥ��Ԫ�أ�����Ҫ���ص�Ԫ�أ��������ָ�������κ�һ������һ���ǵ�һ������
���δ�ҵ����򷵻ؿ�ָ�롣

//#include<stdio.h> // printf
//#include<stdlib.h> //qsort, bsearch, NULL
//
////cpmpareints �ȽϺ�������������Ͳ���
////���д��붨����һ����Ϊ compareints �ĺ�����
////���������� const void* ���͵Ĳ��� a �� b����Щ������ָ�����ڴ��ָ�롣
////�ں������У�����ͨ������Щָ��ǿ��ת��Ϊ int* ���ͣ�
////Ȼ����������ǣ���ȡʵ�ʵ�����ֵ��
////�������� a - b �Ĳ�ֵ��
//int compareints(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);//��һ��*�ǽ����õ���˼
//}
//
//
//int main() {
//
//    int* pItem;
//    int key = 40;
//
//    // �����������鲢��ʼ��
//    int values[] = { 50, 20, 60, 40, 10, 30 };
//
//    // ʹ�� qsort �����������������
//    //�� values ���鴫�ݸ� qsort ������
//    //ͬʱ�ṩ����Ԫ�ص�����6��ÿ��Ԫ�صĴ�Сsizeof(int)�Լ��ȽϺ�����
//    qsort(values, 6, sizeof(int), compareints);//���ú�����������ν������򣬲���Ҫ��������ڲ��߼�
//
//    // ʹ�� bsearch �������ж��ֲ���
//    //����bsearch�������Ѿ��ź��������values������keyֵ��
//    //������key�ĵ�ַ& key���������ʼ��ַvalues��������Ԫ�صĸ���6��
//    //ÿ��Ԫ�صĴ�Сsizeof(int)�Լ��ȽϺ���compareints��Ϊ������
//    //���������ǿ��ת��Ϊint* ���ͺ�ֵ��pItem��
//    pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
//
//    if (pItem != NULL) {
//        // Ŀ��ֵ������������
//        printf("%d is in the array.\n", *pItem);
//    }
//    else {
//        // Ŀ��ֵ��������������
//        printf("%d is not in the array.\n", key);
//    }
//
//    return 0;
//}


//bsearch example with strings
#include <stdio.h>      // printf
#include <stdlib.h>     // qsort, bsearch, NULL
#include <string.h>     // strcmp

char strvalues[][20] = { "some","example","strings","here" };

int main()
{
	char* pItem;
	char key[20] = "example";

	// sort elements in array:

	//(int(*)(const void*, const void*))
	//�����ǽ�����ָ�����ͽ�����ʽ������ת�����﷨������������£�
	//�������ڽ� strcmp ����ת��Ϊ�� qsort ��������ıȽϺ���ָ��������ƥ�䡣
	//ʵ���ϣ����������£�C �����ڽ��к��� ָ������ �ƶ�ʱ�Ǿ��� ��ʽ����ת�� �ģ�������Ҫ��ʽ�ؽ�������ת����
	//��ˣ��ڵ��� qsort ����ʱ������ֱ�Ӵ��� strcmp ������Ϊ�ȽϺ�������������ж���ĺ���ָ������ת����
	//qsort(strvalues, 4, 20, (int(*)(const void*, const void*)) strcmp);
	qsort(strvalues, 4, 20, strcmp);

	// search for the key: ����Ϊָ����ǵ�ַ����������Ψһ�ģ�
	//pItem = (char*)bsearch(key, strvalues, 4, 20, (int(*)(const void*, const void*)) strcmp);
	pItem = (char*)bsearch(key, strvalues, 4, 20, strcmp);

	if (pItem != NULL)
		printf("%s is in the array.\n", pItem);
	else
		printf("%s is not in the array.\n", key);
	return 0;
}

*/

/*
11>calloc
void* calloc (size_t num, size_t size);
���ڴ��з���һ��Ԫ�س�ʼ��Ϊ0������(Allocate and zero-initialize array)


����
num
Ҫ�����Ԫ������
size
ÿ��Ԫ�صĴ�С��

����ֵ
�ɹ�ʱ��ָ����������ڴ���ָ�롣
��ָ�������Ϊalways�����Խ���ǿ��ת��Ϊ���������ָ�����ͣ���ʵ�ֿɽ�����
��������޷�����������ڴ�飬�򷵻ؿ�ָ�롣void*

#include <stdio.h>      // printf, scanf, NULL
#include <stdlib.h>     // calloc, exit, free
int main() {
	int i, n;
	int* pData;
	printf("Amount of numbers to be entered: ");
	scanf("%d", &i);
	pData = (int*)calloc(i, sizeof(int));
	//calloc ������������������Ҫ�����Ԫ������ i ��ÿ��Ԫ�صĴ�С sizeof(int)��
	//�������ʧ�ܣ��� pData Ϊ NULL������ͨ�� exit(1) ����ֹ����
	if (pData == NULL)
	{
		exit(1);
	}
	for (n = 0; n < i; n++)
	{
		//��� n ��ֵΪ 0������д��뽫��ӡ�� "Enter number #1:"����ʾ�û������һ�����֣�
		// ��� n ��ֵΪ 1�����ӡ "Enter number #2:"��
		// �������ơ��������û����԰�����ʾ������Ӧ�����֡�
		printf("Enter number #%d:", n + 1);
		scanf("%d", &pData[n]);
	}
	printf("You have entered: ");
	for (n = 0; n < i; n++)
	{
		printf("%d ", pData[n]);
	}
	free(pData);//free �����ͷŶ�̬������ڴ棬��ֹ�ڴ�й©
	return 0;
}
//Amount of numbers to be entered : 2
//Enter number #1:12
//Enter number #2:32
//You have entered : 12 32

*/

/*
12>div
div_t div (int numer, int denom);
������������ֵ���̺�������

����
numer
Numerator.�����ӣ�
denom����ĸ�
Denominator.����ĸ��

����ֵ
Div��������Ϊdiv_t�Ľṹ�������̺��������ýṹ��STDLIB.H�ж��塣

#include <stdio.h>      //printf
#include <stdlib.h>     //div, div_t

int main()
{
	//������һ�� div_t ���͵Ľṹ����� div_result�����ڴ洢�������,divresult.quot,divresult.rem
	div_t divresult;
	divresult = div(38, 5);
	printf("38 div 5 => %d, remainder %d.\n", divresult.quot, divresult.rem);
	return 0;
}

//38 div 5 => 7, remainder 3.
*/

/*
13>div_v
div_t�ṹ������int quot������int rem
*/


/*
14>getenv
char* getenv (const char* name);//��������ָ��Ϊ�����Ļ���������ֵ�� C �ַ������������ı������ǻ����б��һ���֣���ú��������ؿ�ָ�롣
�ӵ�ǰ������ȡһ��ֵ

����ֵ
���ش�������Ļ�������ֵ��c�ַ�����
��������������Ļ�����������Ϊ��ָ��

// getenv example: getting path
#include <stdio.h>      // printf
#include <stdlib.h>     // getenv

int main()
{
	char* pPath;
	pPath = getenv("PATH");
	if (pPath != NULL)
		printf("The current path is: %s", pPath);
	return 0;
}
*/

/*
15>labs
long int labs (long int n);
���㳤�����ľ���ֵ

����ֵ
n�ľ���ֵ

#include <stdio.h>      // printf
#include <stdlib.h>     // labs

int main()
{
	long int n, m;
	n = labs(65537L);
	m = labs(-100000L);
	printf("n=%ld\n", n);
	printf("m=%ld\n", m);
	return 0;
}


//n=65537
//m=100000
*/

/*
16>malloc
void* malloc (size_t size);
�����ڴ��

����ֵ
����ɹ����򷵻�һ��ָ����������ڴ���ָ�롣
��ָ�������ʼ��Ϊvoid*�����Խ���ǿ��ת��Ϊ���������ָ�����ͣ���ʵ�ֿɽ����á�
�����������������ڴ��ʧ�ܣ��򷵻ؿ�ָ�롣

// malloc example: random string generator
#include <stdio.h>      // printf, scanf, NULL
#include <stdlib.h>     // malloc, free, rand

int main()
{
	int i, n;
	char* buffer;

	printf("How long do you want the string? ");
	scanf("%d", &i);

	buffer = (char*)malloc(i + 1);//i + 1 ��Ϊ�˴洢�ַ��������һ���ַ� \0����ʾ�ַ����Ľ���������������
	if (buffer == NULL)
	{
		exit(1);
	}
	for (n = 0; n < i; n++)
	{
		//����ÿ��λ�� n��ʹ�� rand() ��������һ����Χ�� 0 �� 25 ֮����������
		//Ȼ��ͨ�� 'a' �� ASCII ֵ��97������ƫ�ƣ�������Сд��ĸ��
		buffer[n] = rand() % 26 + 'a';
	}

	buffer[i] = '\0';//���ַ��������һ���ַ�����Ϊ \0����ʾ�ַ����Ľ���

	printf("Random string: %s\n", buffer);
	free(buffer);

	return 0;
}

*/

/*
17>mblen
int mblen (const char* pmb, size_t max);

��ȡ���Ȳ�ȷ�����ֽ��ַ�����Ч��

����ֵ
�����Ϊpmb���ݵĲ������ǿ�ָ�룬��pmb��ָ����ַ��γ�һ����Ч�Ķ��ֽ��ַ�
���Ҳ��ǽ����Ŀ��ַ�ʱ�������ظ��ַ����ֽڴ�С��
������ǽ����Ŀ��ַ�����������0��
������ǲ�������Ч�Ķ��ֽ��ַ����򷵻�-1��

// mblen example
#include <stdio.h>      // printf
#include <stdlib.h>     // mblen, mbtowc, wchar_t(C)

void printbuffer(const char* pt, size_t max)
{
	int length;
	wchar_t dest;//����һ�����ַ����� dest�����ڴ洢ת����Ŀ��ַ���

	mblen(NULL, 0);         // ���� mblen ����״̬
	mbtowc(NULL, NULL, 0);  // ���� mbtowc ����״̬

	while (max > 0) {
		//mblen �������ز��� pt ��ָ��Ķ��ֽ��ַ��ĳ��ȡ��������С�� 1�����ж�ѭ����
		length = mblen(pt, max);
		if (length < 1) break;
		//mbtowc ���������ֽ��ַ�ת��Ϊ���ַ�����������洢�� dest ������
		mbtowc(&dest, pt, length);
		printf("[%lc]", dest);
		pt += length; max -= length;
	}
}

int main()
{
	const char str[] = "test string";

	printbuffer(str, sizeof(str));

	return 0;
}

//Printbufferһ���ַ�һ���ַ��ش�ӡ���ֽ��ַ�����
//��ʾ��ʹ����һ��ʹ�á�C�����Ի�������ͨ�ַ�����
//���Ǹú���֧�ֽ��Ͷ��ֽ��ַ��������Ի�����
//Output:
//
//[t] [e] [s] [t] [] [s] [t] [r] [i] [n] [g]

*/

/*
18>mbtowc
int mbtowc (wchar_t* pwc, const char* pmb, size_t max);
�����ֽ��ַ�ת��Ϊ��Ӧ�Ŀ��ַ�

����
pwc
ָ��wchar_t���Ͷ����ָ�롣
���ߣ��������������һ����ָ�룬����������£��������洢wchar_tת��������Ȼ���ض��ֽ��ַ����ֽڳ��ȡ�
pmb
ָ����ֽ��ַ����ַ������ĵ�һ���ֽڵ�ָ�롣
���ߣ��ò���������һ����ָ�룬����������£����������ڲ���λ״̬����Ϊ��ʼֵ�������ض��ֽ��ַ��Ƿ����������״̬�ı��롣
max
Ҫ���ǵĶ��ֽ��ַ���pmb������ֽ�����
������MB_CUR_MAX c




// mbtowc example 
#include <stdio.h>      // printf 
#include <stdlib.h>     // mbtowc, wchar_t(C) 

void printbuffer (const char* pt, size_t max)
{
  int length;
  wchar_t dest;

  mbtowc (NULL, NULL, 0);  // reset mbtowc 

  while (max>0) {
    length = mbtowc(&dest,pt,max);
    if (length<1) break;
    printf ("[%lc]",dest);
    pt+=length; max-=length;
  }
}

int main()
{
  const char str [] = "mbtowc example";

  printbuffer (str,sizeof(str));

  return 0;
}

*/

/*
19>qsort
void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
������Ԫ�ؽ�������(ִ�п�������)

�������������num��Ԫ�ؽ�������ÿ��Ԫ�صĳ���Ϊ�ֽڴ�С��ʹ�ñȽϺ���ȷ��˳��
�˺���ʹ�õ������㷨ͨ������ָ���ıȽϺ������Ƚ�Ԫ�ضԣ������ǽ�ָ��Ԫ�ضԵ�ָ����Ϊ������
�ú����������κ�ֵ����ͨ����compare����Ķ���Ԫ�ؽ��л������������޸���ָ�����������ݡ�

base
ָ��������Ҫ����ĵ�һ�������ָ�룬ת��Ϊvoid*��
num
����ָ���������Ԫ�صĸ�����Size_t��һ���޷������͡�
size
������ÿ��Ԫ�ص��ֽڴ�С��Size_t��һ���޷�������
compar
�ο�bsearch

�޷���ֵ

// qsort example
#include <stdio.h>      // printf
#include <stdlib.h>     // qsort
#include <string.h>		// strcmp

int values[] = { 40, 10, 100, 90, 20, 25 };

//int compare(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);
//}

int main()
{
	int n;
	//qsort(values, 6, sizeof(int), compare);
	qsort(values, 6, sizeof(int), strcmp);//������һЧ��һ��
	for (n = 0; n < 6; n++)
		printf("%d ", values[n]);
	return 0;
}
*/

/*
20>rand
int rand (void);

����һ��α�����
�����������һ���㷨���ɵģ����㷨ÿ�ε�����ʱ���᷵��һϵ����Ȼ����ص����֡�
���㷨ʹ��һ���������������У�������Ӧ��ʹ�ú���srand��ʼ��ΪһЩ��ͬ��ֵ��

v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

����ֵ
ȡֵ��Χ��0��RAND_MAX֮���������

// rand example: guess the number
#include <stdio.h>      // printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

int main()
{
	int iSecret, iGuess;

	// initialize random seed:
	srand(time(NULL));

	// generate secret number between 1 and 10:
	iSecret = rand() % 10 + 1;

	do {
		printf("Guess the number (1 to 10): ");
		scanf("%d", &iGuess);
		if (iSecret < iGuess) puts("The secret number is lower");
		else if (iSecret > iGuess) puts("The secret number is higher");
	} while (iSecret != iGuess);

	puts("Congratulations!");
	return 0;
}
*/

/*
21>srand
void srand (unsigned int seed);
���������ʼ��
α�����������ʹ����Ϊ���Ӵ��ݵĲ�����ʼ����
������rand������ʹ�õ�ÿ����ͬ������ֵ����������α�����������������rand���������ɲ�ͬ�Ľ�����С�
������ͬ���ӵ�������ͬ��ʼ����������rand������������ͬ�Ľ�����С�
���seed����Ϊ1���������������³�ʼ��Ϊ��ʼֵ�������������rand��rand֮ǰ��ͬ��ֵ��

Ϊ������������������֣�ͨ����srand��ʼ��ΪһЩ��ͬ������ʱֵ�����纯��time���ص�ֵ(��header <ctime>������)��

�޷���ֵ

// srand example 
#include <stdio.h>      // printf, NULL 
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 

int main()
{
	printf("First number: %d\n", rand() % 100);
	srand(time(NULL));
	printf("Random number: %d\n", rand() % 100);
	srand(1);
	printf("Again the first number: %d\n", rand() % 100);

	return 0;
}

//Possible output :
//
//First number : 41
//Random number : 13
//Again the first number : 41
*/

/*
22>system
int system (const char* command);
ִ��ϵͳ����

��������������ִ�����
���commandΪ��ָ�룬��ú�����ͨ���ú��������������Ƿ���ã����������κ����
���������Ч��ȡ����ϵͳ�Ϳ�ʵ�֣����ҿ��ܵ��³����ԷǱ�׼��ʽ���л���ֹ��


����
command
����Ҫִ�е�ϵͳ������ַ�����
���ߣ�Ҳ����ʹ�ÿ�ָ���������������

����ֵ
���command�ǿ�ָ�룬��������������õ�����·���һ����0ֵ�����û���򷵻�һ��0��
���command���ǿ�ָ�룬�򷵻ص�ֵȡ����ϵͳ�Ϳ�ʵ�֡�

// system example : DIR
#include <stdio.h>      // printf
#include <stdlib.h>     // system, NULL, EXIT_FAILURE

int main()
{
	int i;
	printf("Checking if processor is available...");
	if (system(NULL)) puts("Ok");
	else exit(EXIT_FAILURE);
	printf("Executing command DIR...\n");
	//�������� dir ����
	//������������ʾ��ǰĿ¼�е��ļ�����Ŀ¼�б��� Windows ϵͳ�У���
	i = system("dir");
	printf("The value returned was: %d.\n", i);
	return 0;
}
*/

/*
23>free
void free (void* ptr);
�ͷ��ڴ��
���Ϊ null ָ�룬��ú�����ִ���κβ�����

malloc(100*sizeof(int)) ������һ���СΪ 100 �����������ڴ棬�������ڴ���׵�ַ������ buffer1 �С�

calloc(100,sizeof(int)) ������һ���СΪ 100 �����������ڴ棬����ʼ�����е�Ԫ��Ϊ 0���������ڴ���׵�ַ������ buffer2 �С�

realloc(buffer2,500*sizeof(int)) ��֮ǰ����� buffer2 �ڴ���С��չ���� 500 ����������������ָ�뷵�ظ� buffer3��
��Ҫע����ǣ������չ�ɹ����� buffer2 ��ָ��ֵ�ᱻ�ͷţ�������ʹ�á�



// free example
#include <stdlib.h>     // malloc, calloc, realloc, free

int main()
{
	int* buffer1, * buffer2, * buffer3;
	buffer1 = (int*)malloc(100 * sizeof(int));
	buffer2 = (int*)calloc(100, sizeof(int));
	buffer3 = (int*)realloc(buffer2, 500 * sizeof(int));
	free(buffer1);
	free(buffer3);
	return 0;
}

*/


