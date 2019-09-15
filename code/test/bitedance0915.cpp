//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <set>
//#include <unordered_set>
//#include <stack>
//#include <queue>
//#include <algorithm>
//#include <iterator>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    multimap<int, int> data;
//    for (int i = 0; i < n; ++i) {
//        int a;
//        int b;
//        cin >> a;
//        cin >> b;
//        data.insert(make_pair(a, b));
//    }
//    int time = 0;
//    int nums = 0;
//    auto iter = data.begin();
//    while (iter != data.end()) {
//        int beginTime = time;
//        int start = iter->first;
//        int num = iter->second;
//        if (time < start) {
//            time = start;
//        }
//        time += num;
//        int numTemp = 1;
//
//        for (int j = beginTime; j <= time; ++j) {
//            auto it = data.equal_range(j);
//            while (it.first != it.second) {
//                numTemp += it.first->second - 1;
//                ++it.first;
//            }
//            nums = nums > numTemp ? nums : numTemp;
//        }
//        ++iter;
//    }
//    cout << time << " " << nums << endl;
////    vector<vector<int>> data(n, vector<int>(2));
////    for (int i = 0; i < n; ++i) {
////        cin >> data[i][0];
////        cin >> data[i][1];
////    }
////    int time = 0;
////    for (int i = 0; i < n; ++i) {
////        int beginTime = time;
////        int start = data[i][0];
////        int num = data[i][1];
////        if (time < start) {
////            time = start;
////        }
////        time += num;
////        for (int j = beginTime; j <= time; ++j) {
////
////        }
////    }
////    cout << time << endl;
////    for (auto i : data) {
////        for (auto j : i) {
////            cout << j << " ";
////        }
////        cout << endl;
////    }
//    return 0;
//}
//
////int main()
////{
////    int n;
////    cin >> n;
////    vector<int> arr(n + 1,0);
////    vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
////    vector<int> sum(n + 1,0);
////    for (int i = 1; i <= n; ++i) {
////        cin >> arr[i];
////        dp[i][i] = arr[i];
////        sum[i] = sum[i - 1] + arr[i];
////    }
////    for (int i = n - 1; i > 0; --i) {
////        for (int j = i; j <= n; ++j) {
////            dp[i][j] = sum[j] - sum[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
////        }
////    }
////    cout << dp[1][n] << sum[n] - dp[1][n] << endl;
////    return 0;
////}
////struct work {
////    int deadline;
////    int time;
////};
////void cmp(work& a, work& b)
////{
////    return (a.deadline + a.time) < (b.deadline + b.time);
////}
////
////int main()
////{
////    int n;
////    cin >> n;
////    vector<work> data;
////    work temp;
////    while (n > 0) {
////        cin >> temp.deadline;
////        cin >> temp.time;
////        data.push_back(temp);
////        n--;
////    }
////    sort(data.begin(), data.end(),cmp);
////    return 0;
////}
