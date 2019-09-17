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
//long solution(vector<int>& nums)
//{
//    sort(nums.begin(), nums.end());
//    long long suma = 0;
//    long long sumb = 0;
//    long len = nums.size();
//    vector<int> a(len, 0);
//    vector<int> b(len, 0);
//    long idxa = 0;
//    long idxb = 0;
//    for (auto i = len - 1; i >= 0; --i) {
//        int cur = nums[i];
//        if (abs(suma + cur - sumb) > abs(sumb + cur -suma)) {
//            sumb += cur;
//            b[idxb] = cur;
//            ++idxb;
//        } else {
//            suma += cur;
//            a[idxb] = cur;
//            ++idxa;
//        }
//    }
//    return abs(suma - sumb);
//}
//int main()
//{
//    cin >> n;
//    vector<int> a(n, 0);
//    for (long i = 0; i < n; ++i) {
//         cin >> a[i];
//    }
//    long res = solution(a);
//    cout << res << endl;
//    return 0;
//}
////class Solution {
////public:
////    vector<string> fun(string digits) {
////         table = {
////            {},
////            {},
////            {'a', 'b', 'c'},
////            {'d', 'e', 'f'},
////            {'g', 'h', 'i'},
////            {'j', 'k', 'l'},
////            {'m', 'n', 'o'},
////            {'p', 'q' ,'r', 's'},
////            {'t', 'u', 'v'},
////            {'w', 'x', 'y', 'z'}
////        };
////        if (digits.empty()) {
////            return {};
////        }
////        for (int i = 0; i < digits.length(); ++i) {
////            nums.push_back(digits[i] - '0');
////        }
////
////        for (int i = 0; i < table[nums[0]].size(); ++i) {
////            string s;
////            s.push_back(table[nums[0]][i]);
////            dfs(s, 1);
////        }
////        return res;
////    }
////private:
////    void dfs(string str,int level)
////    {
////        if (level == nums.size()) {
////            res.push_back(str);
////            //cout << str << endl;
////        } else {
////            int i = nums[level];
////            vector<char> s = table[i];
////            for (auto ch : s) {
////                dfs(str + ch, level + 1);
////            }
////        }
////    }
////private:
////    vector<string> res;
////    vector<int> nums;
////    vector<vector<char>> table;
////};
////int main()
////{
////    string str;
////    cin >> str;
////    Solution s;
////    vector<string> res = s.fun(str);
////    sort(res.begin(), res.end());
////    cout << "[";
////    for (int i = 0; i < res.size() - 1; ++i) {
////        cout << res[i] << ", ";
////    }
////    cout << res.back();
////    cout << "]" << endl;
////    return 0;
////}
//
////long solution(vector<int>& a)
////{
////    if (a.size() <= 2) {
////        return a.size();
////    }
////    long res = 2;
////    long len= a.size();
////    vector<vector<int>> dp(len, vector<int>(len, 0));
////    for (long i = 1; i < len; ++i) {
////        for (long j = 0; j < i; ++j) {
////            long step = a[i] - a[j] + 10000;
////            if (dp[j][step] > 0) {
////                dp[i][step] = max(dp[j][step] + 1, dp[i][step]);
////            } else {
////                dp[i][step] = 2;
////            }
////            res = res > dp[i][step] ? res : dp[i][step];
////        }
////    }
////    return res;
////}
////int main()
////{
////    long n;
////    cin >> n;
////    vector<int> a(n, 0);
////    for (long i = 0; i < n; ++i) {
////         cin >> a[i];
////    }
////    long res = solution(a);
////    cout << res << endl;
////    return 0;
////}
