#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<iterator>
#include<algorithm>
#include<hash_set>
#include <typeinfo> 
#include<deque>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;


//=====================三大 N*LOGN 排序 4大基础排序=========================================================

////最好的情况，时间复杂度为O(n),最坏的情况下为O（n*n）;
//void bubblesort(vector<int> &arr)
//{
//	int size = arr.size();
//	int flag = 1;
//	for (int i = 0; i < size - 1 && flag; i++)
//	{
//		flag = 0;
//		for (int j = size - 1; j>i; j--)
//		{
//			if (arr[j] < arr[j - 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = temp;
//				flag = 1;
//			}
//		}
//	}
//}
//
////特点是交换移动数据次数少。最好最坏的情况下都为O（n*n），比较次数多，交换时间少;
//void selectsort(vector<int> &arr)
//{
//	int size = arr.size();
//	for (int i = 0; i < size - 1; i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < size; j++)
//		{
//			if (arr[j] < arr[min])
//				min = j;
//		}
//		if (min != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[min];
//			arr[min] = temp;
//		}
//	}
//}
//
////最好的情况，时间复杂度为O(n),最坏的情况O（n*n）;
//void insertsort(vector<int> &arr)
//{
//	int size = arr.size();
//	int j;
//	for (int i = 1; i < size; i++)
//	{
//		if (arr[i]<arr[i - 1])
//		{
//			int t = arr[i];
//			for (j = i - 1; j >= 0 && arr[j] > t; j--)
//			{
//				arr[j + 1] = arr[j];
//			}
//			arr[j + 1] = t;
//		}
//	}
//}
//
////希尔排序首先要注意一点， p要初始化为数组元素个数，然后每次p =  p / 3 + 1 ，必须有+1，不然不能满足所有情况。每次步长改变都是p
////希尔排序是不稳定的排序方法。时间复杂度的计算较复杂，统计得到O（n的3/2次方）
//void shellsort(vector<int> &arr)
//{
//	int size = arr.size();
//	int p = size;
//	do{
//		p = p / 3 + 1;
//		int i, j;
//		for (i = p; i<size; i = i + p)
//		{
//			if (arr[i]<arr[i - p])
//			{
//				int t = arr[i];
//				for (j = i - p; j >= 0 && arr[j] > t; j = j - p)
//				{
//					arr[j + p] = arr[j];
//				}
//				arr[j + p] = t;
//			}
//		}
//	} while (p > 1);
//}
//bool fun(vector<int> &arr)
//{
//	for (int i = 1; i < arr.size() - 1; i++)
//	{
//		if (arr[i] > arr[i + 1])
//			return false;
//	}
//	return true;
//}
//
////快排
//class Qsort
//{
//public:
//	void quicksort(vector<int> &arr)
//	{
//		qprocess(arr,0,arr.size()-1);
//	}
//	void qprocess(vector<int> &arr, int start, int end)
//	{
//		if (start < end)
//		{
//			int mid = partition(arr, start, end);
//			qprocess(arr, start, mid);
//			qprocess(arr, mid + 1, end);
//		}
//	}
//
//	int partition(vector<int> &arr, int start, int end)
//	{
//		int p = arr[start];
//		while (start < end)
//		{
//			while (start < end && arr[end] >= p)
//				end--;
//			arr[start] = arr[end];
//			while (start < end && arr[start] <= p)
//				start++;
//			arr[end] = arr[start];
//		}
//		arr[start] = p;
//		return start;
//	}
//};
//
////归排
//class mergeSort
//{
//public:
//	void mergesort(vector<int> &arr)
//	{
//		mergeprocess(arr, 0, arr.size() - 1);
//	}
//	void mergeprocess(vector<int> &arr, int start, int end)
//	{
//		if (start == end)
//			return;
//		int mid = start + (end - start) / 2;
//		mergeprocess(arr, start, mid);
//		mergeprocess(arr, mid + 1, end);
//		merge(arr, start, mid, end);
//	}
//	void merge(vector<int> &arr, int start, int mid, int end)
//	{
//		int *arr1 = new int[end - start + 1];
//		int p1 = start, p2 = mid+1;
//		int i = 0;
//		while (p1 <= mid && p2 <= end)
//		{
//			arr1[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
//		}
//		while (p1 <= mid)
//			arr1[i++] = arr[p1++];
//		while (p2 <= end)
//			arr1[i++] = arr[p2++];
//		for (int i = 0; i < end - start + 1; i++)
//			arr[start + i] = arr1[i];
//		delete[] arr1;
//		arr1 = NULL;
//	}
//};
//
////堆排
//class Heapsort
//{
//public:
//	void heapsort(vector<int> &arr)
//	{
//		for (int i = arr.size() / 2 - 1; i >= 0; i--)   //arr.size() / 2-1确保以0开始的情况下，前一半的数据进行堆调整
//			heapadjust(arr, i, arr.size());
//		for (int i = arr.size() - 1; i > 0; i--)          //从最后一个元素开始，交换，重新排序
//		{
//			int temp = arr[i];
//			arr[i] = arr[0];
//			arr[0] = temp;
//			heapadjust(arr, 0, i);
//		}
//
//
//	}
//	void heapadjust(vector<int> &arr, int start, int end)      //前闭后开
//	{
//		int temp = arr[start];
//		for (int k = 2 * start + 1; k<end; k = k * 2 + 1) //从start的左子结点开始
//		{
//			if (k + 1<end && arr[k + 1]>arr[k])//如果左子结点小于右子结点，k指向右子结点
//				k++;
//			if (arr[k]>temp)//如果子结点大于父结点，将子结点赋给父结点
//			{
//				arr[start] = arr[k];
//				start = k;          //并且父节点的起始位置跟着改变
//			}
//			else
//				break;
//		}
//		arr[start] = temp;
//	}
//
//	//小根堆
//	void minheapadjust(vector<int> & arr, int start, int end)
//	{
//		int temp = arr[start];
//		for (int i = start * 2 + 1; i < end; i = i * 2 + 1)
//		{
//			if (i < end - 1 && arr[i + 1] < arr[i])
//				i++;
//			if (arr[i] < temp)
//			{
//				arr[start] = arr[i];
//				start = i;
//			}
//			else
//				break;
//		}
//		arr[start] = temp;
//	}
//};
//
////主函数测试排序正确性
//int main()
//{
//	const int N = 50;
//	vector<int> arr(N); //= { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
//	srand((unsigned)time(0));
//	arr[0] = 0;
//	for (int i = 1; i < N; i++)
//	{
//		arr[i] = rand() % 1000;
//	}
//
//	cout << "排序前：" << endl;
//	for (int i = 1; i < arr.size(); i++)
//		cout << arr[i] << "  ";
//	cout << endl;
//	
//	Qsort q;
//	Heapsort h;
//	mergeSort m;
//	//q.quicksort(arr);
//	h.heapsort(arr);
//	//m.mergesort(arr);
//
//	cout << "排序后：" << endl;
//	for (int i = 1; i < arr.size(); i++)
//		cout << arr[i] << "  ";
//	cout << endl;
//	cout << endl;
//	cout << "经过排序后，是否升序：" << fun(arr) << endl;
//
//	system("pause");
//	return 0;
//}

