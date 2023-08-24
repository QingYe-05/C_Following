#define _CRT_SECURE_NO_WARNINGS

//<cstdio>(stdio.h)�⺯��

/*
1>remove

int remove(const char* filename);
ɾ���ļ�
ɾ���ļ�����ָ�����Ƶ��ļ���
����ֱ�Ӷ����ļ�����ʶ���ļ�ִ�еĲ���;�����в��漰�κ�����

����ֵ
����ļ�ɾ���ɹ����򷵻�0��
ʧ��ʱ�����ط�0ֵ��

#include<stdio.h>
int main() {
	if (remove("myfile.txt") != 0)
	{
		perror("Error deleting file\n");
	}
	else
	{
		puts("File successfully deleted\n");
	}
	return 0;
}

*/

/*
2>getchar
int getchar ( void );

�ӱ�׼�л�ȡ�ַ�
���ر�׼���� ����׼���룩 �е���һ���ַ���
���൱���� stdin ��Ϊ�������� getc��

����ֵ
�ɹ��󣬽������ַ���ȡ������Ϊ int ֵ����
��������Ϊ int ����Ӧ����ֵ EOF����ֵָʾʧ�ܣ�
End of file


3>putchar
int putchar ( int character );

���ַ�д���׼�������׼�������
���൱���ñ�׼������� putc ��Ϊ�ڶ�����

����ֵ
�ɹ��󣬽�������д�ַ���
�������д������򷵻� EOF �����ô���ָʾ����ferror����


#include<stdio.h>
int main() {
	int c;
	puts("Enter text. Include a dot('.') in a sentence to ");
		do
		{
			c = getchar();//�Ӽ����л�ȡһ���ַ�
			putchar(c);//���ַ���ӡ����Ļ��
		} while (c != '.');//������ַ�!='.'ʱ������ѭ����ctrl+z�������������ѭ��
	return 0;
}
*/

/*
4>gets
char * gets ( char * str );

�ӱ�׼�����л�ȡ�ַ���
[ע�⣺�˹����� C �� C++ �в��ٿ��ã��� C11 �� C++14 ��ʼ��]
�ӱ�׼���� ��stdin�� �ж�ȡ�ַ�������������Ϊ C �ַ����洢�� str �У�ֱ�����ﻻ�з����ļ�ĩβ��

����ֵ
�ɹ��󣬺������� str��
���������ȡ���������ô���ָʾ����ferror���������ؿ�ָ�루��strָ������ݿ����Ѹ��ģ�
#include <stdio.h>

int main()
{
	char string[256];
	printf("Insert your full address: ");
	gets(string);     // warning: unsafe (see fgets instead)
	printf("Your address is: %s\n", string);
	return 0;
}
*/

/*
5>perror
����
void perror ( const char * str );

��ӡ������Ϣ
������� str ���ǿ�ָ�룬���ӡ str ���ð�� ��:)��һ���ռ䡣Ȼ������ str �Ƿ�Ϊ��ָ�룬�����ӡ���ɵĴ���������������з� ��'\n'����
����ǿ�ָ�룬�򲻻��ӡǰ����Զ�����Ϣ�����Ի��ӡ������Ϣ��

�޷���ֵ

#include <stdio.h>
int main() {
	//��C�����У�FILE* pfile ��һ��������������������һ����Ϊ pfile ��ָ�룬��ָ����Ա����������ļ���
	//FILE* ��һ���ļ����͵�ָ�룬��ָ��һ����Ϊ FILE �Ľṹ�壬�ýṹ����������ڹ����ļ�������Ϣ�����ļ�����λ��ָ��ȡ�
	//ͨ��ʹ�� FILE* ָ�룬����Դ��ļ�����ȡ�ļ����ݡ�д���ļ����ݡ��ر��ļ��Ȳ�����
	//������Ҫʹ���ļ�ʱ��ͨ����ʹ�� fopen() �������ļ��򿪣��������ص��ļ�ָ�븳�� FILE* ���͵ı�����
	//Ȼ�������ʹ�����ָ����ִ���ļ����������ȡ��д�����ݡ�
	//���ʹ�� fclose() �����ر��ļ����ͷ���Դ��

	FILE* pfile;  // ����һ���ļ�ָ��
	pfile = fopen("example.txt", "r");  // ���ļ�����ֻ����ʽ
	if (pfile != NULL) {
		// �ļ������������ȡ�ļ�����
		// ...
		fclose(pfile);  // �ر��ļ�
	}
	else {
		perror("The folling error occurred");
	}
	return 0;
}

*/

