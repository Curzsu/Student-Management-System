#define _CRT_SECURE_NO_WARNINGS
#include "StudentManagerSystem.h"

int main() {
	//改变控制台字体颜色	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	int num;
	while (1) {
		welcome();
		scanf("%d", &num);
		switch (num) {
		case 1:	//录入学生信息
			InputStudent();
			break;
		case 2:	//打印学生信息
			PrintStudent();
			break;
		case 3:	//保存学生信息
			SaveStudent();
			break;
		case 4:	//读取学生信息
			ReadStudent();
			break;
		case 5:	//统计所有学生人数
			CountStudent();
			break;
		case 6:	//查找学生信息
			FindStudent();
			break;
		case 7:	//修改学生信息
			ModifyStudent();
			break;
		case 8:	//删除学生信息
			DeleteStudent();
			break;
		case 9:	//退出系统
			return 0;
		}
	}

	return 0;
}