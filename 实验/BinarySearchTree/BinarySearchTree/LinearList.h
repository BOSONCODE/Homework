#pragma once
class LinearList {
private:
	int element[250000];
	int sze;
public:
	LinearList() { sze = 0; }
	void InputData(int Inputa[], int n);
	int LinearSearch(int key, int &CmpTime);
	int BinarySearch(int key, int &CmpTime);
	void OutputData();
};