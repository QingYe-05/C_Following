#define _CRT_SECURE_NO_WARNINGS
/*
C�����е�math.hͷ�ļ��ṩ����ೣ�õ���ѧ������������һЩ������math.h������

��ֵ������

abs()����ȡ���ͻ򸡵������ľ���ֵ��
fabs()����ȡ���������ľ���ֵ��
ceil()������ȡ�������ز�С�ڸ���������������С����ֵ��
floor()������ȡ�������ز����ڸ��������������������ֵ��
round()���������룬���ظ�������������ӽ�������ֵ��
fmod()������������ģ���㣬���������������������������

���Ǻ�����

sin()��������ֵ��
cos()��������ֵ��
tan()��������ֵ��
asin()��������ֵ��
acos()��������ֵ��
atan()��������ֵ��
ָ���������

pow()���������㣬���ظ��������ĸ���ָ�����ݡ�
sqrt()����ƽ������
exp()����ָ������������e�ĸ���ָ�����ݡ�
log()������eΪ�׵���Ȼ������
log10()������10Ϊ�׵Ķ�����
�������ú�����

max()���������������нϴ��һ����
min()���������������н�С��һ����
rand()�������������
srand()��������������ɵ�����ֵ��
*/

/*
1>fabs
double fabs (double x);      
float fabs (float x);
long double fabs (long double x);
�������ֵ

x
����x�ľ���ֵ:|x|��

#include <stdio.h>      // printf
#include <math.h>       // fabs


int main()
{
	printf("The absolute value of 3.1416 is %f\n", fabs(3.1416));
	printf("The absolute value of -10.6 is %f\n", fabs(-10.6));
	return 0;
}
//Output:
//
//The absolute value of 3.1416 is 3.141600
//The absolute value of - 10.6 is 10.600000

*/

/*
2>ceil
double ceil (double x);      
float ceil (float x);
long double ceil (long double x);

����ȡ��
��������x�����ز�С��x����С����ֵ��

����ֵ
��С��x����С����ֵ(��Ϊ����ֵ)��

#include <stdio.h>      // printf
#include <math.h>       // ceil

int main()
{
	printf("ceil of 2.3 is %.1f\n", ceil(2.3));
	printf("ceil of 3.8 is %.1f\n", ceil(3.8));
	printf("ceil of -2.3 is %.1f\n", ceil(-2.3));
	printf("ceil of -3.8 is %.1f\n", ceil(-3.8));
	return 0;
}

//ceil of 2.3 is 3.0
//ceil of 3.8 is 4.0
//ceil of - 2.3 is - 2.0
//ceil of - 3.8 is - 3.0

*/


/*
3>floor
double floor (double x);      
float floor (float x);
long double floor (long double x);

����ȡ��
��������x�����ز�����x���������ֵ��

����ֵ
x��ֵ��������(��Ϊ����ֵ)��

#include <stdio.h>      // printf
#include <math.h>      // floor

int main()
{
	printf("floor of 2.3 is %.1lf\n", floor(2.3));
	printf("floor of 3.8 is %.1lf\n", floor(3.8));
	printf("floor of -2.3 is %.1lf\n", floor(-2.3));
	printf("floor of -3.8 is %.1lf\n", floor(-3.8));
	return 0;
}

//floor of 2.3 is 2.0
//floor of 3.8 is 3.0
//floor of - 2.3 is - 3.0
//floor of - 3.8 is - 4.0
*/

