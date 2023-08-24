#define _CRT_SECURE_NO_WARNINGS

//<cstdio>(stdio.h)库函数

/*
1>remove

int remove(const char* filename);
删除文件
删除文件名中指定名称的文件。
这是直接对由文件名标识的文件执行的操作;操作中不涉及任何流。

返回值
如果文件删除成功，则返回0。
失败时，返回非0值。

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

从标准中获取字符
返回标准输入 （标准输入） 中的下一个字符。
这相当于用 stdin 作为参数调用 getc。

返回值
成功后，将返回字符读取（提升为 int 值）。
返回类型为 int 以适应特殊值 EOF，该值指示失败：
End of file


3>putchar
int putchar ( int character );

将字符写入标准输出（标准输出）。
这相当于用标准输出调用 putc 作为第二个参

返回值
成功后，将返回所写字符。
如果发生写入错误，则返回 EOF 并设置错误指示器（ferror）。


#include<stdio.h>
int main() {
	int c;
	puts("Enter text. Include a dot('.') in a sentence to ");
		do
		{
			c = getchar();//从键盘中获取一个字符
			putchar(c);//将字符打印在屏幕中
		} while (c != '.');//当这个字符!='.'时，继续循环；ctrl+z在这里结束不了循环
	return 0;
}
*/

/*
4>gets
char * gets ( char * str );

从标准输入中获取字符串
[注意：此功能在 C 或 C++ 中不再可用（从 C11 和 C++14 开始）]
从标准输入 （stdin） 中读取字符，并将它们作为 C 字符串存储到 str 中，直到到达换行符或文件末尾。

返回值
成功后，函数返回 str。
如果发生读取错误，则设置错误指示器（ferror），并返回空指针（但str指向的内容可能已更改）
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
错误
void perror ( const char * str );

打印错误消息
如果参数 str 不是空指针，则打印 str 后跟冒号 （:)和一个空间。然后，无论 str 是否为空指针，都会打印生成的错误描述，后跟换行符 （'\n'）。
如果是空指针，则不会打印前面的自定义消息，但仍会打印错误消息。

无返回值

#include <stdio.h>
int main() {
	//在C语言中，FILE* pfile 是一个变量声明，它声明了一个名为 pfile 的指针，该指针可以被用来操作文件。
	//FILE* 是一个文件类型的指针，它指向一个称为 FILE 的结构体，该结构体包含了用于管理文件流的信息，如文件名、位置指针等。
	//通过使用 FILE* 指针，你可以打开文件、读取文件内容、写入文件数据、关闭文件等操作。
	//当你想要使用文件时，通常会使用 fopen() 函数将文件打开，并将返回的文件指针赋给 FILE* 类型的变量。
	//然后，你可以使用这个指针来执行文件操作，如读取或写入数据。
	//最后，使用 fclose() 函数关闭文件并释放资源。

	FILE* pfile;  // 声明一个文件指针
	pfile = fopen("example.txt", "r");  // 打开文件，以只读方式
	if (pfile != NULL) {
		// 文件操作，例如读取文件内容
		// ...
		fclose(pfile);  // 关闭文件
	}
	else {
		perror("The folling error occurred");
	}
	return 0;
}

*/

