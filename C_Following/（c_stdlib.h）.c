#define _CRT_SECURE_NO_WARNINGS
/*
1>exit(_exit)
void exit (int status);
在清理后(exit)或立即(_exit)终止调用进程

通过将控制权返回给主机环境来正常终止进程，
但不执行任何用于终止进程的常规清理任务（如函数所做的那样）。

如果为 0 ，则向主机环境返回成功终止状态。
如果为真 ，则向主机环境返回不成功的终止状态。

status  - 状态代码
如果为 或，则表示成功。
如果是 ，则表示失败。


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
		//exit(0);//两者效果一样
		exit(EXIT_SUCCESS);
	}
	return 0;
}
*/

/*
2>abort
void abort (void);
中止当前进程(Abort current process)
中止当前进程并返回错误代码

该函数引发信号（就像被调用一样）。
如果未捕获，则会导致程序终止，向主机环境返回依赖于平台的不成功终止错误代码。
程序在不破坏任何对象和调用传递给 或 的任何函数的情况下终止。

无返回值
Abort不会将控制权返回给调用进程。默认情况下，它终止当前进程并返回退出码3

//abort example
#include<stdio.h>
#include<stdlib.h>

int main() {

	FILE* pFile;                 // 声明一个指向 FILE 结构体类型的指针变量 pFile
	pFile = fopen("myfile.txt", "r");   // 以只读模式打开名为 "myfile.txt" 的文件，并将返回的文件指针赋值给 pFile
	if (pFile == NULL) {                 // 检查文件是否成功打开

		fputs("error opening file\n", stderr);   // 在标准错误流中输出错误消息
		abort();                                 // 终止程序的执行,没有abort();程序就不会终止
	}
	// regular process here，这里表示文件成功打开后的正常处理操作

	fclose(pFile);                     // 关闭文件
	return 0;                          // 返回整数值 0，表示程序正常结束
}

*/

/*
3>abs
int abs (int n);  --fabs是double类型
计算绝对值
返回参数 （ ） 的绝对值。

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
//输出：
//n = 23
//m = 11

*/


/*
4>at_quick_exit
int at_quick_exit (void (*func)(void));
设置快速退出时执行的功能
调用时，会自动调用 指向的函数（不带参数）。


返回值
如果函数已成功注册，则返回零值。
如果失败，则返回非零值。

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
//输出：
//Main function : Beginning
//Quick exit function.

*/

/*
5>atexit
int atexit (void (*func)(void));

设置退出时执行的功能
当程序正常终止时，会自动调用 指向的函数，不带参数。
如果对该函数的不同调用指定了多个函数，则它们都以相反的顺序作为堆栈执行
（即指定的最后一个函数是在退出时执行的第一个函数）。
可以将单个函数注册为在退出时多次执行。

返回值
如果函数已成功注册，则返回0值。
如果失败，则返回非0值。

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

将字符串转换为双精度
解析 C 字符串，将其内容解释为浮点数，并将其值返回为 .

返回值
成功后，该函数将转换后的浮点数作为值返回。
如果无法执行有效的转换，则该函数返回0（）。

// atof example: sine calculator -正弦计算器
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atof
#include <math.h>       // sin

int main()
{
	double n, m;                  // 声明两个类型为 double 的变量 n 和 m
	double pi = 3.1415926535;     // 声明一个 double 类型的变量 pi，并赋值为圆周率的近似值
	char buffer[256];             // 声明一个长度为 256 的字符数组 buffer

	printf("Enter degrees: ");    // 提示用户输入角度值
	fgets(buffer, 256, stdin);    // 从标准输入（键盘）获取用户输入并存储在 buffer 数组中
	n = atof(buffer);             // 使用 atof 函数将 buffer 中的字符串转换为 double 类型的数值，并赋值给 n
	m = sin(n * pi / 180);        // 计算角度 n 对应的正弦值，结果存在变量 m 中
	printf("The sine of %f degrees is %f\n", n, m);   // 输出结果，包括角度值和对应的正弦值
	return 0;                     // 返回整数值 0，表示程序正常结束
}

//Enter degrees : 45
//The sine of 45.000000 degrees is 0.707101


*/

