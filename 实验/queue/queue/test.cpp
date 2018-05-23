#include <iostream>
#include "que.h"
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

void testque() {
	que<int>a, b, tmp, tmp2; int x; int front;
	int numa, numb;
	cout << "Please input the number of cards of A: " << endl; cin >> numa;
	for (int i = 1; i <= numa; ++i) cin >> x, a.EnQueue(x);
	cout << "Please input the number of cards of B: " << endl; cin >> numb;
	for (int i = 1; i <= numb; ++i) cin >> x, b.EnQueue(x);
	while (!a.IsEmpty() && !b.IsEmpty()) {
		a.DeQueue(front);
		if (tmp.find(front)) {
			a.EnQueue(front);
			tmp.DeQueue(x);
			while (x != front) {
				tmp2.EnQueue(x);
				tmp.DeQueue(x);
			}
			while (!tmp.IsEmpty()) {
				tmp.DeQueue(front);
				a.EnQueue(front);
			}
			while (!tmp2.IsEmpty()) {
				tmp2.DeQueue(front);
				tmp.EnQueue(front);
			}
		}
		else
			tmp.EnQueue(front);
		b.DeQueue(front);
		if (tmp.find(front)) {
			b.EnQueue(front);
			tmp.DeQueue(x);
			while (x != front) {
				tmp2.EnQueue(x);
				tmp.DeQueue(x);
			}
			while (!tmp.IsEmpty()) {
				tmp.DeQueue(front);
				b.EnQueue(front);
			}
			while (!tmp2.IsEmpty()) {
				tmp2.DeQueue(front);
				tmp.EnQueue(front);
			}
		}
		else
			tmp.EnQueue(front);
	}
	if (a.IsEmpty()) cout << "Congratulations! Winner is A!" << endl;
	else cout << "Congratulations! Winner is B!" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	testque();
	return 0;
}