/*
6>printf


规范		输出										例
d 或 i	有符号十进制整数							392
u		无符号十进制整数							7235
o		无符号八进制								610
x		无符号十六进制整数						7FA
X		无符号十六进制整数（大写）					7FA
f		十进制浮点数，小写						392.65
F		十进制浮点数，大写						392.65
e		科学记数法（尾数/指数），小写				3.9265e+2
E		科学记数法（尾数/指数），大写				3.9265E+2
g		使用最短表示形式：%e 或 %f				392.65
G		使用最短表示形式：%E 或 %F				392.65
一个		十六进制浮点数，小写						-0xc.90FEP-2
一个		十六进制浮点数，大写						-0XC.90FEP-2
c		字符										一个
s		字符串									样本
p		指针地址									b8000000
n		没有打印任何内容。
		相应的参数必须是指向有符号 int 的指针。
		到目前为止写入的字符数存储在指向的位置。
%		一个 % 后跟另一个 % 字符会将单个 % 写入流。	%

--格式说明--
标志						描述
-			在给定字段宽度内左对齐;右对齐是默认值（请参阅宽度子说明符）。
+			即使在正数中，也会在结果前面加上加号或减号（+或-）。默认情况下，只有负数前面带有 - 符号。
空格			如果不打算写入任何符号，则会在值之前插入一个空格。
#			与 o、x 或 X 说明符一起使用时，对于小于零的值，值前面分别带有 0、0x 或 0X。
			与 a、A、e、E、f、F、g 或 G 一起使用时，它强制写入输出包含小数点，即使后面没有更多的数字。
			默认情况下，如果没有数字后跟，则不写入小数点。
0			指定填充时，用零 （0） 而不是空格左填充数字（请参阅宽度子说明符）。
数字			要打印的最小字符数。如果要打印的值小于此数字，则用空格填充结果。即使结果更大，也不会截断该值。
*			宽度不是在格式字符串中指定的，而是作为必须格式化的参数之前的附加整数值参数指定的。

	specifiers（说明符）
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
	printf("Preceding with blanks: %10d \n", 1977);//不够的话在之前填充空格
	printf("Preceding with zeros: %010d \n", 1977);//不够的话在之前填充0
	printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	//%4.2f 表示将浮点数按照总宽度为4、小数点后保留2位的格式输出。因此，浮点数 3.1416 输出为 3.14。
	//%+.0e 表示将浮点数用科学计数法表示，并且指数部分不带小数位，正负数都显示符号。浮点数 3.1416 在此格式下输出为 +3e+00。
	//%E 表示将浮点数用科学计数法表示，并且指数部分采用大写字母。浮点数 3.1416 在此格式下输出为 3.141600E+00。
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
打开文件
打开在参数文件名中指定其名称的文件，并将其与可在将来的操作中由返回的 FILE 指针标识的流相关联。
返回的指针可以通过调用 fclose 或 freopen 与文件解除关联。所有打开的文件在正常程序终止时自动关闭。
运行环境支持至少同时打开FOPEN_MAX个文件。

参数
filename
包含要打开的文件的名称的 C 字符串。
其值应遵循运行环境的文件名规范，并且可以包含路径（如果系统支持）。
mode
包含文件访问模式的 C 字符串。它可以是：

“r”		读：打开文件进行输入操作。该文件必须存在。
“w”		写：为输出操作创建一个空文件。如果已存在同名文件，则会丢弃其内容，并将该文件视为新的空文件。
“一”		附加：在文件末尾打开文件进行输出。输出操作始终将数据写入文件末尾，并对其进行扩展。
		重新定位操作（fseek、fsetpos、rewind）将被忽略。如果文件不存在，则创建该文件。
“r+”	读取/更新：打开文件进行更新（输入和输出）。该文件必须存在。
“w+”	写入/更新：创建一个空文件并打开它进行更新（用于输入和输出）。
		如果已存在同名文件，则会丢弃其内容，并将该文件视为新的空文件。
“A+”	追加/更新：打开一个文件进行更新（输入和输出），所有输出操作都在文件末尾写入数据。
		重新定位操作（fseek、fsetpos、rewind）会影响下一个输入操作，但输出操作会将位置移回文件末尾。
		如果文件不存在，则创建该文件。

使用上面的模式说明符，文件将作为文本文件打开。为了将文件作为二进制文件打开，模式字符串中必须包含“b”字符。
这个额外的“b”字符可以附加到字符串的末尾（从而形成以下复合模式：“rb”，“wb”，“ab”，“r+b”，“w+b”，“a+b”），
或者插入字母和混合模式的“+”符号之间（“rb+”，“wb+”，“ab+”）。

返回值
如果文件成功打开，该函数将返回指向 FILE 对象的指针，该对象可用于在将来的操作中标识流。
否则，将返回空指针。

#include<stdio.h>
int main() {
	FILE* pFile;
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL)
	{
		fputs("fopen example", pFile);
		printf("成功\n");
		fclose(pFile);
	}
	else
	{
		perror("打开错误");
	}
	return 0;
}

*/

