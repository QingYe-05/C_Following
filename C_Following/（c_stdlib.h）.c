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

*/



















/*

*/