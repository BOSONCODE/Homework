#include <iostream>
#include <string>
#include <functional>
#include <stdio.h>
#include <algorithm>
#include "LinearList.h"
using namespace std;

int a[1000000] = { 15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14 };
int c[1000000];

void GenerateDataFile(int n) {
	srand((unsigned)time(NULL));
	fstream fout("Sequence.txt", ios::out);
	for (int i = 0; i < n; ++i)  fout << i << endl;
	for (int i = n-1; i >= 0; --i)  fout << i << endl;
	for (int i = 0; i < n; ++i)  fout << rand() << endl; 
	fout.close();
}

void test(int b[], int n) {
	LinearList<int>test;
	for (int i = 0; i < n; ++i) c[i] = a[i] = b[i];
	test.StdinInput(a, n);
	clock_t start, end;
	int CmpTime = 0, MoveTime = 0;
	cout << "/*************************Test STL Sort: ************************/" << endl;
	start = clock();
	sort(c, c + n);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << (end - start) << endl;

	cout << "/*************************Test Insert Sort: ************************/" << endl;
	CmpTime = 0, MoveTime = 0;
	start = clock();
	test.InsertSort(CmpTime, MoveTime);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << (end-start) << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
//	cout << "The sort result: " << endl;  test.StdoutOutput();

	cout << "/*************************Test Merge Sort: ************************/" << endl;
	test.setLinearList(0);
	CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, n);
	start = clock();
	test.MergeSort(CmpTime, MoveTime, 0, n - 1);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << end - start << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
	//cout << "The sort result: " << endl;  test.StdoutOutput();

	cout << "/*************************Test Quick Sort: ************************/" << endl;
	test.setLinearList(0);
	CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, n);
	start = clock();
	test.QuickSort(CmpTime, MoveTime, 0, n - 1);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << end - start << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
	//cout << "The sort result: " << endl;  test.StdoutOutput();

	cout << "/*************************Test Heap Sort: ************************/" << endl;
	test.setLinearList(0);
	CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, n);
	start = clock();
	test.HeapSort(CmpTime, MoveTime);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << end - start << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
	//cout << "The sort result: " << endl;  test.StdoutOutput();

	cout << "/*************************Test Bubble Sort: ************************/" << endl;
	test.setLinearList(0);
	CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, n);
	start = clock();
	test.BubbleSort(CmpTime, MoveTime);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << end - start << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
	//cout << "The sort result: " << endl;  test.StdoutOutput();

	cout << "/*************************Test Select Sort: ************************/" << endl;
	test.setLinearList(0);
	CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, n);
	start = clock();
	test.SelectSort(CmpTime, MoveTime);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << end - start << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
	//cout << "The sort result: " << endl;  test.StdoutOutput();

	cout << "/*************************Test Shell Sort: ************************/" << endl;
	test.setLinearList(0);
	CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, n);
	start = clock();
	test.ShellSort(CmpTime, MoveTime);
	end = clock();
	cout << end << ends << start << endl;
	cout << "Time consumption: " << end - start << endl;
	cout << "Move time: " << MoveTime << ends << "Cmpare time: " << CmpTime << endl;
	//cout << "The sort result: " << endl;  test.StdoutOutput();
}

void TestAll() {
	int n; cin >> n; GenerateDataFile(n);
	fstream fin("Sequence.txt", ios::in);
	cout << "/**********************************************Ë³ÐòÊýµÄ²âÊÔ:***********************************/ " << endl;
	for (int i = 0; i < n; ++i) fin >> a[i];
	test(a, n);
	cout << "/**********************************************ÄæÐòÊýµÄ²âÊÔ:***********************************/" << endl;
	for (int i = 0; i < n; ++i) fin >> a[i];
	test(a, n);
	cout << "/**********************************************Ëæ»úÊýµÄ²âÊÔ:***********************************/ " << endl;
	for (int i = 0; i < n; ++i) fin >> a[i];
	test(a, n);
	fin.close();
}


int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 9; ++i) cin >> a[i];
	LinearList<int>test;
	test.setLinearList(0);
	int CmpTime = 0, MoveTime = 0;
	test.StdinInput(a, 9);
	test.MergeSort(CmpTime, MoveTime, 0, 8);
	cout << CmpTime << ends << MoveTime << endl;
	return 0;
}