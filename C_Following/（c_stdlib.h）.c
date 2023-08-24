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

*/



















/*

*/