/*
8>putc
int putc ( int character, FILE * stream );

将字符写入流
将字符写入流并前进位置指示器。
字符写在流的内部位置指示器指示的位置，然后自动前进一。

将字符写入流
将字符写入流并前进位置指示器。
字符写在流的内部位置指示器指示的位置，然后自动前进一。

#include<stdio.h>
int main() {
	FILE* pFile;
	char c;

	pFile = fopen("alphabet.txt", "wt");//"w" 表示以写入模式打开文件。如果文件不存在，将创建一个新文件；如果文件已存在，则会清空文件内容。"t" 表示以文本模式打开文件。在文本模式下，进行文件的读写操作时会处理文本的换行符等特殊字符的转换。
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

将字符写入标准输出
将字符写入标准输出（标准输出）。

返回值
成功后，将返回所写字符。
如果发生写入错误，则返回 EOF 并设置错误指示器（ferror）。

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

将字符串写入标准输出
将 str 指向的 C 字符串写入标准输出 （stdout） 并附加换行符 （'\n'）。
该函数从指定的地址 （str） 开始复制，直到到达终止空字符 （'\0'）。此终止空字符不会复制到流中。
请注意，put 与 fput 的不同之处不仅在于它使用 stdout 作为目标，而且还会自动在末尾附加换行符（fput 不会）。


返回值
成功时，将返回非负值。
出错时，该函数返回 EOF 并设置错误指示器（ferror）。

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

重命名文件
将旧名称指定的文件或目录的名称更改为新名称。
这是直接对文件执行的操作;操作中不涉及任何流。
如果 oldname 和 newname 指定了不同的路径，并且系统支持这样做，则文件将移动到新位置。
如果 newname 命名现有文件，则该函数可能会失败或覆盖现有文件，具体取决于特定的系统和库实现。

返回值(同remove)
如果文件重命名成功，则返回零值。
失败时，返回非零值。

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

将流的位置设置为开头
将与流关联的位置指示器设置为文件的开头。
成功调用此函数后，将清除与流关联的文件结束和错误内部指示器，并且将丢弃以前对此流上 ungetc 的调用的所有效果。
在打开进行更新（读+写）的流上，对倒带的调用允许在读取和写入之间切换。

无返回值

*/
//#include<stdio.h>
//int main() {
//	int n;
//	FILE* pFile;
//	char buffer[27];
//	pFile = fopen("alphabet.txt", "w+");
//	for (n = 'a'; n <= 'c'; n++)
//	{
//		fputc(n, pFile);//putc 和 fputc 是等效的，只是 putc 在某些库中可能作为宏实现。
//	}
//	rewind(pFile);//一旦调用了 rewind() 函数，之后的读写操作就会从文件的开头开始进行，而不是继续在文件当前位置进行。
//	fread(buffer, 1, 26, pFile);//将26个1字节大小的字符，以文件流的方式存储在buffer（缓冲）内存块中
//	fclose(pFile);//关闭文件并释放资源。
//	buffer[26] = '\0';
//	puts(buffer);
//	return 0;
//}

