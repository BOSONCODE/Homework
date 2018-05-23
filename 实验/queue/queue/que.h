#pragma once
#include "Queue.h"

template<class T>
class que : Queue<T> {
public:
	que(int _maxSize = 2000, int _size = 0) :maxSize(_maxSize), size(_size) { elem = new T[maxSize]; }
	bool EnQueue(const T &x);
	bool DeQueue(T &x);
	bool getFront(T &x);
	bool IsEmpty()const { return size == 0 ? true : false; }
	bool IsFull()const { return size == maxSize ? true : false; }
	int getSize()const { return size; }
	bool find(const T &x);
	~que() { delete[]elem; };

private:
	T *elem;
	int size;
	int maxSize;
};

template<class T>
bool que<T>::EnQueue(const T &x) {
	if (IsFull()) {
		cout << "队列已经满了!" << endl;
		return false;
	}
	elem[size++] = x;
	return true;
}

template<class T>
bool que<T>::DeQueue(T &x) {
	if (IsEmpty()) {
		cout << "队列为空" << endl;
		return false;
	}
	x = elem[0];
	for (int i = 1; i < size; ++i)
		elem[i - 1] = elem[i];
	--size;
	return true;
}

template<class T>
bool que<T>::getFront(T &x) {
	if (IsEmpty()) {
		cout << "队列为空" << endl;
		return false;
	}
	x = elem[0];
	return true;
}

template<class T>
bool que<T>::find(const T &x) {
	for (int i = 0; i < size; ++i) {
		if (elem[i] == x)
			return true;
	}
	return false;
}