#define _CRT_SECURE_NO_WARNINGS
/*
1>memset
void * memset ( void * ptr, int value, size_t num );
将ptr指向的内存块的前num个字节设置为指定的值(解释为unsigned char)
将缓冲区设置为指定字符

ptr
指向要填充的内存块的指针。
value
需要设置的值。该值作为int类型传递，但函数使用该值的unsigned char转换来填充内存块。
num
要设置为该值的字节数。
Size_t是一个无符号整型


#include<stdio.h>
#include<string.h>
int main() {

	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);//使用memset()函数将字符串 str 的前6个字符都设置为 '-'。
	puts(str);

	return 0;
}
//------every programmer should know memset!

*/


/*
2>strcat
char * strcat ( char * destination, const char * source );
连接字符串(Concatenate strings)

strcat函数将Source附加到Destination后，并以空字符结束结果字符串。
Source的初始字符覆盖Destination的终止null字符。
复制或追加字符串时不执行溢出检查。
如果源字符串和目标字符串重叠，则strcat的行为未定义。

目的地和源头不得重叠

destination
指向目标数组的指针，该数组应包含一个C字符串，并且足够大以包含连接的结果字符串。
source
要追加的C字符串。这应该不重叠的目的地。

返回值
返回目标字符串

#include <stdio.h>
#include <string.h>

int main()
{
	char str[80];
	//使用strcpy()函数将字符串 "these "复制到数组 str 中。
	strcpy(str, "these ");
	//使用strcat()函数将字符串 "strings "拼接到 str 后面。
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	puts(str);
	return 0;
}
//Output:
//these strings are concatenated.
*/


/*
3>strcmp
int strcmp ( const char * str1, const char * str2 );

将 C 字符串 str1 与 C 字符串 str2 进行比较。

此函数开始比较每个字符串的第一个字符。
如果它们彼此相等，则继续以下对，直到字符不同或达到终止空字符。

返回值
返回一个整数值，该值指示字符串之间的关系：
返回值	表明
<0		第一个不匹配的字符在 PTR1 中的值低于 PTR2 中的值
0		两个字符串的内容相等
>0		第一个不匹配的字符在 PTR1 中的值大于在 PTR2 中的值


#include <stdio.h>
#include <string.h>

int main()
{
	char key[] = "apple";
	char buffer[80];
	do {
		printf("Guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (strcmp(key, buffer) != 0);
	puts("Correct answer!");
	return 0;
}
//output:
//Guess my favourite fruit ? orange
//Guess my favourite fruit ? apple
//Correct answer!
*/


/*
4>strcpy
char * strcpy ( char * destination, const char * source );
将source指向的C字符串复制到destination指向的数组中，
包括结束的null字符(并在该点停止)。

参数
destination
指向要在其中复制内容的目标数组的指针。
source
要复制的C字符串。

译文：

返回目标数组的值。

#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}
//Output:
//
//str1: Sample string
//str2 : Sample string
//str3 : copy successful

*/


/*
5>strlen
size_t strlen ( const char * str );
获取字符串长度
C字符串的长度由结束的空字符决定:
C字符串的长度等于字符串开头和结束的空字符之间的字符数
(不包括结束的空字符本身)。

char mystr[100]="test string";
定义了一个长度为100个字符的字符数组，但是mystr初始化的C字符串的长度只有11个字符。
因此，sizeof(mystr)的结果是100，而strlen(mystr)的结果是11。
sizeof()计算数组的大小
strlen()计算字符串的长度


返回值
字符串的长度

#include <stdio.h>
#include <string.h>

int main()
{
	char szInput[256];
	printf("Enter a sentence: ");
	gets(szInput);
	printf("The sentence entered is %u characters long.\n", (unsigned)strlen(szInput));
	return 0;
}
//Output:
//
//Enter sentence : just testing
//The sentence entered is 12 characters long.
*/

