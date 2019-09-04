#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
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
#include<queue>
using namespace std;
using namespace std;


//=================================摩尔斯遍历的前中后遍历=============================================

//struct Treenode
//{
//	int val;
//	Treenode *left;
//	Treenode *right;
//	Treenode(int v) :val(v), left(nullptr), right(nullptr){}
//};
//void create(Treenode **p)
//{
//	int temp;
//	cin >> temp;
//	if (temp == 0)
//		*p = nullptr;
//	else
//	{
//		*p = new Treenode(temp);
//		create(&(*p)->left);
//		create(&(*p)->right);
//	}
//}
//
//
//void morris1(Treenode *root)  //前序
//{
//	if (root)
//	{
//		Treenode* cur = root;
//		Treenode* mor = nullptr;
//		while (cur)
//		{
//			if (cur->left)      //有左孩子
//			{
//				mor = cur->left;
//				while (mor->right && mor->right != cur)  //mor 不为空，并且不等于当前 cur
//					mor = mor->right;
//				if (!mor->right)       //第一次遍历到mor，指向cur
//				{
//					cout << cur->val << " ";
//					mor->right = cur;
//					cur = cur->left;
//					continue;
//				}
//				else
//					mor->right = nullptr;  //第二次遍历到mor，指回空，cur 右移。
//			}
//			else
//				cout << cur->val << " ";
//			cur = cur->right;
//		}
//		cout << endl;
//	}
//}
//
//
//void morris2(Treenode *root)
//{
//	if (root)
//	{
//		Treenode* cur = root;
//		Treenode* mor = nullptr;
//		while (cur)
//		{
//			if (cur->left)      //有左孩子
//			{
//				mor = cur->left;
//				while (mor->right && mor->right != cur)  //mor 不为空，并且不等于当前 cur
//					mor = mor->right;
//				if (!mor->right)       //第一次遍历到mor，指向cur
//				{
//					mor->right = cur;
//					cur = cur->left;
//					continue;
//				}
//				else
//					mor->right = nullptr;  //第二次遍历到mor，指回空，cur 右移。
//			}
//			cout << cur->val << " ";
//			cur = cur->right;
//		}
//		cout << endl;
//	}
//}
//
//
//
//
//
//void resvers(Treenode *root)
//{
//
//	if (!root->right) //链表第一个节点为空，或者只有一个节点，不需要反转
//	{
//		cout << root->val << " ";
//		return;
//	}
//	Treenode *pre = nullptr;
//	Treenode *cur = root;
//	Treenode *next = root->right;
//	while (next)
//	{
//		cur->right = pre;
//		pre = cur;
//		cur = next;
//		next = next->right;
//	}
//	cur->right = pre;
//
//	next = cur;
//	while (next)
//	{
//		cout << next->val << " ";
//		next = next->right;
//	}
//
//	pre = nullptr;
//	next = root->right;
//	while (next)
//	{
//		cur->right = pre;
//		pre = cur;
//		cur = next;
//		next = next->right;
//	}
//	cur->right = pre;
//}
//
//
//void morris3(Treenode *root)
//{
//	if (root)
//	{
//		Treenode* cur = root;
//		Treenode* mor = nullptr;
//		while (cur)
//		{
//			if (cur->left)      //有左孩子
//			{
//				mor = cur->left;
//				while (mor->right && mor->right != cur)  //mor 不为空，并且不等于当前 cur
//					mor = mor->right;
//				if (!mor->right)       //第一次遍历到mor，指向cur
//				{
//					mor->right = cur;
//					cur = cur->left;
//					continue;
//				}
//				else
//				{
//					mor->right = nullptr;    //第二次遍历到mor，指回空，cur 右移。
//					resvers(cur->left);
//				}
//			}
//			cur = cur->right;
//		}
//		resvers(root);
//		cout << endl;
//	}
//}
//
//int main()
//{
//	Treenode * root;
//	create(&root);
//	morris1(root);
//	morris2(root);
//	morris3(root);
//	system("pause");
//}

// 1 2 4 8 0 0 9 0 0 5 10 0 0 11 0 0 3 6 12 0 0 13 0 0 7 14 0 0 15 0 0 

