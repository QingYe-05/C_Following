#define _CRT_SECURE_NO_WARNINGS
/*
1>time
time_t time (time_t* timer);
获取当前时间(Get current time) - 获取系统时间
以time_t类型的值获取当前日历时间

函数返回此值，如果参数不是空指针，它也将此值设置为计时器所指向的对象。

返回的值通常表示从UTC时间1970年1月1日00:00(即当前unix时间戳)开始的秒数。

参数
timer
指向time_t类型对象的指针，时间值存储在该对象中。
或者，这个参数可以是一个空指针，
在这种情况下不使用参数(函数仍然返回一个time_t类型的值和结果)。

返回值
当前日历时间作为time_t对象

如果参数不是空指针，则返回值与存储在参数计时器所指向的位置中的值相同。
如果该函数无法检索日历时间，则返回值-1

// time example
#include <stdio.h>      // printf
#include <time.h>       // time_t, struct tm, difftime, time, mktime

int main()
{
	// time_t timer; 声明一个 time_t 类型的变量 timer，用于存储时间值。
	time_t timer;
	// struct tm y2k = { 0 }; 声明一个 struct tm 类型的结构体变量 y2k，表示2000年1月1日的时间。
	struct tm y2k = { 0 };
	double seconds;

	// 通过将 tm_hour、tm_min 和 tm_sec 设置为 0，将时间设置为午夜 12 点
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	// 通过将 tm_year 设置为 100（因为 tm_year 的起始年份是 1900），tm_mon 设置为 0（1 月份），和 tm_mday 设置为 1（1 日）来表示 2000 年 1 月 1 日。
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;


	// 使用 time 函数获取当前时间的值，并将其存储在 timer 变量中。
	// & timer 用于传递 timer 的地址给 time 函数。

	time(&timer);  // 获取当前时间，等同于 timer = time(NULL)

	// 使用 difftime 函数计算两个时间之间的差异，返回以秒为单位的差值。
	// timer 是当前时间的值，mktime(&y2k) 是将结构体 y2k 表示的时间转换为时间值。
	// 将这两个时间值的差异（以秒为单位）存储在 seconds 变量中。
	seconds = difftime(timer, mktime(&y2k));

	//% .f 表示只输出整数部分，不显示小数点后的位数。
	printf("%.f seconds since January 1, 2000 in the current timezone", seconds);

	return 0;
}
*/

/*
2>difftime
double difftime (time_t end, time_t beginning);
计算开始和结束之间的秒差

返回值
以秒为单位(end-begin)的结果，作为double类型的浮点值。

// difftime example
#include <stdio.h>      // printf
#include <time.h>       // time_t, struct tm, difftime, time, mktime

int main()
{
	time_t now;
	struct tm newyear;
	double seconds;

	time(&now);  // 获取当前时间，等同于 timer = time(NULL)

	//使用 localtime 函数将当前时间的值转换为本地时间，并将结果存储在 newyear 变量中
	//&now 用于传递 now 的地址给 localtime 函数。
	//* localtime(&now) 用于解引用返回的结构体指针，将值复制给 newyear 结构体
	newyear = *localtime(&now);

	//将 newyear 结构体的小时、分钟和秒设置为 0，表示午夜。
	newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;

	//将 newyear 结构体的月份设置为 0（1 月份）和日期设置为 1（1 日），以表示新年。
	newyear.tm_mon = 0;  newyear.tm_mday = 1;


	//使用 difftime 函数计算当前时间与新年之间的秒数差异，并将结果存储在 seconds 变量中。
	//now 是当前时间的值，mktime(&newyear) 是将结构体 newyear 表示的时间转换为时间值
	seconds = difftime(now, mktime(&newyear));

	printf("%.f seconds since new year in the current timezone.\n", seconds);

	return 0;
}
*/



/*
3>localtime -- 转换时间值并为本地时区进行校正
struct tm * localtime (const time_t * timer);
将time_t转换为tm作为本地时间
使用计时器指向的值，用表示相应时间的值填充tm结构，这些值以本地时区表示

参数
timer（计时器）
指向time_t类型对象的指针，该对象包含时间值

返回值
指向tm结构体的指针，该结构体的成员填充了与timer的本地时间表示形式相对应的值。

// localtime example
#include <stdio.h>      // puts, printf
#include <time.h>       // time_t, struct tm, time, localtime

int main()
{
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date: %s", asctime(timeinfo));

	return 0;
}

*/

