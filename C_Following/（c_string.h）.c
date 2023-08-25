#define _CRT_SECURE_NO_WARNINGS
/*
1>memset
void * memset ( void * ptr, int value, size_t num );
��ptrָ����ڴ���ǰnum���ֽ�����Ϊָ����ֵ(����Ϊunsigned char)
������������Ϊָ���ַ�

ptr
ָ��Ҫ�����ڴ���ָ�롣
value
��Ҫ���õ�ֵ����ֵ��Ϊint���ʹ��ݣ�������ʹ�ø�ֵ��unsigned charת��������ڴ�顣
num
Ҫ����Ϊ��ֵ���ֽ�����
Size_t��һ���޷�������


#include<stdio.h>
#include<string.h>
int main() {

	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);//ʹ��memset()�������ַ��� str ��ǰ6���ַ�������Ϊ '-'��
	puts(str);

	return 0;
}
//------every programmer should know memset!

*/


/*
2>strcat
char * strcat ( char * destination, const char * source );
�����ַ���(Concatenate strings)

strcat������Source���ӵ�Destination�󣬲��Կ��ַ���������ַ�����
Source�ĳ�ʼ�ַ�����Destination����ֹnull�ַ���
���ƻ�׷���ַ���ʱ��ִ�������顣
���Դ�ַ�����Ŀ���ַ����ص�����strcat����Ϊδ���塣

Ŀ�ĵغ�Դͷ�����ص�

destination
ָ��Ŀ�������ָ�룬������Ӧ����һ��C�ַ����������㹻���԰������ӵĽ���ַ�����
source
Ҫ׷�ӵ�C�ַ�������Ӧ�ò��ص���Ŀ�ĵء�

����ֵ
����Ŀ���ַ���

#include <stdio.h>
#include <string.h>

int main()
{
	char str[80];
	//ʹ��strcpy()�������ַ��� "these "���Ƶ����� str �С�
	strcpy(str, "these ");
	//ʹ��strcat()�������ַ��� "strings "ƴ�ӵ� str ���档
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

�� C �ַ��� str1 �� C �ַ��� str2 ���бȽϡ�

�˺�����ʼ�Ƚ�ÿ���ַ����ĵ�һ���ַ���
������Ǳ˴���ȣ���������¶ԣ�ֱ���ַ���ͬ��ﵽ��ֹ���ַ���

����ֵ
����һ������ֵ����ֵָʾ�ַ���֮��Ĺ�ϵ��
����ֵ	����
<0		��һ����ƥ����ַ��� PTR1 �е�ֵ���� PTR2 �е�ֵ
0		�����ַ������������
>0		��һ����ƥ����ַ��� PTR1 �е�ֵ������ PTR2 �е�ֵ


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
��sourceָ���C�ַ������Ƶ�destinationָ��������У�
����������null�ַ�(���ڸõ�ֹͣ)��

����
destination
ָ��Ҫ�����и������ݵ�Ŀ�������ָ�롣
source
Ҫ���Ƶ�C�ַ�����

���ģ�

����Ŀ�������ֵ��

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
��ȡ�ַ�������
C�ַ����ĳ����ɽ����Ŀ��ַ�����:
C�ַ����ĳ��ȵ����ַ�����ͷ�ͽ����Ŀ��ַ�֮����ַ���
(�����������Ŀ��ַ�����)��

char mystr[100]="test string";
������һ������Ϊ100���ַ����ַ����飬����mystr��ʼ����C�ַ����ĳ���ֻ��11���ַ���
��ˣ�sizeof(mystr)�Ľ����100����strlen(mystr)�Ľ����11��
sizeof()��������Ĵ�С
strlen()�����ַ����ĳ���


����ֵ
�ַ����ĳ���

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

