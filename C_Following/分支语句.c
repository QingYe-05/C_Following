//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//////1.��֧���if else
//
////int main() {
////
////	int age = 10;
////	if (18<=age)
////	{
////		printf("����\n");
////	}
////	else {
////		printf("δ����\n");
////		printf("����̸����\n");//���Ӵ����ŵĻ�����仰������ӡ
////	}
////
////	return 0;
////}
//
////int main() {
////
////	int age = 60;
////	if (age > 18)
////		printf("����\n");
////	else if (18 <= age < 26)//��ʱ���������������꣬��Ϊ���ж���������˼��age>=18||age<26�������Ҫ��&&������������
////		printf("����\n");
////
////	return 0;
////}
//
////int main() {
////
////	int age = 170;
////	if (age > 18)
////		printf("����\n");
////	else if (age >= 18 && age < 26)
////		printf("����\n");
////	else if (age >= 26 && age < 40)
////		printf("����\n");
////	else if (age >= 40 && age < 60)
////		printf("׳��\n");
////	else if (age >= 60 && age < 100)
////		printf("����\n");
////	else
////		printf("�ϲ���\n");
////	return 0;
////}
//
//
////int main() {
////	int a = 0;
////	int b = 2;
////	//else�������ifƥ�䣬����Ĵ�Ϊ�գ���Ϊa=0��������������Ȼ��������ڲ����
////	//if (a == 1)
////	//	if (b == 2)
////	//		printf("hehe\n");
////	//else//����else
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
////	//����Ч����һ���ģ����Ҫ��һ�����õĴ�����
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
////	//if (num=5)//���д�����ӡ��hehe =���Ǹ��� ==���ж�
////	if(5 == num)
////	{
////		printf("hehe\n");
////	}
////
////	return 0;
////}
//
////��ϰ��1.�ж�һ�����Ƿ�Ϊ����
////		2.���1-100֮�������
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
////	if (Odd(num))//���ú���
////		//if (0 != num % 2)
////	{
////		printf("%d������\n", num);
////	}
////	else
////	{
////		printf("%d��������\n", num);
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
////	print("1-100���ܹ���%d������\n", flag);
////
////	return 0;
////}
//
////switch case���(case��ڣ�break����)
//
////int main() {
////	int day = 0;//����������
////	scanf("%d", &day);
////	switch (day)
////	{
////	case 1://case����������� ���ͳ��� ���ʽ
////		printf("����һ\n");
////		break;
////	case 2:printf("���ڶ�\n");
////		break;
////	case 3:printf("������\n");
////		break;
////	case 4:printf("������\n");
////		break;
////	case 5:printf("������\n");
////		break;
////	case 6:printf("������\n");
////		break;
////	case 7:printf("������\n");
////		break;
////	default:
////		printf("��������\n");
////		break;
////	}
////
////	return 0;
////}
//
////1-5������
////6-7��Ϣ��
//
////int main() {
////	int day = 0;//����������
////	scanf("%d", &day);
////	switch (day)
////	{
////	case 1:
////	case 2:
////	case 3:
////	case 4:
////	case 5:printf("������\n");
////		break;
////	case 6:
////	case 7:printf("��Ϣ��\n");
////		break;
////	default:
////		printf("��������\n");
////		break;
////	}
////
////	return 0;
////}