/*
6>printf


�淶		���										��
d �� i	�з���ʮ��������							392
u		�޷���ʮ��������							7235
o		�޷��Ű˽���								610
x		�޷���ʮ����������						7FA
X		�޷���ʮ��������������д��					7FA
f		ʮ���Ƹ�������Сд						392.65
F		ʮ���Ƹ���������д						392.65
e		��ѧ��������β��/ָ������Сд				3.9265e+2
E		��ѧ��������β��/ָ��������д				3.9265E+2
g		ʹ����̱�ʾ��ʽ��%e �� %f				392.65
G		ʹ����̱�ʾ��ʽ��%E �� %F				392.65
һ��		ʮ�����Ƹ�������Сд						-0xc.90FEP-2
һ��		ʮ�����Ƹ���������д						-0XC.90FEP-2
c		�ַ�										һ��
s		�ַ���									����
p		ָ���ַ									b8000000
n		û�д�ӡ�κ����ݡ�
		��Ӧ�Ĳ���������ָ���з��� int ��ָ�롣
		��ĿǰΪֹд����ַ����洢��ָ���λ�á�
%		һ�� % �����һ�� % �ַ��Ὣ���� % д������	%

--��ʽ˵��--
��־						����
-			�ڸ����ֶο���������;�Ҷ�����Ĭ��ֵ������Ŀ����˵��������
+			��ʹ�������У�Ҳ���ڽ��ǰ����ϼӺŻ���ţ�+��-����Ĭ������£�ֻ�и���ǰ����� - ���š�
�ո�			���������д���κη��ţ������ֵ֮ǰ����һ���ո�
#			�� o��x �� X ˵����һ��ʹ��ʱ������С�����ֵ��ֵǰ��ֱ���� 0��0x �� 0X��
			�� a��A��e��E��f��F��g �� G һ��ʹ��ʱ����ǿ��д���������С���㣬��ʹ����û�и�������֡�
			Ĭ������£����û�����ֺ������д��С���㡣
0			ָ�����ʱ������ ��0�� �����ǿո���������֣�����Ŀ����˵��������
����			Ҫ��ӡ����С�ַ��������Ҫ��ӡ��ֵС�ڴ����֣����ÿո����������ʹ�������Ҳ����ضϸ�ֵ��
*			��Ȳ����ڸ�ʽ�ַ�����ָ���ģ�������Ϊ�����ʽ���Ĳ���֮ǰ�ĸ�������ֵ����ָ���ġ�

	specifiers��˵������
length	d i				u o x X				f F e E g G a A			c				s		p		n
(none)	int	unsigned	int						double				int				char*	void*	int*
hh		signed char		unsigned char																signed char*
h		short int		unsigned short int															short int*
l		long int		unsigned long int							wint_t	wchar_t*				long int*
ll		long long int	unsigned long long int														long long int*
j		intmax_t		uintmax_t																	intmax_t*
z		size_t			size_t																		size_t*
t		ptrdiff_t		ptrdiff_t																	ptrdiff_t*
L												long double

//example
#include<stdio.h>
int main() {
	printf("Characters: %c %c \n", 'a', 65);
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d \n", 1977);//�����Ļ���֮ǰ���ո�
	printf("Preceding with zeros: %010d \n", 1977);//�����Ļ���֮ǰ���0
	printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	//%4.2f ��ʾ�������������ܿ��Ϊ4��С�������2λ�ĸ�ʽ�������ˣ������� 3.1416 ���Ϊ 3.14��
	//%+.0e ��ʾ���������ÿ�ѧ��������ʾ������ָ�����ֲ���С��λ������������ʾ���š������� 3.1416 �ڴ˸�ʽ�����Ϊ +3e+00��
	//%E ��ʾ���������ÿ�ѧ��������ʾ������ָ�����ֲ��ô�д��ĸ�������� 3.1416 �ڴ˸�ʽ�����Ϊ 3.141600E+00��
	printf("Width trick: %*d \n", 5, 10);
	printf("%s \n", "A string");
	return 0;
}

//output

Characters: a A
Decimals: 1977 650000
Preceding with blanks:       1977
Preceding with zeros: 0000001977
Some different radices: 100 64 144 0x64 0144
floats: 3.14 +3e+000 3.141600E+000
Width trick:    10
A string

*/