//
//class Quicksort
//{
//public:
//	int partiton(vector<int> &arr, int start, int end)
//	{
//		int temp = arr[start];
//		while (start < end)
//		{
//			while (start < end && arr[end] >= temp)
//				end--;
//			arr[start] = arr[end];
//			while (start < end && arr[start] <= temp)
//				start++;
//			arr[end] = arr[start];
//		}
//		arr[start] = temp;
//		return start;
//	}
//
//	void qsort(vector<int> &arr, int start, int end)
//	{
//		if (start < end)
//		{
//			int mid = partiton(arr, start, end);
//			qsort(arr, start, mid);
//			qsort(arr, mid + 1, end);
//		}
//	}
//	void quicksort(vector<int> &arr)
//	{
//		qsort(arr, 0, arr.size() - 1);
//	}
//};
//
//
//class Heapsort
//{
//public:
//	void heapsort(vector<int> &arr)
//	{
//		for (int i = arr.size() / 2-1; i >= 0; i--)   //arr.size() / 2-1确保以0开始的情况下，前一半的数据进行堆调整
//			heapadjust(arr, i, arr.size());
//		for (int i = arr.size() - 1; i > 0; i--)          //从最后一个元素开始，交换，重新排序
//		{
//			int temp = arr[i];
//			arr[i] = arr[0];
//			arr[0] = temp;
//			heapadjust(arr, 0, i);
//		}
//
//
//	}
//	void heapadjust(vector<int> &arr, int start, int end)      //前闭后开
//	{
//		int temp = arr[start];
//		for (int k = 2 * start + 1; k<end; k = k * 2 + 1) //从start的左子结点开始
//		{
//			if (k + 1<end && arr[k + 1]>arr[k])//如果左子结点小于右子结点，k指向右子结点
//				k++;
//			if (arr[k]>temp)//如果子结点大于父结点，将子结点赋给父结点
//			{
//				arr[start] = arr[k];
//				start = k;          //并且父节点的起始位置跟着改变
//			}
//			else
//				break;
//		}
//		arr[start] = temp;        
//	}
//
//	//小根堆
//	void minheapadjust(vector<int> & arr, int start, int end)
//	{
//		int temp = arr[start];
//		for (int i = start * 2 + 1; i < end; i = i * 2 + 1)
//		{
//			if (i < end - 1 && arr[i + 1] < arr[i])
//				i++;
//			if (arr[i] < temp)
//			{
//				arr[start] = arr[i];
//				start = i;
//			}
//			else
//				break;
//		}
//		arr[start] = temp;
//	}
//};
//
//
//bool equal(vector<int> &a1, vector<int> &a2)
//{
//	for (int i = 0; i < a1.size(); i++)
//	{
//		if (a1[i] != a2[i])
//			return false;
//	}
//	return true;
//}