/*
4>round
 double round  (double x);      
 float roundf (float x);
 long double roundl (long double x);

��������
������ӽ�x������ֵ���м���������������롣

#include <stdio.h>      // printf 
#include <math.h>       // round, floor, ceil, trunc 

int main()
{
	const char* format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
	printf("value\tround\tfloor\tceil\ttrunc\n");
	printf("-----\t-----\t-----\t----\t-----\n");
	printf(format, 2.3, round(2.3), floor(2.3), ceil(2.3), trunc(2.3));
	printf(format, 3.8, round(3.8), floor(3.8), ceil(3.8), trunc(3.8));
	printf(format, 5.5, round(5.5), floor(5.5), ceil(5.5), trunc(5.5));
	printf(format, -2.3, round(-2.3), floor(-2.3), ceil(-2.3), trunc(-2.3));
	printf(format, -3.8, round(-3.8), floor(-3.8), ceil(-3.8), trunc(-3.8));
	printf(format, -5.5, round(-5.5), floor(-5.5), ceil(-5.5), trunc(-5.5));
	return 0;
}
//��ʼֵ	��������  ����ȡ��  ����ȡ�� ����
//value   round   floor   ceil    trunc
//-----   -----   -----   ----    -----
//2.3     2.0     2.0     3.0     2.0
//3.8     4.0     3.0     4.0     3.0
//5.5     6.0     5.0     6.0     5.0
//-2.3    -2.0    -3.0    -2.0    -2.0
//-3.8    -4.0    -4.0    -3.0    -3.0
//-5.5    -6.0    -6.0    -5.0    -5.0

*/
/*
5>trunc
double trunc (double x);      
float truncf (float x);
long double truncl (long double x);
��������
������4����������
*/


/*
6>fmod
double fmod (double numer, double denom);      
float fmod (float numer, float denom);
long double fmod (long double numer, long double denom);
��ģ����  -- �����������

numer
�̷��ӵ�ֵ��
denom
�̷�ĸ��ֵ

����ֵ
�������������

#include <stdio.h>      // printf
#include <math.h>       // fmod

int main()
{
	printf("fmod of 5.3 / 2 is %f\n", fmod(5.3, 2));
	printf("fmod of 18.5 / 4.2 is %f\n", fmod(18.5, 4.2));
	return 0;
}
//Output:
//
//fmod of 5.3 / 2 is 1.300000
//fmod of 18.5 / 4.2 is 1.700000

*/


//���Ǻ�����
//
//sin()��������ֵ��
//cos()��������ֵ��
//tan()��������ֵ��
//asin()��������ֵ��
//acos()��������ֵ��
//atan()��������ֵ��

/*
7>sin
 double sin (double x);      
 float sin (float x);
 long double sin (long double x);

 ��������
����x���Ƚǵ�����ֵ��

x
�û��ȱ�ʾ�Ƕȵ�ֵ��
1���ȵ���180/PI�ȡ�

#include <stdio.h>      // printf
#include <math.h>       // sin

#define PI 3.14159265

int main()
{
	double param, result;
	param = 30.0;

	//����֮PI
	result = sin(param * PI / 180);
	printf("The sine of %f degrees is %f.\n", param, result);
	return 0;
}
//Output:
//
//The sine of 30.000000 degrees is 0.500000.
*/


/*
8>cos
 double cos (double x);      
 float cos (float x);
 long double cos (long double x);
��������
����x���Ƚǵ�����ֵ��

x
�û��ȱ�ʾ�Ƕȵ�ֵ��
1���ȵ���180/PI�ȡ�

#include <stdio.h>      // printf
#include <math.h>       // cos

#define PI 3.14159265

int main()
{
	double param, result;
	param = 60.0;
	result = cos(param * PI / 180.0);
	printf("The cosine of %f degrees is %f.\n", param, result);
	return 0;
}
//Output:
//
//The cosine of 60.000000 degrees is 0.500000.

*/


/*
9>tan
 double tan (double x);      
 float tan (float x);
 long double tan (long double x);
��������
����x���Ƚǵ�����ֵ��

x
��ʾ�Ƕȵ�ֵ���û��ȱ�ʾ��
1���ȵ���180/PI�ȡ�

#include <stdio.h>      // printf
#include <math.h>       // tan

#define PI 3.14159265

int main()
{
	double param, result;
	param = 45.0;
	result = tan(param * PI / 180.0);
	printf("The tangent of %f degrees is %f.\n", param, result);
	return 0;
}
//Output:
//
//The tangent of 45.000000 degrees is 1.000000.

*/