/*

7>fopen
FILE * fopen ( const char * filename, const char * mode );
���ļ�
���ڲ����ļ�����ָ�������Ƶ��ļ�������������ڽ����Ĳ������ɷ��ص� FILE ָ���ʶ�����������
���ص�ָ�����ͨ������ fclose �� freopen ���ļ�������������д򿪵��ļ�������������ֹʱ�Զ��رա�
���л���֧������ͬʱ��FOPEN_MAX���ļ���

����
filename
����Ҫ�򿪵��ļ������Ƶ� C �ַ�����
��ֵӦ��ѭ���л������ļ����淶�����ҿ��԰���·�������ϵͳ֧�֣���
mode
�����ļ�����ģʽ�� C �ַ������������ǣ�

��r��		�������ļ�����������������ļ�������ڡ�
��w��		д��Ϊ�����������һ�����ļ�������Ѵ���ͬ���ļ�����ᶪ�������ݣ��������ļ���Ϊ�µĿ��ļ���
��һ��		���ӣ����ļ�ĩβ���ļ�����������������ʼ�ս�����д���ļ�ĩβ�������������չ��
		���¶�λ������fseek��fsetpos��rewind���������ԡ�����ļ������ڣ��򴴽����ļ���
��r+��	��ȡ/���£����ļ����и��£����������������ļ�������ڡ�
��w+��	д��/���£�����һ�����ļ����������и��£�����������������
		����Ѵ���ͬ���ļ�����ᶪ�������ݣ��������ļ���Ϊ�µĿ��ļ���
��A+��	׷��/���£���һ���ļ����и��£�����������������������������ļ�ĩβд�����ݡ�
		���¶�λ������fseek��fsetpos��rewind����Ӱ����һ���������������������Ὣλ���ƻ��ļ�ĩβ��
		����ļ������ڣ��򴴽����ļ���

ʹ�������ģʽ˵�������ļ�����Ϊ�ı��ļ��򿪡�Ϊ�˽��ļ���Ϊ�������ļ��򿪣�ģʽ�ַ����б��������b���ַ���
�������ġ�b���ַ����Ը��ӵ��ַ�����ĩβ���Ӷ��γ����¸���ģʽ����rb������wb������ab������r+b������w+b������a+b������
���߲�����ĸ�ͻ��ģʽ�ġ�+������֮�䣨��rb+������wb+������ab+������

����ֵ
����ļ��ɹ��򿪣��ú���������ָ�� FILE �����ָ�룬�ö���������ڽ����Ĳ����б�ʶ����
���򣬽����ؿ�ָ�롣

#include<stdio.h>
int main() {
	FILE* pFile;
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL)
	{
		fputs("fopen example", pFile);
		printf("�ɹ�\n");
		fclose(pFile);
	}
	else
	{
		perror("�򿪴���");
	}
	return 0;
}

*/

/*
8>putc
int putc ( int character, FILE * stream );

���ַ�д����
���ַ�д������ǰ��λ��ָʾ����
�ַ�д�������ڲ�λ��ָʾ��ָʾ��λ�ã�Ȼ���Զ�ǰ��һ��

���ַ�д����
���ַ�д������ǰ��λ��ָʾ����
�ַ�д�������ڲ�λ��ָʾ��ָʾ��λ�ã�Ȼ���Զ�ǰ��һ��

#include<stdio.h>
int main() {
	FILE* pFile;
	char c;

	pFile = fopen("alphabet.txt", "wt");//"w" ��ʾ��д��ģʽ���ļ�������ļ������ڣ�������һ�����ļ�������ļ��Ѵ��ڣ��������ļ����ݡ�"t" ��ʾ���ı�ģʽ���ļ������ı�ģʽ�£������ļ��Ķ�д����ʱ�ᴦ���ı��Ļ��з��������ַ���ת����
	for ( c = 'A'; c < 'Z'; c++)
	{
		putc(c, pFile);
	}
	fclose(pFile);
	return 0;
}
*/
/*
9>putchar
nt putchar ( int character );

���ַ�д���׼���
���ַ�д���׼�������׼�������

����ֵ
�ɹ��󣬽�������д�ַ���
�������д������򷵻� EOF �����ô���ָʾ����ferror����

#include<stdio.h>
int main() {
	char c;
	for ( c = 'A'; c < 'Z'; c++)
	{
		putchar(c);
	}

	return 0;
}
*/
/*
10>puts
int puts ( const char * str );

���ַ���д���׼���
�� str ָ��� C �ַ���д���׼��� ��stdout�� �����ӻ��з� ��'\n'����
�ú�����ָ���ĵ�ַ ��str�� ��ʼ���ƣ�ֱ��������ֹ���ַ� ��'\0'��������ֹ���ַ����Ḵ�Ƶ����С�
��ע�⣬put �� fput �Ĳ�֮ͬ������������ʹ�� stdout ��ΪĿ�꣬���һ����Զ���ĩβ���ӻ��з���fput ���ᣩ��


����ֵ
�ɹ�ʱ�������طǸ�ֵ��
����ʱ���ú������� EOF �����ô���ָʾ����ferror����

#include<stdio.h>
int main() {
	char string[] = "hello world!";
	puts(string);
	return 0;
}
*/
/*
11>rename
int rename ( const char * oldname, const char * newname );

�������ļ�
��������ָ�����ļ���Ŀ¼�����Ƹ���Ϊ�����ơ�
����ֱ�Ӷ��ļ�ִ�еĲ���;�����в��漰�κ�����
��� oldname �� newname ָ���˲�ͬ��·��������ϵͳ֧�������������ļ����ƶ�����λ�á�
��� newname ���������ļ�����ú������ܻ�ʧ�ܻ򸲸������ļ�������ȡ�����ض���ϵͳ�Ϳ�ʵ�֡�

����ֵ(ͬremove)
����ļ��������ɹ����򷵻���ֵ��
ʧ��ʱ�����ط���ֵ��

#include<stdio.h>
int main() {
	int result;
	char oldname[] = "oldname.txt";
	char newname[] = "newname.txt";
	result = rename(oldname, newname);
	if (result==0)
	{
		puts("File successfully renamed");
	}
	else
	{
		perror("Error renaming file");
	}
	return 0;
}
*/
/*
12>rewind
void rewind ( FILE * stream );

������λ������Ϊ��ͷ
������������λ��ָʾ������Ϊ�ļ��Ŀ�ͷ��
�ɹ����ô˺����󣬽���������������ļ������ʹ����ڲ�ָʾ�������ҽ�������ǰ�Դ����� ungetc �ĵ��õ�����Ч����
�ڴ򿪽��и��£���+д�������ϣ��Ե����ĵ��������ڶ�ȡ��д��֮���л���

�޷���ֵ

*/
//#include<stdio.h>
//int main() {
//	int n;
//	FILE* pFile;
//	char buffer[27];
//	pFile = fopen("alphabet.txt", "w+");
//	for (n = 'a'; n <= 'c'; n++)
//	{
//		fputc(n, pFile);//putc �� fputc �ǵ�Ч�ģ�ֻ�� putc ��ĳЩ���п�����Ϊ��ʵ�֡�
//	}
//	rewind(pFile);//һ�������� rewind() ������֮��Ķ�д�����ͻ���ļ��Ŀ�ͷ��ʼ���У������Ǽ������ļ���ǰλ�ý��С�
//	fread(buffer, 1, 26, pFile);//��26��1�ֽڴ�С���ַ������ļ����ķ�ʽ�洢��buffer�����壩�ڴ����
//	fclose(pFile);//�ر��ļ����ͷ���Դ��
//	buffer[26] = '\0';
//	puts(buffer);
//	return 0;
//}