//struct node
//{
//	int value;
//	node* left;
//	node* right;
//};
//
////前序创建二叉树
//void creatbypre(node** t)
//{
//	int value;
//	cin >> value;
//	if (value == 0)
//		*t = nullptr;
//	else
//	{
//		*t = new node;
//		(*t)->value = value;
//		creatbypre(&(*t)->left);
//		creatbypre(&(*t)->right);
//	}
//}
//
////基础的摩尔斯遍历
//void morrisbase(node* root)
//{
//	node* cur = root;
//	node* mor = NULL;
//	while (cur)
//	{
//		if (cur->left)        //有左孩子就让摩尔斯遍历其左孩子，然后一直遍历到其最右子节点
//		{
//			mor = cur->left;
//			while (!mor->right && mor->right!= cur)
//				mor = mor->right;
//			if (!mor->right)        //如果最右子节点为空，指向当前cur
//			{
//				mor->right = cur;
//				cur = cur->left;     //cur 指向其左孩子。
//				continue;
//			}
//			else
//				mor->right = NULL;   //让右孩子指回空
//		}
//		cur = cur->right;    //cur没有左孩子，直接右移
//	}	
//}
//
////摩尔斯前序遍历  每个节点第一次就打印
//void morrisbypre(node* root)
//{
//	node* cur = root;
//	node* mor = nullptr;
//	
//	while (cur != nullptr)
//	{
//		if (cur->left!=nullptr)   //如果当前节点左节点不为空
//		{       
//			mor = cur->left;
//			while (mor->right != nullptr && mor->right != cur)
//			{
//				mor = mor->right;
//			}
//			if (mor->right == nullptr)       //有左孩子的节点第一次被访问，前序需要打印这些节点。
//			{
//				cout << cur->value << " ";
//				mor->right = cur;
//				cur = cur->left;
//				continue;
//			}
//			else                  
//				mor->right = nullptr;
//		}
//		else
//		{
//			cout << cur->value << " ";
//		}
//		cur = cur->right;      //左节点为空，直接右移
//	}
//	cout << endl;
//}
//
////摩尔斯中序遍历，每个节点第二次才打印（节点无左节点只会遍历一次）
//void morrisbymid(node* root)
//{
//	node* cur = root;
//	node* mor = nullptr;
//
//	while (cur != nullptr)
//	{
//		if (cur->left != nullptr)   //如果当前节点左节点不为空
//		{
//			mor = cur->left;
//			while (mor->right != nullptr && mor->right != cur)
//			{
//				mor = mor->right;
//			}
//			if (mor->right == nullptr)
//			{
//				mor->right = cur;
//				cur = cur->left;
//				continue;
//			}
//			else
//				mor->right = nullptr;            
//		}
//		cout << cur->value << " ";   //没有左子树的节点打印和有左子树的第二次打印。
//		cur = cur->right;     
//	}
//	cout << endl;
//}
//
////摩尔斯后续遍历，只找到两次遍历的那些节点，逆序打印它左子节点的所有右节点。最后while结束后，单独逆序打印ROOT节点
//void morrisbyafter(node* root)
//{
//	node* cur = root;
//	node* mor = NULL;
//	while (cur)
//	{
//		if (cur->left){
//			mor = cur->left;
//			while (!mor->right && mor->right != cur)
//				mor = mor->right;
//			if (!mor->right){
//				mor->right = cur;
//				cur = cur->left;
//				continue;
//			}
//			else{
//				mor->right = NULL;
//				fun(cur->left);     
//			}
//		}
//		cur = cur->right;
//	}
//	fun(root); 
//}
//
//void fun(node *root){ ; }
////摩尔斯遍历的前中遍历

//=================================摩尔斯遍历的前中后遍历=============================================


//==================================前缀树 ============================================================
//不带统计次数，只负责判断是否出现的前缀树

//struct treenode
//{
//	treenode * child[26];
//	bool is_end;
//	treenode() :is_end(false)
//	{
//		for (int i = 0; i < 26; i++)
//			child[i] = NULL;
//	}
//};
//
//class Trie
//{
//public:
//	Trie() {
//		root = newnode();
//	}
//	void insert(string word1)
//	{
//		const char *word = word1.c_str();
//		treenode * p = root;
//		while (*word)
//		{
//			int pos = *word - 'a';
//			if (!p->child[pos])  //如果没有
//			{
//				p->child[pos] = newnode();
//			}
//			p = p->child[pos];
//			word++;
//		}
//		p->is_end = true;
//	}
//	bool search(string word1) {
//		const char *word = word1.c_str();
//		treenode * p = root;
//		while (*word)
//		{
//			int pos = *word - 'a';
//			if (!p->child[pos])  //如果没有
//				return false;
//			else
//			{
//				p = p->child[pos];
//				word++;
//			}
//		}
//		return p->is_end;
//	}
//	bool startsWith(string prefix1) {
//		const char *prefix = prefix1.c_str();
//		treenode * p = root;
//		while (*prefix)
//		{
//			int pos = *prefix - 'a';
//			if (!p->child[pos])  //如果没有
//				return false;
//			else
//			{
//				p = p->child[pos];
//				prefix++;
//			}
//		}
//		return true;
//	}
//	~Trie()
//	{
//		for (int i = 0; i < vec.size(); i++)
//		{
//			delete vec[i];
//			vec[i] = NULL;
//		}
//	}
//private:
//	treenode * newnode()
//	{
//		treenode * p = new treenode();
//		vec.push_back(p);
//		return p;
//	}
//	vector<treenode *> vec;
//	treenode *root;
//};

//带前缀和统计次数的前缀树

//struct node
//{
//	vector<node *> arr;
//	int finish;
//	int visit;
//	node()
//	{
//		arr.resize(26,nullptr);
//		finish = 0;
//		visit = 0;
//	}
//};
//
//class trietree
//{
//public:
//	trietree()
//	{
//		root = new node();
//		arr1.push_back(root);
//	}
//	void insert(string &str)      //插入到trie 树中
//	{
//		int i = 0;
//		node *cur = root;
//		while (i < str.size())
//		{
//			int pos = str[i++] - 'a';
//			if (!cur->arr[pos] )
//			{
//				cur->arr[pos] = new node();
//				arr1.push_back(cur->arr[pos]);
//			}
//			cur = cur->arr[pos];
//			cur->visit++;
//		}
//		cur->finish++;
//	}
//
//	int serach(string &str)       //有多少个str的字符串
//	{
//		int i = 0;
//		node *cur = root;
//		while (i < str.size())
//		{
//			int pos = str[i++] - 'a';
//			if (!cur->arr[pos])
//				return 0;
//			cur = cur->arr[pos];
//		}
//		return cur->finish;
//	}
//
//	int trienumber(string &str)  //以str为前缀的字符串有多少个。
//	{
//		int i = 0;
//		node *cur = root;
//		while (i < str.size())
//		{
//			int pos = str[i++] - 'a';
//			if (!cur->arr[pos])
//				return 0;
//			cur = cur->arr[pos];
//		}
//		return cur->visit;
//	}
//	~trietree()
//	{
//		for (int i = 0; i < arr1.size(); i++)
//			delete arr1[i];
//	}
//private:
//	node *root;
//	vector<node *> arr1;
//};

