#include"Calculator.h"

int isp(char c)
{
	switch (c)
	{
	case '#': return 0;
	case '(': return 1;
	case '*':case'/': return 5;
	case '+':case '-': return 3;
	case ')': return 6;
	default: return -1;
	}
}

int icp(char c)
{
	switch (c)
	{
	case '#': return 0;
	case '(': return 6;
	case '*':case'/': return 4;
	case '+':case '-': return 2;
	case ')': return 1;
	default: return -1;
	}
}


void Calculator::addOperand(double value)
{
	s.Push(value);
}

bool Calculator::get2Operands(double& left, double& right)
{
	if (s.isEmpty())
	{
		cerr << "缺少右操作数！" << endl;
		return false;
	}
	s.Pop(right);
	if (s.isEmpty())
	{
		cerr << "缺少左操作数！" << endl;
		return false;
	}
	s.Pop(left);
	return true;
}

void Calculator::doOperator(char op)
{
	double left, right, value;
	bool result = get2Operands(left, right);
	if (result)
	{
		switch (op)
		{
		case '+':
			value = left + right;
			s.Push(value);
			break;
		case '-':
			value = left - right;
			s.Push(value);
			break;
		case '*':
			value = left * right;
			s.Push(value);
			break;
		case '/':
			if (right == 0.0)
			{
				cerr << "Divide by 0！" << endl;
				Clear();
			}
			else
			{
				value = left / right;
				s.Push(value);
			}
			break;
		}
	}
	else Clear();
}

void Calculator::Clear()
{
	s.makeEmpty();
}


void postfix()
{
	SeqStack<char> s;
	char ch = '#', ch1, op;  //ch为在栈外的字符，ch1为在栈中的字符
	s.Push(ch);
	cin.get(ch);
	while (!s.isEmpty() && ch != '#')
	{
		if (isdigit(ch))
		{
			cout << ch;
			cin.get(ch);
		}
		else
		{
			s.getTop(ch1);
			if (isp(ch1) < icp(ch))
			{
				s.Push(ch);
				cin.get(ch);
			}
			else if (isp(ch1) > icp(ch))
			{
				s.Pop(op);
				cout << op;
			}
			else
			{
				s.Pop(op);
				if (op == '(') cin.get(ch);
			}
		}
	}
}

extern Node* infixToPostfix(string str)
{
	double operand;
	str = str + '#';
	Node* head, *current;
	SeqStack <char> st;
	char ch1;
	int i = 0;
	while (i < str.size())
	{
		if (isdigit(str[i]))
		{
			if (i == 0)
			{
				operand = atof(&str[i]);
				current = new Node(true, operand, 0.0);
				head = current;
			}
			else
			{
				operand = atof(&str[i]);
				current->next = new Node(true, operand, 0.0);
				current = current->next;
			}
			while (isdigit(str[i]) || str[i] == '.')
			{
				i++;
			}
		}
		else
		{
			if (st.isEmpty())
			{
				if (i == str.size() - 1) break;
				else
				{
					st.Push(str[i]);
					i++;
				}
			}
			else
			{
				st.getTop(ch1);
				if (isp(ch1) < icp(str[i]))
				{
					st.Push(str[i]);
					i++;
				}
				else if (isp(ch1) > icp(str[i]))
				{
					st.Pop(ch1);
					current->next = new Node(false, 0.0, ch1);
					current = current->next;
				}
				else
				{
					st.Pop(ch1);
					i++;
				}
			}
		}
	}
	
	/*Node* t_head = head;
	while (t_head!= nullptr)
	{
		if (t_head->isDouble)
		{
			cout << t_head->operand << " ";
		}
		else
		{
			cout << t_head->mOperator << " ";
		}
		t_head = t_head->next;
	}*/
	return head;
}
double Calculator::runPostfixString(Node* head)
{
	double newOperand;
	while (head != nullptr)
	{
		if (head->isDouble) addOperand(head->operand);
		else doOperator(head->mOperator);
		head = head->next;
	}
	s.Pop(newOperand);
	return newOperand;
}