/*
13>fread
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );//size_t表示无符号整型

ptr：指向大小至少为 （size*count） 字节的内存块的指针，转换为 void*。
size:要读取的每个元素的大小（以字节为单位）,size_t是无符号整数类型。
count:元素个数，每个元素的大小为字节大小。
stream:指向指定输入流的 FILE 对象的指针

从流中读取数据块
从流中读取计数元素数组，每个元素的大小为字节，并将它们存储在 ptr 指定的内存块中。
流的位置指示器按读取的总字节数前进。
如果成功，则读取的总字节数为（大小*计数）

返回值
返回成功读取的元素总数。
如果此数字与 count 参数不同，则表示读取时发生读取错误或到达文件末尾。在这两种情况下，都会设置正确的指标，可以分别用 ferror 和 feof 进行检查。
如果大小或计数为0，则该函数返回0，并且流状态和 ptr 指向的内容保持不变。

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
		fputs("File error", stderr);//stderr标准输出和标准误差被打印到屏幕上
		exit(1);//stdlib.h
	}

	//获取文件大小：
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);//获取文件当前的指针位置
	rewind(pFile);//将文件指针重新定位到文件的开头，从开头读

	//分配内存以包含整个文件
	buffer = (char*)malloc(sizeof(char) * lSize);// 根据(lSize)文件大小分配内存空间 malloc - m:memory内存 alloc:allocate分配
	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
		exit(2);
	}
	//将文件复制到缓冲区中
	result = fread(buffer, 1, lSize, pFile);// 从文件中读取数据到缓冲区,将lSize个1字节大小的字符，以文件流的方式存储在result（缓冲）内存块中
	if (result != lSize)
	{
		fputs("Reading error", stderr);

		exit(3);
	}
	printf("%d", result);

	//整个文件现在被加载到内存缓冲区中
	// terminate终止
	fclose(pFile);
	free(buffer);
	return 0;
}

//此代码将 alphabet.txt 加载到动态分配的内存缓冲区中，该缓冲区可用于将文件的内容作为数组进行操作。


*/



/*
14>fseek
int fseek ( FILE * stream, long int offset, int origin );

重新定位流位置指示器(将文件指针移动到指定位置)
将与流关联的位置指示器设置为新位置。
对于以二进制模式打开的流，新位置是通过向源指定的参考位置添加偏移量来定义的。
对于以文本模式打开的流，偏移量应为零或先前调用 ftel 返回的值，并且源必须SEEK_SET。

stream
指向标识流的 FILE 对象的指针。
offset
二进制文件：要从源偏移的字节数。
文本文件：零或 ftell 返回的值。
origin
用作偏移参考的位置。它由 <cstdio> 中定义的以下常量之一指定，专门用作此函数的参数：
不断	参考位置
SEEK_SET	文件开头
SEEK_CUR	文件指针的当前位置
SEEK_END	文件结尾 *

返回值
如果成功，该函数将返回0。
否则，它将返回非0值。
如果发生读取或写入错误，则设置错误指示器（ferror）。

#include<stdio.h>
int main() {
	FILE* pFile;  // 声明一个文件指针变量 pFile
	pFile = fopen("alphabet.txt", "wb"); // 打开名为 "alphabet.txt" 的文件以供写入，并将文件指针赋值给 pFile
	fputs("This is an apple.", pFile); // 向文件中写入字符串 "This is an apple."
	fseek(pFile, 9, SEEK_SET); // 在文件中定位到距离文件 起始 位置 9 个字节的位置
	fputs(" sam", pFile);  // 在定位后的位置写入字符串 "sam"
	fseek(pFile, 2, SEEK_CUR); // 在文件中定位到距离文件 当前 位置 2 个字节的位置
	fputs(" sam", pFile);
	fseek(pFile, 0, SEEK_CUR); // 在文件中定位到距离文件 末尾 位置 0 个字节的位置
	fputs(" sam", pFile);
	fclose(pFile);  // 关闭文件
	return 0;
}

//文档中的内容 - 三个sam分别对应 SEEK_SET SEEK_CUR SEEK_END
//This is a sampl sam sam
*/

/*
15>ftell
long int ftell ( FILE * stream );
获取流中的当前位置
返回流的位置指示器的当前值()。
对于二进制流，这是从文件开头开始的字节数。
对于文本流，数值可能没有意义，但仍可用于稍后使用 fseek 将位置恢复到相同位置

返回值
成功后，返回仓位指标的当前值。
失败时，返回 -1L，并将 errno 设置为特定于系统的正值。

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
		fseek(pFile, 0, SEEK_END);   // non-portable：不可移植的
		size = ftell(pFile);//获取当前指针的位置
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	return 0;
}

*/

