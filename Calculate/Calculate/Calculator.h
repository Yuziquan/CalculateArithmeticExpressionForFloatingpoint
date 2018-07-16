#pragma once
#include<stdlib.h>
#include"SeqStack.h"
#include<iostream>
#include<cctype>
#include<string>
using namespace std;


struct Node
{
	bool isDouble;
	double operand;
	char mOperator;
	Node* next;
	Node(bool isD = false, double opd = 0.0, char mOp = 'z')
	{
		isDouble = isD;
		operand = opd;
		mOperator = mOp;
		next = nullptr;
	}
};

class Calculator
{
public:
	Calculator(int sz) : s(sz) {}
	void Clear();
    double runPostfixString(Node* head);
	
private:
	SeqStack<double> s;
	void addOperand(double value);
	bool get2Operands(double& left, double& right);
	void doOperator(char op);
};

