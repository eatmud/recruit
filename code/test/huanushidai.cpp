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
////string solution(string & str1, string &str2)
////{
////    int len1 = str1.length();
////    int len2 = str2.length();
////    int longest = 0;
////    int longest_index = 0;
////    string res;
////    vector<vector<int>> dp(len1,vector<int>(len2,0));
////    for (int i = 0; i < len1; i++)
////    {
////        dp[i][0] = (str1[i] == str1[0]) ? 1 : 0;
////    }
////    for (int j = 0; j < len2; j++)
////    {
////        dp[0][j] = (str1[0] == str2[j]) ? 1 : 0;
////    }
////    for (int i = 1; i < len1; i++)
////    {
////        for (int j = 1; j < len2; j++)
////        {
////            if (str1[i] == str2[j])
////            {
////                dp[i][j] = dp[i - 1][j - 1]+1;
//////                if (longest < dp[i][j])
//////                {
//////                    longest = dp[i][j];
//////                    longest_index = i;
//////                }
////            }
////        }
////    }
////    for (int i = 0; i < len1; ++i) {
////        for (int j = 0; j < len2; ++j) {
////            if (longest < dp[i][j])
////                {
////                    longest = dp[i][j];
////                    longest_index = i;
////                }
////        }
////    }
////    for (int i = longest_index - longest + 1; i <= longest; ++i) {
////       res += str1[i];
////    }
////    return res;
////}
////int main()
////{
////    string s1;
////    string s2;
////    getline(cin, s1);
////    getline(cin,s2);
////    string res = solution(s1, s2);
////    cout << res << endl;
////    return 0;
////}
//
//
//int main()
//{
//    int n;
//    int m;
//    int val;
//    vector<vector<int>> data;
//    cin >> n;
//    cin >> m;
//    for (int i = 0; i < n; ++i) {
//        vector<int> line;
//        for (int j = 0; j < m; ++j) {
//            cin >> val;
//            line.push_back(val);
//        }
//        data.push_back(line);
//    }
//    vector<vector<int>> dp(n,vector<int>(m,0));
//    vector<vector<pair<int,int>>> mark(n, vector<pair<int,int>>(m));
//    for (int i = 1; i < n; ++i) {
//        dp[i][0] = dp[i - 1][0] + data[i][0];
//        mark[i][0] = make_pair(i - 1, 0);
//    }
//    for (int i = 1; i < m; ++i) {
//        dp[0][i] = dp[0][i - 1] + data[0][i - 1];
//        mark[0][i] = make_pair(0, i  -1);
//    }
//    for (int i = 1; i < n; ++i) {
//        for (int j = 1; j < m; ++j) {
//            dp[i][j] = min(dp[i][j - 1] + data[i][j], dp[i - 1][j]);
//            if (dp[i][j - 1] <= dp[i - 1][j]) {
//                mark[i][j] = make_pair(i, j - 1);
//            } else {
//                mark[i][j] = make_pair(i - 1, j);
//            }
//        }
//    }
//    stack<pair<int, int>> p;
//    pair<int,int> s = make_pair(n - 1,m - 1);
//    while (s.first || s.second) {
//        p.push(s);
//        s = mark[s.first][s.second];
//    }
//    p.push(s);
//    while (!p.empty()) {
//        cout << p.top().first << " " << p.top().second << endl;
//        p.pop();
//    }
//    return 0;
//}