//==================================前缀树 ============================================================




//==================================并查集 ============================================================

//左神版本
//struct Node
//{
//	int a;
//	bool operator==(const Node &w)
//	{
//		return a == w.a;
//	}
//	bool operator!=(const Node &w)
//	{
//		return !(*this == w);
//	}
//};
//
//
//class unionfindset
//{
//public:
//	//初始化，一次性把所有样本给入，创建好并查集。
//	unionfindset(const vector<Node> &arr)
//	{
//		for (Node x : arr)
//		{
//			fathermap[x] = x;
//			sizemap[x] = 1;
//		}
//	}
//	//判断是否同一集合
//	bool issameset(Node a, Node b)
//	{
//		return findhead(a) == findhead(b);
//	}
//	//合并
//	void Union(Node a, Node b)
//	{
//		Node ahead = findhead(a);		//a的代表节点
//		Node bhead = findhead(b);		//b的代表节点
//		if (ahead != bhead) //不在一个集合，需要合并
//		{
//			int asetsize = sizemap[ahead];  //a所在集合的大小，查找集合大小，只能通过代表节点的大小表示。其他的失效了。
//			int bsetsize = sizemap[bhead];  //b所在集合的大小
//			if (asetsize <= bsetsize)   //小的挂在大的下
//			{
//				fathermap[ahead] = bhead;
//				sizemap[bhead] = asetsize + bsetsize;
//			}
//			else
//			{
//				fathermap[bhead] = ahead;
//				sizemap[ahead] = asetsize + bsetsize;
//			}
//		}
//	}
//private:
//	//查找代表节点（递归版本）
//	//Node findhead(Node node)
//	//{
//	//	Node father = fathermap[node];  
//	//	if (father != node)    //代表不是当前集合的代表节点
//	//		father = findhead(father);  //递归寻找father的代表节点。
//	//	fathermap[node] = father;		//更新当前节点的父节点就为代表节点，打扁平。
//	//	return father;					//返回代表节点。
//	//}
//
//	//查找代表节点（迭代版本）
//	Node findhead(Node node)
//	{
//		stack<Node> s;
//		Node cur = node;         
//		Node parent = fathermap[node];
//		while (cur != parent)    //如果当前节点不是代表节点
//		{
//			s.push(cur);         //就压栈并一直找其父节点是否代表节点。
//			cur = parent;
//			parent = fathermap[cur];
//		}
//		//上个while结束的 parent 就是代表节点，把栈中所有节点的父节点改为代表节点。
//		while (!s.empty())       
//		{
//			fathermap[s.top()] = parent;
//			s.pop();
//		}
//		return parent;
//	}
//private:
//	unordered_map<Node, Node> fathermap;//键代表当前节点。值代表父节点是谁
//	unordered_map<Node, int> sizemap;	//键所在的集合有多少元素
//};

//自己版本
//struct Node
//{
//	int a;
//	bool operator==(const Node &w)
//	{
//		return a == w.a;
//	}
//	bool operator!=(const Node &w)
//	{
//		return !(*this == w);
//	}
//};
//
//class unionset
//{
//public:
//	unionset(vector<Node> &arr)
//	{
//		for (auto &x : arr)
//		{
//			fathermap[x] = x;
//			sizemap[x] = 1;
//		}
//	}
//	bool inoneunion(Node a, Node b)
//	{
//		return find(a) == find(b);
//	}
//	void unionoperator(Node a, Node b)
//	{
//		Node ap = find(a);
//		Node bp = find(b);
//		if (ap != bp)
//		{
//			if (sizemap[ap] >= sizemap[bp])
//			{
//				fathermap[bp] = ap;
//				sizemap[ap] += sizemap[bp];
//			}
//			else
//			{
//				fathermap[ap] = bp;
//				sizemap[bp] += sizemap[ap];
//			}
//		}
//	}
//private:
//	unordered_map<Node, Node> fathermap;	//代表其父节点是谁
//	unordered_map<Node, int> sizemap;		//代表其所在集合大小是多少
//	Node find(Node node)
//	{
//		stack<Node> s;
//		while (fathermap[node] != node)     //只要node的上一级不是node自己
//		{
//			s.push(node);
//			node = fathermap[node];
//		}
//		while (!s.empty())
//		{
//			fathermap[s.top()] = node;
//			s.pop();
//		}
//		return node;
//	}
//};

//==================================并查集 ============================================================



//==================================KMP ============================================================