/*
13>fread
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );//size_t��ʾ�޷�������

ptr��ָ���С����Ϊ ��size*count�� �ֽڵ��ڴ���ָ�룬ת��Ϊ void*��
size:Ҫ��ȡ��ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��,size_t���޷����������͡�
count:Ԫ�ظ�����ÿ��Ԫ�صĴ�СΪ�ֽڴ�С��
stream:ָ��ָ���������� FILE �����ָ��

�����ж�ȡ���ݿ�
�����ж�ȡ����Ԫ�����飬ÿ��Ԫ�صĴ�СΪ�ֽڣ��������Ǵ洢�� ptr ָ�����ڴ���С�
����λ��ָʾ������ȡ�����ֽ���ǰ����
����ɹ������ȡ�����ֽ���Ϊ����С*������

����ֵ
���سɹ���ȡ��Ԫ��������
����������� count ������ͬ�����ʾ��ȡʱ������ȡ����򵽴��ļ�ĩβ��������������£�����������ȷ��ָ�꣬���Էֱ��� ferror �� feof ���м�顣
�����С�����Ϊ0����ú�������0��������״̬�� ptr ָ������ݱ��ֲ��䡣

#include<stdio.h>
#include<stdlib.h>
int main() {
	FILE* pFile;
	long lSize;
	char* buffer;
	size_t result;

	pFile = fopen("alphabet.txt", "rb");
	if (pFile == NULL)
	{
		fputs("File error", stderr);//stderr��׼����ͱ�׼����ӡ����Ļ��
		exit(1);//stdlib.h
	}

	//��ȡ�ļ���С��
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);//��ȡ�ļ���ǰ��ָ��λ��
	rewind(pFile);//���ļ�ָ�����¶�λ���ļ��Ŀ�ͷ���ӿ�ͷ��

	//�����ڴ��԰��������ļ�
	buffer = (char*)malloc(sizeof(char) * lSize);// ����(lSize)�ļ���С�����ڴ�ռ� malloc - m:memory�ڴ� alloc:allocate����
	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
		exit(2);
	}
	//���ļ����Ƶ���������
	result = fread(buffer, 1, lSize, pFile);// ���ļ��ж�ȡ���ݵ�������,��lSize��1�ֽڴ�С���ַ������ļ����ķ�ʽ�洢��result�����壩�ڴ����
	if (result != lSize)
	{
		fputs("Reading error", stderr);

		exit(3);
	}
	printf("%d", result);

	//�����ļ����ڱ����ص��ڴ滺������
	// terminate��ֹ
	fclose(pFile);
	free(buffer);
	return 0;
}

//�˴��뽫 alphabet.txt ���ص���̬������ڴ滺�����У��û����������ڽ��ļ���������Ϊ������в�����


*/



