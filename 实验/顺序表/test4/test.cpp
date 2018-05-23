#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include "SequentialList.h"
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	SeqList<int> s;
	s.input();
	s.output();
	s.unique_list();
	s.output();
	SeqList<int>s2;
	s2.input();
	s2.output();
	s2.Sort();
	s.Sort();
	s2.output();
	s2.merge_list(&s);
	s2.output();
	return 0;
}

/*
input:
6
3 2 0 9 8 2
4
9 1 3 5

6
3 2 0 9 8 2
0

*/