/*
16>scanf
参考printf

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

控制流缓冲
	附注：
	setbuf函数控制流的缓冲。stream参数必须指向一个未被读写的打开文件。
	如果buffer参数为NULL，则流未被缓冲。
	如果不是，缓冲区必须指向长度为BUFSIZ的字符数组，其中BUFSIZ是STDIO.H中定义的缓冲区大小。
	用户指定的缓冲区，而不是给定流的默认系统分配的缓冲区，用于I/O缓冲。
	默认情况下，stderr流是无缓冲的，但您可以使用setbuf为stderr分配缓冲区。

参数
stream
指向标识打开流的 FILE 对象的指针。
buffer
用户分配的缓冲区。长度应至少为 BUFSIZ 字节。
或者，可以指定空指针以禁用缓冲。

无返回值

#include <stdio.h>
int main()
{
	//BUFSIZ 是一个宏定义，在标准库头文件 <stdio.h> 中定义，表示标准I/O缓冲区的大小。
	//它的具体值可以根据系统和编译器的不同而变化，通常是一个较大的正整数

	char buffer[BUFSIZ];  // 声明一个字符数组 buffer，大小为 BUFSIZ
	FILE* pFile1, * pFile2;  // 声明两个文件指针变量 pFile1 和 pFile2

	pFile1 = fopen("myfile1.txt", "w");  // 使用 写入模式 打开名为 "myfile1.txt" 的文件，将文件指针赋值给 pFile1
	pFile2 = fopen("myfile2.txt", "a");  // 使用 追加模式 打开名为 "myfile2.txt" 的文件，将文件指针赋值给 pFile2

	setbuf(pFile1, buffer);  // 将文件 pFile1 关联到缓冲区 buffer
	fputs("This is sent to a buffered stream", pFile1);  // 将字符串 "This is sent to a buffered stream" 写入到 pFile1 中
	fflush(pFile1);  // 刷新缓冲区，将缓冲区中的内容写入到文件 pFile1 中
	//myfile1.txt中的内容This is sent to a buffered stream

	setbuf(pFile2, NULL);  // 将文件 pFile2 设置为无缓冲模式
	fputs("This is sent to an unbuffered stream", pFile2);  // 将字符串 "This is sent to an unbuffered stream" 直接写入到 pFile2
	//myfile2.txt中的内容fopen exampleThis is sent to an unbuffered stream
	//"fopen example" 是由于之前使用了 fopen() 函数打开文件而产生的

	fclose(pFile1);  // 关闭文件 pFile1
	fclose(pFile2);  // 关闭文件 pFile2

	return 0;  // 返回状态码 0，表示程序正常结束
}


在此示例中，打开两个文件进行写入。
与文件 myfile1.txt 关联的流设置为用户分配的缓冲区;
对其执行写入操作;数据在逻辑上是流的一部分，但在调用 fflush 函数之前尚未写入设备。
示例中与文件 myfile2.txt 关联的第二个缓冲区设置为无缓冲，因此后续输出操作将尽快写入设备。
但是，关闭文件后，缓冲流和未缓冲流的最终状态是相同的（关闭文件会刷新其缓冲区）。
*/


/*
18>fflush
int fflush ( FILE * stream );

Flush stream
如果给定流已打开以进行写入（或者如果它已打开以进行更新，
并且最后一个 I/O 操作是输出操作），则其输出缓冲区中的任何未写入数据都将写入该文件。

如果流是空指针，则会刷新所有此类流。
此调用后，流将保持打开状态。
当文件关闭时，无论是由于调用 fclose 还是因为程序终止，都将自动刷新与其关联的所有缓冲区。

返回值
如果缓冲区已成功刷新，则Fflush返回0。
如果指定的流没有缓冲区或打开仅供读取，也会返回值0。
EOF的返回值表示错误。

fclose		Close file (function)
fopen		Open file (function)
setbuf		Set stream buffer (function)
setvbuf		Change stream buffering (function)


#include <stdio.h>
char mybuffer[80];  // 声明一个字符数组 mybuffer，大小为 80
int main() {
	FILE* pFile;  // 声明一个文件指针变量 pFile

	pFile = fopen("example.txt", "r+");  // 使用读写模式打开名为 "example.txt" 的文件，并将文件指针赋值给 pFile
	if (pFile == NULL) {  // 检查文件是否成功打开，如果失败则输出错误信息并返回
		perror("Error opening file");
	}
	else {
		fputs("test", pFile);  // 将字符串 "test" 写入到文件 pFile 中
		fflush("pFile");  // 刷新文件流 pFile
		fgets(mybuffer, 80, pFile);  // 从文件 pFile 中读取一行内容到 mybuffer 中，最多读取 80 个字符
		puts(mybuffer);  // 输出 mybuffer 中的字符串
		fclose(pFile);  // 关闭文件 pFile
		return 0;  // 返回状态码 0，表示程序正常结束
	}
	return 0;  // 返回状态码 0，表示程序正常结束
}

*/


