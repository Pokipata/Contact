#include <stdio.h>
#include <string.h>
#define MAX 1000
#define NAME 20
#define TELE 11

struct PeoInfo//创建人物信息类型
{
	char name[NAME];
	char tele[TELE];
};

enum Option
{
	EXIT,  //0
	ADD,   //1
	DEL,   //2
	SEARCH,//3
	MODIFY,//4
	SHOW,  //5
};


struct Contact//创建通讯录类型
{
	struct PeoInfo data[MAX];//存放一个信息
	int size;//记录当前已经有了的元素个数
};
//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ShowContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
