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
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//struct TreeNode {
//  int val;
//  TreeNode *left;
//  TreeNode *right;
//  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//// 两数之和
//vector<int> twoSum(vector<int>& nums, int target)
//{
//    map<int, int> data;
//    vector<int> index;
//    int n = 0;
//    for (int val : nums) {
//        data[val] = n;
//        ++n;
//    }
//    n = 0;
//    for (auto val : nums) {
//        if (data.find(target - val) != data.end()) {
//            if (data[target - val] != n) {
//                index.push_back(n);
//                index.push_back(data[target - val]);
//                return index;
//            }
//        }
//        ++n;
//    }
//    return index;
//}
//// 两数之和
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//    if (l1 == nullptr || l2 == nullptr) {
//        return nullptr;
//    }
//    ListNode* res= new ListNode(0);
//    ListNode* curNode = res;
//    ListNode* p1 = l1;
//    ListNode* p2 = l2;
//    int carry = 0;
//    while (p1 || p2) {
//        int num1 = p1 ? p1->val : 0;
//        int num2 = p2 ? p2->val : 0;
//        int sum = num1 + num2 + carry;
//        carry = sum / 10;
//       // curNode->val = sum % 10;
//        curNode->next = new ListNode(sum % 10);
//        curNode = curNode->next;
//        if (p1) {
//            p1 = p1->next;
//        }
//        if (p2) {
//            p2 = p2->next;
//        }
//    }
//    if (carry == 1) {
//        curNode->next = new ListNode(1);
//    }
//    return res->next;
//}
//// 三数之和
//vector<vector<int>> threeSum(vector<int>& nums)
//{
//    sort(nums.begin(), nums.end());
//    if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
//        return {};
//    }
//    vector<vector<int>> res;
//    for (int i = 0; i < nums.size(); i++)
//    {
//        int fix = nums[i];
//        if (fix > 0) {
//            break;
//        }
//        if (i > 0 && fix == nums[i-1]) {
//            continue;
//        }
//        int l = i + 1;
//        int r = nums.size() - 1;
//        while (l < r) {
//            if (nums[l]+nums[r]==-fix) {
//                if (l == i + 1 || r == nums.size() - 1) {
//                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
//                    l++;
//                    r--;
//                } else if (nums[l] == nums[l-1]) {
//                    l++;
//                } else if (nums[r] == nums[r+1]) {
//                    r--;
//                } else {
//                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
//                    l++;
//                    r--;
//                }
//            } else if (nums[l] + nums[r] < -fix) {
//                l++;
//            }  else {
//                r--;
//            }
//        }
//    }
//    return res;
//}
//// 最长连续公共子序列
//int longestContinueCommonSubsequence(string & str1, string &str2)
//{
//    int len1 = str1.length();
//    int len2 = str2.length();
//    int longest = 0;
//    int longest_index = 0;
//    vector<vector<int>>dp(len1,vector<int>(len2,0));
//    for (int i = 0; i < len1; i++)
//    {
//        dp[i][0] = (str1[i] == str1[0]) ? 1 : 0;
//    }
//    for (int j = 0; j < len2; j++)
//    {
//        dp[0][j] = (str1[0] == str2[j]) ? 1 : 0;
//    }
//    for (int i = 1; i < len1; i++)
//    {
//        for (int j = 1; j < len2; j++)
//        {
//            if (str1[i] == str2[j])
//            {
//                dp[i][j] = dp[i - 1][j - 1]+1;
//            }
//            if (longest < dp[i][j])
//            {
//                longest = dp[i][j];
//                longest_index = i;
//            }
//        }
//    }
//    string s = str1.substr(longest_index - longest + 1,longest);
////    for (int i = longest_index - longest + 1; i <= longest; ++i) {
////        cout << str1[i];
////    }
//    cout << s << endl;
//    cout << longest_index << endl;
//    return longest;
//}
//
//// 最长公共子序列
//int longestCommonSubsequence(string text1, string text2)
//{
//    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
//    for (int i = text1.size() - 1; i >=0; --i) {
//        for (int j = text2.size() - 1; j >=0; --j) {
//            if (text1[i] == text2[j]) {
//                dp[i][j] = dp[i + 1][j + 1] + 1;
//            } else {
//                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
//            }
//        }
//    }
//    int i = 0;
//    int j = 0;
//    string s;
////    vector<int> index;
//    while (dp[i][j]) {
//        if(dp[i][j]==dp[i + 1][j]){
//            i++; //  下
//        } else if(dp[i][j]==dp[i][j+1]){
//            j++; //  右
//        } else if(dp[i][j]>dp[i + 1][j + 1]){
//            i++;
//            j++;
//            s += text1[i]; // 右下
//        }
//    }
//    cout << s << endl;
//    return dp[0][0];
//}
//// 最长公共子数组
//// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
//// 输入:nullptr
//// A: [1,2,3,2,1]
//// B: [3,2,1,4,7]
//// 输出: 3
//// 解释:
//// 长度最长的公共子数组是 [3, 2, 1]。
//int findLength(vector<int>& A, vector<int>& B)
//{
//    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1,0));
//    int ans = 0;
//    for (int i = A.size() - 1; i >= 0; --i) {
//        for (int j = B.size() - 1; j >= 0; --j) {
//            if (A[i] == B[j]) {
//                dp[i][j] = dp[i + 1][j + 1] + 1;
//                ans = ans > dp[i][j] ? ans : dp[i][j];
//            }
//        }
//    }
//    return ans;
//}
//// 最长上升子序列
//// 给定一个无序的整数数组，找到其中最长上升子序列的长度。
//// 示例:
//// 输入: [10,9,2,5,3,7,101,18]
//// 输出: 4
//// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
//int lengthOfLIS(vector<int>& nums) {
//    // 动态规划 + 二分查找
//     if (nums.size() <= 1) {
//        return nums.size();
//    }
//    int len = nums.size();
//    vector<int> help(len, 0);
//    int res = 0;
//    for (int val : nums) {
//        int i = 0;
//        int j = res;
//        while (i < j) {
//            int m = (i + j) / 2;
//            if (help[m] < val) {
//                i = m + 1;
//            } else {
//                j = m;
//            }
//        }
//        help[i] = val;
//        res = max(res, i + 1);
//    }
//    return res;
//    /*
//    // 动态规划
//    if (nums.size() <= 1) {
//        return nums.size();
//    }
//    int len = nums.size();
//    vector<int> dp(len, 0);
//    int res = 1;
//    int maxVal = 0;
//    dp[0] = 1;
//    for (int i = 1; i < len; ++i) {
//        maxVal = 0;
//        for (int j = 0; j < i; ++j) {
//            if (nums[i] > nums[j]) {
//                maxVal = max(maxVal, dp[j]);
//            }
//        }
//        dp[i] = maxVal + 1;
//        res = max(res, dp[i]);
//    }
//   return res;
//   */
//}
////  最长连续递增序列
//// 给定一个未经排序的整数数组，找到最长且连续的的递增序列。
//// 示例 1:
//// 输入: [1,3,5,4,7]
//// 输出: 3
//// 解释: 最长连续递增序列是 [1,3,5], 长度为3。
//// 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
//int findLengthOfLCIS(vector<int>& nums) {
//    if (nums.size() <= 1) {
//        return nums.size();
//    }
//    size_t res = 1;
//    size_t num = 1;
//    for (size_t i = 1; i < nums.size(); ++i) {
//        if (nums[i] > nums[i - 1]) {
//            ++num;
//        } else {
//            num = 1;
//        }
//        res = num > res ? num : res;
//    }
//    return res;
//}
//// 最长回文字符串
//// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//// 输入: "babad"
//// 输出: "bab"
//// 注意: "aba" 也是一个有效答案。
//int longestPalindrome(string s)
//{
//    map<char,int> count;
//    int ans = 0;
//    for (auto ch : s) {
//        ++count[ch];
//    }
//    for (pair<char, int> val : count) {
//        ans += (val.second / 2 * 2);
//        if (val.second % 2 == 1 && ans % 2 == 0) {
//            ++ans;
//        }
//    }
//    return ans;
//}
//// 5 最长回文子串
//// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//// 示例 1：
//// 输入: "babad"
//// 输出: "bab"
//// 注意: "aba" 也是一个有效答案。。
//string longestPalindrome5(string s)
//{
//    int len = s.length();
//    if (len <= 1) {
//        return s;
//    }
//    int longestPalindrome = 1;
//    string longestPalindromeStr = s.substr(0, 1);
//    vector<vector<bool>> dp(len, vector<bool>(len, false));
//    for (int r = 1; r < len; r++) {
//        for (int l = 0; l < r; l++) {
//            if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
//                dp[l][r] = true;
//                if (r - l + 1 > longestPalindrome) {
//                    longestPalindrome = r - l + 1;
//                    longestPalindromeStr = s.substr(l, longestPalindrome);
//                }
//            }
//        }
//    }
//    return longestPalindromeStr;
//}
//// 最长回文子序列
//// 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
//// 输入:
//// "bbbab"
//// 输出:
//// 4
//// 一个可能的最长回文子序列为 "bbbb"。
//int longestPalindromeSubseq(string s)
//{
//    int len = s.length();
//    vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
//    for (int i = len - 1; i >= 0; --i) {
//        dp[i][i] = 1;
//        for (int j = i + 1; j < len; ++j) {
//            if (s[i] == s[j]) {
//                dp[i][j] = dp[i + 1][j - 1] + 2;
//            } else {
//                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//            }
//        }
//    }
//    return dp[0][len - 1];
//}
//// 最长无重复子串
//// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//// 示例 1:
//// 输入: "abcabcbb"
//// 输出: 3
//// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//int lengthOfLongestSubstring(string s)
//{
//    if (s.length() <= 1) {
//        return s.length();
//    }
//    unordered_set<char> str;
//    int res = 1;
//    int num = 0;
//    size_t i = 0;
//    size_t j = 0;
//    while (i < s.length() && j < s.length()) {
//        if (str.find(s[j]) == str.end()) {
//            str.insert(s[j]);
//            ++j;
//            num = j - i;
//            res = res > num ? res : num;
//        } else {
//            str.erase(s[i]);
//            ++i;
//        }
//    }
//    return res;
//}
//// LeetCode 11
//// 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
//// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//// 说明：你不能倾斜容器，且 n 的值至少为 2。
//// 输入: [1,8,6,2,5,4,8,3,7]
//// 输出: 49
//int maxArea(vector<int>& height) {
//    //双指针法
//    int len = height.size();
//    if (len < 2) {
//        return 0;
//    }
//    int res = 0;
//    int left = 0;
//    int right = len - 1;
//    while (left < right) {
//        int h = min(height[right],height[left]);
//        int d = (right - left);
//        res = max(res, d * h);
//        if (height[left] < height[right]) {
//            ++left;
//        } else {
//            --right;
//        }
//    }
//    return res;
//}
//// LeetCode 17
//// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//class Solution {
//public:
//    vector<string> letterCombinations(string digits) {
//         table = {
//            {},
//            {},
//            {'a', 'b', 'c'},
//            {'d', 'e', 'f'},
//            {'g', 'h', 'i'},
//            {'j', 'k', 'l'},
//            {'m', 'n', 'o'},
//            {'p', 'q' ,'r', 's'},
//            {'t', 'u', 'v'},
//            {'w', 'x', 'y', 'z'}
//        };
//        if (digits.empty()) {
//            return {};
//        }
//        for (int i = 0; i < digits.length(); ++i) {
//            nums.push_back(digits[i] - '0');
//        }
//
//        for (int i = 0; i < table[nums[0]].size(); ++i) {
//            string s;
//            s.push_back(table[nums[0]][i]);
//            dfs(s, 1);
//        }
//        return res;
//    }
//private:
//    void dfs(string str,int level)
//    {
//        if (level == nums.size()) {
//            res.push_back(str);
//            //cout << str << endl;
//        } else {
//            int i = nums[level];
//            vector<char> s = table[i];
//            for (auto ch : s) {
//                dfs(str + ch, level + 1);
//            }
//        }
//    }
//private:
//    vector<string> res;
//    vector<int> nums;
//    vector<vector<char>> table;
//};
//// LeetCode 20
//// 有效括号匹配
//bool isValid(string s)
//{
//    if (s.empty()) {
//        return true;
//    }
//    stack<char> p;
//    for (auto ch : s) {
//        if (p.empty() && (ch == ')' || ch == ']' || ch == '}')) {
//            return false;
//        }
//        if (ch == '(' || ch == '[' || ch == '{') {
//            p.push(ch);
//        } else {
//            if (ch == ')' && p.top() != '(') {
//                return false;
//            } else if (ch == ']' && p.top() != '[') {
//                return false;
//            } else if (ch == '}' && p.top() != '{') {
//                return false;
//            } else {
//                p.pop();
//            }
//            /*
//            if (ch - p.top() == 1 || ch - p.top() == 2) { //ascii,{}和[]左右括号相差2，()相差1
//                p.pop();
//            } else {
//                return false;
//            }
//            */
//        }
//    }
//    return p.empty();
//}
//// LeetCode 21
//// 合并两个有序链表
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//    if (l1 == nullptr) {
//        return l2;
//    } else if (l2 == nullptr) {
//        return l1;
//    } else {
//        if (l1->val <= l2->val) {
//            l1->next = mergeTwoLists(l1->next, l2);
//            return l1;
//        } else {
//            l2->next = mergeTwoLists(l1, l2->next);
//            return l2;
//        }
//    }
//   /*
//    ListNode*  res = new ListNode(-1);
//    ListNode* cur = res;
//    while (l1 != nullptr && l2 != nullptr) {
//        if (l1->val <= l2->val) {
//            cur->next = l1;
//            l1 = l1->next;
//        } else {
//            cur->next = l2;
//            l2 = l2->next;
//        }
//        cur = cur->next;
//    }
//    cur->next = (l1 == nullptr) ? l2 : l1;
//    return res->next;
//    */
//}
//// leetCode 22
//// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
///*
//    回溯算法基本思想：能进则进，进不了则换，换不了则退
//    括号生成算法类似于二叉树先序遍历
//    可用递归生成问题解空间树
//    再用剪枝函数来对解空间树进行剪枝
//
//    括号生成:
//    进入左子树条件： ( 括号小于 n
//    进入右子树条件： ） 括号小于 （ 括号
//    */
//void backTrace(vector<string>& res, string cur, int close, int open, int max)
//{
//    if (cur.length() == max * 2) {
//        res.push_back(cur);
//        return;
//    }
//    if (open < max) {
//        backTrace(res, cur + '(', close, open + 1, max);
//    }
//    if (close < open) {
//        backTrace(res, cur + ')', close + 1, open, max);
//    }
//}
//vector<string> generateParenthesis(int n)
//{
//    vector<string> res;
//    backTrace(res, "", 0, 0, n);
//    return res;
//}
//// leetcode 31
////实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
////
////如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
////
////必须原地修改，只允许使用额外常数空间。
////
////以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
////1,2,3 → 1,3,2
////3,2,1 → 1,2,3
////1,1,5 → 1,5,1。
//void nextPermutation(vector<int>& nums)
//{
//    int i = nums.size() - 2;
//    int j = nums.size() - 1;
//    while (i >= 0 && nums[i + 1] <= nums[i]) {
//        i--;
//    }
//    if (i >= 0) {
//        while (j >= 0 && nums[j] <= nums[i]) {
//            j--;
//        }
//        swap(nums[i], nums[j]);
//    }
//    reverse(nums.begin() + i + 1,nums.end());
//}
//// 接雨水
//// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//// 输出: 6
//int trap(vector<int>& height)
//{
//    int ans = 0;
//    size_t current = 0;
//    stack<int> st;
//    while (current < height.size()) {
//        while (!st.empty() && height[current] > height[st.top()]) {
//            int top = st.top();
//            st.pop();
//            if (st.empty())
//                break;
//            int distance = current - st.top() - 1;
//            int bounded_height = min(height[current], height[st.top()]) - height[top];
//            ans += distance * bounded_height;
//        }
//        st.push(current++);
//    }
//    return ans;
//}
//// 二叉树遍历
//// 中序遍历
//vector<int> inorderTraversal(TreeNode* root)
//{
//    vector<int> res;
//    stack<TreeNode*> helper;
//    if (root == nullptr) {
//        return res;
//    }
//    TreeNode* cur = root;
//    while (cur || !helper.empty()) {
//        while (cur) {
//            helper.push(cur);
//            cur = cur->left;
//        }
//        cur = helper.top();
//        helper.pop();
//        res.push_back(cur->val);
//        cur = cur->right;
//    }
//    return res;
//}
//// 前序遍历
//vector<int> preorderTraversal(TreeNode* root)
//{
//    vector<int> res;
//    stack<TreeNode*> helper;
//    if (root == nullptr) {
//        return res;
//    }
//    TreeNode* cur = root;
//    helper.push(cur);
//    while (!helper.empty()) {
//        cur = helper.top();
//        helper.pop();
//        res.push_back(cur->val);
//        if (cur->right) {
//            helper.push(cur->right);
//        }
//        if (cur->left) {
//            helper.push(cur->left);
//        }
//    }
//    return res;
//}
//// 后序遍历
//vector<int> postorderTraversal(TreeNode* root)
//{
////     单栈法
//    vector<int> res;
//    stack<TreeNode*> helper;
//    TreeNode* ordered = nullptr;
//    TreeNode* cur = root;
//    while (cur || !helper.empty()) {
//        while (cur) {
//            helper.push(cur);
//            cur = cur->left;
//        }
//        cur = helper.top();
//        if (cur->right == nullptr || cur->right == ordered) {
//            res.push_back(cur->val);
//            helper.pop();
//            ordered = cur;
//            cur = nullptr;
//        } else {
//            cur = cur->right;
//        }
//    }
//    return res;
//    /*
//    双栈法
//    vector<int> res;
//    stack<int> output;
//    stack<TreeNode*> helper;
//    if (root == nullptr) {
//        return res;
//    }
//    TreeNode* cur = root;
//    helper.push(cur);
//    while (!helper.empty()) {
//        cur = helper.top();
//        helper.pop();
//        output.push(cur->val);
//        if (cur->left) {
//            helper.push(cur->left);
//        }
//        if (cur->right) {
//            helper.push(cur->right);
//        }
//    }
//    while (!output.empty()) {
//        res.push_back(output.top());
//        output.pop();
//    }
//    return res;
//    */
//}
//// 层次遍历
//vector<int> PrintFromTopToBottom(TreeNode* root)
//{
//    vector<int> res;
//    if(root == NULL)
//        return res;
//    queue<TreeNode*> q;
//    q.push(root);
//    while(!q.empty())
//    {
//        res.push_back(q.front()->val);
//        if(q.front()->left != NULL)
//            q.push(q.front()->left);
//        if(q.front()->right != NULL)
//            q.push(q.front()->right);
//        q.pop();
//    }
//    return res;
//}
///*
//// 返回二维数组
//vector<vector<int>> levelOrder(TreeNode* root)
//{
//    vector<vector<int>> res;
//    vector<int> level;
//    if (root == nullptr) {
//        return res;
//    }
//    TreeNode* curNode = root;
//    queue<TreeNode*> q;
//    int width = 0;
//    q.push(curNode);
//    while (!q.empty()) {
//        width = q.size();
//        for (int i = 0; i < width; ++i) {
//            curNode = q.front();
//            level.push_back(curNode->val);
//            if (curNode->left != nullptr) {
//                q.push(curNode->left);
//            }
//            if (curNode->right != nullptr) {
//                q.push(curNode->right);
//            }
//            q.pop();
//        }
//        res.push_back(level);
//        level.clear();
//    }
//    return res;
//}
//*/
//int main()
//{
//    vector<int> data = {2, 7, 11, 15};
//    int target = 9;
//    vector<int> res = twoSum(data, target);
//    for (auto val : res) {
//        cout << val << " ";
//    }
//    cout << endl;
//    cout << "最长连续公共子序列" << endl;
//    string x= "acbac";
//    string y = "acaccbabb";
//    cout << longestContinueCommonSubsequence(x, y) << endl;
//    cout << "最长连续公共子序列" << endl;
//    cout << longestCommonSubsequence(x, y) << endl;;
//    cout << "最长回文字符串" << endl;
//    string palindrome = "abcdbbfcba";
//    cout << longestPalindrome(palindrome) << endl;
//    cout << "最长回文字符串" << endl;
//    cout << "最长回文子串" << endl;
//    cout << longestPalindrome5("abcdbbfcba") << endl;
//    cout << "最长回文子串" << endl;
//    cout << "接雨水" << endl;
//    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
//    cout << trap(height) << endl;
//    vector<int> lsis{1,3,5,7};
//    cout << findLengthOfLCIS(lsis) << endl;
//    cout << "最长无重复子串" << endl;
//    cout << lengthOfLongestSubstring("dvdf") << endl;
//    cout << "电话号码字母组合" << endl;
//    Solution solu;
//    vector<string> letterComb = solu.letterCombinations("23");
//    for (auto s : letterComb) {
//        cout << s << " ";
//    }
//    cout << endl;
//    cout << "有效括号组合" << endl;
//    vector<string> parenthesis = generateParenthesis(3);
//}
