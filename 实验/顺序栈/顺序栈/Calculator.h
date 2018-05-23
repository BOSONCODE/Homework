#pragma once
#ifndef BOSON2
#define BOSON2

#include <math.h>
#include "SeqStack.h"
#include <iostream>
#include <map>
using namespace std;

class Calculator {
private:
	SeqStack<long double>s;
	void AddOperand(long double value);
	int get2Operands(long double &left, long double &right);
	void DoOperator(char op);
public:
	Calculator(int sz = maxSize-1) : s(sz) {}
	long double Run(char *s, int len, map<char, long double>g);
	void Clear();
};

void Calculator::DoOperator(char op) {			//进行运算符的运算操作
	long double left, right, value = 0; int res;
	res = get2Operands(left, right);
	if (2 == res) {
		switch (op) {
		case'+': value = left + right; s.Push(value); break;
		case'-': value = left - right; s.Push(value); break;
		case'*': value = left * right; s.Push(value); break;
		case'/': if (right == 0.0) { cerr << "Divide by 0!" << endl; Clear(); }
				 else { value = left / right; s.Push(value); }
				 break;
		}
	}
	else if (1 == res) s.Push(right);
	else s.Push(0);
}

void Calculator::Clear() {
	s.MakeEmpty();
}

int Calculator::get2Operands(long double &left, long double &right) {	//获取栈中的操作数
	if (true == s.IsEmpty()) {
		//cerr << "缺少右操作数!" << endl;
		return 0;
	}
	s.Pop(right);
	if (true == s.IsEmpty()) {
		//cerr << "缺少左操作数!" << endl;
		return 1;
	}
	s.Pop(left);
	return 2;
}

void Calculator::AddOperand(long double value) {  // 加进栈
	s.Push(value);
}

long double Calculator::Run(char *str, int len, map<char, long double>g) {
	long double x;
	for (int i = 0; i < len; ++i) {
		switch (str[i]) {
		case'+':case'-':case'*':case'/':
			DoOperator(str[i]); break;
		default: AddOperand(g[str[i]]);
		}
	}
	s.getTop(x);
	Clear();
	return x;
}

#endif // !BOSON2