#define _CRT_SECURE_NO_WARNINGS
/*
C语言中的math.h头文件提供了许多常用的数学函数。下面是一些常见的math.h函数：

数值操作：

abs()：求取整型或浮点型数的绝对值。
fabs()：求取浮点型数的绝对值。
ceil()：向上取整，返回不小于给定浮点型数的最小整数值。
floor()：向下取整，返回不大于给定浮点型数的最大整数值。
round()：四舍五入，返回给定浮点型数最接近的整数值。
fmod()：浮点型数求模运算，返回两个浮点型数相除的余数。

三角函数：

sin()：求正弦值。
cos()：求余弦值。
tan()：求正切值。
asin()：求反正弦值。
acos()：求反余弦值。
atan()：求反正切值。
指数与对数：

pow()：求幂运算，返回给定底数的给定指数次幂。
sqrt()：求平方根。
exp()：求指数函数，返回e的给定指数次幂。
log()：求以e为底的自然对数。
log10()：求以10为底的对数。
其他常用函数：

max()：返回两个参数中较大的一个。
min()：返回两个参数中较小的一个。
rand()：生成随机数。
srand()：设置随机数生成的种子值。
*/

/*
1>fabs
double fabs (double x);      
float fabs (float x);
long double fabs (long double x);
计算绝对值

x
返回x的绝对值:|x|。

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

向上取整
向上舍入x，返回不小于x的最小整数值。

返回值
不小于x的最小整数值(作为浮点值)。

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

向下取整
向下舍入x，返回不大于x的最大整数值。

返回值
x的值向下舍入(作为浮点值)。

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

四舍五入
返回最接近x的整数值，中间情况从零四舍五入。

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
//初始值	四舍五入  向下取整  向上取整 舍零
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
舍零运算
见上述4的例子运算
*/


/*
6>fmod
double fmod (double numer, double denom);      
float fmod (float numer, float denom);
long double fmod (long double numer, long double denom);
求模运算  -- 计算除法余数

numer
商分子的值。
denom
商分母的值

返回值
除法运算的余数

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


//三角函数：
//
//sin()：求正弦值。
//cos()：求余弦值。
//tan()：求正切值。
//asin()：求反正弦值。
//acos()：求反余弦值。
//atan()：求反正切值。

/*
7>sin
 double sin (double x);      
 float sin (float x);
 long double sin (long double x);

 计算正弦
返回x弧度角的正弦值。

x
用弧度表示角度的值。
1弧度等于180/PI度。

#include <stdio.h>      // printf
#include <math.h>       // sin

#define PI 3.14159265

int main()
{
	double param, result;
	param = 30.0;

	//六分之PI
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
计算余弦
返回x弧度角的余弦值。

x
用弧度表示角度的值。
1弧度等于180/PI度。

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
计算切线
返回x弧度角的正切值。

x
表示角度的值，用弧度表示。
1弧度等于180/PI度。

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

返回值
主arcsinx，在区间[- /2，+ /2]弧度内。
1弧度等于180/PI度。


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
计算反余弦
返回以弧度表示的arccosx的主值。


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
计算弧切线 反正切
返回x的arctan的主值，以弧度表示。

返回值
x的主arctan，在区间[- pi/2，+ pi/2]弧度内。
1弧度等于180/PI度。

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
//输出:
//1.000000的弧切是45.000000度。
*/



//指数与对数：
//
//pow()：求幂运算，返回给定底数的给定指数次幂。
//sqrt()：求平方根。
//exp()：求指数函数，返回e的给定指数次幂。
//log()：求以e为底的自然对数。
//log10()：求以10为底的对数。
// 

/*13>pow
double pow (double base, double exponent);      
float pow (float base, float exponent);
long double pow (long double base, long double exponent);     
double pow (double base, int exponent);
long double pow (long double base, int exponent);

提高权
返回基数的幂指数:

base
基础值。
exponent
指数的值。

返回值
取底的幂指数的结果。
如果基数是有限负的，并且指数是有限的但不是整数，则会导致域错误。
如果基数和指数都为零，在某些实现上也可能导致域错误。
如果base为零且exponent为负，则可能导致域错误或极点错误(或没有错误，取决于库实现)。
如果结果太大或太小而无法用返回类型的值表示，则该函数还可能导致范围错误。

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

计算平方根
返回根号x。

返回值
√x。
如果x为负，则出现域错误:

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

计算指数函数
返回x的以e为底的指数函数，即e的x次方:。

返回值
x的指数值。
如果结果的大小太大，无法用返回类型的值表示，
则该函数返回带有正确符号的HUGE_VAL

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
//e的5次方
//The exponential value of 5.000000 is 148.413159.
*/



/*16>log
double log (double x);      
float log (float x);
long double log (long double x);
计算自然对数
自然对数是以e为底的对数:自然指数函数(exp)的倒数。

返回值
x的自然对数。
如果x是负的，它会导致一个域错误。
如果x为零，则可能导致极点错误(取决于库实现)。

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

计算公对数
返回x的公数对数(以10为底)。

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



//其他常用函数：
//
//fmax()：返回两个参数中较大的一个。
//fmin()：返回两个参数中较小的一个。
//rand()：生成随机数。
//srand()：设置随机数生成的种子值。
#include<math.h>
int main() {

	return 0;
}
/*18>fmax
double fmax (double x, double y);

最大值
返回其参数中较大的一个:x或y。


返回值
其参数的最大数值。

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
返回值
其参数的最小数值。

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

将浮点值拆分为小数和整数部分。
整数部分存储在intpart所指向的对象中，小数部分由函数返回。
这两部分的符号都是x。

参数
x
将浮点值分解为多个部分。
intpart
指向一个对象(与x相同类型)的指针，其中整型部分以与x相同的符号存储。

返回值
x的小数部分，同样的符号。

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