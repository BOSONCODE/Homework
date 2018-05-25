#pragma once
#include "linearList.h"

template<class T>
class List :public LinearList<T> {
public:
	List() { first = new LinkNode<T>; }
	List(const T& x) { first = new LinkNode<T>(x); }
	List(List<T>&L);
	~List() { makeEmpty(); }
	void makeEmpty();
	int Length()const;
	LinkNode<T>*getHead()const { return first; }
	LinkNode<T>*Search(T &x) const;
	LinkNode<T>*Locate(int i) const;
	bool getData(int i, T& x);
	void setData(int i, T &x);
	bool Insert(int i, T &x);
	bool Remove(int i, T &x);
	void unique();
	bool IsEmpty()const {
		return first->link == NULL ? true : false;
	}
	bool IsFull() const { return false; }
	void Sort(int flag = 0);
	void input();
	void output();
	//List<T>& operator = (List<T>&L);
protected:
	LinkNode<T>*first;
};

template<class T>
List<T>::List(List<T>&L) {
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL) {
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

template<class T>
void List<T>::makeEmpty() {
	LinkNode<T>*q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template<class T>
int List<T>::Length()const {
	LinkNode<T> *p = first->link; int count = 0;
	while (p != NULL)
		p = p->link, ++count;
	return count;
}

template<class T>
LinkNode<T>*List<T>::Search(T &x)const {
	LinkNode<T> *current = first->link;
	while (current != NULL) {
		if (current->data == x) break;
		else current = current->link;
	}
	return current;
}

template<class T>
LinkNode<T> *List<T>::Locate(int i)const {
	if (i < 0)  return NULL;
	LinkNode<T> *current = first; int k = 0;
	while (current != NULL && k < i)
		current = current->link, ++k;
	return current;
}

template<class T>
bool List<T>::getData(int i, T &x)  {
	if (i <= 0) return NULL;
	LinkNode<T>*current = Locate(i);
	if (current == NULL) return false;
	x = current->data;
	return true;
}

template<class T>
void List<T>::setData(int i, T &x) {
	if (i <= 0) return;
	LinkNode<T>*current = Locate(i);
	if (current == NULL) return;
	current->data = x;
}

template<class T>
bool List<T>::Insert(int i, T &x) {
	LinkNode<T>*current = Locate(i);
	if (current == NULL) return false;
	LinkNode<T> *newNode = new LinkNode<T>(x);
	if (newNode == NULL) {
		cerr << "存储分配错误!" << endl;
		exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template<class T>
bool List<T>::Remove(int i, T &x){
	LinkNode<T>*current = Locate(i - 1);
	if (current == NULL || current->link == NULL) return false;
	LinkNode<T>*del = current->link;
	current->link = del->link;
	x = del->data; delete del;
	return true;
}

template<class T>
void List<T>::output() {
	LinkNode<T>*current = first->link;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}

template<class T>
void List<T>::input() {
	cout << "请输入元素的个数: " << endl;
	int x; cin >> x;
	for (int i = 1; i <= x; ++i){
		int d; cin >> d;
		this->Insert(i-1, d);
	}
}

template<class T>
void List<T>::Sort(int flag = 0) {
	LinkNode<T>*head1 = getHead(), *head2 = getHead();
	if (flag == 0) {
		while ((head1 = head1->link) != NULL) {
			head2 = head1->link;
			while (head2 != NULL) {
				if (head2->data < head1->data) {
					swap(head2->data, head1->data);
				}
				head2 = head2->link;
			}
		}
	}
	else {
		while ((head1 = head1->link) != NULL) {
			head2 = head1->link;
			while (head2 != NULL) {
				if (head2->data > head1->data) {
					swap(head2->data, head1->data);
				}
				head2 = head2->link;
			}
		}
	}
}

template<class T>
void List<T>::unique() {
	LinkNode<T>*head1 = getHead(), *head2 = getHead();
	int cnt1 = 0, cnt2 = 0;
	while (NULL != head1->link && NULL != head1) {
		head1 = head1->link;
		head2 = head1->link;
		++cnt1; cnt2 = cnt1;
		while (NULL != head2) {
			++cnt2;
			if (head2->data == head1->data) {
				Remove(cnt2+1, head2->data);
			}
			head2 = head2->link;
		}
	}
}
