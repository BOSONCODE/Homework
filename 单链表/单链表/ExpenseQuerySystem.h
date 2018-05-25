#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct LinkList {
	string date;
	string project;
	double expense;
	LinkList *nxt;
	LinkList(LinkList *ptr = NULL) { nxt = ptr; }
	LinkList (string a, string b, double c) :
		date(a), project(b), expense(c) {
		nxt = NULL;
	}
};

class ExpenseQuerySystem {
private:
	LinkList *first;
public:
	ExpenseQuerySystem() { first = new LinkList; }
	ExpenseQuerySystem(string a, string b, double c) {
		first = new LinkList(a, b, c);
	}
	LinkList *getHead() const { return first; }
	double maxexpense() const;
	double minexpense() const;
	double averageexpense() const;
	void searchbydate(string targetdate) const;
	void searchbyproject(string targetproject) const;
	void Input(char *filename);
	void Output() const;
	void Insert(string date, string project, double cost) const;
};


double ExpenseQuerySystem::maxexpense() const {
	LinkList *head = getHead();
	double ans = -2e8;
	while (head->nxt != NULL) {
		head = head->nxt;
		ans = max(ans, head->expense);
	}
	return ans;
}

double ExpenseQuerySystem::minexpense() const {
	LinkList *head = getHead();
	double ans = 2e8;
	while (head->nxt != NULL) {
		head = head->nxt;
		ans = min(ans, head->expense);
	}
	return ans;
}

double ExpenseQuerySystem::averageexpense() const {
	LinkList *head = getHead();
	double sum = 0.0;
	int cnt = 0;
	while (head->nxt != NULL) {
		head = head->nxt;
		sum += head->expense;
		++cnt;
	}
	return sum / cnt;
}

void ExpenseQuerySystem::searchbydate(string targetdate) const {
	LinkList *head = getHead();
	double sum = 0.0;
	while (NULL != head->nxt) {
		head = head->nxt;
		if (head->date == targetdate) {
			cout << "��������Ϊ: " << head->date << " "
				<< "���ѵ���ĿΪ: " << head->project << " "
				<< "���ѵķ���Ϊ: " << head->expense << endl;
			sum += head->expense;
		}
	}
	cout << "��һ���ܹ�������: " << sum << " Ԫ" << endl;
}

void ExpenseQuerySystem::searchbyproject(string targetproject) const {
	LinkList *head = getHead();
	double sum = 0.0;
	while (NULL != head->nxt) {
		head = head->nxt;
		if (head->project == targetproject) {
			cout << "��������Ϊ: " << head->date << " "
				<< "���ѵ���ĿΪ: " << head->project << " "
				<< "���ѵķ���Ϊ: " << head->expense << endl;
			sum += head->expense;
		}
	}
	cout << "�����Ŀ�ܹ�������: " << sum << " Ԫ" << endl;
}

void ExpenseQuerySystem::Insert(string date, string project, double cost) const {
	LinkList *head = getHead();
	while (head ->nxt != NULL)
		head = head->nxt;
	head->nxt = new LinkList(date, project, cost);
}


void ExpenseQuerySystem::Input(char *filename) {
	fstream fin(filename);
	if (!fin.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		fin.close();
		return;
	}
	string date, project; double cost;
	while (fin >> date >> project >> cost) {
		Insert(date, project, cost);
	}
	fin.close();
}

void ExpenseQuerySystem::Output() const {
	LinkList *head = getHead();
	while (NULL != head->nxt && NULL != head) {
		head = head->nxt;
		cout << "��������Ϊ: " << head->date << " "
			<< "���ѵ���ĿΪ: " << head->project << " "
			<< "���ѵķ���Ϊ: " << head->expense << endl;
	}
}