/*
14>fseek
int fseek ( FILE * stream, long int offset, int origin );

���¶�λ��λ��ָʾ��(���ļ�ָ���ƶ���ָ��λ��)
������������λ��ָʾ������Ϊ��λ�á�
�����Զ�����ģʽ�򿪵�������λ����ͨ����Դָ���Ĳο�λ�����ƫ����������ġ�
�������ı�ģʽ�򿪵�����ƫ����ӦΪ�����ǰ���� ftel ���ص�ֵ������Դ����SEEK_SET��

stream
ָ���ʶ���� FILE �����ָ�롣
offset
�������ļ���Ҫ��Դƫ�Ƶ��ֽ�����
�ı��ļ������ ftell ���ص�ֵ��
origin
����ƫ�Ʋο���λ�á����� <cstdio> �ж�������³���֮һָ����ר�������˺����Ĳ�����
����	�ο�λ��
SEEK_SET	�ļ���ͷ
SEEK_CUR	�ļ�ָ��ĵ�ǰλ��
SEEK_END	�ļ���β *

����ֵ
����ɹ����ú���������0��
�����������ط�0ֵ��
���������ȡ��д����������ô���ָʾ����ferror����

#include<stdio.h>
int main() {
	FILE* pFile;  // ����һ���ļ�ָ����� pFile
	pFile = fopen("alphabet.txt", "wb"); // ����Ϊ "alphabet.txt" ���ļ��Թ�д�룬�����ļ�ָ�븳ֵ�� pFile
	fputs("This is an apple.", pFile); // ���ļ���д���ַ��� "This is an apple."
	fseek(pFile, 9, SEEK_SET); // ���ļ��ж�λ�������ļ� ��ʼ λ�� 9 ���ֽڵ�λ��
	fputs(" sam", pFile);  // �ڶ�λ���λ��д���ַ��� "sam"
	fseek(pFile, 2, SEEK_CUR); // ���ļ��ж�λ�������ļ� ��ǰ λ�� 2 ���ֽڵ�λ��
	fputs(" sam", pFile);
	fseek(pFile, 0, SEEK_CUR); // ���ļ��ж�λ�������ļ� ĩβ λ�� 0 ���ֽڵ�λ��
	fputs(" sam", pFile);
	fclose(pFile);  // �ر��ļ�
	return 0;
}

//�ĵ��е����� - ����sam�ֱ��Ӧ SEEK_SET SEEK_CUR SEEK_END
//This is a sampl sam sam
*/

/*
15>ftell
long int ftell ( FILE * stream );
��ȡ���еĵ�ǰλ��
��������λ��ָʾ���ĵ�ǰֵ()��
���ڶ������������Ǵ��ļ���ͷ��ʼ���ֽ�����
�����ı�������ֵ����û�����壬���Կ������Ժ�ʹ�� fseek ��λ�ûָ�����ͬλ��

����ֵ
�ɹ��󣬷��ز�λָ��ĵ�ǰֵ��
ʧ��ʱ������ -1L������ errno ����Ϊ�ض���ϵͳ����ֵ��

#include <stdio.h>
int main()
{
	FILE* pFile;
	long size;

	pFile = fopen("alphabet.txt", "rb");
	if (pFile == NULL)
	{
		perror("Error opening file");
	}
	else
	{
		fseek(pFile, 0, SEEK_END);   // non-portable��������ֲ��
		size = ftell(pFile);//��ȡ��ǰָ���λ��
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	return 0;
}

*/

/*
16>scanf
�ο�printf

#include <stdio.h>
int main ()
{
  char str [80];
  int i;

  printf ("Enter your family name: ");
  scanf ("%79s",str);
  printf ("Enter your age: ");
  scanf ("%d",&i);
  printf ("Mr. %s , %d years old.\n",str,i);
  printf ("Enter a hexadecimal number: ");
  scanf ("%x",&i);
  printf ("You have entered %#x (%d).\n",i,i);

  return 0;
}

//Enter your family name: Soulie
//Enter your age: 29
//Mr. Soulie , 29 years old.
//Enter a hexadecimal number: ff
//You have entered 0xff (255).
*/

