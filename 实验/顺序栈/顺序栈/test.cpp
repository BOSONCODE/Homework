#include "SeqStack.h"
#include "Calculator.h"
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <stdlib.h>
using namespace std;

// + - * / % () 
map<char, long double>g;

int icp(char c) {
	if (c == '#') return 0;
	if (c == '(') return 6;
	if (c == '*' || c == '/' || c == '%') return 4;
	if (c == '+' || c == '-') return 2;
	if (c == ')') return 1;
}

int isp(char c) {
	if (c == '#') return 0;
	if (c == '(') return 1;
	if (c == '*' || c == '/' || c == '%') return 5;
	if (c == '+' || c == '-') return 3;
	if (c == ')') return 6;
}

bool judge(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(')
		return true;
	return false;
}

void pre_str_pow(char *s, int &cnt, char *ans, int len) {			//将输入中的数字映射成英文字母
	cnt = 0; int tot = 0;
	long double sum = 0.0;
	bool flag = false;
	int numafterdots = 0;
	for (int i = 0; i < len; ++i) {
		if (i == 0 && s[1] == '-' && s[0] == '0') ans[cnt++] = 'A' + (tot++);
		else if (judge(s[i - 1]) && s[i + 1] == '-' && s[i] == '0') ans[cnt++] = 'A' + (tot++);
		if (s[i] == '.') {
			flag = true;
			continue;
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')' || s[i] == '(' || s[i] == '%') {
			if (sum > 0) ans[cnt++] = 'A' + (tot++); sum = 0.0, flag = false, numafterdots = 0;
			ans[cnt++] = s[i];
		}
		else if (s[i] == '^') {
			if (s[i + 1] == '(') {
				++i;
				while (s[i] != ')' && i < len) ++i;
			}
			else {
				++i;
				while (s[i] >= '0' && s[i] <= '9' && i < len) ++i; --i;
			}
			ans[cnt++] = 'A' + (tot++);
			sum = 0.0, flag = false, numafterdots = 0;
		}
		else {
			long double t = s[i] - '0';
			if (flag) t = t * pow(10.0, -(++numafterdots));
			if (!flag) sum = sum * 10 + t;
			else sum += t;
		}
	}
	if (sum > 0)
		ans[cnt++] = 'A' + (tot++);
}

void getnumber_pow(long double *ans, char *s, int &lenans, int len) {   //分出字符串中的数字
	lenans = 0;
	long double sum = 0.0;
	bool flag = false;
	int numafterdots = 0;
	for (int i = 0; i < len; ++i) {
		if (i == 0 && s[0] == '0' && judge(s[i + 1])) ans[lenans++] = 0.0;
		else if (judge(s[i - 1]) && s[i + 1] == '-' && s[i] == '0') ans[lenans++] = 0.0;
		if (s[i] == '.') {
			flag = true;
			continue;
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')' || s[i] == '(' || s[i] == '%') {
			if (sum > 0)ans[lenans++] = sum; sum = 0.0, flag = false, numafterdots = 0;
		}
		else if (s[i] == '^') {
			long double sum2 = 0.0; ++i;
			if (s[i] == '(') {
				++i; ++i; int end = ++i;
				while (s[end] != ')') ++end;
				for (int j = i; j <= end - 1; ++j) sum2 = sum2 * 10 + s[j] - '0';
				i = end;
				ans[lenans++] = pow(sum, -sum2);
			}
			else {
				int end = i;
				while (s[end] >= '0' && s[end] <= '9') ++end;
				for (int j = i; j <= end - 1; ++j) sum2 = sum2 * 10 + s[j] - '0';
				i = end - 1;
				ans[lenans++] = pow(sum, sum2);
			}
			sum = 0.0, sum2 = 0.0;
		}
		else {
			long double t = s[i] - '0';
			if (flag) t = t * pow(10.0, -(++numafterdots));
			if (!flag) sum = sum * 10 + t;
			else sum += t;
		}
	}
	if (sum > 0)
		ans[lenans++] = sum;
}

void transfer_to_poststr_pow(int &instrlen, char *instr, char *poststr) {
	SeqStack<char>s;
	char top;
	int  lenpoststr = 0;
	for (int i = 0; i < instrlen; ++i) {
		if (false == judge(instr[i]) && instr[i] != ')' && instr[i] != '(')
			poststr[lenpoststr++] = instr[i];
		else if (instr[i] != ')' && s.IsEmpty() == true && judge(instr[i]))
			s.Push(instr[i]);
		else {
			if (instr[i] == '(') s.Push(instr[i]);
			else if (instr[i] == ')') {
				while (s.IsEmpty() == false) {
					s.getTop(top);
					if (top == '(') break;
					poststr[lenpoststr++] = top;
					s.Pop(top);
				}
				if (top == '(') s.Pop(top);
			}
			else {
				s.getTop(top);
				while (isp(top) >= icp(instr[i])) {
					if (top != '(' && top != ')')
						poststr[lenpoststr++] = top;
					s.Pop(top);
					if (s.IsEmpty() == false) s.getTop(top);
					else break;
				}
				s.Push(instr[i]);
			}
		}
	}
	while (s.IsEmpty() == false) {
		s.getTop(top);
		if (top != '(' && top != ')')
			poststr[lenpoststr++] = top;
		s.Pop(top);
	}
	instrlen = lenpoststr;
	s.MakeEmpty();
}

long double calc_pow(char *poststr, int len) {
	Calculator s;
	return s.Run(poststr, len, g);
}

long double run_pow(char *s) {
	char instr[1000], poststr[1000];
	long double num[2000];
	g.clear();
	int newlen, lennum, len = strlen(s);
	pre_str_pow(s, newlen, instr, len);			//将输入中的数字映射成英文字母
												//for (int i = 0; i < newlen; ++i) cout << instr[i]; cout << endl;
	transfer_to_poststr_pow(newlen, instr, poststr);
	getnumber_pow(num, s, lennum, len);
	for (int i = 0; i < lennum; ++i) {
		g['A' + i] = num[i];
	}
	return calc_pow(poststr, newlen);
}

void pre_str(char *s, int &cnt, char *ans, int len) {			//将输入中的数字映射成英文字母
	cnt = 0; int tot = 0;
	long double sum = 0.0;
	bool flag = false;
	int numafterdots = 0;
	for (int i = 0; i < len; ++i) {
		if (i == 0 && s[1] == '-' && s[0] == '0') ans[cnt++] = 'A' + (tot++);
		else if (judge(s[i - 1]) && s[i + 1] == '-' && s[i] == '0') ans[cnt++] = 'A' + (tot++);
		if (s[i] == '.') {
			flag = true;
			continue;
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')' || s[i] == '(' || s[i] == '%') {
			if (sum > 0) ans[cnt++] = 'A' + (tot++); sum = 0.0, flag = false, numafterdots = 0;
		    ans[cnt++] = s[i];
		}
		else if (s[i] == '^') {
			++i; 
			if (s[i] == '(') {
				//while (s[i] != ')' && i < len) ++i;
				int lenl = 0, lenr = 0;
				while (i < len && ((lenl == 0 && lenr == 0) || lenl != lenr)) {
					if (s[i] == '(') lenl++;
					else if (s[i] == ')')lenr++;
					++i;
				}
				--i;
			}
			else {
				while (s[i] >= '0' && s[i] <= '9' && i < len) ++i; --i;
			}
			ans[cnt++] = 'A' + (tot++);
			sum = 0.0, flag = false, numafterdots = 0;
		}
		else {
			long double t = s[i] - '0';
			if (flag) t = t * pow(10.0, -(++numafterdots));
			if (!flag) sum = sum * 10 + t;
			else sum += t;
		}
	}
	if (sum > 0) {
		ans[cnt++] = 'A' + (tot++);
	}
}

void getnumber(long double *ans, char *s, int &lenans, int len) {   //分出字符串中的数字
	lenans = 0;
	long double sum = 0.0;
	bool flag = false;
	int numafterdots = 0;
	for (int i = 0; i < len; ++i) {
		if (i == 0 && s[0] == '0' && s[i+1] == '-') ans[lenans++] = 0.0;
		else if (judge(s[i - 1]) && s[i + 1] == '-' && s[i] == '0') ans[lenans++] = 0.0;
		if (s[i] == '.') {
			flag = true;
			continue;
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')' || s[i] == '(' || s[i] == '%') {
			if (sum > 0)ans[lenans++] = sum; sum = 0.0, flag = false, numafterdots = 0;
		}
		else if (s[i] == '^') {
			long double sum2 = 0.0; ++i;
			if (s[i] == '(') { //推断思路: a^p p为一个复杂的式子 那么在输入的时候一定最外面有括号那么只需要
							   //数数第一次左右括号相等的时候就是指数划分完成的时候
				string str; int lenl = 0, lenr = 0;
				while ((lenl == 0 && lenr == 0) || lenl != lenr) {
					if (s[i] == '(') lenl++; else if (s[i] == ')')lenr++;
					str += s[i++];
				}
				int len = str.length();
				char *str_pow = new char[len + 1];
				for (int i = 0; i < len; ++i) str_pow[i] = str[i]; str_pow[len] = '\0';
				ans[lenans++] = pow(sum, run_pow(str_pow));
				delete[]str_pow;
			}
			else {
				int end = i;
				while (s[end] >= '0' && s[end] <= '9') ++end;
				for (int j = i; j <= end - 1; ++j) sum2 = sum2 * 10 + s[j] - '0';
				i = end - 1;
				ans[lenans++] = pow(sum, sum2);
			}
			sum = 0.0, sum2 = 0.0, numafterdots = 0, flag = false;
		}
		else {
			long double t = s[i] - '0';
			if (flag) t = t * pow(10.0, -(++numafterdots));
			if (!flag) sum = sum * 10 + t;
			else sum += t;
		}
	}
	if (sum > 0)
		ans[lenans++] = sum;
}

void transfer_to_poststr(int &instrlen, char *instr, char *poststr) {		//中缀表达式转后缀表达式
	SeqStack<char>s;
	char top;
	int  lenpoststr = 0;
	for (int i = 0; i < instrlen; ++i) {
		if (false == judge(instr[i]) && instr[i] != ')' && instr[i] != '(')
			poststr[lenpoststr++] = instr[i];
		else if (instr[i] != ')' && s.IsEmpty() == true && judge(instr[i]))
			s.Push(instr[i]);
		else {
			if (instr[i] == '(') s.Push(instr[i]);
			else if (instr[i] == ')') {
				while (s.IsEmpty() == false) {
					s.getTop(top);
					if (top == '(') break;
					poststr[lenpoststr++] = top;
					s.Pop(top);
				}
				if (top == '(') s.Pop(top);
			}
			else {
				s.getTop(top);
				while (isp(top) >= icp(instr[i])) {
					if (top != '(' && top != ')')
						poststr[lenpoststr++] = top;
					s.Pop(top);
					if (s.IsEmpty() == false) s.getTop(top);
					else break;
				}
				s.Push(instr[i]);
			}
		}
	}
	while (s.IsEmpty() == false) {
		s.getTop(top);
		if (top != '(' && top != ')')
			poststr[lenpoststr++] = top;
		s.Pop(top);
	}
	instrlen = lenpoststr;
	s.MakeEmpty();
}

long double calc(char *poststr, int len) {
	Calculator s;
	return s.Run(poststr, len, g);
}

void solve_str(char *s, int &newlen) {
	int len = strlen(s);
	for (int i = 0; i < len; ++i) {				//为了考虑负数的情况 先将 +-、--这种情况合并成-、+
		if (s[i] == '+' && s[i + 1] == '-') {
			s[i] = '-';
			for (int j = i + 1; j + 1 < len; ++j) {
				s[j] = s[j + 1];
			}
			s[--len] = '\0';
		}
		else if (s[i] == '-' && s[i + 1] == '-') {
			s[i] = '+';
			for (int j = i + 1; j + 1 < len; ++j) {
				s[j] = s[j + 1];
			}
			s[--len] = '\0';
		}
	}
	//预处理字符串 将所有的-前面补上一个零 得特判掉-前面有一个数的情况通过加一个+实现 也就是num+0-
	//也不知道这么处理负数的情况对不对QAQ o(╯□╰)o
	for (int i = 0; i < len; ++i) {
		if (s[i] == '-') {
			for (int j = len; j >= i + 1; --j) {
				s[j] = s[j - 1];
			}
			++len;
			s[i] = '0';
			if (s[i - 1] >= '0' && s[i - 1] <= '9') {
				for (int j = len; j >= i + 1; --j) {
					s[j] = s[j - 1];
				}
				s[i] = '+';
				++len;
				++i;
			}
			++i;
		}
	}
	newlen = len;
} //

long double run(char *s) {
	char instr[1000], poststr[1000];
	long double num[2000];
	g.clear();
	int newlen, lennum, len;
	solve_str(s, len);
	pre_str(s, newlen, instr, len);			//将输入中的数字映射成英文字母										//for (int i = 0; i < newlen; ++i) cout << instr[i]; cout << endl;
	transfer_to_poststr(newlen, instr, poststr);
	//for (int i = 0; i < newlen; ++i) cout << poststr[i] << ends; cout << endl;
	getnumber(num, s, lennum, len);
	for (int i = 0; i < lennum; ++i) {
		g['A' + i] = num[i];
	}
	return  calc(poststr, newlen);
}

int main() {
	ios::sync_with_stdio(false);
	char s[1000];
	while (cin >> s) {
		cout << "The final ans is " << run(s) << endl;
	}
	return 0;
}

/*
input:
2*3-1
(1+2)*(5*4-3)-6
3+4*(5+6)
3.2+5.6*(6.3+12*(6.2+6.0))
(1+2)*(2+3)
((1+2)*(2+3)+(1+2)*(2+3))*((1+2)*(2+3)+(1+2)*(2+3))
(-3+6*12)+(3*(-2))
(3+4)*12-(-(5+6)*8)
(-3+6*12)+(-(-(23+5*(-8))))
(-3-2)+(2*(-5))
(56*(-2)+(32)-56)
(2^10/(2^(-3))+256)
0.0+0.0
0+5
2^((1+2)*(2+3))

output:
5
45
47
858.32
15
900
63
172
52
-15
-136
8448
0
5
32768
*/