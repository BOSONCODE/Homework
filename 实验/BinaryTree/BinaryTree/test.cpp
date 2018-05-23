#include "BinTree.h"

void visit(BinTreeNode<int> *subTree) {
	cout << subTree->data << ends;
}
void visitchar(BinTreeNode<char> *subTree) {
	cout << subTree->data << ends;
}


void test() {
	int arr[7] = {1, 2, 3, 4, 5, 6, -1};
	int end = -1;
	char VLR[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	char LVR[] = { 'B', 'C', 'A', 'D', 'F', 'E' };
	BinaryTree<char>str;
	BinTreeNode<char> *res = str.createBinaryTree(VLR, LVR, 6);
	str.preOrder(res, visitchar); cout << endl;
	str.inOrder(res, visitchar); cout << endl;
	str.postOrder(res, visitchar); cout << endl;
	BinaryTree<int> t(-1, arr, 7);
	BinaryTree<int> s;	s = t;
	BinaryTree<int>c;
	cin >> c; cout << c << endl;
	s.preOrder1(visit); cout << endl;
	cout << "�ݹ�ǰ�����:" << endl;
	t.preOrder1(visit); cout << endl;
	cout << "�ݹ��������:" << endl;
	t.inOrder1(visit); cout << endl;
	cout << "�ݹ�������:" << endl;
	t.postOrder1(visit); cout << endl;
	cout << "�ǵݹ��α���:" << endl;
	t.levelOrder1(visit); cout << endl;
	cout << "�ǵݹ�ǰ�����:" << endl;
	t.preOrder2(visit); cout << endl;
	cout << "�ǵݹ��������:" << endl;
	t.inOrder2(visit); cout << endl;
	cout << "�ǵݹ�������:" << endl;
	t.postOrder2(visit); cout << endl;
	cout << "���ĸ߶�Ϊ:" << endl;
	cout << t.Height(t.getRoot()) << endl;
	cout << "Ҷ�ӽڵ�ĸ���Ϊ: " << endl;
	cout << t.CountLeaf(t.getRoot()) << endl;
	cout << "�ڵ����Ϊ:" << endl;
	cout << t.CountNode(t.getRoot()) << endl;
	cout << "���ָ�����Ĳ��:" << endl;
	t.printNodeLevel(t.getRoot());
	cout << t << endl;
}

int main() {
	test();
	return 0;
}