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
////bool solution(int n)
////{
////    vector<int> v;
////    while (n) {
////        if (n & 1) {
////            v.push_back(1);
////        } else {
////            v.push_back(0);
////        }
////        n = n >> 1;
////    }
////    reverse(v.begin(), v.end());
////    int l = 0;
////    int r = v.size() - 1;
////    while (l < r) {
////        if (v[l] != v[r]) {
////            return false;
////        }
////        l++;
////        r--;
////    }
////    return true;
////}
////int main()
////{
////    int n;
////    vector<int> data;
////    int val;
////    cin >> n;
////    while (cin >> val) {
////        data.push_back(val);
////    }
////    for (auto i : data) {
////        if (solution(i)) {
////            cout << "YES" << endl;
////        } else {
////            cout << "NO" << endl;
////        }
////    }
////    return 0;
////}
////struct TreeNode {
////  int val;
////  TreeNode *left;
////  TreeNode *right;
////  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
////};
////int main()
////{
////    int n,m,k,t,val;
////    int v,l,r;
////    while (cin >> t) {
////        for (int tt = 0; tt < t; ++tt) {
////            map<int, TreeNode*> map;
////            cin >> n;
////            for (int j = 0; j < n; ++j) {
////                map[j] = new TreeNode(0);
////            }
////            vector<int> father(n,0);
////            for (int i = 0; i < father.size(); ++i) {
////                father[i] = i;
////            }
////            for (int i = 0; i < n; ++i) {
////                cin >> v >> l >> r;
////                if (l != -1) {
////                    father[l] = i;
////                    map[i]->left = map[l];
////                }
////                if (r != -1) {
////                    father[r] = i;
////                    map[i]->right = map[r];
////                }
////                map[i]->val = v;
////            }
////            int index = 0;
////            for (int i = 0; i < father.size(); ++i) {
////                if (father[i] == i) {
////                    index = i;
////                }
////            }
////            TreeNode* root = map[index];
////            queue<TreeNode*> q;
////            q.push(root);
////            int len = 1;
////            TreeNode* temp = nullptr;
////            int pre = -100000;
////            int res = 0;
////            bool flag = true;
////            while (!q.empty()) {
////                temp = q.front();
////                q.pop();
////                res += temp->val;
////                if (temp->left) {
////                    q.push(temp->left);
////                }
////                if (temp->right) {
////                    q.push(temp->right);
////                }
////                len--;
////                if (len == 0) {
////                    len = q.size();
////                    if (res <= pre) {
////                        flag = false;
////                        break;
////                    }
////                    pre = res;
////                    res = 0;
////                }
////            }
////            if (flag) {
////                cout << "YES" << endl;
////            } else {
////                cout << "NO" << endl;
////            }
////        }
////
////    }
////    return 0;
////}
//
////int main()
////{
////    int k, m, t,val;
////    cin >> t;
////    for (int i = 0; i < t; i++) {
////        cin >> k >> m;
////        vector<int> data;
////        vector<int> dp(31, 0);
////        for (int i = 0; i < m; ++i) {
////            cin >> val;
////            data.push_back(val);
////            dp[val] = 1;
////        }
////        int res = m;
////        for (int i = 1; i <= 30; ++i) {
////            if (dp[i] == 0) {
////                bool f = true;
////                int l = i, r = i;
////                int j = k;
////                while (j >= 0) {
////                    if (l >= 1 && l <=30 && dp[l] == 1){
////                        f = false;
////                    }
////                    if (r >= 1 && r <=30 && dp[r] == 1){
////                        f = false;
////                    }
////                    if (l >= 2) {
////                        l--;
////                    }
////                    if (r <= 29) {
////                        r++;
////                    }
////                    j--;
////                }
////                if (f) {
////                    dp[i] = 1;
////                    res++;
////                }
////            }
////        }
////        cout <<
// << endl;
////    }
////    return 0;
////}