/*
7>atoi
int atoi (const char * str);

将字符串转换为整数integer

返回值
成功后，该函数将转换后的整数作为值返回。
如果转换后的值超出 的可表示值范围，则会导致未定义的行为。


// atoi example
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atoi

int main()
{
	int i;                     // 声明一个类型为 int 的变量 i
	char buffer[256];          // 声明一个长度为 256 的字符数组 buffer

	printf("Enter a number: ");   // 提示用户输入一个数字
	fgets(buffer, 256, stdin);    // 从标准输入（键盘）获取用户输入的内容，并存储在 buffer 数组中
	i = atoi(buffer);             // 使用 atoi 函数将 buffer 中的字符串转换为 int 类型的数值，并赋值给 i
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);    // 输出结果，包括用户输入的值和它的两倍
	return 0;                    // 返回整数值 0，表示程序正常结束
}

*/

/*
8>atol
long int atol ( const char * str );

将字符串转换为长整数long integer

返回值
成功后，该函数将转换后的整数作为值返回。
如果无法执行有效的转换，则返回0。

// atol example
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atol

int main()
{
	long int li;
	char buffer[256];
	printf("Enter a long number: ");
	fgets(buffer, 256, stdin);
	li = atol(buffer);// 使用 atol 函数将 buffer 中的字符串转换为long int 类型的数值，并赋值给 li
	printf("The value entered is %ld. Its double is %ld.\n", li, li * 2);
	return 0;
}


//Enter a number : 567283
//The value entered is 567283. Its double is 1134566.

*/

/*
9>atoll
long long int atoll ( const char * str );

将字符串转换为长整型long long integer

返回值
成功后，该函数将转换后的整数作为值返回。
如果无法执行有效的转换，则返回0。

// atoll example
#include <stdio.h>      // printf, fgets
#include <stdlib.h>     // atoll

int main()
{
	long long int lli;
	char buffer[256];
	printf("Enter a long number: ");
	fgets(buffer, 256, stdin);
	lli = atoll(buffer);// 使用 atoi 函数将 buffer 中的字符串转换为long long int 类型的数值，并赋值给 lli
	printf("The value entered is %lld. Its double is %lld.\n", lli, lli * 2);
	return 0;
}

//Enter a number : 9275806
//The value entered is 9275806. Its double is 18551612.

*/

