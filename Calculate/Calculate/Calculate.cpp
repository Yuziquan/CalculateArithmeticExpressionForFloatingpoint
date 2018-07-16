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
		cout << "请输入你想计算的算术表达式：" << endl;
		cin >> str;
		//cout << "其后缀表示为：";
		infixToPostfix(str);
		cout << endl;
		cout << "Result = "<<c.runPostfixString(infixToPostfix(str));
		cout<<endl<<endl;
	}
	return 0;
}

