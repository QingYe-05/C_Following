//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>//标准输入
//
//
///*一、while循环*/
//
//
////int main() {
////	int i = 1;
////	while (i<=10)
////	{
////		if (i==5)
////		{
////			//break;//在while循环中，break用于永久的终止循环
////
////			continue;//在while循环中，continue用于跳过当前本次循环continue后面的代码，继续下一次循环
////			
////		}
////		printf("%d ", i);
////		i++;
////	}
////
////	return 0;
////
////}
//
////getchar
//
////EOF - end of file 文件结束标志
//
////int main() {
////
////	int ch = getchar();//获取一个字符,返回的类型是整型，原因1.ASCII码 2.EOF（-1）
////	printf("%c\n", ch);
////	putchar(ch);//输出一个字符
////
////	return 0;
////}
//
////int main() {
////	
////	int ch1 = 0;
////	while ((ch1 = getchar()) != EOF)//循环在键盘上获取一个字符，Ctrl+Z结束循环
////	{
////		putchar(ch1);
////	}
////
////	return 0;
////}
//
////int main() {
////
////	char password[20] = { 0 };
////	printf("请输入密码：");
////	scanf("%s", password);//这里不用加&，因为password是数组，本来就是地址
////	printf("请确认密码(Y/N)：");
////	//清理缓冲区
////	//getchar();//拿走'\n'
////	//但是getchar()只能清理一个字符，因此要加循环
////	int tem = 0;
////	while ((tem=getchar())!='\n')
////	{
////		;//相当于清理缓冲区
////	}
////	int ch = getchar();
////	if (ch=='Y')
////	{
////		printf("确认成功\n");
////	}
////	else
////	{
////		printf("确认失败\n");
////	}
////	
////	return 0;
////}
//
////实现输入一串字符，只输出数字的代码
//
////int main() {
////	int ch = 0;
////	while ((ch = getchar())!=EOF)
////	{
////		if (ch < '0'||ch>'9')
////		{
////			continue;
////		}
////		putchar(ch);
////	}
////
////	return 0;
////}
//
////while循环的框架
////int main() {
////	int a = 1;//初始化
////	while (a<5)//判断部分
////	{
////		printf("%d\n", a);
////		a++;//调整部分
////	}
////
////	return 0;
////}
//
//
///*二、for循环*/
//
//
//////for循环的框架
//////for (初始化; 判断; 调整部分) {},for循环修改起来比较清晰，即相对于while循环的优势
////int main() {
////
////	int i = 0;
////	for (i = 1; i < 10; i++)
////	{
////		if (i == 5)
////		{
////			//break;
////			continue;//与while中的不一样，for循环中没有跳过i++，因此打印结果是12346789
////		}
////		printf("%d ", i);
////	}
////	return 0;
////}
//
////int main() {
////
////	for (;;) {//一旦判断部分省略，则判断部分恒为真，不建议随便省略
////		printf("hehe\n");
////	}
////
////	return 0;
////}
//
////int main() {
////
////	int i = 0;
////	int j = 0;
////	for (; i < 3; i++)
////	{
////		for (; j < 3; j++) {//只打印出3个hehe，因为i=2的时候j为3，无法进入内部循环，程序结束
////			printf("hehe\n");
////		}
////	}
////
////	return 0;
////}
//
//
//////请问循环了多少次？  answer：0次  因为判断条件k=0是赋值语句，为假，因此一次没进去
////int main() {
////	
////	int i = 0;
////	int k = 0;
////	for (i = 0, k = 0; k = 0; i++, k++)
////		k++;
////	return 0;
////}
//
///*do while循环 先执行在判断*/
//
////int main() {
////	int i = 1;
////	do
////	{
////		if (i==5)
////		{
////			//break;
////			continue;//跳过本次循环，跳过continue后面的代码，i不变，死循环
////		}
////		printf("%d ",i);
////		i++;
////	} while (i<=10);//这里的分号不能少
////
////	return 0;
////}
//
//
//
//
//
//
//
//
//
///* 循环 练习
//1.计算n的阶乘
//2.计算1!+2!+3!+...+10!
//3.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x, int v[], int n);
//功能：在v[0]<=v[1]<=v[2]<=...<=v[n-1]的数组中查找x
//4.编写代码，演示多个字符从两端移动，向中间汇聚
//5.编写代码实现，模拟用户登录情景，并且只能登录三次。
//（只允许输入三次密码，如果密码正确则提示成功登录，如果三次军错误，则退出程序）
//*/
//
//////1.计算n的阶乘
////int main() {
////	int count = 1;
////	int n = 1;
////	scanf("%d",&n);
////	int ans = 1;
////	if (n>=0)
////	{
////		if (n > 0)
////		{
////			while (i<=n)//循环判断i不能超过n
////			{
////				ans = ans * i;
////				i++;
////			}
////			printf("%d的阶乘为%d", n, ans);
////		}
////		else {
////			printf("0的阶乘为1\n");
////		}
////	}
////	else
////	{
////		printf("负数没有阶乘\n");
////	}
////	return 0;
////}
//
//////2.计算1!+ 2!+ 3!+ ... + 10!
////int main() {
////
////	int ans = 1;
////	int n = 10;
////	int sum = 0;
////	for (int i = 1;  i <= n;  i++)
////	{
////		int j = 1;
////		int ans = 1;//这两个变量初始化很重要，每次求下一个数的阶乘都要将这两个变量初始化为1
////		for (int j = 1; j <= i; j++) {
////			ans = ans * j;//依次求每一个数的阶乘
////		}
////		sum = sum + ans;//将每个数的阶乘依次累加
////	}
////	printf("1!+2!+3!+...+10!=%d", sum);
////	return 0;
////}
//// 精简解法
////int main() {
////	int n = 0;
////	int sum = 0;
////	int num = 1;
////	int tep = 1;
////	scanf("%d",&n);
////	for (int i = 1; i <= n; i++)
////	{
////		num = num * i;
////		sum = sum + num;
////	}
////	printf("%d", sum);
////	return 0;
////}
//
////3.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x, int v[], int n);
////功能：在v[0] <= v[1] <= v[2] <= ... <= v[n - 1]的数组中查找x
//
//
////#define MAX 100000
////int binsearch(int x, int* v, int n) {
////	int left = 0;//用下标来记录
////	int right = n-1;
////
////
////	for (; left <= right; )//初始化和调整部分省略
////	{
////		int mid = (left + right) / 2;
////		if (x < v[mid])
////		{
////			right = mid - 1;//这里要排除范围之外的数
////		}
////		else if (x > v[mid])
////		{
////			left = mid + 1;
////		}
////		else
////		{
////			return mid;
////		}
////		//while (left <= right)
////		//{
////		//	int mid = (left + right) / 2;
////		//	if (x < v[mid])
////		//	{
////		//		right = mid - 1;//这里要排除范围之外的数
////		//	}
////		//	else if (x > v[mid])
////		//	{
////		//		left = mid + 1;
////		//	}
////		//	else
////		//	{
////		//		return mid;
////		//	}
////
////		//}
////	}
////	return -1;// 如果没有找到，返回一个特殊值
////}
////int main() {
////
////	int x = 1;
////	int n = MAX;
////	int v[MAX] = {0};
////	scanf("%d", &x);
////	for (int i = 0; i < MAX; i++)
////	{
////		v[i] = i;
////	}
////	int index = binsearch(x, v, n);//数组传参的时候用v，而不能用v[i]
////	if (index!=-1)
////		printf("找到了，在数组中%d的下标为%d\n",x,index);
////	else
////		printf("在数组中未找到%d\n",x);
////	return 0;
////}
//
//////4.编写代码，演示多个字符从两端移动，向中间汇聚
////#include<string.h>
////#include<Windows.h>
////int main() {
////	char arr1[] = "'Cause I like me better when I like me better when I'm with you";
////	char arr2[] = "###############################################################";
////	int left = 0;
////	int right = strlen(arr1) - 1;
////	while (left<=right)
////	{
////		arr2[left] = arr1[left];
////		arr2[right] = arr1[right];
////		printf("%s\n",arr2);
////		Sleep(500);//睡眠0.5秒
////		system("cls");//清空屏幕
////		left++;
////		right--;
////	}
////	return 0;
////}
//
//
//
////5.编写代码实现，模拟用户登录情景，并且只能登录三次。
////（只允许输入三次密码，如果密码正确则提示成功登录，如果三次均错误，则退出程序）
////#include<string.h>
////int main() {
////	int account = 666;
////	char pwd1[] = "123456";
////	char pwd2[20] = { 0 };
////	int count = 0;
////	printf("账号：666\n");
////	while (count < 3)
////	{
////		printf("请输入密码：");
////		scanf("%s", pwd2);
////		//C语言比较两个字符串是否相同，要用strcmp，相等返回值是0，比较的是相对应的ASCII码值
////		if (strcmp(pwd1, pwd2) == 0)//连个字符串比较不能用 == 或者 != 
////		{
////			printf("登录成功\n");
////			break;
////		}
////		else
////		{
////			printf("密码错误，重新输入\n");
////			count++;
////		}
////		if (count >= 3) {
////			printf("三次密码均错误，退出程序\n");
////			break;
////		}
////	}
////	return 0;
////}
//
//
//
//
//
//
//////写一个猜数字游戏
//////1. 自动产生一个1 - 100之间的随机数
//////2.猜数字
//////	a.猜对了，就恭喜你，游戏结束
//////	b.你猜错了，会告诉猜大了，还是猜小了，继续猜，直到猜对
//////3.游戏可以一直玩，除非退出游戏
////#include<stdlib.h>
////void menu() {
////	printf("***********************************\n");
////	printf("********    猜数字游戏    *********\n");
////	printf("********      1.Play      *********\n");
////	printf("********      0.Exit      *********\n");
////	printf("***********************************\n");
////}
////
////void game() {
////	//1.随机生成一个数字
////	// rand()随机生成一个0-32767之间的数字，时间 - 时间戳
////	//2.猜数字
////	//只有rand()函数，每次生成的数字都是一样的
////	//因此需要在调用rand()之前，还需要调用srand()函数来设置随机数生成器
////	//srand(100)只能生成固定值，因此需要用到时间戳，让这个生成数变随机
////
////	int ret = rand()%100+1;//%100的余数是1-99，然后+1，范围就是1-100
////	printf("%d\n", ret);
////	int guess = 0;
////	while (1)
////	{
////		printf("请猜数字:>\n");
////		scanf("%d", &guess);
////		if (guess > ret)
////		{
////			printf("猜大了\n");
////		}
////		else if (guess < ret)
////		{
////			printf("猜小了\n");
////		}
////		else
////		{
////			printf("恭喜你猜对了！\n");
////			break;
////		}
////	}
////}
////
////int main() {
////	int input = 0;
////	srand((unsigned int)time(NULL));//time_t 整型，需进一步转换为unsigned int类型，只需要调用一次即可
////	//先执行一次，在判断
////	do
////	{
////		menu();//打印菜单
////		printf("请选择:>");
////		scanf("%d", &input);//特别要注意&什么时候加，什么时候不加
////		switch (input)
////		{
////		case 1:
////			game();
////			break;
////		case 0:
////			printf("退出游戏\n");
////			break;
////		default:
////			printf("选择错误，请重新选择\n");
////			break;
////		}
////	} while (input);
////	return 0;
////}
//
//
//
//////求1-100能被3整除的数
////int main() {
////
////	for (int i = 3; i <= 100; i+=3)
////	{
////		//if (i % 3 == 0) {
////		//	printf("%d ", i);
////		//}
////		
////		//优化算法，将i++改为i+=3
////		printf("%d ",i);
////	}
////
////	return 0;
////}
//
//
//////求两个数的最大公约数（辗转相除法）
////int main() {
////	int m = 0;
////	int n = 0;
////	int max = 0;
////	printf("m,n均不能为0，请输入m，n的值：\n");
////	scanf("%d%d", &m, &n);
////	
////  //简洁方法
////	//while (max = m%n)
////	//{
////	//	m = n;
////	//	n = max;
////	//}
////	//printf("最大公约数为：%d\n", n);
////
////	while (1)
////	{
////		if (m > n)
////		{
////			m = m % n;
////			if (m == 0)
////			{
////				printf("%d\n", n);
////				break;
////			}
////		}
////		else
////		{
////			//n = n % m;
////			//if (n==0)
////			//{
////			//	printf("%d\n", m);
////			//	break;
////			//}
////			//等价于上述代码
////			max = n;
////			n = m;
////			m = max;
////		}
////	}
////	return 0;
////}
//
//////求最小公倍数（m*n/最大公约数）
////int main() {
////	int m = 0;
////	int n = 0;
////	int tmp = 0;
////	printf("m,n均不能为0，请输入m，n的值：\n");
////	scanf("%d%d", &m, &n);
////	int m1 = m;
////	int n1 = n;
////	//简洁方法
////	while (tmp = m%n)
////	{
////		m = n;
////		n = tmp;
////	}
////	printf("%d\n", m1 * n1 / n);
////	return 0;
////}
//
//
//
//
//
//
//////作业
//////打印1000-2000年之间的闰年
////// year%400==0 || (year%4==0 && year%100!=0) 
////int main() {
////
////	int n = 2000;
////	for (int year = 1000; year <=n; year++)
////	{
////		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
////			printf("%d\n", year);
////		}
////	}
////}
//
//////写一个代码：打印100-200之间的素数
//////素数-质数
///////只能被1和它本身整除
////int main() {
////	int i = 0;
////	int j = 0;
////	for (i = 101; i < 200; i += 2)
////	{
////		for (j = 2; j < i; j += 2)
////		{
////			if (i % j == 0) {
////				break;
////			}
////
////		}
////		if (i == j)
////		{
////			printf("%d ", i);
////		}
////	}
////	return 0;
////}
//////优化方法  从几个不同的角度优化  1.偶数 2.因子开方 3.设置反证法标记（这样判断条件就不局限于内层循环的正反了）
////#include<stdio.h>
////#include<math.h>
////int main() {
////	int i, j;
////	for (i = 101; i <= 200; i += 2) {//偶数不可能是素数
////		int isPrime = 1;  // 假设当前数字是素数
////		//m=a*b  -  a和b中至少有一个数字是 <= 开平方m的 16=2*8=4*4  math.h中的sqrt()函数 - 开平方
////		for (j = 2; j < sqrt(i); j++) {//这里要是用j--的话，下面判断的地方就不可以用(j==i)了
////			if (i % j == 0) {
////				isPrime = 0;  // 若能整除，则不是素数  -- 这种反证法思想很重要
////				break;
////			}
////		}
////		if (isPrime) {//如果这里不设置素数标志的话，而直接用(i%j!=0)判断的话，这里的j是全局的j而不是局部的j，因此不能用这个方法判断
////			printf("%d ", i);
////		}
////	}
////	return 0;
////}
//
//
//
///*三、goto语句*/
//
//
////int main() {
////
////flag://死循环
////	printf("haha\n");
////	printf("hehe\n");
////
////	goto flag;
////	return 0;
////}
//
////关机程序
////只要运行起来就会在一分钟内关机，如果输入：我是猪，就取消关机！
//	//shutdown -s -t 60 //-s表示设置关机，-t表示设置时间，60表示60s后关机
//	//shutdown -a //取消关机
////#include<string.h>
////#include<stdlib.h>
////
////int main() {
////
////	//关机
////	//C语言提供了一个函数：system() - 执行系统命令
////	system("shutdown -s -t 60");//需引用stdlib.h头文件
////	char arr1[20] = { 0 };
////
////again:
////	printf("请注意！你的电脑将会在一分钟后关机，请输入 我是猪 即可取消关机。\n");
////	scanf("%s", arr1);
////	if (strcmp(arr1, "我是猪") == 0)//需要引用string.h头文件
////	{
////		system("shutdown -a");
////		printf("已取消关机\n");
////	}
////	else
////	{
////		printf("输入字段不匹配，请重新输入\n");
////		goto again;
////	}
////
////	return 0;
////}
//
//
//////goto语句只能在一个函数范围内跳转，不能跨函数
////void test() {
////
////flag:
////	printf("test\n");
////}
////int main() {
////
////	goto flag;
////	return 0;
////}