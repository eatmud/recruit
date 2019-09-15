//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//class A
//{
//public:
////    A()
////    {
////        cout << "a" << endl;
////    }
//     virtual void print() { cout<<"A.."<<endl; }
//};
//class B : public A
//{
//public:
//     virtual void print() { cout<<"B.."<<endl; }
//};
//
//class C : public B
//{
//public:
//     virtual void print() { cout<<"C.."<<endl; }
//};
//struct xx {
////    long long x1;
////    char x2;
////    int x3;
//    char x4[2];
////    int x6;
//    static int x5;
//};
//int xx::x5 = 0;
//int main()
//{
//    xx x;
////    cout << &x << endl;
////    printf("%p\n",&(x.x1));
////    printf("%p\n",&(x.x2));
////    cout << &(x.x3) << endl;
//    cout << &(x.x4) << endl;
////    //cout << &(x.x5) << endl;
////    printf("%p\n",&(x.x6));
//    cout << sizeof(xx) << endl;
//         C c1;
//         c1.print();
//         A &a1 = c1;
//         a1.print(); // prints C
//         A a2 = c1;
//         a2.print(); // prints A
//         return 0;
//
//}
//////int StrToInt(string str) {
//////        if(str.empty()) return 0;
//////        string resTmp;
//////        int res = 0;
//////        int n = 1;
//////        int resTmpLength;
//////        int i = 0;
//////        int symb = 0;
//////        if(str[0] == '+')
//////        {
//////            i = 1;
//////        }
//////        if(str[0] == '-')
//////        {
//////            i = 1;
//////            symb = -1;
//////        }
//////        for(;i < str.length();++i)
//////        {
//////            if( '0' <= str[i] && str[i] <= '9')
//////                resTmp += str[i];
//////            else
//////                return 0;
//////        }
//////        cout << resTmp << endl;
//////        resTmpLength = resTmp.length();
//////        for(i = resTmpLength - 1;i >= 0;--i)
//////        {
//////            int n1 = (resTmp[i] - '0');
//////            int np = resTmpLength - i - 1;
//////            int n2 = pow(10,np);
//////            res += (n1*n2);
//////            //res += (str[i] - '0')*pow(10,resTmpLength - i + 1);
//////            //cout << resTmp[i] << " " << n1 << " " << n2 << " " << np << " " << " " << res << endl;
//////        }
//////        return (symb == -1)?(-res):res;
//////    }
//////
//////struct TreeNode {
//////    int val;
//////    struct TreeNode *left;
//////    struct TreeNode *right;
//////    TreeNode(int x) :
//////            val(x), left(NULL), right(NULL) {
//////    }
//////};
//////
//////class Solution {
//////public:
//////    char* Serialize(TreeNode *root) {
//////        if(!root) return nullptr;
//////        string str;
//////        preOrder(root,str);
//////        int strLen = str.length();
//////        char* res = new char[strLen+1];
//////        int i = 0;
//////        for(;i < strLen;++i){
//////            res[i] = str[i];
//////        }
//////        res[i] = '\0';
//////        return res;
//////    }
//////    void preOrder(TreeNode *root,string &str){
//////        if(!root){
//////            str += '#';
//////            return;
//////        }
//////        str += to_string(root->val);
//////        str += ',';
//////        preOrder(root->left,str);
//////        preOrder(root->right,str);
//////    }
//////    TreeNode* Deserialize(char *str) {
//////        if(!str || *str == '\0') return nullptr;
//////        TreeNode* res = Deserialize(&str);
//////        return res;
//////    }
//////    TreeNode* Deserialize(char **str){
//////        if(**str == '#'){
//////            ++(*str);
//////            return nullptr;
//////        }
//////        int num = 0;
//////        while((**str)!= ',' && (**str) != '\0'){
//////            num += (num *10 + (**str - '0'));
//////            ++(*str);
//////        }
//////        TreeNode* root = new TreeNode(num);
//////        if((**str) == '\0'){
//////            return root;
//////        }else{
//////            ++(*str);
//////        }
//////        root->left = Deserialize(str);
//////        root->right = Deserialize(str);
//////        return root;
//////    }
//////};
//////int main()
//////{
////////    cout << "Hello world!" << endl;
//////////    vector<vector<int> > temp(2,vector<int>(2,0));
//////////    for(int i = 0;i < 2;++i)
//////////    {
//////////        cout << temp[i][0] << " " << temp[i][1] << endl;
//////////    }
////////    string s = "+1a3";
////////    cout << StrToInt(s) << endl;
////////    //cout << pow(10,2) << endl;
//////    char* str = "1,2,3";
//////    Solution a;
//////    TreeNode* res;
//////    res = a.Deserialize(str);
//////    char* s = a.Serialize(res);
//////    return 0;
//////}
////
////#include <iostream>
////using namespace std;
////class Base1 {
////private :
////    int a;
////};
////class Base2 {
////private:
////    int b;
////};
////class Derived:
////    public virtual Base1, public virtual Base2 {
////public:
////    virtual void fun1() {}
////private:
////    int c;
////};
////class DeleteTest {
////public:
////    int* newSpace()
////    {
////        a = static_cast<int*> (malloc(sizeof(int)));
////        *a = 1;
////        cout << "malloc a, a adress : " << a << ", a: " << *a << endl;
////        return a;
////    };
////    void delSpace()
////    {
////        free(a);
////        cout << "free a, a adress : " << a << ", a: " << *a << endl;
////        a = nullptr;
////    };
////public:
////    int* a;
////};
////
////int main()
////{
////    DeleteTest* test = new DeleteTest;
////    int* add = test->newSpace();
////    test->delSpace();
////    delete test;
////    *add = 2;
////    cout << "add : " << add << ", *add : " << *add << endl;
////    cout << "delete DeleteTest, DeleteTest adress : " << test << ", a: " << *(test->a) << endl;
//////    cout << sizeof(Base1) << endl;
//////    cout << sizeof(Base2) << endl;
//////    cout << sizeof(Derived) << endl;
////    return 0;
////}
////#include <algorithm>
////#include <iostream>
////#include <vector>
////#include <numeric>
////#include <iterator>
////#include <iomanip>
////using namespace std;
////vector<float> solution(const vector<int>& data,int k)
////{
////    vector<float> res;
////    if (k <= 0 || k > data.size() || data.empty()) {
////        return res;
////    }
////
////    auto it = data.begin();
////    while (it != data.end()) {
////        float sum = 0.00;
////        if (it + k <= data.end()) {
////            sum = accumulate(it, it + k, 0) / k;
////            res.push_back(sum);
////        } else {
////            break;
////        }
////        ++it;
////    }
////    return res;
////}
////int main()
////{
////    vector<int> data;
////    vector<float> res;
////    int val;
////    while(cin >> val) {
////        data.push_back(val);
////    }
////    int k = data.back();
////    data.pop_back();
////    res = solution(data, k);
////    cout.setf(ios::fixed);
////    for (auto i : res) {
////        cout << fixed << setprecision(2) << i << " ";
////    }
////    cout << endl;
////    return 0;
////}
