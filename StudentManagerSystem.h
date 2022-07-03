#pragma once
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

//每操作完一次就要清空屏幕
void cleanScreen() {
	system("pause");   //暂停
	system("cls");		//清空屏幕
}

//欢迎界面
void welcome() {
	printf("*************************************************\n");
	printf("\t\t欢迎使用学生管理系统\t\t\t\n");
	printf("*************************************************\n");
	printf("*\t\t请选择功能列表\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t9.退出系统\t\t\t*\n");
	printf("\n");
}

typedef struct student {
	char name[30];	//名字
	int age;	//年龄
	long long stuNum;  //学号
	int score;	//分数
}Student;

typedef struct _Node {
	Student stu;
	struct _Node* pNext;
}Node;

Node* g_pHead = NULL;   //初始化头指针

//录入学生信息
void InputStudent() {
	Node* pNewNode = (Node*)malloc(sizeof(Node)); //注意这边是(sizeof(Node))，而不是sizeof(Node*)!!!
	pNewNode->pNext = NULL;

	//头插法
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	}
	else {
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	//输入数据
	printf("请输入学生信息：\n");
	printf("输入姓名：\n");
	scanf("%s", pNewNode->stu.name);
	printf("输入年龄：\n");
	scanf("%d", &pNewNode->stu.age);
	printf("输入学号：\n");
	scanf("%lld", &pNewNode->stu.stuNum);
	printf("输入分数：\n");
	scanf("%d", &pNewNode->stu.score);
	printf("学生信息录入成功！\n");
	cleanScreen();
}

//输出学生信息
void PrintStudent() {
	Node* p = g_pHead;
	printf("*************************************************\n");
	printf("学号\t\t姓名\t\t年龄\t\t分数\n");
	while (p != NULL) {
		printf("%-16lld", p->stu.stuNum);
		printf("%-16s", p->stu.name);
		printf("%-16d", p->stu.age);
		printf("%-16d\n", p->stu.score);
		p = p->pNext;
	}
	cleanScreen();
}

//保存学生信息
void SaveStudent() {
	//打开文件
	FILE* fp = fopen("C:\\Users\\14185\\Desktop\\stuinfo.dat", "w");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return;
	}
	//将数据写入文件(遍历链表)
	Node* p = g_pHead;
	while (p != NULL) {
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}

	//关闭文件
	fclose(fp);
	printf("数据保存成功！\n");
	cleanScreen();
}

//读取文件中的数据
void ReadStudent() {
	FILE* fp = fopen("C:\\Users\\14185\\Desktop\\stuinfo.dat", "r");
	if (fp == NULL) {
		printf("读取文件失败！\n");
		return;
	}
	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp)) {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;

		memcpy(pNewNode, &stu, sizeof(Student));

		if (g_pHead == NULL) {
			g_pHead = pNewNode;
		}
		else {
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
		fclose(fp);
		printf("文件读取成功！\n");
		cleanScreen();
	}
}
//统计所有学生人数
void CountStudent() {
	int cnt = 0;
	Node* p = g_pHead;
	while (p != NULL) {
		++cnt;
		p = p->pNext;
	}
	printf("学生的总人数为：%d\n", cnt);
	cleanScreen();
}

//查找学生
void FindStudent() {
	long long stuNum;   //学号
	printf("请输入需要查找学生的学号：\n");
	scanf("%lld", &stuNum);
	Node* p = g_pHead;
	while (p != NULL) {
		if (p->stu.stuNum == stuNum) {
			printf("学号：%lld  姓名：%s  年龄：%d  分数：%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			cleanScreen();
			return;
		}
		p = p->pNext;
	}
	printf("没有找到相关学生信息。\n");
	cleanScreen();
}

//修改学生信息
void ModifyStudent() {
	printf("请输入需要修改学生信息的学号：\n");
	long long stuNum;
	scanf("%lld", &stuNum);
	Node* p = g_pHead;
	while (p != NULL) {
		if (p->stu.stuNum == stuNum) {
			printf("请输入修改后的信息(学号/姓名/年龄/分数):\n");
			scanf("%lld %s %d %d", &p->stu.stuNum, p->stu.name, &p->stu.age, &p->stu.score);
			cleanScreen();
			return;
		}
		p = p->pNext;
	}
	printf("没有找到学生信息。\n");
	cleanScreen();
}

//删除学生信息
void DeleteStudent() {
	printf("请输入需要删除的学生信息的学号：\n");
	long long stuNum;
	scanf("%lld", &stuNum);
	Node* p1, * p2;    //注意这里p2前面也要加星号！

	//如果一开始链表为空
	if (g_pHead == NULL) {
		printf("没有找到学生信息。\n");
		cleanScreen();
		return;
	}

	//如果要删除的点正好是头结点
	if (g_pHead->stu.stuNum == stuNum) {
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		printf("删除成功！\n");
		cleanScreen();
		return;
	}

	//要删除的点位于中间位置
	Node* p = g_pHead;
	while (p->pNext != NULL) {
		if (p->pNext->stu.stuNum == stuNum) {
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			printf("删除成功！\n");
			cleanScreen();
			return;
		}
	}
	printf("没有找到学生信息。\n");
	cleanScreen();
	return;
}