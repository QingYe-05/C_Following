#define _CRT_SECURE_NO_WARNINGS
/*
1>time
time_t time (time_t* timer);
��ȡ��ǰʱ��(Get current time) - ��ȡϵͳʱ��
��time_t���͵�ֵ��ȡ��ǰ����ʱ��

�������ش�ֵ������������ǿ�ָ�룬��Ҳ����ֵ����Ϊ��ʱ����ָ��Ķ���

���ص�ֵͨ����ʾ��UTCʱ��1970��1��1��00:00(����ǰunixʱ���)��ʼ��������

����
timer
ָ��time_t���Ͷ����ָ�룬ʱ��ֵ�洢�ڸö����С�
���ߣ��������������һ����ָ�룬
����������²�ʹ�ò���(������Ȼ����һ��time_t���͵�ֵ�ͽ��)��

����ֵ
��ǰ����ʱ����Ϊtime_t����

����������ǿ�ָ�룬�򷵻�ֵ��洢�ڲ�����ʱ����ָ���λ���е�ֵ��ͬ��
����ú����޷���������ʱ�䣬�򷵻�ֵ-1

// time example
#include <stdio.h>      // printf
#include <time.h>       // time_t, struct tm, difftime, time, mktime

int main()
{
	// time_t timer; ����һ�� time_t ���͵ı��� timer�����ڴ洢ʱ��ֵ��
	time_t timer;
	// struct tm y2k = { 0 }; ����һ�� struct tm ���͵Ľṹ����� y2k����ʾ2000��1��1�յ�ʱ�䡣
	struct tm y2k = { 0 };
	double seconds;

	// ͨ���� tm_hour��tm_min �� tm_sec ����Ϊ 0����ʱ������Ϊ��ҹ 12 ��
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	// ͨ���� tm_year ����Ϊ 100����Ϊ tm_year ����ʼ����� 1900����tm_mon ����Ϊ 0��1 �·ݣ����� tm_mday ����Ϊ 1��1 �գ�����ʾ 2000 �� 1 �� 1 �ա�
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;


	// ʹ�� time ������ȡ��ǰʱ���ֵ��������洢�� timer �����С�
	// & timer ���ڴ��� timer �ĵ�ַ�� time ������

	time(&timer);  // ��ȡ��ǰʱ�䣬��ͬ�� timer = time(NULL)

	// ʹ�� difftime ������������ʱ��֮��Ĳ��죬��������Ϊ��λ�Ĳ�ֵ��
	// timer �ǵ�ǰʱ���ֵ��mktime(&y2k) �ǽ��ṹ�� y2k ��ʾ��ʱ��ת��Ϊʱ��ֵ��
	// ��������ʱ��ֵ�Ĳ��죨����Ϊ��λ���洢�� seconds �����С�
	seconds = difftime(timer, mktime(&y2k));

	//% .f ��ʾֻ����������֣�����ʾС������λ����
	printf("%.f seconds since January 1, 2000 in the current timezone", seconds);

	return 0;
}
*/

/*
2>difftime
double difftime (time_t end, time_t beginning);
���㿪ʼ�ͽ���֮������

����ֵ
����Ϊ��λ(end-begin)�Ľ������Ϊdouble���͵ĸ���ֵ��

// difftime example
#include <stdio.h>      // printf
#include <time.h>       // time_t, struct tm, difftime, time, mktime

int main()
{
	time_t now;
	struct tm newyear;
	double seconds;

	time(&now);  // ��ȡ��ǰʱ�䣬��ͬ�� timer = time(NULL)

	//ʹ�� localtime ��������ǰʱ���ֵת��Ϊ����ʱ�䣬��������洢�� newyear ������
	//&now ���ڴ��� now �ĵ�ַ�� localtime ������
	//* localtime(&now) ���ڽ����÷��صĽṹ��ָ�룬��ֵ���Ƹ� newyear �ṹ��
	newyear = *localtime(&now);

	//�� newyear �ṹ���Сʱ�����Ӻ�������Ϊ 0����ʾ��ҹ��
	newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;

	//�� newyear �ṹ����·�����Ϊ 0��1 �·ݣ�����������Ϊ 1��1 �գ����Ա�ʾ���ꡣ
	newyear.tm_mon = 0;  newyear.tm_mday = 1;


	//ʹ�� difftime �������㵱ǰʱ��������֮����������죬��������洢�� seconds �����С�
	//now �ǵ�ǰʱ���ֵ��mktime(&newyear) �ǽ��ṹ�� newyear ��ʾ��ʱ��ת��Ϊʱ��ֵ
	seconds = difftime(now, mktime(&newyear));

	printf("%.f seconds since new year in the current timezone.\n", seconds);

	return 0;
}
*/



