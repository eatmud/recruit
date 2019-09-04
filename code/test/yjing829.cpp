////#include <iostream>
////#include <algorithm>
////#include <iterator>
////#include <vector>
////#include <string>
////
////using namespace std;
////
////int main()
////{
////    vector<int> distance;
////    vector<int> capacity;
////    int maxDistance;
////    string str;
////    getline(cin, str);
////    string temp;
////    int val;
////    for (int i = 0; i < str.length(); ++i) {
////        if (str[i] == ' ') {
////            val = stoi(temp);
////            distance.push_back(val);
////            temp.clear();
////        }
////        temp += str[i];
////    }
////    val = stoi(temp);
////    distance.push_back(val);
////    str.clear();
////    temp.clear();
////    getline(cin, str);
////    for (int i = 0; i < str.length(); ++i) {
////        if (str[i] == ' ') {
////            val = stoi(temp);
////            capacity.push_back(val);
////            temp.clear();
////        }
////        temp += str[i];
////    }
////    val = stoi(temp);
////    capacity.push_back(val);
////    cin >> maxDistance;
////    for (auto j : distance) {
////        cout << j << " ";
////    }
////    cout << endl;
////    for (auto j : capacity) {
////        cout << j << " ";
////    }
////    cout << endl;
////    cout << maxDistance << endl;
////    return 0;
////}
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using  namespace std;
//string s1,s2;
//string tmp = "";
//int temp,D;
//int main()
//{
//    while (getline(cin, s1)){
//    vector<int> v1;
//    for (int i = 0; i < s1.size(); i++){
//        if (i != s1.size() - 1 && s1[i] != ' ')
//        tmp += s1[i];
//        else if (s1[i] == ' '){
//        v1.push_back(stoi(tmp));
//        tmp = "";
//        }
//        else if (i == s1.size() - 1){
//        tmp += s1[i];
//        v1.push_back(stoi(tmp));
//        tmp = "";
//        }
//    }
//    getline(cin, s2);
//    vector<int>v2;
//    for (int i = 0; i < s2.size(); i++){
//        if (i != s2.size() - 1 && s2[i] != ' ')
//            tmp += s2[i];
//            else if (s2[i] == ' '){
//            v2.push_back(stoi(tmp));
//            tmp = "";
//        }
//        else if (i == s2.size() - 1){
//            tmp += s2[i];
//            v2.push_back(stoi(tmp));
//            tmp = "";
//        }
//    }
//    cin >> D;
//    vector<int>dp(D + 1, 0);
//    for (int i = 1; i < v1.size(); i++){
//        for (int j = D; j >= 0; j--){
//            if (j >= v1[i - 1])
//                dp[j] = max(dp[j], dp[j - v1[i - 1]] + v2[i - 1]);
//        }
//    }
//    cout << dp[D] << endl;
//    }
//}