//class Solution
//{
//public:
//	//主串，子串
//	int fun(string s1, string s2)
//	{
//		if ((s1.size() < s2.size()) || s1.empty() || s2.empty())
//			return -1;
//		int i = -1;
//		int j = -1;
//		int s1length = s1.size();
//		int s2length = s2.size();
//		next_(s2);
//		while ((i < s1length) && (j < s2length))
//		{
//			if (j == -1 || s1[i] == s2[j])
//			{
//				i++; j++;
//			}
//			else
//			{
//				j = next[j];
//			}
//		}
//		if (j == s2.size())
//			return i - j;
//		else
//			return -1;
//	}
//	//普通next
//	void next_(string s2)
//	{
//		next.resize(s2.size(), 0);
//		int i = 0;
//		int j = -1;
//		next[0] = -1;
//		while (i < next.size() - 1)
//		{
//			if (j == -1 || s2[i] == s2[j])
//			{
//				++i;
//				++j;
//				next[i] = j;
//				cout << next[i] << " ";
//			}
//			else
//				j = next[j];
//		}
//		cout << endl;
//	}
//
//	//改进next
//	void next_(string s2)
//	{
//		next.resize(s2.size(), 0);
//		int i = 0;
//		int j = -1;
//		next[0] = -1;
//		while (i < next.size() - 1)
//		{
//			if (j == -1 || s2[i] == s2[j])
//			{
//				++i;
//				++j;
//				if (s2[i] != s2[j])
//					next[i] = j;
//				else
//					next[i] = next[j];
//				cout << next[i] << " ";
//			}
//			else
//				j = next[j];
//		}
//		cout << endl;
//	}
//
//private:
//	vector<int> next;
//};

//==================================KMP ============================================================


//==================================马拉车算法 ==========================================

//class solution {
//public:
//	string longestpalindrome(string s)
//	{
//		if (s.length() < 1)
//		{
//			return "";
//		}
//		int start = 0, end = 0;
//		for (int i = 0; i < s.length(); i++)  //以每个字符为中心往两边扩。
//		{
//			int len1 = expandaroundcenter(s, i, i);//一个元素为中心
//			int len2 = expandaroundcenter(s, i, i + 1);//两个元素为中心
//			int len = max(len1, len2);
//			if (len > end - start)             //如果当前扩出来的长度比原来大，更新起始。
//			{
//				start = i - (len - 1) / 2;
//				end = i + len / 2;
//			}
//		}
//		return s.substr(start, end - start + 1);
//	}
//
//	int expandaroundcenter(string s, int left, int right)
//	{
//		int l = left, r = right;
//		while (l >= 0 && r < s.length() && s[l] == s[r])
//		{// 计算以left和right为中心的回文串长度
//			l--;
//			r++;
//		}
//		return r - l - 1;
//	}
//};

//==================================马拉车算法 ==========================================


//==================================霍夫曼编码，用最小堆实现 ==========================================
//==================================霍夫曼编码，用最小堆实现 ==========================================


//===========B树的性质===================

//1、一个M阶的B - 树，每个结点最多含有M - 1对键 - 链接,最少含有M/2对键-链接,除根节点外不能少于2对。
// (B树是用于存储海量数据的，一般其一个结点就占用磁盘一个块的大小。)
//2、每个结点根据实际情况可以包含大量的关键字信息和分支，树的深度降低了，这就意味着查找一个元素只要很少结点从外存磁盘中读入内存，很快访问到要查找的数据。
// （因为从内存访问磁盘的过程涉及磁盘IO操作，速度很慢，所以次数越少越好）

//===========B树的性质===================


//===========B+树的性质===================

//1、有n棵子树的结点中含有n - 1 个关键字；(与B 树n棵子树有n - 1个关键字 保持一致，)
//2、所有的叶子结点中包含了全部关键字的信息，及指向含有这些关键字记录的指针，且叶子结点本身依关键字的大小自小而大的顺序链接。
//3、所有的非终端结点可以看成是索引部分，结点中仅含有其子树根结点中最大（或最小）关键字。
//最大的区别在于，B树是像2-3树那样把数据分散到所有的结点中，而B+树的数据都集中在叶结点，上层结点只是数据的索引，并不包含数据信息
//1、为什么说B + -tree比B 树更适合实际应用中操作系统的文件索引和数据库索引？
//
//数据库索引采用B + 树的主要原因是 B树在提高了磁盘IO性能的同时并没有解决元素遍历的效率低下的问题。正是为了解决这个问题，B + 树应运而生。
//
//B + 树只要遍历叶子节点就可以实现整棵树的遍历。而且在数据库中基于范围的查询是非常频繁的，而B树需要遍历整棵树，效率太低。
//走进搜索引擎的作者梁斌老师针对B树、B + 树给出了他的意见（来源于July）：
//
//“B + 树还有一个最大的好处，方便扫库，B树必须用中序遍历的方法按序扫库，而B + 树直接从叶子结点挨个扫一遍就完了，B + 树支持range - query非常方便，而B树不支持。这是数据库选用B + 树的最主要原因。
//
//比如要查 5 - 10之间的，B + 树一把到5这个标记，再一把到10，然后串起来就行了，B树就非常麻烦。B树的好处，就是成功查询特别有利，因为树的高度总体要比B + 树矮。不成功的情况下，B树也比B + 树稍稍占一点点便宜。B树比如你的例子中查，17的话，一把就得到结果了。
//
//有很多基于频率的搜索是选用B树，越频繁query的结点越往根上走，前提是需要对query做统计，而且要对key做一些变化。
//
//另外B树也好B + 树也好，根或者上面几层因为被反复query，所以这几块基本都在内存中，不会出现读磁盘IO，一般已启动的时候，就会主动换入内存。”
//
//"mysql 底层存储是用B+树实现的，因为在内存中B+树是没有优势的，但是一到磁盘，B+树的威力就出来了"。
//
//B + 树是B树的变形，它把所有的附属数据都放在叶子结点中，只将关键字和子女指针保存于内结点，内结点完全是索引的功能，最大化了内结点的分支因子。不过是n个关键字对应着n个子女，子女中含有父辈的结点信息，叶子结点包含所有信息（内结点包含在叶子结点中，内结点没有指向“附属数据”的指针必须索引到叶子结点）。这样的话还有一个好处就是对于每个结点所需的索引次数都是相等的，保证了稳定性。

