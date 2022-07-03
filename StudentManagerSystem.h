#pragma once
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

//ÿ������һ�ξ�Ҫ�����Ļ
void cleanScreen() {
	system("pause");   //��ͣ
	system("cls");		//�����Ļ
}

//��ӭ����
void welcome() {
	printf("*************************************************\n");
	printf("\t\t��ӭʹ��ѧ������ϵͳ\t\t\t\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t9.�˳�ϵͳ\t\t\t*\n");
	printf("\n");
}

typedef struct student {
	char name[30];	//����
	int age;	//����
	long long stuNum;  //ѧ��
	int score;	//����
}Student;

typedef struct _Node {
	Student stu;
	struct _Node* pNext;
}Node;

Node* g_pHead = NULL;   //��ʼ��ͷָ��

//¼��ѧ����Ϣ
void InputStudent() {
	Node* pNewNode = (Node*)malloc(sizeof(Node)); //ע�������(sizeof(Node))��������sizeof(Node*)!!!
	pNewNode->pNext = NULL;

	//ͷ�巨
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	}
	else {
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	//��������
	printf("������ѧ����Ϣ��\n");
	printf("����������\n");
	scanf("%s", pNewNode->stu.name);
	printf("�������䣺\n");
	scanf("%d", &pNewNode->stu.age);
	printf("����ѧ�ţ�\n");
	scanf("%lld", &pNewNode->stu.stuNum);
	printf("���������\n");
	scanf("%d", &pNewNode->stu.score);
	printf("ѧ����Ϣ¼��ɹ���\n");
	cleanScreen();
}

//���ѧ����Ϣ
void PrintStudent() {
	Node* p = g_pHead;
	printf("*************************************************\n");
	printf("ѧ��\t\t����\t\t����\t\t����\n");
	while (p != NULL) {
		printf("%-16lld", p->stu.stuNum);
		printf("%-16s", p->stu.name);
		printf("%-16d", p->stu.age);
		printf("%-16d\n", p->stu.score);
		p = p->pNext;
	}
	cleanScreen();
}

//����ѧ����Ϣ
void SaveStudent() {
	//���ļ�
	FILE* fp = fopen("C:\\Users\\14185\\Desktop\\stuinfo.dat", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
		return;
	}
	//������д���ļ�(��������)
	Node* p = g_pHead;
	while (p != NULL) {
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}

	//�ر��ļ�
	fclose(fp);
	printf("���ݱ���ɹ���\n");
	cleanScreen();
}

//��ȡ�ļ��е�����
void ReadStudent() {
	FILE* fp = fopen("C:\\Users\\14185\\Desktop\\stuinfo.dat", "r");
	if (fp == NULL) {
		printf("��ȡ�ļ�ʧ�ܣ�\n");
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
		printf("�ļ���ȡ�ɹ���\n");
		cleanScreen();
	}
}
//ͳ������ѧ������
void CountStudent() {
	int cnt = 0;
	Node* p = g_pHead;
	while (p != NULL) {
		++cnt;
		p = p->pNext;
	}
	printf("ѧ����������Ϊ��%d\n", cnt);
	cleanScreen();
}

//����ѧ��
void FindStudent() {
	long long stuNum;   //ѧ��
	printf("��������Ҫ����ѧ����ѧ�ţ�\n");
	scanf("%lld", &stuNum);
	Node* p = g_pHead;
	while (p != NULL) {
		if (p->stu.stuNum == stuNum) {
			printf("ѧ�ţ�%lld  ������%s  ���䣺%d  ������%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			cleanScreen();
			return;
		}
		p = p->pNext;
	}
	printf("û���ҵ����ѧ����Ϣ��\n");
	cleanScreen();
}

//�޸�ѧ����Ϣ
void ModifyStudent() {
	printf("��������Ҫ�޸�ѧ����Ϣ��ѧ�ţ�\n");
	long long stuNum;
	scanf("%lld", &stuNum);
	Node* p = g_pHead;
	while (p != NULL) {
		if (p->stu.stuNum == stuNum) {
			printf("�������޸ĺ����Ϣ(ѧ��/����/����/����):\n");
			scanf("%lld %s %d %d", &p->stu.stuNum, p->stu.name, &p->stu.age, &p->stu.score);
			cleanScreen();
			return;
		}
		p = p->pNext;
	}
	printf("û���ҵ�ѧ����Ϣ��\n");
	cleanScreen();
}

//ɾ��ѧ����Ϣ
void DeleteStudent() {
	printf("��������Ҫɾ����ѧ����Ϣ��ѧ�ţ�\n");
	long long stuNum;
	scanf("%lld", &stuNum);
	Node* p1, * p2;    //ע������p2ǰ��ҲҪ���Ǻţ�

	//���һ��ʼ����Ϊ��
	if (g_pHead == NULL) {
		printf("û���ҵ�ѧ����Ϣ��\n");
		cleanScreen();
		return;
	}

	//���Ҫɾ���ĵ�������ͷ���
	if (g_pHead->stu.stuNum == stuNum) {
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		printf("ɾ���ɹ���\n");
		cleanScreen();
		return;
	}

	//Ҫɾ���ĵ�λ���м�λ��
	Node* p = g_pHead;
	while (p->pNext != NULL) {
		if (p->pNext->stu.stuNum == stuNum) {
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			printf("ɾ���ɹ���\n");
			cleanScreen();
			return;
		}
	}
	printf("û���ҵ�ѧ����Ϣ��\n");
	cleanScreen();
	return;
}