/*
3>localtime -- ת��ʱ��ֵ��Ϊ����ʱ������У��
struct tm * localtime (const time_t * timer);
��time_tת��Ϊtm��Ϊ����ʱ��
ʹ�ü�ʱ��ָ���ֵ���ñ�ʾ��Ӧʱ���ֵ���tm�ṹ����Щֵ�Ա���ʱ����ʾ

����
timer����ʱ����
ָ��time_t���Ͷ����ָ�룬�ö������ʱ��ֵ

����ֵ
ָ��tm�ṹ���ָ�룬�ýṹ��ĳ�Ա�������timer�ı���ʱ���ʾ��ʽ���Ӧ��ֵ��

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
4>mktime -- ������ʱ��ת��Ϊ����ֵ
time_t mktime (struct tm * timeptr);
��tm�ṹת��Ϊtime_t

����time_t���͵�ֵ����ֵ��ʾtimeptr��ָ���tm�ṹ�������ı���ʱ��(�����޸�)��

// --> �������ִ��localtime�����ķ���ת��

����ֵ
����Ϊ�������ݵ�����ʱ�����Ӧ��time_tֵ��
����޷���ʾ����ʱ�䣬�򷵻�ֵ-1

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

	//��ʾ�û��������� prompt user for date
	printf("Enter year: "); fflush(stdout); scanf("%d", &year);
	printf("Enter month: "); fflush(stdout); scanf("%d", &month);
	printf("Enter day: "); fflush(stdout); scanf("%d", &day);

	//��ȡ��ǰʱ����Ϣ�������޸�Ϊ�û�ѡ���ֵ
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	//����mktime: timeinfo->tm_wday������
	mktime(timeinfo);


	//timeinfo->tm_wday �洢�˱�ʾ���ڼ���������ʹ�ø������� weekday �����л�ȡ��Ӧ�����ڼ�����
	printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);

	return 0;
}

*/




/*
>5asctime
char* asctime (const struct tm * timeptr);

��tm�ṹת��Ϊ�ַ���
��timeptrָ���tm�ṹ�����ݽ���Ϊ����ʱ�䣬������ת��Ϊ������Ӧ���ں�ʱ�������ɶ��汾��c�ַ�����
���ص��ַ�����ʽ����:
Www Mmm dd hh:mm:ss yyyy
����Www��ʾ�����գ�Mmm��ʾ�·�(����ĸ��ʾ)��dd��ʾ�·ݵĵڼ��죬hh:mm:ss��ʾʱ�䣬yyyy��ʾ��ݡ�
���ַ������һ�������ַ�('\n')�����Կ��ַ�������
���Ķ�����Ϊ�൱��:

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
��time_tֵת��Ϊ�ַ���

��������ȼ���:
asctime(localtime(timer))

����ʱ��ָ���ֵ����Ϊ����ʱ�䣬������ת��Ϊc�ַ��������а����Ա���ʱ���ʾ����Ӧʱ������ڵ�����ɶ��汾��
���ص��ַ�����ʽ����:
Www Mmm dd hh:mm:ss yyyy
����Www��ʾ�����գ�Mmm��ʾ�·�(����ĸ��ʾ)��dd��ʾ�·ݵĵڼ��죬hh:mm:ss��ʾʱ�䣬yyyy��ʾ��ݡ�
���ַ������һ�������ַ�('\n')�����Կ��ַ�������

// ctime example
#include <stdio.h>      // printf
#include <time.h>       // time_t, time, ctime

int main()
{
	time_t rawtime;

	time(&rawtime);//��ȡ��ǰ����ʱ�䣬��������У������ӡ������NULL
	printf("The current local time is: %s", ctime(&rawtime));

	return 0;
}

*/


/*
7>clock
clock_t clock (void);
���س��������ĵĴ�����ʱ��

����ֵ
�����ض�����ִ����صļ�Ԫ������������ʱ�ӵδ�����
���ʧ�ܣ��ú�������ֵ-1��

// clock example: frequency of primes
#include <stdio.h>      // printf
#include <time.h>       // clock_t, clock, CLOCKS_PER_SEC
#include <math.h>       // sqrt

int frequency_of_primes(int n) {
	int i, j;
	int freq = n - 1;
	//���������Ķ��壬������ָ���� 1 ��ֻ�ܱ� 1 ����������������������������壬1 ������Ϊ��������
	//��Ϊ�������ϴ��� 1 ��������ͬʱ��ֻ��һ�����ӣ��� 1��������������ͬ�����ӡ�
	//���ԣ�1 �������������õ������Ǵ� 2 ��ʼ���������� 2��3��5��7��11 �ȡ�
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
	//��������С�� 100, 000�����������Ϊ 99999����������Ƶ��
	printf("The number of primes lower than 100,000 is: %d\n", f);
	//t = clock() - t; ����ִ�д��������ʱ����������������ֵ��ֵ������ t�����ڽ�����ʱ��
	t = clock() - t;
	printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
	return 0;
}
*/
