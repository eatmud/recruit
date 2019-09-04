#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// 两数之和
vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> data;
    vector<int> index;
    int n = 0;
    for (int val : nums) {
        data[val] = n;
        ++n;
    }
    n = 0;
    for (auto val : nums) {
        if (data.find(target - val) != data.end()) {
            if (data[target - val] != n) {
                index.push_back(n);
                index.push_back(data[target - val]);
                return index;
            }
        }
        ++n;
    }
    return index;
}
// 最长连续公共子序列
int longestContinueCommonSubsequence(string & str1, string &str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int longest = 0;
    int longest_index = 0;
    vector<vector<int>>dp(len1,vector<int>(len2,0));
    for (int i = 0; i < len1; i++)
    {
        dp[i][0] = (str1[i] == str1[0]) ? 1 : 0;
    }
    for (int j = 0; j < len2; j++)
    {
        dp[0][j] = (str1[0] == str2[j]) ? 1 : 0;
    }
    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = dp[i - 1][j - 1]+1;
                if (longest < dp[i][j])
                {
                    longest = dp[i][j];
                    longest_index = i;
                }
            }
        }
    }
    for (int i = longest_index - longest + 1; i <= longest; ++i) {
        cout << str1[i];
    }
    cout << endl;
    return longest;
}

// 最长公共子序列
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    int ans = 0;
    for (int i = text1.size() - 1; i >=0; --i) {
        for (int j = text2.size() - 1; j >=0; --j) {
            if (text1[i] == text2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}
// 最长公共子数组
// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
// 输入:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// 输出: 3
// 解释:
// 长度最长的公共子数组是 [3, 2, 1]。
int findLength(vector<int>& A, vector<int>& B)
{
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1,0));
    int ans = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        for (int j = B.size() - 1; j >= 0; --j) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                ans = ans > dp[i][j] ? ans : dp[i][j];
            }
        }
    }
    return ans;
}
// 最长回文字符串
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
int longestPalindrome(string s)
{
    map<char,int> count;
    int ans = 0;
    for (auto ch : s) {
        ++count[ch];
    }
    for (pair<char, int> val : count) {
        ans += (val.second / 2 * 2);
        if (val.second % 2 == 1 && ans % 2 == 0) {
            ++ans;
        }
    }
    return ans;
}
// 5 最长回文子串
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。。
string longestPalindrome5(string s)
{
    int len = s.length();
    if (len <= 1) {
        return s;
    }
    int longestPalindrome = 1;
    string longestPalindromeStr = s.substr(0, 1);
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int r = 1; r < len; r++) {
        for (int l = 0; l < r; l++) {
            if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                dp[l][r] = true;
                if (r - l + 1 > longestPalindrome) {
                    longestPalindrome = r - l + 1;
                    longestPalindromeStr = s.substr(l, longestPalindrome);
                }
            }
        }
    }
    return longestPalindromeStr;
}
// 最长回文子序列
// 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
// 输入:
// "bbbab"
// 输出:
// 4
// 一个可能的最长回文子序列为 "bbbb"。
int longestPalindromeSubseq(string s)
{
    int len = s.length();
    vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
    for (int i = len - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < len; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][len - 1];
}
// 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
// 二叉树遍历
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 中序遍历
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> helper;
    if (root == nullptr) {
        return res;
    }
    TreeNode* cur = root;
    while (cur || !helper.empty()) {
        while (cur) {
            helper.push(cur);
            cur = cur->left;
        }
        cur = helper.top();
        helper.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}
// 前序遍历
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> helper;
    if (root == nullptr) {
        return res;
    }
    TreeNode* cur = root;
    helper.push(cur);
    while (!helper.empty()) {
        cur = helper.top();
        helper.pop();
        res.push_back(cur->val);
        if (cur->right) {
            helper.push(cur->right);
        }
        if (cur->left) {
            helper.push(cur->left);
        }
    }
    return res;
}
// 后序遍历
vector<int> postorderTraversal(TreeNode* root)
{
//     单栈法
    vector<int> res;
    stack<TreeNode*> helper;
    TreeNode* ordered = nullptr;
    TreeNode* cur = root;
    while (cur || !helper.empty()) {
        while (cur) {
            helper.push(cur);
            cur = cur->left;
        }
        cur = helper.top();
        if (cur->right == nullptr || cur->right == ordered) {
            res.push_back(cur->val);
            helper.pop();
            ordered = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
    return res;
    /*
    双栈法
    vector<int> res;
    stack<int> output;
    stack<TreeNode*> helper;
    if (root == nullptr) {
        return res;
    }
    TreeNode* cur = root;
    helper.push(cur);
    while (!helper.empty()) {
        cur = helper.top();
        helper.pop();
        output.push(cur->val);
        if (cur->left) {
            helper.push(cur->left);
        }
        if (cur->right) {
            helper.push(cur->right);
        }
    }
    while (!output.empty()) {
        res.push_back(output.top());
        output.pop();
    }
    return res;
    */
}
// 层次遍历
vector<int> PrintFromTopToBottom(TreeNode* root)
{
    vector<int> res;
    if(root == NULL)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        res.push_back(q.front()->val);
        if(q.front()->left != NULL)
            q.push(q.front()->left);
        if(q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
    }
    return res;
}

int main()
{
    vector<int> data = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(data, target);
    for (auto val : res) {
        cout << val << " ";
    }
    cout << endl;
    cout << "最长连续公共子序列" << endl;
    string x= "acbac";
    string y = "acaccbabb";
    cout << longestContinueCommonSubsequence(x, y) << endl;
    cout << "最长连续公共子序列" << endl;
    cout << "最长回文字符串" << endl;
    string palindrome = "abcdbbfcba";
    cout << longestPalindrome(palindrome) << endl;
    cout << "最长回文字符串" << endl;
    cout << "最长回文子串" << endl;
    cout << longestPalindrome5("abcdbbfcba") << endl;
    cout << "最长回文子串" << endl;
    cout << "接雨水" << endl;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}
