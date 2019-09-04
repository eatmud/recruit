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


//=====================���� N*LOGN ���� 4���������=========================================================

////��õ������ʱ�临�Ӷ�ΪO(n),��������ΪO��n*n��;
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
////�ص��ǽ����ƶ����ݴ����١�����������¶�ΪO��n*n�����Ƚϴ����࣬����ʱ����;
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
////��õ������ʱ�临�Ӷ�ΪO(n),������O��n*n��;
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
////ϣ����������Ҫע��һ�㣬 pҪ��ʼ��Ϊ����Ԫ�ظ�����Ȼ��ÿ��p =  p / 3 + 1 ��������+1����Ȼ�����������������ÿ�β����ı䶼��p
////ϣ�������ǲ��ȶ������򷽷���ʱ�临�Ӷȵļ���ϸ��ӣ�ͳ�Ƶõ�O��n��3/2�η���
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
////����
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
////����
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
////����
//class Heapsort
//{
//public:
//	void heapsort(vector<int> &arr)
//	{
//		for (int i = arr.size() / 2 - 1; i >= 0; i--)   //arr.size() / 2-1ȷ����0��ʼ������£�ǰһ������ݽ��жѵ���
//			heapadjust(arr, i, arr.size());
//		for (int i = arr.size() - 1; i > 0; i--)          //�����һ��Ԫ�ؿ�ʼ����������������
//		{
//			int temp = arr[i];
//			arr[i] = arr[0];
//			arr[0] = temp;
//			heapadjust(arr, 0, i);
//		}
//
//
//	}
//	void heapadjust(vector<int> &arr, int start, int end)      //ǰ�պ�
//	{
//		int temp = arr[start];
//		for (int k = 2 * start + 1; k<end; k = k * 2 + 1) //��start�����ӽ�㿪ʼ
//		{
//			if (k + 1<end && arr[k + 1]>arr[k])//������ӽ��С�����ӽ�㣬kָ�����ӽ��
//				k++;
//			if (arr[k]>temp)//����ӽ����ڸ���㣬���ӽ�㸳�������
//			{
//				arr[start] = arr[k];
//				start = k;          //���Ҹ��ڵ����ʼλ�ø��Ÿı�
//			}
//			else
//				break;
//		}
//		arr[start] = temp;
//	}
//
//	//С����
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
////����������������ȷ��
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
//	cout << "����ǰ��" << endl;
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
//	cout << "�����" << endl;
//	for (int i = 1; i < arr.size(); i++)
//		cout << arr[i] << "  ";
//	cout << endl;
//	cout << endl;
//	cout << "����������Ƿ�����" << fun(arr) << endl;
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
//		for (int i = arr.size() / 2-1; i >= 0; i--)   //arr.size() / 2-1ȷ����0��ʼ������£�ǰһ������ݽ��жѵ���
//			heapadjust(arr, i, arr.size());
//		for (int i = arr.size() - 1; i > 0; i--)          //�����һ��Ԫ�ؿ�ʼ����������������
//		{
//			int temp = arr[i];
//			arr[i] = arr[0];
//			arr[0] = temp;
//			heapadjust(arr, 0, i);
//		}
//
//
//	}
//	void heapadjust(vector<int> &arr, int start, int end)      //ǰ�պ�
//	{
//		int temp = arr[start];
//		for (int k = 2 * start + 1; k<end; k = k * 2 + 1) //��start�����ӽ�㿪ʼ
//		{
//			if (k + 1<end && arr[k + 1]>arr[k])//������ӽ��С�����ӽ�㣬kָ�����ӽ��
//				k++;
//			if (arr[k]>temp)//����ӽ����ڸ���㣬���ӽ�㸳�������
//			{
//				arr[start] = arr[k];
//				start = k;          //���Ҹ��ڵ����ʼλ�ø��Ÿı�
//			}
//			else
//				break;
//		}
//		arr[start] = temp;        
//	}
//
//	//С����
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

//======================�������� 4��������� ==============================================================




//======================================������ǰ�к�ǵݹ����==========================================

//typedef struct node
//{
//	int data;
//	struct node* lchild;  //����
//	struct node* rchild;  //�Һ���
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
//		//ÿ�ν��뵽����ʱ��pһ����NULL;
//		p = s.top();
//		s.pop();
//		//���P���Һ���Ϊ�ջ����Һ����Ѿ����ʹ������ӡ
//		if (!p->rchild || p->rchild == last)
//		{
//			cout << p->data << " ";
//			last = p;
//		}
//		else     //�ŷ��������ӣ�Ҫ�����ұ�
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
//			//�ߵ����ROOTһ��Ϊ��
//			root = s.top();
//			s.pop();
//			if (!root->rchild || root->rchild == last) //�����ǰ�ڵ���Һ���Ϊ�գ����ߵ�ǰ�����ҽڵ��Ѿ�������������ӡ��
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

//======================================������ǰ�к�ǵݹ����==========================================




//=====================================  ��һ�ö������������루�������ڵ㣩 ==========================================
//=======================��������ֵ�ǵ�ǰ�������߶ȣ��������������뱣����maxlenth��===============================
//int MaxDistance(node* pRoot, int &maxlenth)
//{
//	if (pRoot == NULL)
//		return 0;
//
//	//����������������
//	int leftlenth = MaxDistance(pRoot->lchild, maxlenth);
//	int rightlenth = MaxDistance(pRoot->rchild, maxlenth);
//
//	//��һ����ʱ�������浱ǰ����Զ���룬�������ԭ���ģ���ô����
//	int temp = leftlenth + rightlenth;
//	if (temp > maxlenth)
//		maxlenth = temp;
//
//	return leftlenth > rightlenth ? leftlenth + 1 : rightlenth + 1;
//}