//======================三大排序 4大基础排序 ==============================================================




//======================================二叉树前中后非递归遍历==========================================

//typedef struct node
//{
//	int data;
//	struct node* lchild;  //左孩子
//	struct node* rchild;  //右孩子
//}BTNode;
//
//void creatbypre(BTNode** t)
//{
//	int value;
//	cin >> value;
//	if (value == 0)
//		*t = nullptr;
//	else
//	{
//		*t = new BTNode;
//		(*t)->data = value;
//		creatbypre(&(*t)->lchild);
//		creatbypre(&(*t)->rchild);
//	}
//}
//
//void mid(BTNode * root)
//{
//	if (!root)
//		return;
//	BTNode *p = root;
//	stack<BTNode *> s;
//	while (!s.empty() || p)
//	{
//		while (p)
//		{
//			s.push(p);
//			p = p->lchild;
//		}
//		if (!s.empty())
//		{
//			p = s.top();
//			s.pop();
//			cout << p->data << " ";
//			p = p->rchild;
//		}
//	}
//	cout << endl;
//}
//
//void pre(BTNode * root)
//{
//	if (!root)
//		return;
//	BTNode *p = root;
//	stack<BTNode *> s;
//	while (!s.empty() || p)
//	{
//		while (p)
//		{
//			s.push(p);
//			cout << p->data << " ";
//			p = p->lchild;
//		}
//		if (!s.empty())
//		{
//			p = s.top();
//			s.pop();
//			p = p->rchild;
//		}
//	}
//	cout << endl;
//}
//
//void after(BTNode * root)
//{
//	if (!root)
//		return;
//	BTNode *p = root;
//	BTNode *last = NULL;
//	stack<BTNode *> s;
//
//	while (p)
//	{
//		s.push(p);
//		p = p->lchild;
//	}
//	while (!s.empty())
//	{
//		//每次进入到这里时，p一定是NULL;
//		p = s.top();
//		s.pop();
//		//如果P的右孩子为空或者右孩子已经访问过，则打印
//		if (!p->rchild || p->rchild == last)
//		{
//			cout << p->data << " ";
//			last = p;
//		}
//		else     //才访问了左孩子，要访问右边
//		{
//			s.push(p);
//			p = p->lchild;
//			while (p)
//			{
//				s.push(p);
//				p = p->lchild;
//			}
//		}
//	}
//	cout << endl;
//}
//
//
//
//void qian(BTNode *root ,vector<int> &arr)
//{
//	if (root)
//	{
//		stack<BTNode *> s;
//		while (!s.empty() || root)
//		{
//			while (root)
//			{
//				s.push(root);
//				arr.push_back(root->data);
//				root = root->lchild;
//			}
//			if (!s.empty())
//			{
//				root = s.top();
//				s.pop();
//				root = root->rchild;
//			}
//		}
//	}
//}
//
//void zhong(BTNode *root, vector<int> &arr)
//{
//	if (root)
//	{
//		stack<BTNode *> s;
//		while (!s.empty() || root)
//		{
//			while (root)
//			{
//				s.push(root);
//				root = root->lchild;
//			}
//			if (!s.empty())
//			{
//				root = s.top();
//				arr.push_back(root->data);
//				s.pop();
//				root = root->rchild;
//			}
//		}
//	}
//}
//
//void hou(BTNode *root, vector<int> &arr)
//{
//	if (root)
//	{
//		stack<BTNode *> s;
//		BTNode *last = NULL;
//		while (root)
//		{
//			s.push(root);
//			root = root->lchild;
//		}
//		while (!s.empty())
//		{
//			//走到这里，ROOT一定为空
//			root = s.top();
//			s.pop();
//			if (!root->rchild || root->rchild == last) //如果当前节点的右孩子为空，或者当前孩子右节点已经被遍历过，打印。
//			{
//				arr.push_back(root->data);
//				last = root;
//			}
//			else
//			{
//				s.push(root);
//				root = root->rchild;
//				while (root)
//				{
//					s.push(root);
//					root = root->lchild;
//				}
//			}
//		}
//	}
//}
//
//void qianqian(BTNode *root,vector<int> &arr)
//{
//	if (root)
//	{
//		arr.push_back(root->data);
//		qianqian(root->lchild, arr);
//		qianqian(root->rchild, arr);
//	}
//}
//
//void zhongzhong(BTNode *root, vector<int> &arr)
//{
//	if (root)
//	{
//		zhongzhong(root->lchild, arr);
//		arr.push_back(root->data);
//		zhongzhong(root->rchild, arr);
//	}
//}
//
//void houhou(BTNode *root, vector<int> &arr)
//{
//	if (root)
//	{
//		houhou(root->lchild, arr);
//		houhou(root->rchild, arr);
//		arr.push_back(root->data);
//	}
//}
//
//bool equal(vector<int> &arr1, vector<int> &arr2)
//{
//	if (arr1.size() != arr2.size())
//		return false;
//	for (int i = 0; i < arr1.size(); i++)
//	{
//		if (arr1[i] != arr2[i])
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	BTNode *node;
//	creatbypre(&node);
//	vector<int> qian1, qian2, zhong1, zhong2, hou1, hou2;
//
//	qian(node, qian1);
//	qianqian(node, qian2);
//	cout << equal(qian1, qian2)<<endl;
//
//	zhong(node, zhong1);
//	zhongzhong(node, zhong2);
//	cout << equal(zhong1, zhong2) << endl;
//
//	hou(node, hou1);
//	houhou(node, hou2);
//	cout << equal(hou1, hou2) << endl;
//	system("pause");
//}

//======================================二叉树前中后非递归遍历==========================================




//=====================================  求一棵二叉树的最大距离（任意两节点） ==========================================
//=======================函数返回值是当前结点的最大高度，整个树的最大距离保存在maxlenth中===============================
//int MaxDistance(node* pRoot, int &maxlenth)
//{
//	if (pRoot == NULL)
//		return 0;
//
//	//左右子树的最大距离
//	int leftlenth = MaxDistance(pRoot->lchild, maxlenth);
//	int rightlenth = MaxDistance(pRoot->rchild, maxlenth);
//
//	//用一个临时变量保存当前的最远距离，如果大于原来的，那么交换
//	int temp = leftlenth + rightlenth;
//	if (temp > maxlenth)
//		maxlenth = temp;
//
//	return leftlenth > rightlenth ? leftlenth + 1 : rightlenth + 1;
//}