/*
10>asin

����ֵ
��arcsinx��������[- /2��+ /2]�����ڡ�
1���ȵ���180/PI�ȡ�


#include <stdio.h>      // printf
#include <math.h>       // asin

#define PI 3.14159265

int main()
{
	double param, result;
	param = 0.5;
	result = asin(param) * 180.0 / PI;
	printf("The arc sine of %f is %f degrees\n", param, result);
	return 0;
}
Output:

The arc sine of 0.500000 is 30.000000 degrees.
*/



/*
11>acos
���㷴����
�����Ի��ȱ�ʾ��arccosx����ֵ��


#include <stdio.h>      // printf 
#include <math.h>       // acos 

#define PI 3.14159265

int main()
{
	double param, result;
	param = 0.5;
	result = acos(param) * 180.0 / PI;
	printf("The arc cosine of %f is %f degrees.\n", param, result);
	return 0;
}

//Output:
//The arc cosine of 0.500000 is 60.000000 degrees.
*/

/*
12>atan
double atan (double x);      
float atan (float x);
long double atan (long double x);
���㻡���� ������
����x��arctan����ֵ���Ի��ȱ�ʾ��

����ֵ
x����arctan��������[- pi/2��+ pi/2]�����ڡ�
1���ȵ���180/PI�ȡ�

#include <stdio.h>      // printf
#include <math.h>       // atan

#define PI 3.14159265

int main()
{
	double param, result;
	param = 1.0;
	result = atan(param) * 180 / PI;
	printf("The arc tangent of %f is %f degrees\n", param, result);
	return 0;
}
//���:
//1.000000�Ļ�����45.000000�ȡ�
*/



//ָ���������
//
//pow()���������㣬���ظ��������ĸ���ָ�����ݡ�
//sqrt()����ƽ������
//exp()����ָ������������e�ĸ���ָ�����ݡ�
//log()������eΪ�׵���Ȼ������
//log10()������10Ϊ�׵Ķ�����
// 

/*13>pow
double pow (double base, double exponent);      
float pow (float base, float exponent);
long double pow (long double base, long double exponent);     
double pow (double base, int exponent);
long double pow (long double base, int exponent);

���Ȩ
���ػ�������ָ��:

base
����ֵ��
exponent
ָ����ֵ��

����ֵ
ȡ�׵���ָ���Ľ����
������������޸��ģ�����ָ�������޵ĵ�������������ᵼ�������
���������ָ����Ϊ�㣬��ĳЩʵ����Ҳ���ܵ��������
���baseΪ����exponentΪ��������ܵ��������򼫵����(��û�д���ȡ���ڿ�ʵ��)��
������̫���̫С���޷��÷������͵�ֵ��ʾ����ú��������ܵ��·�Χ����

#include <stdio.h>      // printf
#include <math.h>       // pow

int main()
{
	printf("7 ^ 3 = %f\n", pow(7.0, 3.0));
	printf("4.73 ^ 12 = %f\n", pow(4.73, 12.0));
	printf("32.01 ^ 1.54 = %f\n", pow(32.01, 1.54));
	return 0;
}

//Output:
//
//7 ^ 3 = 343.000000
//4.73 ^ 12 = 125410439.217423
//32.01 ^ 1.54 = 208.036691

*/


/*14>sqrt
double sqrt (double x);      
float sqrt (float x);
long double sqrt (long double x);

����ƽ����
���ظ���x��

����ֵ
��x��
���xΪ��������������:

#include <stdio.h>      // printf
#include <math.h>       // sqrt

int main()
{
	double param, result;
	param = 1024.0;
	result = sqrt(param);
	printf("sqrt(%f) = %f\n", param, result);
	return 0;
}
//Output:
//
//sqrt(1024.000000) = 32.000000

*/