/*
10>bsearch
void* bsearch (const void* key, const void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

数组中的二分搜索(Binary search in array)
对已排序的数组执行二分查找。


参数
key
指向用作搜索键的对象的指针，类型转换为 .void*
base
指向执行搜索的数组的第一个对象的指针，类型转换为 .void*
num
数组中由 指向的元素数。
是无符号整型。basesize_t
size
数组中每个元素的大小（以字节为单位）。
是无符号整型。size_t
compar
指向比较两个元素的函数的指针。
由 反复调用此函数以与 中的各个元素进行比较。它应遵循以下原型：bsearchkeybase

int compar (const void* pkey, const void* pelem);
将两个指针作为参数：第一个指针始终为 ，第二个指针指向数组的一个元素（两者都类型转换为 ）。该函数应返回（以稳定和传递的方式）：keyconst void*

//strcmp的返回值，逻辑和此函数一样
返回值	意义
<0	    指向的元素 在指向的元素之前pkeypelem
0	    指向的元素等效于pkeypelem
>0	    指向的元素在指向的元素之后pkeypelem

对于可以使用常规关系运算符进行比较的类型，常规函数可能如下所示：compar


int compareMyType (const void * a, const void * b)
{
  if ( *(MyType*)a <  *(MyType*)b ) return -1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
}

返回值
指向数组中与搜索匹配的条目的指针。
如果有多个匹配元素（即，要返回的元素），这可能指向其中任何一个（不一定是第一个）。
如果未找到，则返回空指针。

//#include<stdio.h> // printf
//#include<stdlib.h> //qsort, bsearch, NULL
//
////cpmpareints 比较函数，用于排序和查找
////这行代码定义了一个名为 compareints 的函数。
////它接收两个 const void* 类型的参数 a 和 b，这些参数是指向常量内存的指针。
////在函数体中，我们通过将这些指针强制转换为 int* 类型，
////然后解引用它们，获取实际的整数值。
////函数返回 a - b 的差值。
//int compareints(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);//第一个*是解引用的意思
//}
//
//
//int main() {
//
//    int* pItem;
//    int key = 40;
//
//    // 定义整数数组并初始化
//    int values[] = { 50, 20, 60, 40, 10, 30 };
//
//    // 使用 qsort 函数对数组进行排序
//    //将 values 数组传递给 qsort 函数，
//    //同时提供数组元素的数量6、每个元素的大小sizeof(int)以及比较函数。
//    qsort(values, 6, sizeof(int), compareints);//内置函数，至于如何进行排序，不需要深度掌握内部逻辑
//
//    // 使用 bsearch 函数进行二分查找
//    //调用bsearch函数在已经排好序的数组values中搜索key值。
//    //它接受key的地址& key、数组的起始地址values、数组中元素的个数6、
//    //每个元素的大小sizeof(int)以及比较函数compareints作为参数。
//    //搜索结果被强制转换为int* 类型后赋值给pItem。
//    pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
//
//    if (pItem != NULL) {
//        // 目标值存在于数组中
//        printf("%d is in the array.\n", *pItem);
//    }
//    else {
//        // 目标值不存在于数组中
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
	//部分是将函数指针类型进行显式声明和转换的语法。在这种情况下，
	//它被用于将 strcmp 函数转换为与 qsort 函数所需的比较函数指针类型相匹配。
	//实际上，大多数情况下，C 语言在进行函数 指针类型 推断时是具有 隐式类型转换 的，而不需要显式地进行类型转换。
	//因此，在调用 qsort 函数时，可以直接传递 strcmp 函数作为比较函数，而无需进行额外的函数指针类型转换：
	//qsort(strvalues, 4, 20, (int(*)(const void*, const void*)) strcmp);
	qsort(strvalues, 4, 20, strcmp);

	// search for the key: （因为指针就是地址，本来就是唯一的）
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
在内存中分配一个元素初始化为0的数组(Allocate and zero-initialize array)


参数
num
要分配的元素数。
size
每个元素的大小。

返回值
成功时，指向函数分配的内存块的指针。
该指针的类型为always，可以将其强制转换为所需的数据指针类型，以实现可解引用
如果函数无法分配请求的内存块，则返回空指针。void*

#include <stdio.h>      // printf, scanf, NULL
#include <stdlib.h>     // calloc, exit, free
int main() {
	int i, n;
	int* pData;
	printf("Amount of numbers to be entered: ");
	scanf("%d", &i);
	pData = (int*)calloc(i, sizeof(int));
	//calloc 函数接受两个参数：要分配的元素数量 i 和每个元素的大小 sizeof(int)。
	//如果分配失败（即 pData 为 NULL），则通过 exit(1) 来终止程序。
	if (pData == NULL)
	{
		exit(1);
	}
	for (n = 0; n < i; n++)
	{
		//如果 n 的值为 0，则该行代码将打印出 "Enter number #1:"，提示用户输入第一个数字；
		// 如果 n 的值为 1，则打印 "Enter number #2:"，
		// 依此类推。这样，用户可以按照提示输入相应的数字。
		printf("Enter number #%d:", n + 1);
		scanf("%d", &pData[n]);
	}
	printf("You have entered: ");
	for (n = 0; n < i; n++)
	{
		printf("%d ", pData[n]);
	}
	free(pData);//free 函数释放动态分配的内存，防止内存泄漏
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
计算两个整数值的商和余数。

参数
numer
Numerator.（分子）
denom（分母项）
Denominator.（分母）

返回值
Div返回类型为div_t的结构，包含商和余数。该结构在STDLIB.H中定义。

#include <stdio.h>      //printf
#include <stdlib.h>     //div, div_t

int main()
{
	//声明了一个 div_t 类型的结构体变量 div_result，用于存储除法结果,divresult.quot,divresult.rem
	div_t divresult;
	divresult = div(38, 5);
	printf("38 div 5 => %d, remainder %d.\n", divresult.quot, divresult.rem);
	return 0;
}

//38 div 5 => 7, remainder 3.
*/