//===========B+树的性质===================


//红黑树的插入的代码
//bool Insert(const K& key, const V& value)
//{
//	//根节点为空
//	if (_root == NULL)
//	{
//		_root = new Node(key, value);
//		_root->_color = BLACK;
//
//		return true;
//	}
//	//根节点不为空
//
//	//找到新节点插入位置
//	Node* parent = NULL;
//	Node* cur = _root;
//
//	while (cur)
//	{
//		if (cur->_key < key)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else if (cur->_key >key)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else
//			return false;
//	}
//	//插入新节点
//	cur = new Node(key, value);
//	cur->_color = RED;
//	if (parent->_key > key)
//	{
//		parent->_left = cur;
//		cur->_parent = parent;
//	}
//	else//parent->_key < key
//	{
//		parent->_right = cur;
//		cur->_parent = parent;
//	}
//
//	//插入节点后颜色的调整
//	while (parent && parent->_color == RED)
//	{
//		Node* grandfather = parent->_parent;//grandfather颜色一定为黑色
//		if (parent == grandfather->_left)
//		{
//			Node* uncle = grandfather->_right;
//
//			//uncle存在且为红
//			if (uncle && uncle->_color == RED)
//			{
//				parent->_color = uncle->_color = BLACK;
//				grandfather->_color = RED;
//
//				cur = grandfather;
//				parent = cur->_parent;
//			}
//			else//uncle不存在/uncle存在且为黑
//			{
//				if (cur == parent->_right)
//				{
//					RotateL(parent);
//					swap(parent, cur);
//				}
//				RotateR(grandfather);
//				parent->_color = BLACK;
//				grandfather->_color = RED;
//			}
//		}
//		else//grandfather->_right==parent
//		{
//			Node* uncle = grandfather->_left;
//
//			//uncle存在且为红
//			if (uncle && uncle->_color == RED)
//			{
//				parent->_color = uncle->_color = BLACK;
//				grandfather->_color = RED;
//
//				cur = grandfather;
//				parent = cur->_parent;
//			}
//			else//不存在/存在且为黑
//			{
//				if (cur == parent->_left)
//				{
//					RotateR(parent);
//					swap(cur, parent);
//				}
//
//				RotateL(grandfather);
//				parent->_color = BLACK;
//				grandfather->_color = RED;
//			}
//		}
//	}//end while (parent && parent->_color == RED)
//
//	_root->_color = BLACK;
//
//	return true;
//}
//红黑树的插入的代码


//===============================汉诺塔问题代码======================================

//n个从from移动到to 上面去。 =  上面n-1从from移动到help上 + 第n个从from移动到to + n-1个从help移动到to
//void process(int n, string from, string to, string help)
//{
//	if (n == 1)
//		cout << "move 1 from " << from << " to " << to << endl;
//	else
//	{
//		process(n - 1, from, help, to);
//		cout << "move "<<n<<" from " << from << " to " << to << endl;
//		process(n - 1, help, to, from);
//	}
//}
//
//int main()
//{
//	string from = "A";
//	string to = "B";
//	string help = "C";
//	process(3, from, to, help);
//	system("pause");
//}

//===============================汉诺塔问题代码======================================


//================================马拉车算法=========================================

//需要一个数组arr 记录第I个数为对称轴能扩到的最远下标。
//需要一个记录当前

//class manacher
//{
//public:
//	string manacherstring(string &str)
//	{
//		string res;
//		for (int i = 0; i < str.size(); i++)
//		{
//			res += "#";
//			res.push_back(str[i]);
//		}
//		res += "#";
//		return  res;
//	}
//
//	int maxlcpslength(string &str)
//	{
//		if (str.empty())
//			return 0;
//		string res = manacherstring(str);
//		vector<int> arr(res.size(),0);
//		int c = -1;      //对称中心位置
//		int r = -1;		 //最远对称右边界
//		int Max = -1;
//		for (int i = 0; i < res.size(); i++)
//		{
//			//如果r>i, 2*c-i代表，i关于c的对称位置。 arr[2*c-i]和r-i，其中前者代表i的对称区域小于r时，r-i代表i当前最远能扩
//			//如果r<=i，代表arr[i]=1； 
//			arr[i] = r>i ? min(arr[2 * c - i], r - i) : 1;  
//
//			//保证扩出来的左边界和右边界否不越界
//			while (i + arr[i]<res.size() && i - arr[i]> -1)
//			{
//				if (res[i + arr[i]] == res[i - arr[i]])
//					arr[i]++;
//				else
//					break;
//			}
//			//更新r 和c 
//			if (i + arr[i] > r)
//			{
//				r = i + arr[i];
//				c = i;
//			}
//			//更新Max;
//			Max = max(Max, arr[i]);
//		}
//		return Max - 1;
//	}
//};

//================================马拉车算法=========================================





//=================================单调双端队列========================

