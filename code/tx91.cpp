//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int n;
//    int m;
//    int res = 0;
//    vector<int> a;
//    map<int,int> b;
//    cin >> n;
//    cin >> m;
//    cin.get();
//    string s;
//    string str;
//    int val;
//    getline(cin, s);
//    s += '\n';
//    for (int i = 0; i < s.length(); ++i) {
//        if (s[i] == ' ' || s[i] == '\n') {
//            val = stoi(str);
//            a.push_back(val);
//            str.clear();
//        }
//        str += s[i];
//    }
////    val = stoi(str);
////    a.push_back(val);
//    str.clear();
//    s.clear();
//    getline(cin, s);
//    s += '\n';
//    for (int i = 0; i < s.length(); ++i) {
//        if (s[i] == ' ' || s[i] == '\n') {
//            val = stoi(str);
//            ++b[val];
//            str.clear();
//        }
//        str += s[i];
//    }
//    str.clear();
//    s.clear();
//    for (auto index : a) {
//        for (auto key : b) {
//            if ((index + key.first) % 2 ==1 && key.second > 0) {
//                key.second--;
//                res++;
//            }
//        }
//    }
//    cout << res << endl;
//    return res;
////    cout << n << " " << m << endl;
////    for (auto i : a) {
////        cout << i << " ";
////    }
////    cout << endl;
////    for (auto i : b) {
////        cout << i.first << " " << i.second << endl;
////    }
//    return 0;
//}
