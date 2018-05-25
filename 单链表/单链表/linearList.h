#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

template<class T>
struct LinkNode {
	T data;
	LinkNode<T> *link;
	LinkNode(LinkNode<T> *ptr = NULL) { link = ptr; }
	LinkNode(const T& item, LinkNode<T> *ptr = NULL) {
		data = item, link = ptr;
	}
};


template<class T>
class LinearList {
public:
	LinearList() {};
	~LinearList() {};
	//virtual int Size() const = 0;
	virtual int Length() const = 0;
	virtual LinkNode<T> *Search(T &x) const = 0;
	virtual LinkNode<T> *Locate(int i) const = 0;
	virtual bool getData(int i, T &x) = 0;
	virtual void setData(int i, T &x) = 0;
	virtual bool Insert(int i, T &x) = 0;
	virtual bool Remove(int i, T &x) = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual void Sort(int flag = 0) = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	//virtual LinearList<T>operator = (LinearList<T> &L) = 0;
};