//窗口最大值，窗口最小值
//int main()
//{
//	vector<int> arr;
//	int num = 5;
//
//	deque<int> maxd;
//	deque<int> mind;
//	int L = 0, R = 0;
//	int sum = 0;
//	while (L < arr.size())
//	{
//		//只要没有break，R 就一直 ++ 
//		while (R < arr.size())
//		{
//			while (!maxd.empty() && arr[maxd.back()] <= arr[R])
//			{
//				maxd.pop_back();
//			}
//			maxd.push_back(R);
//			while (!mind.empty() && arr[mind.back()] >= arr[R])
//			{
//				mind.pop_back();
//			}
//			mind.push_back(R);
//			//最大值和最小值分别记录在双端队列的头部。
//			if (arr[maxd.front()] - arr[mind.front()] > num)
//				break;
//			R++;
//		}
//		sum += R - L;  //以L开头，满足 max-min<=num 的个数。
//		//如果最大值和最小值的窗口过期了。更新队列。
//		if (maxd.front() == L)
//			maxd.pop_front();
//		if (mind.front() == L)
//			mind.pop_front();
//		L++;			// L右移，继续计算。
//	}
//	cout << sum << endl;
//}

//=================================单调双端队列========================


//=================================单调栈======================================

//class Solution {
//public:
//	int maximalRectangle(vector<vector<char>>& matrix) {
//		if (matrix.empty())
//			return 0;
//		vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size(), 0));
//		for (int i = 0; i < matrix.size(); i++)
//		{
//			for (int j = 0; j < matrix[0].size(); j++)
//			if (i == 0)
//			{
//				table[i][j] = matrix[i][j] - '0';
//			}
//			else
//			{
//				if (matrix[i][j] == '0')
//					table[i][j] = 0;
//				else
//					table[i][j] = table[i - 1][j] + 1;
//			}
//		}
//		int max = 0;
//		for (int i = 0; i < table.size(); i++)
//		{
//			int temp = fun(table[i]);
//			max = max < temp ? temp : max;
//		}
//		return max;
//	}
//
//	int fun(vector<int> &arr)
//	{
//		int max = 0;
//		stack<int> s;
//		for (int i = 0; i < arr.size(); i++)
//		{
//			while (!s.empty() && arr[s.top()] >= arr[i])   //如果单调栈不为空，并且s的最近元素大于等于当前元素（这个地方可以不考虑相等的问题）
//			{
//				int temp = s.top();
//				s.pop();
//				int left = -1;
//				if (!s.empty())
//					left = s.top();
//				max = ((i - left - 1)*arr[temp]) > max ? ((i - left - 1)*arr[temp]) : max;
//			}
//			s.push(i);
//		}
//		// 4 5 5 5 3 3  4 4 5 5 
//
//		//加完之后，单调栈可能还有剩余
//		while (!s.empty())
//		{
//			int temp = s.top();
//			s.pop();
//			if (!s.empty())
//				max = ((arr.size() - 1 - s.top())*arr[temp]) > max ? ((arr.size() - 1 - s.top())*arr[temp]) : max;
//			else
//				max = (arr.size()*arr[temp]) > max ? (arr.size()*arr[temp]) : max;
//		}
//		return max;
//	}
//};

//=================================单调栈======================================




//==================================LRU=====================================


//==================================LFU=====================================


//==================================跳跃表====================================


//====================================计算器问题==========================================

//计算器问题总结：
//
//中缀转后缀。需要一个栈存放操作符，一个string表示后缀表达式。
//遍历原始string。
//遇到是数字，就加入后缀表达式。要加分界符。
//遇到的是符号：
//1、是左括号直接压栈。
//2、是右括号，不压栈，一直弹栈，直到栈顶是左括号。弹栈过程中加入到后缀表达式。
//3、优先权最高的运算符直接压榨，否则栈不为空，不为左括号，就一直弹栈，直到栈顶的优先级比自己低。（言下之意优先权比自己高和自己一样的都要弹出去）
//
//遍历完原始表达式后，最后一个数字不要忘记加入后缀表达式。
//栈中剩余元素依次弹栈并加入后缀表达式。
//
//后缀表达式的计算：
//把后缀表达式中的数字压栈，遇到符号就从栈中弹出元素（根据操作符需要个数弹出），计算并把结果压入。
//直到最后栈中只剩一个元素，即结果。
//
//string zhongtohou(string &str)
//{
//	stack<string> s;
//	string res;
//	string temp;
//	for (int i = 0; i < str.size(); i++)
//	{
//		//如果是数字，一直加。
//		if (str[i] >= '0' && str[i] <= '9')
//			temp += str[i];
//		else  //不是数字，应该将之前的数字temp+！输出。
//		{
//			if (!temp.empty())  //有可能一开始就是( ，也会进到这里。此时temp是空，不用加分界符
//			{
//				res += temp + "!";
//				temp.clear();
//			}
//			if (str[i] == '(')		//左括号直接压入
//			{
//				string stmp(1, str[i]);
//				s.push(stmp + "!");
//			}
//			else if (str[i] == '*' || str[i] == '/')
//			{
//				//当前符号是* /，要把它下面的所有* /弹出。
//				// 栈不空，栈顶不是（，+，- ，言外之意就是* /
//				while (!s.empty() && s.top() != "(!"&&s.top() != "+!"&&s.top() != "-!")
//				{
//					res += s.top(); s.pop();
//				}
//				string stmp(1, str[i]);
//				s.push(stmp + "!");
//			}
//			else if (str[i] == ')')
//			{
//				while (s.top() != "(!")  //栈顶不是（，一直弹，加入中缀表达式
//				{
//					res += s.top(); s.pop();
//				}
//				s.pop();             //删掉（
//			}
//			else  //str[i] 是加减
//			{
//				//当前符号是+ -。要把它下面的所有* / + - 弹出。
//				//如果栈不空，并且栈顶不是（  ，言外之意就是* / + -
//				while (!s.empty() && s.top() != "(!")
//				{
//					res += s.top(); s.pop();
//				}
//				string stmp(1, str[i]);
//				s.push(stmp + "!");
//			}
//		}
//	}
//	//最后一个数先加进去。
//	if (!temp.empty())  
//	{
//		res += temp + "!";
//		temp.clear();
//	}
//	while (!s.empty())
//	{
//		res += s.top();
//		s.pop();
//	}
//	return res;
//}
//
//double houtores(string &str)
//{
//	stack<double> s;
//	string temp;
//	// 9!3!1!-!3!*!10!2!/!+!+!
//	for (int i = 0; i < str.size(); i++)
//	{
//		//如果是数字，一直加。
//		if (str[i] >= '0' && str[i] <= '9')
//			temp += str[i];
//		else
//		{
//			if (str[i] == '!' )	//如果是分界符，变数字，压栈。下一位。
//			{
//				s.push(stoi(temp));
//				temp.clear();
//				continue;
//			}
//			else	// + - * / 其中一个
//			{
//				double two = s.top(); s.pop();
//				double one = s.top(); s.pop();
//				if (str[i] == '+')
//					one = one + two;
//				else if (str[i] == '-')
//					one = one - two;
//				else if (str[i] == '*')
//					one = one * two;
//				else
//				{
//					if (two == 0)
//						throw exception("除数不能为0\n");
//					one = one / two;
//				}
//				s.push(one);
//				i++;
//			}
//		}
//	}
//	return s.top();
//}