/*
17>setbuf
void setbuf ( FILE * stream, char * buffer );

����������
	��ע��
	setbuf�����������Ļ��塣stream��������ָ��һ��δ����д�Ĵ��ļ���
	���buffer����ΪNULL������δ�����塣
	������ǣ�����������ָ�򳤶�ΪBUFSIZ���ַ����飬����BUFSIZ��STDIO.H�ж���Ļ�������С��
	�û�ָ���Ļ������������Ǹ�������Ĭ��ϵͳ����Ļ�����������I/O���塣
	Ĭ������£�stderr�����޻���ģ���������ʹ��setbufΪstderr���仺������

����
stream
ָ���ʶ������ FILE �����ָ�롣
buffer
�û�����Ļ�����������Ӧ����Ϊ BUFSIZ �ֽڡ�
���ߣ�����ָ����ָ���Խ��û��塣

�޷���ֵ

#include <stdio.h>
int main()
{
	//BUFSIZ ��һ���궨�壬�ڱ�׼��ͷ�ļ� <stdio.h> �ж��壬��ʾ��׼I/O�������Ĵ�С��
	//���ľ���ֵ���Ը���ϵͳ�ͱ������Ĳ�ͬ���仯��ͨ����һ���ϴ��������

	char buffer[BUFSIZ];  // ����һ���ַ����� buffer����СΪ BUFSIZ
	FILE* pFile1, * pFile2;  // ���������ļ�ָ����� pFile1 �� pFile2

	pFile1 = fopen("myfile1.txt", "w");  // ʹ�� д��ģʽ ����Ϊ "myfile1.txt" ���ļ������ļ�ָ�븳ֵ�� pFile1
	pFile2 = fopen("myfile2.txt", "a");  // ʹ�� ׷��ģʽ ����Ϊ "myfile2.txt" ���ļ������ļ�ָ�븳ֵ�� pFile2

	setbuf(pFile1, buffer);  // ���ļ� pFile1 ������������ buffer
	fputs("This is sent to a buffered stream", pFile1);  // ���ַ��� "This is sent to a buffered stream" д�뵽 pFile1 ��
	fflush(pFile1);  // ˢ�»����������������е�����д�뵽�ļ� pFile1 ��
	//myfile1.txt�е�����This is sent to a buffered stream

	setbuf(pFile2, NULL);  // ���ļ� pFile2 ����Ϊ�޻���ģʽ
	fputs("This is sent to an unbuffered stream", pFile2);  // ���ַ��� "This is sent to an unbuffered stream" ֱ��д�뵽 pFile2
	//myfile2.txt�е�����fopen exampleThis is sent to an unbuffered stream
	//"fopen example" ������֮ǰʹ���� fopen() �������ļ���������

	fclose(pFile1);  // �ر��ļ� pFile1
	fclose(pFile2);  // �ر��ļ� pFile2

	return 0;  // ����״̬�� 0����ʾ������������
}


�ڴ�ʾ���У��������ļ�����д�롣
���ļ� myfile1.txt ������������Ϊ�û�����Ļ�����;
����ִ��д�����;�������߼���������һ���֣����ڵ��� fflush ����֮ǰ��δд���豸��
ʾ�������ļ� myfile2.txt �����ĵڶ�������������Ϊ�޻��壬��˺����������������д���豸��
���ǣ��ر��ļ��󣬻�������δ������������״̬����ͬ�ģ��ر��ļ���ˢ���仺��������
*/


/*
18>fflush
int fflush ( FILE * stream );

Flush stream
����������Ѵ��Խ���д�루����������Ѵ��Խ��и��£�
�������һ�� I/O �������������������������������е��κ�δд�����ݶ���д����ļ���

������ǿ�ָ�룬���ˢ�����д�������
�˵��ú��������ִ�״̬��
���ļ��ر�ʱ�����������ڵ��� fclose ������Ϊ������ֹ�������Զ�ˢ��������������л�������

����ֵ
����������ѳɹ�ˢ�£���Fflush����0��
���ָ������û�л�������򿪽�����ȡ��Ҳ�᷵��ֵ0��
EOF�ķ���ֵ��ʾ����

fclose		Close file (function)
fopen		Open file (function)
setbuf		Set stream buffer (function)
setvbuf		Change stream buffering (function)


#include <stdio.h>
char mybuffer[80];  // ����һ���ַ����� mybuffer����СΪ 80
int main() {
	FILE* pFile;  // ����һ���ļ�ָ����� pFile

	pFile = fopen("example.txt", "r+");  // ʹ�ö�дģʽ����Ϊ "example.txt" ���ļ��������ļ�ָ�븳ֵ�� pFile
	if (pFile == NULL) {  // ����ļ��Ƿ�ɹ��򿪣����ʧ�������������Ϣ������
		perror("Error opening file");
	}
	else {
		fputs("test", pFile);  // ���ַ��� "test" д�뵽�ļ� pFile ��
		fflush("pFile");  // ˢ���ļ��� pFile
		fgets(mybuffer, 80, pFile);  // ���ļ� pFile �ж�ȡһ�����ݵ� mybuffer �У�����ȡ 80 ���ַ�
		puts(mybuffer);  // ��� mybuffer �е��ַ���
		fclose(pFile);  // �ر��ļ� pFile
		return 0;  // ����״̬�� 0����ʾ������������
	}
	return 0;  // ����״̬�� 0����ʾ������������
}

*/


