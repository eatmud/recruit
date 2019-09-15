//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <set>
//#include <unordered_set>
//#include <stack>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
////int main()
////{
////    int n;
////    int m;
////    int val;
////    vector<int> data;
////    int res;
////    cin >> n;
////    cin >> m;
////    while (cin >> val) {
////        data.push_back(val);
////    }
////    sort(data.begin(),data.end());
////    return 0;
////}
//int main()
//{
//    int n;
//    int k;
//    int ms;
//    int me;
//    int val;
//    int idx = 0;
//    vector<int> s;
//    vector<int> e;
//    int res = 0;
//    cin >> n;
//    cin >> k;
//    cin >> ms;
//    cin >> me;
//    while (idx < n) {
//        cin >> val;
//        s.push_back(val);
//        idx++;
//    }
//    while (idx > 0) {
//        cin >> val;
//        e.push_back(val);
//        idx--;
//    }
//    vector<bool> se(n,false);
//    for (int i = 0; i < n; ++i) {
//        res += (s[i] >= e[i]) ? s[i] : e[i];
//        se[i] = (s[i] >= e[i]) ? false : true;
//    }
//    cout << res << endl;
//    for (auto i : se) {
//        if (i) {
//            cout << 'E';
//        } else {
//            cout << 'S';
//        }
//    }
//    cout << endl;
////    for (auto i : s) {
////        cout << i << " ";
////    }
////    cout << endl;
////    for (auto i : e) {
////        cout << i << " ";
////    }
////    cout << endl;
//    return 0;
//}
