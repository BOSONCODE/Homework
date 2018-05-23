#pragma once
#ifndef baga
#define baga

#include "linearList.h"

const int defaultsize = 100;

template<class T>
class SeqList : public LinearList<T> {

protected:
	T *data;
	int maxSize;
	int last;
	void reSize(int newSize);
public:
	SeqList(int sz = defaultsize);
	SeqList(SeqList<T>&L);
	~SeqList() { delete[]data; }
	int Size()const { return maxSize; }
	int Length()const { return last + 1; }
	int Search(T &x) const;
	int Locate(int i) const;
	bool getData(int i, T &x) const {
		if (i > 0 && i <= last + 1) {
			x = data[i - 1];
			return true;
		}
		else
			return false;
	}
	void setData(int i, T &x) {
		if (i > 0 && i <= last + 1)
			data[i - 1] = x;
	}
	bool Insert(int i, T &x);
	bool Remove(int i, T &x);
	bool IsEmpty() const {
		return (last == -1) ? true : false;
	}
	bool IsFull() const {
		return (last == maxSize - 1) ? true : false;
	}
	void input();
	void output();
	void Sort();
	void merge_list(SeqList<T> *rhs, int flag = 0);
	void unique_list();
	//SeqList<T>operator = (SeqList<T>&L);
};

template<class T>
void SeqList<T>::unique_list() {
	for (int i = 0; i <= last; ++i) {			//����data����
		for (int j = i + 1; j <= last; ++j) {	//Ѱ���ظ����ֵ�Ԫ��
			if (data[j] == data[i]) {
				this->Remove(j + 1, data[j]);			//ɾ���ظ�Ԫ��
			}
		}
	}
}

template<class T>
void SeqList<T>::merge_list(SeqList<T> *rhs, int flag = 0) {
	T *a = new T[this->Length()];
	T *b = new T[rhs->Length()];
	//�ֱ������ݳ���
	for (int i = 0; i <= last; ++i) a[i] = data[i];
	for (int i = 1; i <= rhs->Length(); ++i) assert(rhs->getData(i, b[i - 1]) == true);
	reSize(this->Length() + rhs->Length());
	int t1 = 0, t2 = 0, t = 0;
	if (!flag) {			//Ĭ�ϴ�С��������
		while (t1 < this->Length() || t2 < rhs->Length()) {
			if (t1 < this->Length() && t2 < rhs->Length()) {
				if (a[t1] < b[t2]) data[t++] = a[t1++];
				else data[t++] = b[t2++];
			}
			else if (t1 < this->Length()) {
				data[t++] = a[t1++];
			}
			else {
				data[t++] = b[t2++];
			}
		}
	}
	else {
		while (t1 < this->Length() || t2 < rhs->Length()) {
			if (t1 < this->Length() && t2 < rhs->Length()) {
				if (a[t1] > b[t2]) data[t++] = a[t1++];
				else data[t++] = b[t2++];
			}
			else if (t1 < this->Length()) {
				data[t++] = a[t1++];
			}
			else {
				data[t++] = b[t2++];
			}
		}
	}
	last = t - 1;
}

template<class T>
SeqList<T>::SeqList(int sz) {
	if (sz > 0) {
		maxSize = sz; last = -1;
		data = new T[maxSize];
		if (data == NULL) {
			cerr << "�洢�������!" << endl;
			exit(1);
		}
	}
}

template<class T>
SeqList<T>::SeqList(SeqList<T>& L) {
	maxSize = L.Size(); last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL) {
		cerr << "�洢����ʧ��!" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; ++i) {
		L.getData(i, value);
		data[i - 1] = value;
	}
}

template<class T>
void SeqList<T>::reSize(int newSize) {
	if (newSize <= 0) {
		cerr << "��Ч�������С!" << endl;
		return;
	}
	if (newSize != maxSize) {
		T *newarray = new T[newSize];
		if (newarray == NULL) {
			cerr << "�洢����ʧ��!" << endl;
			exit(1);
		}
		int n = last + 1;
		T *srcptr = data;
		T *destptr = newarray;
		while (n-->0) *destptr++ = *srcptr++;
		delete[] data;
		data = newarray; maxSize = newSize;
	}
}

template<class T>
int SeqList<T>::Search(T &x) const {
	for (int i = 0; i <= last + 1; ++i)
		if (data[i] == x)
			return i + 1;
	return 0;
}

template<class T>
int SeqList<T>::Locate(int i) const {
	if (i >= 1 && i <= last + 1)
		return i;
	return 0;
}

template<class T>
bool SeqList<T>::Insert(int i, T &x) {
	if (last == maxSize - 1) return false;
	if (i < 0 || i > last + 1) return false;
	for (int j = last; j >= i; --j)
		data[j + 1] = data[j];
	data[i] = x;
	++last;
	return true;
}

template<class T>
bool SeqList<T>::Remove(int i, T &x) {
	if (last == -1) return false;
	if (i < 1 || i > last + 1) return false;
	x = data[i - 1];
	for (int j = i; j <= last; ++j) {
		data[j - 1] = data[j];
	}
	--last;
	return true;
}

template<class T>
void SeqList<T>::input() {
	cout << "��ʼ����˳���,���������Ԫ�ظ�����";
	while (1) {
		cin >> last;
		if (last <= maxSize - 1) break;
		cout << "��Ԫ�ظ����������󣬷�Χ���ܳ���" << maxSize - 1 << ":";
	}
	--last;
	for (int i = 0; i <= last; ++i) {
		cin >> data[i];
		cout << i + 1 << endl;
	}
}

template<class T>
void SeqList<T>::output() {
	cout << "˳���ǰԪ�����λ��Ϊ:" << last << endl;
	for (int i = 0; i <= last; ++i)
		cout << "#" << i + 1 << ":" << data[i] << endl;
}

/*template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T>&L){
maxSize = L.Size(); last = L.Length() - 1;
T value;
data = new T[maxSize];
if(data == NULL){
cerr << "�洢����ʧ��!" << endl;
exit(1);
}
for (int i = 1; i <= last + 1; ++i){
L.getData(i, value);
data[i-1] = value;
}
return *this;
}*/

template<class T>
void SeqList<T>::Sort() {
	sort(data, data + this->Length());
}

#endif