/*
19>fgets
char * fgets ( char * str, int num, FILE * stream );

�����л�ȡ�ַ���(Get string from stream)
�����ж�ȡ�ַ���������Ϊ C �ַ����洢�� str �У�ֱ����ȡ ��num-1�� ���ַ��򵽴ﻻ�з����ļ�ĩβ�����ȷ�����Ϊ׼��
���з�ʹ fgets ֹͣ��ȡ��������������Ϊ��Ч�ַ����������ڸ��Ƶ� str ���ַ����С�
��ֹ���ַ����Զ����ӵ����Ƶ� str ���ַ�֮��


����ֵ
�ɹ��󣬺������� str��
����ڳ��Զ�ȡ�ַ�ʱ�����ļ�ĩβ�������� eof ָʾ�� ��feof����
����ڶ�ȡ�κ��ַ�֮ǰ��������������򷵻ص�ָ��Ϊ��ָ�루str �����ݱ��ֲ��䣩��
���������ȡ���������ô���ָʾ����ferror���������ؿ�ָ�루��strָ������ݿ����Ѹ��ģ���


��ע�⣬fgets �� get ��ȫ��ͬ��
fgets ����������������������ָ�� str ������С�������ַ����а����κν������з���
get ����ʹ�� stdin ��ΪԴ�����������ɵ��ַ����в������������з������Ҳ�����ָ�� str ������С������ܵ��»����������

//fgets example
#include<stdio.h>
int main() {

	FILE* pFile;
	char mystring[100];

	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL) //����ļ��Ƿ�ɹ���
	{
		perror("Error opening file");
	}
	else {
		if (fgets(mystring,100,pFile)!=NULL)  //���ļ��ж�ȡһ�������� 100 ���ַ����ַ�����������洢�� mystring ��
		{
			puts(mystring);
		}
		fclose(pFile);
	}
	return 0;
}

*/



/*
20>fgetc
int fgetc ( FILE * stream );

�����л�ȡ�ַ�(Get character from stream)
����ָ�������ڲ��ļ�λ��ָʾ����ǰָ����ַ���Ȼ���ڲ��ļ�λ��ָʾ����ǰ������һ���ַ���

����ֵ
�ɹ��󣬽������ַ���ȡ������Ϊ int ֵ����
��������Ϊ int ����Ӧ����ֵ EOF����ֵ��ʾʧ�ܣ�
���λ��ָʾ��λ���ļ�ĩβ����ú������� EOF ���������� eof ָʾ�� ��feof����
�������������ȡ���󣬸ú������᷵�� EOF������Ϊ���������ָʾ�� ��ferror����

//fgetc example: money counter
#include<stdio.h>
int main() {
	FILE* pFile;
	int c;
	int n = 0;
	pFile = fopen("myfile.txt", "r"); // ʹ��ֻ��ģʽ����Ϊ "myfile.txt" ���ļ��������ļ�ָ�븳ֵ�� pFile
	if (pFile == NULL)
	{
		perror("Error opening file");
	}
	else
	{
		do
		{
			c = fgetc(pFile);// ���ļ� pFile �ж�ȡһ���ַ��������丳ֵ��
			if (c =='$')
			{
				n++;
			}
		} while (c != EOF);
		fclose(pFile);
		printf("The file contains %d dollar sign characters ($).\n", n);
	}
	return 0;
}


*/
/*
21>setvbuf
int setvbuf ( FILE * stream, char * buffer, int mode, size_t size );

���������� -> ����������ͻ�������С

ָ�����Ļ��������ú�������ָ����������ģʽ�ʹ�С�����ֽ�Ϊ��λ����
����������ǿ�ָ�룬��ú������Զ����仺������ʹ�� size ��ΪҪʹ�õĴ�С����ʾ����
���򣬻�����ָ����������������С�ֽڵĻ�������


����
stream
ָ���ʶ������ FILE �����ָ�롣
buffer
�û�����Ļ�����������Ӧ����Ϊ�ֽڴ�С��
�������Ϊ null ָ�룬�ú������Զ����仺������
mode
ָ���ļ�����ģʽ���� <cstdio> �ж�������������ĺ곣����_IOFBF��_IOLBF �� _IONBF���������˲�����ֵ��
		_IOFBF	��ȫ���壺�����ʱ��һ����������������ˢ�£����ͻ�д�����ݡ�
						 �ڡ����롱�ϣ���������������һ�����Ϊ��ʱ������������䡣
		_IOLBF	��·���壺�����ʱ���������з��������л򻺳�����������ˢ�£�ʱ�������ȷ���ʲô������д�����ݡ�
						 �ڡ����롱�ϣ���������������һ�����Ϊ��ʱ������������䵽��һ�����з���
		_IONBF	�޻��壺��ʹ�û�������ÿ�� I/O �������ᾡ��д�롣����������£������Ի������ʹ�С������
size
��������С�����ֽ�Ϊ��λ����
��������������ǿ�ָ�룬���ֵ����ȷ�������Զ�Ϊ����������Ĵ�С��

����ֵ
�������������ȷ������ļ����򷵻�0ֵ��
���򣬷��ط�0ֵ;�����������ģʽ������Ч����仺����ʱ������������

// setvbuf example
#include <stdio.h>

int main()
{
	FILE* pFile;                        // ����һ��ָ�� FILE �ṹ�����͵�ָ����� pFile

	pFile = fopen("myfile.txt", "w");   // ��д��ģʽ����Ϊ "myfile.txt" ���ļ����������ص��ļ�ָ�븳ֵ�� pFile

	setvbuf(pFile, NULL, _IOFBF, 1024); // ���� pFile �Ļ�����Ϊȫ����ģʽ����СΪ 1024 �ֽ�

	// File operations here                // ����������ļ�����
	for (char i = 'a'; i < 'z'; i++)	// ѭ����Сд��ĸ 'a' �� 'y'
	{
		fputc(i, pFile);				// ����ǰ��ĸд���ļ�
	}

	fclose(pFile);                      // �ر��ļ�

	return 0;                           // ��������ֵ 0����ʾ������������
}
//�ڴ�ʾ���У�������һ����Ϊ myfile.txt ���ļ���
//��Ϊ������������ 1024 �ֽڵ�������������
//���ÿ����� 1024 �ֽڻ�����ʱ����Ӧ�����������������д����ļ���

*/