/*
13>div_v
div_t结构包含商int quot和余数int rem
*/


/*
14>getenv
char* getenv (const char* name);//检索包含指定为参数的环境变量的值的 C 字符串。如果请求的变量不是环境列表的一部分，则该函数将返回空指针。
从当前环境获取一个值

返回值
返回带有请求的环境变量值的c字符串，
如果不存在这样的环境变量，则为空指针

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
计算长整数的绝对值

返回值
n的绝对值

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
分配内存块

返回值
如果成功，则返回一个指向函数分配的内存块的指针。
该指针的类型始终为void*，可以将其强制转换为所需的数据指针类型，以实现可解引用。
如果函数分配请求的内存块失败，则返回空指针。

// malloc example: random string generator
#include <stdio.h>      // printf, scanf, NULL
#include <stdlib.h>     // malloc, free, rand

int main()
{
	int i, n;
	char* buffer;

	printf("How long do you want the string? ");
	scanf("%d", &i);

	buffer = (char*)malloc(i + 1);//i + 1 是为了存储字符串的最后一个字符 \0（表示字符串的结束），否则会溢出
	if (buffer == NULL)
	{
		exit(1);
	}
	for (n = 0; n < i; n++)
	{
		//对于每个位置 n，使用 rand() 函数生成一个范围在 0 到 25 之间的随机数，
		//然后通过 'a' 的 ASCII 值（97）进行偏移，以生成小写字母。
		buffer[n] = rand() % 26 + 'a';
	}

	buffer[i] = '\0';//将字符串的最后一个字符设置为 \0，表示字符串的结束

	printf("Random string: %s\n", buffer);
	free(buffer);

	return 0;
}

*/

/*
17>mblen
int mblen (const char* pmb, size_t max);

获取长度并确定多字节字符的有效性

返回值
如果作为pmb传递的参数不是空指针，则当pmb所指向的字符形成一个有效的多字节字符
并且不是结束的空字符时，将返回该字符的字节大小。
如果它是结束的空字符，则函数返回0，
如果它们不构成有效的多字节字符，则返回-1。

// mblen example
#include <stdio.h>      // printf
#include <stdlib.h>     // mblen, mbtowc, wchar_t(C)

void printbuffer(const char* pt, size_t max)
{
	int length;
	wchar_t dest;//声明一个宽字符类型 dest，用于存储转换后的宽字符。

	mblen(NULL, 0);         // 重置 mblen 函数状态
	mbtowc(NULL, NULL, 0);  // 重置 mbtowc 函数状态

	while (max > 0) {
		//mblen 函数返回参数 pt 所指向的多字节字符的长度。如果长度小于 1，则中断循环。
		length = mblen(pt, max);
		if (length < 1) break;
		//mbtowc 函数将多字节字符转换为宽字符，并将结果存储在 dest 变量中
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

//Printbuffer一个字符一个字符地打印多字节字符串。
//该示例使用了一个使用“C”语言环境的普通字符串，
//但是该函数支持解释多字节字符串的语言环境。
//Output:
//
//[t] [e] [s] [t] [] [s] [t] [r] [i] [n] [g]

*/