/*
4>mktime -- 将本地时间转换为日历值
time_t mktime (struct tm * timeptr);
将tm结构转换为time_t

返回time_t类型的值，该值表示timeptr所指向的tm结构所描述的本地时间(可以修改)。

// --> 这个函数执行localtime所做的反向转换

返回值
与作为参数传递的日历时间相对应的time_t值。
如果无法表示日历时间，则返回值-1

// mktime example: weekday calculator
#include <stdio.h>      // printf, scanf
#include <time.h>       // time_t, struct tm, time, mktime

int main()
{
	time_t rawtime;
	struct tm* timeinfo;
	int year, month, day;
	const char* weekday[] = { "Sunday", "Monday",
							   "Tuesday", "Wednesday",
							   "Thursday", "Friday", "Saturday" };

	//提示用户输入日期 prompt user for date
	printf("Enter year: "); fflush(stdout); scanf("%d", &year);
	printf("Enter month: "); fflush(stdout); scanf("%d", &month);
	printf("Enter day: "); fflush(stdout); scanf("%d", &day);

	//获取当前时间信息并将其修改为用户选择的值
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	//调用mktime: timeinfo->tm_wday将设置
	mktime(timeinfo);


	//timeinfo->tm_wday 存储了表示星期几的索引，使用该索引从 weekday 数组中获取相应的星期几名称
	printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);

	return 0;
}

*/




/*
>5asctime
char* asctime (const struct tm * timeptr);

将tm结构转换为字符串
将timeptr指向的tm结构的内容解释为日历时间，并将其转换为包含相应日期和时间的人类可读版本的c字符串。
返回的字符串格式如下:
Www Mmm dd hh:mm:ss yyyy
其中Www表示工作日，Mmm表示月份(用字母表示)，dd表示月份的第几天，hh:mm:ss表示时间，yyyy表示年份。
该字符串后跟一个换行字符('\n')，并以空字符结束。
它的定义行为相当于:

char* asctime(const struct tm *timeptr)
{
  static const char wday_name[][4] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  };
  static const char mon_name[][4] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };
  static char result[26];
  sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
	wday_name[timeptr->tm_wday],
	mon_name[timeptr->tm_mon],
	timeptr->tm_mday, timeptr->tm_hour,
	timeptr->tm_min, timeptr->tm_sec,
	1900 + timeptr->tm_year);
  return result;
}


// asctime example
#include <stdio.h>      // printf
#include <time.h>       // time_t, struct tm, time, localtime, asctime

int main()
{
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("The current date/time is: %s", asctime(timeinfo));

	return 0;
}
*/

/*
6>ctime
char* ctime (const time_t * timer);
将time_t值转换为字符串

这个函数等价于:
asctime(localtime(timer))

将计时器指向的值解释为日历时间，并将其转换为c字符串，其中包含以本地时间表示的相应时间和日期的人类可读版本。
返回的字符串格式如下:
Www Mmm dd hh:mm:ss yyyy
其中Www表示工作日，Mmm表示月份(用字母表示)，dd表示月份的第几天，hh:mm:ss表示时间，yyyy表示年份。
该字符串后跟一个换行字符('\n')，并以空字符结束。

// ctime example
#include <stdio.h>      // printf
#include <time.h>       // time_t, time, ctime

int main()
{
	time_t rawtime;

	time(&rawtime);//获取当前本地时间，这个必须有，否则打印出来是NULL
	printf("The current local time is: %s", ctime(&rawtime));

	return 0;
}

*/


/*
7>clock
clock_t clock (void);
返回程序所消耗的处理器时间

返回值
自与特定程序执行相关的纪元以来所经过的时钟滴答数。
如果失败，该函数返回值-1。

// clock example: frequency of primes
#include <stdio.h>      // printf
#include <time.h>       // clock_t, clock, CLOCKS_PER_SEC
#include <math.h>       // sqrt

int frequency_of_primes(int n) {
	int i, j;
	int freq = n - 1;
	//对于质数的定义，质数是指大于 1 且只能被 1 和自身整除的整数。根据这个定义，1 不被认为是质数。
	//因为它不符合大于 1 的条件，同时它只有一个因子，即 1，而不是两个不同的因子。
	//所以，1 不是质数。常用的质数是从 2 开始的整数，如 2、3、5、7、11 等。
	for (i = 2; i <= n; ++i) for (j = sqrt(i); j > 1; --j) if (i % j == 0) { --freq; break; }
	return freq;
}

int main()
{
	clock_t t;
	int f;
	t = clock();
	printf("Calculating...\n");
	f = frequency_of_primes(99999);
	//函数计算小于 100, 000（即传入参数为 99999）的质数的频数
	printf("The number of primes lower than 100,000 is: %d\n", f);
	//t = clock() - t; 计算执行代码所需的时钟周期数，并将差值赋值给变量 t，用于结束计时。
	t = clock() - t;
	printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
	return 0;
}
*/
