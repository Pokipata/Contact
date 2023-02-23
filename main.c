#include "contact.h"
void menu()
{
	printf("1.增加\n2.删除\n3.查找\n4.修改\n5.显示\n0.退出\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con里包含1000个元素data和记录元素个数的size
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("输入数字选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("出错\n");
			break;
		}
	} while (input);
	return 0;
}