//====================================计算器问题==========================================


//====================================二分图的最大匹配 == 二分图的最小点覆盖===============================

//#define MAXN 9999
//using namespace std;
//int nx, ny;//nx表示二分图左边顶点的个数，ny表示二分图右边顶点的个数
//int m;//m代表边的条数
//int cx[MAXN], cy[MAXN];//如果有cx[i]=j，则必有cy[j]=i，说明i点和j点能够匹配
//int x, y;//x点到y点有边
//int e[MAXN][MAXN];//邻接矩阵
//int visited[MAXN];//标记数组，标记的永远是二分图右边的顶点
//int ret;//最后结果
//int point(int u)//这个函数的作用是寻找增广路和更新cx，xy数组，如果找到了增广路，函数返回1，找不到，函数返回0。
//{
//	for (int v = 1; v <= ny; v++)//依次遍历右边的所有顶点
//	{
//		if (e[u][v] && !visited[v])//条件一：左边的u顶点和右边的v顶点有连通边，条件二：右边的v顶点在没有被访问过，这两个条件必须同时满足
//		{
//			visited[v] = 1;//将v顶点标记为访问过的
//			if (cy[v] == -1 || point(cy[v]))//条件一：右边的v顶点没有左边对应的匹配的点，条件二：以v顶点在左边的匹配点为起点能够找到一条增广路（如果能够到达条件二，说明v顶点在左边一定有对应的匹配点）。
//			{
//				cx[u] = v;//更新cx，cy数组
//				cy[v] = u;
//				return 1;
//			}
//		}
//	}
//	return 0;//如果程序到达了这里，说明对右边所有的顶点都访问完了，没有满足条件的。
//}
//int main()
//{
//	while (cin >> m >> nx >> ny)
//	{
//		memset(cx, -1, sizeof(cx));//初始化cx，cy数组的值为-1
//		memset(cy, -1, sizeof(cy));
//		memset(e, 0, sizeof(e));//初始化邻接矩阵
//		ret = 0;
//		while (m--)//输入边的信息和更新邻接矩阵
//		{
//			cin >> x >> y;
//			e[x][y] = 1;
//		}
//		for (int i = 1; i <= nx; i++)//对二分图左边的所有顶点进行遍历
//		{
//			if (cx[i] == -1)//如果左边的i顶点还没有匹配的点，就对i顶点进行匹配
//			{
//				memset(visited, 0, sizeof(visited));//每次进行point时，都要对visited数组进行初始化
//				ret += point(i);//point函数传入的参数永远是二分图左边的点
//			}
//		}
//		cout << ret << endl;
//	}
//}

//====================================二分图的最大匹配 == 二分图的最小点覆盖===============================


//=====================================================BST树====================================================

