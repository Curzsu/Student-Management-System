#define _CRT_SECURE_NO_WARNINGS
#include "StudentManagerSystem.h"

int main() {
	//�ı����̨������ɫ	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	int num;
	while (1) {
		welcome();
		scanf("%d", &num);
		switch (num) {
		case 1:	//¼��ѧ����Ϣ
			InputStudent();
			break;
		case 2:	//��ӡѧ����Ϣ
			PrintStudent();
			break;
		case 3:	//����ѧ����Ϣ
			SaveStudent();
			break;
		case 4:	//��ȡѧ����Ϣ
			ReadStudent();
			break;
		case 5:	//ͳ������ѧ������
			CountStudent();
			break;
		case 6:	//����ѧ����Ϣ
			FindStudent();
			break;
		case 7:	//�޸�ѧ����Ϣ
			ModifyStudent();
			break;
		case 8:	//ɾ��ѧ����Ϣ
			DeleteStudent();
			break;
		case 9:	//�˳�ϵͳ
			return 0;
		}
	}

	return 0;
}