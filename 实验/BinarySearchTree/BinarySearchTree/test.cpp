#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include "LinearList.h"
#include "BST.h"
#include <cstring>
#include <string>

using namespace std;

#define MAXN 1000000
#define ST 1000000

int SearchTime = ST;

int a[MAXN], b[MAXN];

void Input(int n, bool IsRand){
	for (int i = 0; i < n; ++i) a[i] = 2 * i + 1, b[i] = 2 * (i+1);
	if(IsRand) random_shuffle(a, a + n);
	//cout << "a: ";
	//for (int i = 1; i <= n; ++i) cout << a[i] << ends; cout << endl;
}

void TestLinearSearch(int n, bool IsRand) {
	srand((unsigned)time(NULL));
	Input(n, IsRand);
	LinearList test;
	test.InputData(a, n);
	//int SearchTime; cin >> SearchTime;
	int key = 0, res, sum = SearchTime;
	int CmpTime = 0;
	while (SearchTime-- > 0) {
		key = rand() % (n); key = a[key];
		res = test.LinearSearch(key, CmpTime);
		//if (res == -1) cout << "There is no such element!QAQ~" << endl;
		//else cout << "The key lies in " << res << " position!@_@" << endl;
		key = 0;
	}
	cout << "The successful average compare time is " << CmpTime*1.0/sum << endl;
	
	SearchTime = sum;
	while (SearchTime-- > 0) {
		key = rand() % (n);   key = b[key];
		res = test.LinearSearch(key, CmpTime);
		//if (res == -1) cout << "There is no such element!QAQ~" << endl;
		//else cout << "The key lies in " << res << " position!@_@" << endl;
		key = 0;
	}
	cout << "The unsuccessful average compare time is " << CmpTime*1.0 / sum << endl;
}

void TestBinarySearch(int n){
	srand((unsigned)time(NULL));
	Input(n, false);
	LinearList test;
	test.InputData(a, n);
	//int SearchTime; cin >> SearchTime;
	int key = 0, res, sum = SearchTime;
	int CmpTime = 0;
	while(SearchTime-->0){
		key = rand() % (n); key = a[key];
		res = test.BinarySearch(key, CmpTime);
		//if(res == -1) cout << "There is no such element!QAQ~" << endl;
		//else cout << "The key lies in " << res << " position!@_@" << endl;
		key = 0;
	}
	cout << "The successful average compare time is " << CmpTime*1.0/sum << endl;

	SearchTime = sum;
	while (SearchTime-->0) {
		key = rand() % (n);   key = b[key];
		res = test.BinarySearch(key, CmpTime);
		//if (res == -1) cout << "There is no such element!QAQ~" << endl;
		//else cout << "The key lies in " << res << " position!@_@" << endl;
		key = 0;
	}
	cout << "The unsuccessful average compare time is " << CmpTime*1.0 / sum << endl;
}

void TestBST(int n){
	srand((unsigned)time(NULL));
	Input(n, false);
	BST test;
	test.CreateBBST(a, n);
	//int SearchTime; cin >> SearchTime;
	int key = 0, sum = SearchTime;
	node *res;
	int CmpTime = 0;
	while(SearchTime-->0){
		key = rand() % (n); key = a[key];
		res = test.Search(key, CmpTime);
		//if(res == NULL) cout << "There is no such element!QAQ~" << endl;
		//else cout << "The key lies in " << res << " position!@_@" << endl;
		key = 0;
	}
	cout << "The successful average compare time is " << CmpTime*1.0/sum << endl;

	SearchTime = sum;
	while (SearchTime-->0) {
		key = rand() % (n);   key = b[key];
		res = test.Search(key, CmpTime);
		//if (res == NULL) cout << "There is no such element!QAQ~" << endl;
		//else cout << "The key lies in " << res << " position!@_@" << endl;
		key = 0;
	}
	cout << "The unsuccessful average compare time is " << CmpTime*1.0 / sum << endl;
}

void test(){
	int n;
	clock_t start, end;
	
	cout << "TestLinearSearch: randdata" << endl;
	cin >> n; SearchTime = ST;
	start = clock(); 
	TestLinearSearch(n, true);
	end = clock();	
	cout << (end-start)*1.0/CLOCKS_PER_SEC << endl;

	cout << "TestLinearSearch:  " << endl;
	cin >> n; SearchTime = ST;
	start = clock();	
	TestLinearSearch(n, false);
	end = clock();		
	cout << (end-start)*1.0/CLOCKS_PER_SEC << endl;

	cout << "TestBinarySearch: " << endl;
	cin >> n; SearchTime = ST;
	start = clock();	
	TestBinarySearch(n);
	end = clock();		
	cout << (end-start)*1.0/CLOCKS_PER_SEC << endl;

	cout << "TestBST: " << endl;
	cin >> n; SearchTime = ST;
	start = clock();	
	TestBST(n);
	end = clock();		
	cout << (end - start)*1.0 / CLOCKS_PER_SEC << endl;
}

int main(){
	ios::sync_with_stdio(false);
	test();
	return 0;
}