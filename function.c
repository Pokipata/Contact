#include "contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
		printf("通讯录已满，请删除后再增加\n");
	else
	{
		printf("输入姓名:>");
		scanf_s("%s", ps->data[ps->size].name, NAME);
		printf("输入电话号码:>");
		scanf_s("%s", ps->data[ps->size].tele, TELE);
		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空\n");
	else
	{
		int i = 0;
		printf("%-20s\t%-11s\n", "姓名", "电话号码");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-11s\n",
				ps->data[i].name,
				ps->data[i].tele);
		}
	}
}

//查找名字
static int FindByName(struct Contact* ps, char name[NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到的情况
}

void DelContact(struct Contact* ps)
{
	char name[NAME];
	printf("输入需要删除的人名:>");
	scanf_s("%s", name, NAME);
	//查找要删除的人在什么位置
	int pos = FindByName(ps, name);
	//找到了返回名字的下标，未找到返回 -1
	if (pos == -1)
	{
		printf("删除的人不存在\n");
	}
	else
	{   //删除
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[NAME];
	printf("输入需要查找的人名:>");
	scanf_s("%s", name, NAME);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("未找到\n");
	}
	else
	{
		printf("%-20s\t%-11s\n", "姓名", "电话号码");
		printf("%-20s\t%-11s\n",
			ps->data[pos].name,
			ps->data[pos].tele);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[NAME];
	printf("请输入要修改人的名字:>");
	scanf_s("%s", name, NAME);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改人的信息不错在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf_s("%s", ps->data[pos].name, NAME);
		printf("请输入电话:>");
		scanf_s("%s", ps->data[pos].tele, TELE);
		printf("修改完成\n");
	}
}
