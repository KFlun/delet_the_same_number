#include<iostream>
using namespace std;

struct Number
{
	int number;
	int mark = 0;
	Number *next;
};

int main()
{
	//创建链表
	int n;
	cout << "请输入链表的长度：" << endl;
	cin >> n;
	Number *head = new Number;
	Number *pass = head;
	Number *end = pass;
	cout << "请依次输入链表结点的数：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> pass->number;
		if (i != n - 1)//注意尾指针的指向
		{
			pass = new Number;
			end->next = pass;
			end = pass;
		}
	}
	end->next = NULL;

	//判断是否有相同的数
	pass = head;
	Number *ps = pass->next;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (ps->number == pass->number)ps->mark = 1;
			if (ps->next != NULL)ps = ps->next;
		}
		if (pass != ps && pass->next != NULL && pass->next->next != NULL)//注意尾指针的指向
		{
			pass = pass->next;
			ps = pass->next;
		}
	}
	ps = new Number;//改变ps的指向
	delete ps;//释放ps的空间

	//删除重复的数
	pass = head->next;
	Number *guard = head;
	for (int i = 0; i < n; i++)
	{
		if (pass->mark)
		{
			guard->next = pass->next;
			pass->next = NULL;
			if (guard->next != NULL)pass = guard->next;
		}
		else
		{
			guard = pass;
			if (pass->next != NULL)pass = pass->next;
		}
	}

	//读取链表的数值
	pass = head;
	for (int i = 0;; i++)
	{
		if (pass == NULL)break;
		cout << pass->number << ",";
		pass = pass->next;
	}
	cout << endl;

	system("pause");
	return 0;
}