//typedef struct bstnode
//{
//	int val;
//	bstnode* left;
//	bstnode* right;
//	bstnode(int v) :val(v)
//	{
//		left = right = nullptr;
//	}
//}bstnode,*bstptr;
//
//
//class bsttree
//{
//public:
//	bstnode* searchBST(bstnode* root, int val)   //该函数的返回值，取决于查询目的，只是为了知道是否存在，可以返回T/F，找到了还要用，可以返回节点。
//	{
//		if (!root)								//节点为空，说明没有，返回null
//			return nullptr;
//		else if (val == root->val)				//值相等，找到
//			return root;
//		else if (val < root->val)				//值<当前节点值，递归查找左子树
//			return searchBST(root->left, val);	//值>当前节点值，递归查找右子树
//		else
//			return searchBST(root->right, val);
//	}
//
//	bool insertBST(bstnode** root, int val)
//	{
//		if (!(*root))							//根节点为空，新建节点。
//		{
//			*root = new bstnode(val);
//			return true;
//		}
//		else if (val == (*root)->val)			//找到，返回F
//			return false;
//		else if (val < (*root)->val)			//值<当前节点值，如果当前节点左子树为空，新建节点。 如果左子树不为空，递归调用左子树。
//		{
//			if (!(*root)->left)
//			{
//				(*root)->left = new bstnode(val);
//				return true;
//			}
//			else
//				return insertBST(&(*root)->left, val);
//		}
//		else                                    //和左子树对称。
//		{
//			if (!(*root)->right)
//			{
//				(*root)->right = new bstnode(val);
//				return true;
//			}
//			else
//				return insertBST(&(*root)->right, val);
//		}
//	}
//
//	bool deletebst(bstnode* root, int val)		//和查找操作基本一样。其实就是找到了这个节点。就删除。
//	{
//		if (!root)
//			return false;
//		else if (val == root->val)
//			return Delete(root);
//		else if (val < root->val)
//			return deletebst(root->left, val);
//		else
//			return deletebst(root->right, val);
//	}
//	bool Delete(bstnode* root)    //已经找到节点了，执行删除操作。三种情况
//	{
//		bstnode* p1;
//		bstnode* p2;
//		if (!root->left)				//左子树为空或者左右子树都为空，都是这种情况。
//		{
//			p1 = root; root = root->right; delete(p1); 
//		}
//		else if (!root->right)          //右子树空，直接让左节点继承。
//		{
//			p1 = root; root = root->left; delete(p1);
//		}
//		else                           //都不为空，找到直接后继节点。此处又有两种可能。
//		{
//			p1 = root;
//			p2 = root->right;
//			while (p2->left)
//			{
//				p1 = p2; p2 = p2->left;
//			}
//			root->val = p2->val;
//			if (p1 == root)
//				p1->right = p2->right;
//			else
//				p1->left = p2->right;
//			delete(p1);
//		}
//		return true;
//	}
//	
//	void release(bstnode* root)          
//	{
//		if (root)
//		{
//			release(root->left);
//			delete(root);
//			release(root->right);
//		}
//	}
//	void mid(bstnode*root,vector<int>& arr)
//	{
//		if (root)
//		{
//			mid(root->left,arr);
//			arr.push_back(root->val);
//			mid(root->right,arr);
//		}
//	}
//};

//=====================================================BST树====================================================


//typedef struct AVLnode
//{
//	int val;
//	AVLnode *left;
//	AVLnode *right;
//	int bf;
//	AVLnode(int v) :val(v), left(nullptr), right(nullptr), bf(0){}
//}AVLnode;
//
//void R_rotate(AVLnode *root)	//root的bt大于0时右旋
//{
//	AVLnode* p1 = root;
//	root = root->left;
//	p1->left = root->right;
//	root->right = p1;
//}
//
//void R_rotate(AVLnode *root)	//root的bt小于0时左旋
//{
//	AVLnode* p1 = root;
//	root = root->right;
//	p1->right = root->left;
//	root->left = p1;
//}
//
//void leftbalance(AVLnode *root)
//{
//
//
//
//}   





//struct MGraph
//{
//	int numpoint, numedge;
//	vector<vector<int>> arr;
//	vector<int> vexdata;
//};
//
//void CreateMGraph(MGraph *G)
//{
//	cin >> G->numpoint >> G->numedge;
//	for (int i = 0; i < G->numpoint; i++)
//		cin >> G->vexdata[i];
//	for (int i = 0; i < G->numpoint; i++)
//	{
//		G->arr.push_back(vector<int>(G->numpoint, -1));
//	}
//	for (int i = 0; i < G->numedge; i++)
//	{
//		int x, y, w;
//		cin >> x >> y >> w;
//		G->arr[x][y] = w;
//		G->arr[y][x] = w;
//	}
//}
//
//
//
//struct Edgenode
//{
//	int index;
//	int weight;
//	Edgenode *next;
//};
//
//struct Vexnode
//{
//	int	 Vexdata;
//	Edgenode *first;
//};
//
//struct LGraph
//{
//	int numpoint, numedge;
//	vector<Vexnode> arr;
//};
//
//void CreateLGraph(LGraph *G)
//{
//	cin >> G->numpoint >> G->numedge;
//	G->arr.resize(G->numpoint);
//	for (int i = 0; i < G->numpoint; i++)
//	{
//		cin >> G->arr[i].Vexdata;
//		G->arr[i].first = nullptr;
//	}
//	for (int i = 0; i < G->numedge; i++)
//	{
//
//
//
//	}
//}






////大数相乘
//string dashu(string s1, string s2)
//{
//	string str1 = s1;
//	string str2 = s2;
//	string res = "";
//	int len1 = str1.size();
//	int len2 = str2.size();
//	int len = len1 + len2;
//	vector<int> v(len2);
//	for (int i = len1 - 1; i >= 0; i--)
//	{
//		for (int j = 0; j<len2; j++)
//		{
//			int num1 = str1[i] - '0';
//			int num2 = str2[j] - '0';
//			v[j] = v[j] + num1*num2;
//		}
//		v.insert(v.begin(), 0);
//	}
//	for (int i = len - 1; i>0; i--){
//		int count = v[i] / 10;
//		int Ncount = v[i] % 10;
//		v[i] = Ncount;
//		v[i - 1] = v[i - 1] + count;
//	}
//
//	for (int i = 0; i<v.size(); i++)
//	{
//		if (v[i] != 0 || i >= 1)
//		{
//			res += to_string(v[i]);
//		}
//	}
//	return res;
//}
//
//int n;
//int main()
//{
//	cin >> n;
//	string down = "1";
//	string up = "0";
//	int k = n;
//	while (k-->1)
//		down = dashu(down, 2);
//	for (int i = 0; i < n; i++)
//	{
//		up = dashu(up, 2);
//		int m = up.size() - 1;
//		up[m] = char(up[m] + 1);
//	}
//	cout << up << "/" << down << endl;
//	system("pause");
//	return 0;
//}



























