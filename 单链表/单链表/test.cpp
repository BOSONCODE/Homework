#include "linknode.h"
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include "ExpenseQuerySystem.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

int prime[20000];

int getprimefactor(int *prime, int n) {
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				prime[cnt++] = i;
				n /= i;
			}
		}
	}
	return cnt;
}

List<int> GenerateList(int cnt, int *prime) {
	List<int>s;
	for (int i = 0; i < cnt; ++i) {
		s.Insert(i, prime[i]);
	}
	s.Sort(1);
	return s;
}

void test2() {
	List<int> s;
	s.input();
	s.output();
	s.Sort();
	cout << "After the sort: " << endl;
	s.output();
	int targetnumber;
	cin >> targetnumber;
	if (NULL != s.Search(targetnumber)) cout << "Find it!" << endl;
	else cout << "There is no this number!" << endl;
	s.unique();
	cout << "After the unique operation: " << endl;
	s.output();
}

void test3() {
	ExpenseQuerySystem obj;
	char *s = "C:\\Users\\BOSON\\Desktop\\1.txt";
	obj.Input(s);
	obj.Output();
	string targetdate, targetproject;
	cout << "所有项目最小花费为: " << endl;
	cout << obj.minexpense() << endl;
	cout << "所有项目最大花费为: " << endl;
	cout << obj.maxexpense() << endl;
	cout << obj.averageexpense() << endl;
	cout << "请输入要查询的日期: " << endl;
	cin >> targetdate;
	obj.searchbydate(targetdate);
	cout << "请输入要查询的项目: " << endl;
	cin >> targetproject;
	obj.searchbyproject(targetproject);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t = getprimefactor(prime, 2100);
	List<int>ans = GenerateList(t, prime);
	ans.output();
	test2();
	test3();
	return 0;
}