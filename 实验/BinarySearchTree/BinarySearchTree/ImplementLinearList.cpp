#ifndef BOSON
#define BOSON
#include "LinearList.h"
#include <iostream>

void LinearList::InputData(int Inputa[], int n) {
	for (int i = 0; i < n; ++i)
		element[i] = Inputa[sze++];
}

int LinearList::LinearSearch(int key, int &CmpTime) {
	for (int i = 0; i < sze; ++i) {
		++CmpTime;
		if (element[i] == key)
			return i;
	}
	return -1;
}

int LinearList::BinarySearch(int key, int &CmpTime) {
	int l = 0, r = sze-1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		++CmpTime;
		if (element[mid] == key) return mid + 1;
		if (element[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

void LinearList::OutputData() {
	for (int i = 0; i < sze; ++i)
		std::cout << element[i] << std::ends;
	std::cout << std::endl;
}

#endif
