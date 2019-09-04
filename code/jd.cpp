//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <vector>
//#include <string>
//#include <map>
//#include <set>
//
//using namespace std;
//
//int main()
//{
//    int N;
//    cin >> N;
//    int h;
//    multiset<int> heigh;
//    vector<int> backVal(N, 0);
//    vector<int> frontVal(N, 0);
//    while (cin >> h) {
//        heigh.insert(h);
//    }
//    if (heigh.empty()) {
//        cout << 0 << endl;
//        return 0;
//    }
//    backVal[N - 1] = *heigh.end();
//    frontVal[N - 1] = *heigh.begin();
//    for (int i = N -1; i <= 0; i--) {
//
//    }
//    cout << N << endl;
//    for (auto i : heigh) {
//        cout << i << " ";
//    }
//    return 0;
//}
//
//
////#include <iostream>
////#include <algorithm>
////#include <iterator>
////#include <vector>
////#include <string>
////using namespace std;
////
////int main()
////{
////    int N;
////    cin >> N;
////    int h;
////    vector<int> heigh;
////    while (cin >> h) {
////        heigh.push_back(h);
////    }
////    if (heigh.empty()) {
////        cout << 0 << endl;
////        return 0;
////    }
////    cout << N / 2;
////    return 0;
////}