/*
19>fgets
char * fgets ( char * str, int num, FILE * stream );

从流中获取字符串(Get string from stream)
从流中读取字符并将其作为 C 字符串存储到 str 中，直到读取 （num-1） 个字符或到达换行符或文件末尾，以先发生者为准。
换行符使 fgets 停止读取，但它被函数视为有效字符，并包含在复制到 str 的字符串中。
终止空字符会自动附加到复制到 str 的字符之后。


返回值
成功后，函数返回 str。
如果在尝试读取字符时遇到文件末尾，则设置 eof 指示器 （feof）。
如果在读取任何字符之前发生这种情况，则返回的指针为空指针（str 的内容保持不变）。
如果发生读取错误，则设置错误指示器（ferror），并返回空指针（但str指向的内容可能已更改）。


请注意，fgets 与 get 完全不同：
fgets 不仅接受流参数，还允许指定 str 的最大大小，并在字符串中包含任何结束换行符。
get 不仅使用 stdin 作为源，而且在生成的字符串中不包含结束换行符，并且不允许指定 str 的最大大小（这可能导致缓冲区溢出）

//fgets example
#include<stdio.h>
int main() {

	FILE* pFile;
	char mystring[100];

	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL) //检查文件是否成功打开
	{
		perror("Error opening file");
	}
	else {
		if (fgets(mystring,100,pFile)!=NULL)  //从文件中读取一行最多包含 100 个字符的字符串，并将其存储在 mystring 中
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

从流中获取字符(Get character from stream)
返回指定流的内部文件位置指示符当前指向的字符。然后，内部文件位置指示器将前进到下一个字符。

返回值
成功后，将返回字符读取（提升为 int 值）。
返回类型为 int 以适应特殊值 EOF，该值表示失败：
如果位置指示器位于文件末尾，则该函数返回 EOF 并设置流的 eof 指示器 （feof）。
如果发生其他读取错误，该函数还会返回 EOF，但改为设置其错误指示器 （ferror）。

//fgetc example: money counter
#include<stdio.h>
int main() {
	FILE* pFile;
	int c;
	int n = 0;
	pFile = fopen("myfile.txt", "r"); // 使用只读模式打开名为 "myfile.txt" 的文件，并将文件指针赋值给 pFile
	if (pFile == NULL)
	{
		perror("Error opening file");
	}
	else
	{
		do
		{
			c = fgetc(pFile);// 从文件 pFile 中读取一个字符，并将其赋值给
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

更改流缓冲 -> 控制流缓冲和缓冲区大小

指定流的缓冲区。该函数允许指定缓冲区的模式和大小（以字节为单位）。
如果缓冲区是空指针，则该函数会自动分配缓冲区（使用 size 作为要使用的大小的提示）。
否则，缓冲区指向的数组可以用作大小字节的缓冲区。


参数
stream
指向标识打开流的 FILE 对象的指针。
buffer
用户分配的缓冲区。长度应至少为字节大小。
如果设置为 null 指针，该函数会自动分配缓冲区。
mode
指定文件缓冲模式。在 <cstdio> 中定义了三个特殊的宏常量（_IOFBF、_IOLBF 和 _IONBF），用作此参数的值：
		_IOFBF	完全缓冲：在输出时，一旦缓冲区已满（或刷新），就会写入数据。
						 在“输入”上，当请求输入操作且缓冲区为空时，缓冲区将填充。
		_IOLBF	线路缓冲：在输出时，当将换行符插入流中或缓冲区已满（或刷新）时，无论先发生什么，都会写入数据。
						 在“输入”上，当请求输入操作且缓冲区为空时，缓冲区将填充到下一个换行符。
		_IONBF	无缓冲：不使用缓冲区。每个 I/O 操作都会尽快写入。在这种情况下，将忽略缓冲区和大小参数。
size
缓冲区大小（以字节为单位）。
如果缓冲区参数是空指针，则此值可以确定函数自动为缓冲区分配的大小。

返回值
如果缓冲区已正确分配给文件，则返回0值。
否则，返回非0值;这可能是由于模式参数无效或分配缓冲区时出现其他错误。

// setvbuf example
#include <stdio.h>

int main()
{
	FILE* pFile;                        // 声明一个指向 FILE 结构体类型的指针变量 pFile

	pFile = fopen("myfile.txt", "w");   // 以写入模式打开名为 "myfile.txt" 的文件，并将返回的文件指针赋值给 pFile

	setvbuf(pFile, NULL, _IOFBF, 1024); // 设置 pFile 的缓冲区为全缓冲模式，大小为 1024 字节

	// File operations here                // 在这里进行文件操作
	for (char i = 'a'; i < 'z'; i++)	// 循环从小写字母 'a' 到 'y'
	{
		fputc(i, pFile);				// 将当前字母写入文件
	}

	fclose(pFile);                      // 关闭文件

	return 0;                           // 返回整数值 0，表示程序正常结束
}
//在此示例中，将创建一个名为 myfile.txt 的文件，
//并为关联的流请求 1024 字节的完整缓冲区，
//因此每次填充 1024 字节缓冲区时，才应将输出到此流的数据写入该文件。

*/


