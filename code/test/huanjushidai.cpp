//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <set>
//#include <unordered_set>
//#include <stack>
//#include <queue>
//#include <list>
//#include <algorithm>
//#include <functional>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    string s = to_string(n);
//    cout << s << endl;
//    vector<char> bigNum{'S', 'B', 'Q', 'W', 'Y'};
//    int a = pow(2,32);
//    cout << to_string(a) << endl;
//    return 0;
//}
////const int N = 1028;
////const int TOP_NUM = 128;
////vector<vector<int>> solution(const list<int>& list1,const list<int>& list2, const list<int>& list3)
////{
////    vector<vector<int>> res;
////    auto it = list1.begin();
////    vector<int> data1;
////    vector<int> data2;
////    vector<int> data3;
////    while (it != list1.end()) {
////        data1.push_back(*it);
////        ++it;
////    }
////    it = list2.begin();
////    while (it != list2.end()) {
////        data2.push_back(*it);
////        ++it;
////    }
////    it = list3.begin();
////    while (it != list3.end()) {
////        data3.push_back(*it);
////        ++it;
////    }
////    sort(data1.begin(), data1.end(), less<int>());
////    sort(data2.begin(),data2.end(), less<int>());
////    sort(data3.begin(), data3.end(), less<int>());
////    for(int i = 0; i < TOP_NUM; ++i) {
////        res.push_back(vector<int>{data1[i], data2[i],data3[i]});
////    }
////    return res;
////}
////int main()
////{
////    list<int> list1;
////    list<int> list2;
////    list<int> list3;
////    int val;
////    for (int j = 0; j < N; ++j) {
////        cin >> val;
////        list1.push_back(val);
////    }
////    for (int j = 0; j < N; ++j) {
////        cin >> val;
////        list2.push_back(val);
////    }
////    for (int j = 0; j < N; ++j) {
////        cin >> val;
////        list3.push_back(val);
////    }
////    vector<vector<int>> res;
////    res = solution(list1,list2,list3);
////    return 0;
////}
