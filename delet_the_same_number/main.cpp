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
	//��������
	int n;
	cout << "����������ĳ��ȣ�" << endl;
	cin >> n;
	Number *head = new Number;
	Number *pass = head;
	Number *end = pass;
	cout << "���������������������" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> pass->number;
		if (i != n - 1)//ע��βָ���ָ��
		{
			pass = new Number;
			end->next = pass;
			end = pass;
		}
	}
	end->next = NULL;

	//�ж��Ƿ�����ͬ����
	pass = head;
	Number *ps = pass->next;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (ps->number == pass->number)ps->mark = 1;
			if (ps->next != NULL)ps = ps->next;
		}
		if (pass != ps && pass->next != NULL && pass->next->next != NULL)//ע��βָ���ָ��
		{
			pass = pass->next;
			ps = pass->next;
		}
	}
	ps = new Number;//�ı�ps��ָ��
	delete ps;//�ͷ�ps�Ŀռ�

	//ɾ���ظ�����
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

	//��ȡ�������ֵ
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