/*
18>mbtowc
int mbtowc (wchar_t* pwc, const char* pmb, size_t max);
将多字节字符转换为相应的宽字符

参数
pwc
指向wchar_t类型对象的指针。
或者，这个参数可以是一个空指针，在这种情况下，函数不存储wchar_t转换，但仍然返回多字节字符的字节长度。
pmb
指向多字节字符（字符串）的第一个字节的指针。
或者，该参数可以是一个空指针，在这种情况下，函数将其内部移位状态重置为初始值，并返回多字节字符是否具有依赖于状态的编码。
max
要考虑的多字节字符的pmb的最大字节数。
不超过MB_CUR_MAX c




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
对数组元素进行排序(执行快速排序)

按基数对数组的num个元素进行排序，每个元素的长度为字节大小，使用比较函数确定顺序。
此函数使用的排序算法通过调用指定的比较函数来比较元素对，方法是将指向元素对的指针作为参数。
该函数不返回任何值，但通过按compare定义的对其元素进行基本重排序来修改所指向的数组的内容。

base
指向数组中要排序的第一个对象的指针，转换为void*。
num
基数指向的数组中元素的个数。Size_t是一个无符号整型。
size
数组中每个元素的字节大小。Size_t是一个无符号整型
compar
参考bsearch

无返回值

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
	qsort(values, 6, sizeof(int), strcmp);//和上述一效果一样
	for (n = 0; n < 6; n++)
		printf("%d ", values[n]);
	return 0;
}
*/

/*
20>rand
int rand (void);

生成一个伪随机数
这个数字是由一种算法生成的，该算法每次调用它时都会返回一系列显然不相关的数字。
该算法使用一个种子来生成序列，该序列应该使用函数srand初始化为一些不同的值。

v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

返回值
取值范围在0到RAND_MAX之间的整数。

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
设置随机起始点
伪随机数生成器使用作为种子传递的参数初始化。
对于在rand调用中使用的每个不同的种子值，可以期望伪随机数生成器在随后的rand调用中生成不同的结果序列。
具有相同种子的两个不同初始化将在随后的rand调用中生成相同的结果序列。
如果seed设置为1，则生成器被重新初始化为初始值，并产生与调用rand或rand之前相同的值。

为了生成类似随机的数字，通常将srand初始化为一些不同的运行时值，例如函数time返回的值(在header <ctime>中声明)。

无返回值

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
执行系统命令

调用命令处理程序来执行命令。
如果command为空指针，则该函数仅通过该函数检查命令处理器是否可用，而不调用任何命令。
调用命令的效果取决于系统和库实现，并且可能导致程序以非标准方式运行或终止。


参数
command
包含要执行的系统命令的字符串。
或者，也可以使用空指针来检查命令处理程序。

返回值
如果command是空指针，则在命令处理器可用的情况下返回一个非0值，如果没有则返回一个0。
如果command不是空指针，则返回的值取决于系统和库实现。

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
	//它调用了 dir 命令
	//该命令用于显示当前目录中的文件和子目录列表（在 Windows 系统中）。
	i = system("dir");
	printf("The value returned was: %d.\n", i);
	return 0;
}
*/

/*
23>free
void free (void* ptr);
释放内存块
如果为 null 指针，则该函数不执行任何操作。

malloc(100*sizeof(int)) 分配了一块大小为 100 个整型数的内存，并将该内存的首地址保存在 buffer1 中。

calloc(100,sizeof(int)) 分配了一块大小为 100 个整型数的内存，并初始化所有的元素为 0，并将该内存的首地址保存在 buffer2 中。

realloc(buffer2,500*sizeof(int)) 将之前分配的 buffer2 内存块大小扩展到了 500 个整型数，并将其指针返回给 buffer3。
需要注意的是，如果扩展成功，则 buffer2 的指针值会被释放，不能再使用。



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