/*
22>fputc
int fputc ( int character, FILE * stream );
将字符写入流(Write character to stream)

将字符写入流并前进位置指示器。
字符写在流的内部位置指示器指示的位置，然后自动前进一。

返回值
成功后，将返回所写字符。
如果发生写入错误，则返回 EOF 并设置错误指示器（ferror）。

// fputc example: alphabet writer
#include <stdio.h>

int main()
{
	FILE* pFile;            // 声明一个指向 FILE 结构体类型的指针变量 pFile
	char c;                 // 声明一个字符变量 c

	pFile = fopen("alphabet.txt", "w");   // 以写入模式打开名为 "alphabet.txt" 的文件，并将返回的文件指针赋值给 pFile
	if (pFile != NULL) {                  // 检查文件是否成功打开

		for (c = 'A'; c <= 'Z'; c++)       // 循环从大写字母 'A' 到 'Z'
			fputc(c, pFile);               // 将当前字母写入文件

		fclose(pFile);                     // 关闭文件
	}
	return 0;                             // 返回整数值 0，表示程序正常结束
}

*/



/*
23>fputs
int fputs ( const char * str, FILE * stream );
将字符串写入流(Write string to stream)
将 str 指向流的 C 字符串写入流。

该函数从指定的地址 （str） 开始复制，直到到达终止空字符 （'\0'）。
此终止空字符不会复制到流中。
请注意，fput 与 put 的不同之处不仅在于可以指定目标流，
而且 fput 不会写入其他字符，而 put 会自动在末尾附加换行符。


返回值
成功时，将返回非负值。
出错时，该函数返回 EOF 并设置错误指示器（ferror）。

// fputs example
#include <stdio.h>

int main()
{
	FILE* pFile;                    // 声明一个指向 FILE 结构体类型的指针变量 pFile
	char sentence[256];             // 声明一个长度为 256 的字符数组 sentence

	printf("Enter sentence to append: ");   // 提示用户输入一句话
	fgets(sentence, 256, stdin);              // 获取用户输入的内容并存储在 sentence 数组中
	pFile = fopen("mylog.txt", "a");          // 以追加模式打开名为 "mylog.txt" 的文件，并将返回的文件指针赋值给 pFile
	fputs(sentence, pFile);                   // 将 sentence 中的内容写入文件
	fclose(pFile);                            // 关闭文件
	return 0;                                 // 返回整数值 0，表示程序正常结束
}

*/

