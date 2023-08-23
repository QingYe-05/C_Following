//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//////1.分支语句if else
//
////int main() {
////
////	int age = 10;
////	if (18<=age)
////	{
////		printf("成年\n");
////	}
////	else {
////		printf("未成年\n");
////		printf("不能谈恋爱\n");//不加大括号的话，这句话正常打印
////	}
////
////	return 0;
////}
//
////int main() {
////
////	int age = 60;
////	if (age > 18)
////		printf("少年\n");
////	else if (18 <= age < 26)//此时输出结果依旧是青年，因为这判断条件的意思是age>=18||age<26，因此有要用&&连接两个条件
////		printf("青年\n");
////
////	return 0;
////}
//
////int main() {
////
////	int age = 170;
////	if (age > 18)
////		printf("少年\n");
////	else if (age >= 18 && age < 26)
////		printf("青年\n");
////	else if (age >= 26 && age < 40)
////		printf("中年\n");
////	else if (age >= 40 && age < 60)
////		printf("壮年\n");
////	else if (age >= 60 && age < 100)
////		printf("老年\n");
////	else
////		printf("老不死\n");
////	return 0;
////}
//
//
////int main() {
////	int a = 0;
////	int b = 2;
////	//else和最近的if匹配，此题的答案为空，因为a=0不符合条件，自然不会进入内层语句
////	//if (a == 1)
////	//	if (b == 2)
////	//		printf("hehe\n");
////	//else//悬空else
////	//	printf("haha\n");
////	//return 0;
////	if (a == 1)
////	{
////		if (b == 2) {
////			printf("hehe\n");
////		}	
////		else {
////			printf("haha\n");
////		}
////	}
////	return 0;
////}
//
////int test() {
////	//if (1)
////	//	return 0;
////	//printf("haha\n");
////	//return 1;
////	
////	//两种效果是一样的，因此要有一个良好的代码风格
////	if (1)
////	{
////		return 0;
////	}
////	else
////	{
////		return 1;
////	}
////}
////
////
////int main() {
////
////	test();
////	return 0;
////}
//
////int main() {
////
////	int num = 3;
////	//if (num=5)//运行代码会打印出hehe =号是复制 ==是判断
////	if(5 == num)
////	{
////		printf("hehe\n");
////	}
////
////	return 0;
////}
//
////练习：1.判断一个数是否为奇数
////		2.输出1-100之间的奇数
////int Odd(int num) {
////	if (0 == num % 2)
////	{
////		return 0;
////	}
////	else
////	{
////		return 1;
////	}
////}
////int main() {
////	int num = 0;
////	scanf("%d", &num);
////	if (Odd(num))//调用函数
////		//if (0 != num % 2)
////	{
////		printf("%d是奇数\n", num);
////	}
////	else
////	{
////		printf("%d不是奇数\n", num);
////	}
////	return 0;
////}
//
////int main() {
////	int n = 100;
////	int flag = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		if (0==i%2)
////		{
////			printf("%d\n", i);
////			flag++;
////		}
////	}
////	print("1-100中总共有%d个奇数\n", flag);
////
////	return 0;
////}
//
////switch case语句(case入口，break出口)
//
////int main() {
////	int day = 0;//必须是整型
////	scanf("%d", &day);
////	switch (day)
////	{
////	case 1://case后面必须是是 整型常量 表达式
////		printf("星期一\n");
////		break;
////	case 2:printf("星期二\n");
////		break;
////	case 3:printf("星期三\n");
////		break;
////	case 4:printf("星期四\n");
////		break;
////	case 5:printf("星期五\n");
////		break;
////	case 6:printf("星期六\n");
////		break;
////	case 7:printf("星期七\n");
////		break;
////	default:
////		printf("输入有误\n");
////		break;
////	}
////
////	return 0;
////}
//
////1-5工作日
////6-7休息日
//
////int main() {
////	int day = 0;//必须是整型
////	scanf("%d", &day);
////	switch (day)
////	{
////	case 1:
////	case 2:
////	case 3:
////	case 4:
////	case 5:printf("工作日\n");
////		break;
////	case 6:
////	case 7:printf("休息日\n");
////		break;
////	default:
////		printf("输入有误\n");
////		break;
////	}
////
////	return 0;
////}