/*15>exp
double exp (double x);      
float exp (float x);
long double exp (long double x);

����ָ������
����x����eΪ�׵�ָ����������e��x�η�:��

����ֵ
x��ָ��ֵ��
�������Ĵ�С̫���޷��÷������͵�ֵ��ʾ��
��ú������ش�����ȷ���ŵ�HUGE_VAL

#include <stdio.h>      // printf
#include <math.h>       // exp

int main()
{
	double param, result;
	param = 5.0;
	result = exp(param);
	printf("The exponential value of %f is %f.\n", param, result);
	return 0;
}
//Output:
//e��5�η�
//The exponential value of 5.000000 is 148.413159.
*/



/*16>log
double log (double x);      
float log (float x);
long double log (long double x);
������Ȼ����
��Ȼ��������eΪ�׵Ķ���:��Ȼָ������(exp)�ĵ�����

����ֵ
x����Ȼ������
���x�Ǹ��ģ����ᵼ��һ�������
���xΪ�㣬����ܵ��¼������(ȡ���ڿ�ʵ��)��

#include <stdio.h>      // printf
#include <math.h>       // log

int main()
{
	double param, result;
	param = 2.7;
	result = log(param);//
	printf("log(%f) = %f\n", param, result);
	return 0;
}
//log(2.700000) = 0.993252

*/

/*17>log10
ouble log10 (double x);      
float log10 (float x);
long double log10 (long double x);

���㹫����
����x�Ĺ�������(��10Ϊ��)��

#include <stdio.h>      // printf 
#include <math.h>       // log10 

int main()
{
	double param, result;
	param = 1000.0;
	result = log10(param);
	printf("log10(%f) = %f\n", param, result);
	return 0;
}

//log10(1000.000000) = 3.000000

*/



//�������ú�����
//
//fmax()���������������нϴ��һ����
//fmin()���������������н�С��һ����
//rand()�������������
//srand()��������������ɵ�����ֵ��
#include<math.h>
int main() {

	return 0;
}
/*18>fmax
double fmax (double x, double y);

���ֵ
����������нϴ��һ��:x��y��


����ֵ
������������ֵ��

#include <stdio.h>      // printf
#include <math.h>       // fmax

int main()
{
	printf("fmax (100.0, 1.0) = %f\n", fmax(100.0, 1.0));
	printf("fmax (-100.0, 1.0) = %f\n", fmax(-100.0, 1.0));
	printf("fmax (-100.0, -1.0) = %f\n", fmax(-100.0, -1.0));
	return 0;
}
//Output:
//
//fmax(100.0, 1.0) = 100.000000
//fmax(-100.0, 1.0) = 1.000000
//fmax(-100.0, -1.0) = -1.000000

*/


/*19>fmin
double fmin (double x, double y);
����ֵ
���������С��ֵ��

include <stdio.h>      // printf 
#include <math.h>       // fmin 

int main()
{
	printf("fmin (100.0, 1.0) = %f\n", fmin(100.0, 1.0));
	printf("fmin (-100.0, 1.0) = %f\n", fmin(-100.0, 1.0));
	printf("fmin (-100.0, -1.0) = %f\n", fmin(-100.0, -1.0));
	return 0;
}
//Output:

//fmin (100.0, 1.0) = 1.000000
//fmin (-100.0, 1.0) = -100.000000
//fmin (-100.0,-1.0) = -100.000000
*/

/*
20>modf
double modf (double x, double* intpart);

������ֵ���ΪС�����������֡�
�������ִ洢��intpart��ָ��Ķ����У�С�������ɺ������ء�
�������ֵķ��Ŷ���x��

����
x
������ֵ�ֽ�Ϊ������֡�
intpart
ָ��һ������(��x��ͬ����)��ָ�룬�������Ͳ�������x��ͬ�ķ��Ŵ洢��

����ֵ
x��С�����֣�ͬ���ķ��š�

#include <stdio.h>      // printf
#include <math.h>       // modf

int main()
{
	double param, fractpart, intpart;

	param = 3.14159265;
	fractpart = modf(param, &intpart);
	printf("%f = %f + %f \n", param, intpart, fractpart);
	return 0;
}
//Output:
//
//3.141593 = 3.000000 + 0.141593
*/


/*20>rand



*/
/*21>srand



*/