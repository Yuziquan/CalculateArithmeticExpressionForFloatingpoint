#include<iostream>
#include"Calculator.h"
#include <string>
using namespace std;

extern Node* infixToPostfix(string str);

int main(void)
{
	string str;
	while (1)
	{
		Calculator c(30);
		cout << "���������������������ʽ��" << endl;
		cin >> str;
		//cout << "���׺��ʾΪ��";
		infixToPostfix(str);
		cout << endl;
		cout << "Result = "<<c.runPostfixString(infixToPostfix(str));
		cout<<endl<<endl;
	}
	return 0;
}