/*
22>fputc
int fputc ( int character, FILE * stream );
���ַ�д����(Write character to stream)

���ַ�д������ǰ��λ��ָʾ����
�ַ�д�������ڲ�λ��ָʾ��ָʾ��λ�ã�Ȼ���Զ�ǰ��һ��

����ֵ
�ɹ��󣬽�������д�ַ���
�������д������򷵻� EOF �����ô���ָʾ����ferror����

// fputc example: alphabet writer
#include <stdio.h>

int main()
{
	FILE* pFile;            // ����һ��ָ�� FILE �ṹ�����͵�ָ����� pFile
	char c;                 // ����һ���ַ����� c

	pFile = fopen("alphabet.txt", "w");   // ��д��ģʽ����Ϊ "alphabet.txt" ���ļ����������ص��ļ�ָ�븳ֵ�� pFile
	if (pFile != NULL) {                  // ����ļ��Ƿ�ɹ���

		for (c = 'A'; c <= 'Z'; c++)       // ѭ���Ӵ�д��ĸ 'A' �� 'Z'
			fputc(c, pFile);               // ����ǰ��ĸд���ļ�

		fclose(pFile);                     // �ر��ļ�
	}
	return 0;                             // ��������ֵ 0����ʾ������������
}

*/



/*
23>fputs
int fputs ( const char * str, FILE * stream );
���ַ���д����(Write string to stream)
�� str ָ������ C �ַ���д������

�ú�����ָ���ĵ�ַ ��str�� ��ʼ���ƣ�ֱ��������ֹ���ַ� ��'\0'����
����ֹ���ַ����Ḵ�Ƶ����С�
��ע�⣬fput �� put �Ĳ�֮ͬ���������ڿ���ָ��Ŀ������
���� fput ����д�������ַ����� put ���Զ���ĩβ���ӻ��з���


����ֵ
�ɹ�ʱ�������طǸ�ֵ��
����ʱ���ú������� EOF �����ô���ָʾ����ferror����

// fputs example
#include <stdio.h>

int main()
{
	FILE* pFile;                    // ����һ��ָ�� FILE �ṹ�����͵�ָ����� pFile
	char sentence[256];             // ����һ������Ϊ 256 ���ַ����� sentence

	printf("Enter sentence to append: ");   // ��ʾ�û�����һ�仰
	fgets(sentence, 256, stdin);              // ��ȡ�û���������ݲ��洢�� sentence ������
	pFile = fopen("mylog.txt", "a");          // ��׷��ģʽ����Ϊ "mylog.txt" ���ļ����������ص��ļ�ָ�븳ֵ�� pFile
	fputs(sentence, pFile);                   // �� sentence �е�����д���ļ�
	fclose(pFile);                            // �ر��ļ�
	return 0;                                 // ��������ֵ 0����ʾ������������
}

*/

