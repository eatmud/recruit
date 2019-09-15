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
//// leetcode 39 组合总和
////给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
////candidates 中的数字可以无限制重复被选取。
////说明：
////所有数字（包括 target）都是正整数。
////解集不能包含重复的组合。 
////示例:
////输入: candidates = [2,3,6,7], target = 7,
////所求解集为:
////[
////  [7],
////  [2,2,3]
////]
//class Solution_39 {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
//    {
//        vector<vector<int>> res;
//        vector<int> path;
//        if (candidates.empty() || target < 0) {
//            return res;
//        }
//        backtrace(0, res,path,candidates,target);
//        return res;
//    }
//    void backtrace(int start,vector<vector<int>>& res, vector<int>& path, vector<int>& candidates,int target)
//    {
//        if (target == 0) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = start; i < candidates.size() && target > 0; ++i) {
//            path.push_back(candidates[i]);
//            backtrace(i, res, path, candidates, target - candidates[i]);
//            path.pop_back();
//        }
//    }
//};
////int main()
////{
////    Solution_39 solution;
////    vector<int> candidates{2, 3, 6, 7};
////    int target = 7;
////    vector<vector<int>> res = solution.combinationSum(candidates, target);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
////leetcode 40 组合总和2
////给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
////candidates 中的每个数字在每个组合中只能使用一次。
////说明：
////所有数字（包括目标数）都是正整数。
////解集不能包含重复的组合。 
////示例 1:
////输入: candidates = [10,1,2,7,6,1,5], target = 8,
////所求解集为:
////[
////  [1, 7],
////  [1, 2, 5],
////  [2, 6],
////  [1, 1, 6]
////]
//class Solution_40 {
//public:
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<vector<int>> res;
//        vector<int> path;
//        if (candidates.empty() || target < 0) {
//            return res;
//        }
//        sort(candidates.begin(), candidates.end());
//        backtrace(0, res, path, candidates, target);
//        return res;
//    }
//    void backtrace(int start,vector<vector<int>>& res, vector<int>& path, vector<int>& candidates,int target)
//    {
//        if (target == 0) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
//            if (i > start && candidates[i] == candidates[i-1]) {
//                continue;
//            }
//            path.push_back(candidates[i]);
//            backtrace(i + 1, res, path, candidates, target - candidates[i]);
//            path.pop_back();
//        }
//    }
//};
////int main()
////{
////    Solution_40 solution;
////    vector<int> candidates{10,1,2,7,6,1,5};
////    int target = 8;
////    vector<vector<int>> res = solution.combinationSum2(candidates, target);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
////leetcode 77 组合
////给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
////示例:
////输入: n = 4, k = 2
////输出:
////[
////  [2,4],
////  [3,4],
////  [2,3],
////  [1,2],
////  [1,3],
////  [1,4],
////]
//class Solution_77 {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> res;
//        vector<int> path;
//        if (n < 1 || k < 0 || k > n) {
//            return res;
//        }
//        backtrace(1, res, path, n, k);
//        return res;
//    }
//    void backtrace(int start, vector<vector<int>>& res, vector<int>& path, int n, int k)
//    {
//        if (path.size() == k) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = start; i <= n; ++i) {
//            path.push_back(i);
//            backtrace(i + 1, res, path, n, k);
//            path.erase(path.end() - 1);
//        }
//    }
//};
////int main()
////{
////    Solution_77 solution;
////    int n = 4;
////    int k = 2;
////    vector<vector<int>> res = solution.combine(n, k);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
//
////leetcose 216 组合总和3
////找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
////说明：
////所有数字都是正整数。
////解集不能包含重复的组合。 
////示例 1:
////输入: k = 3, n = 7
////输出: [[1,2,4]]
//class Solution_216 {
//public:
//    vector<vector<int>> combinationSum3(int k, int n) {
//        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
//        vector<vector<int>> res;
//        vector<int> path;
//        if (n < 1 || k < 1 || n < k) {
//            return res;
//        }
//        backtrace(nums, res, path, 0, k, n);
//        return res;
//    }
//    void backtrace(vector<int>& nums, vector<vector<int>>& res,vector<int>& path, int start, int k, int n)
//    {
//        if (k == 0 && n == 0) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = start; i < nums.size(); ++i) {
//            path.push_back(nums[i]);
//            backtrace(nums, res, path, i + 1, k - 1, n - nums[i]);
//            path.pop_back();
//        }
//    }
//};
////int main()
////{
////    Solution_216 solution;
////    int n = 3;
////    int k = 7;
////    vector<vector<int>> res = solution.combinationSum3(n, k);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
//
////leetcode 46 全排列
////给定一个没有重复数字的序列，返回其所有可能的全排列。
////示例:
////输入: [1,2,3]
////输出:
////[
////  [1,2,3],
////  [1,3,2],
////  [2,1,3],
////  [2,3,1],
////  [3,1,2],
////  [3,2,1]
////]。
//
//class Solution_46 {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> path;
//        vector<int> visit(nums.size());
//        if (nums.empty()) {
//            return res;
//        }
//        backtrace(res, path, nums, visit);
//        return res;
//    }
//    void backtrace(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, vector<int>& visit)
//    {
//        if (path.size() == nums.size()) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); ++i) {
//            if (visit[i] == 1) {
//                continue;
//            }
//            visit[i] = 1;
//            path.push_back(nums[i]);
//            backtrace(res, path, nums, visit);
//            visit[i] = 0;
//            path.pop_back();
//        }
//    }
//};
////int main()
////{
////    Solution_46 solution;
////    vector<int> nums{1, 2, 3};
////    vector<vector<int>> res = solution.permute(nums);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
//
////LeetCode 47 全排列
////给定一个可包含重复数字的序列，返回所有不重复的全排列。
////示例:
////输入: [1,1,2]
////输出:
////[
////  [1,1,2],
////  [1,2,1],
////  [2,1,1]
////]
//class Solution_47 {
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> path;
//        vector<bool> visit(nums.size(), false);
//        if (nums.empty()) {
//            return res;
//        }
//        sort(nums.begin(), nums.end());
//        backtrace(res, path, visit, nums);
//        return res;
//    }
//    void backtrace(vector<vector<int>>& res, vector<int>& path,vector<bool>& visit,vector<int>& nums)
//    {
//        if (path.size() == nums.size()) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); ++i) {
//            if (visit[i] == false) {
//                if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == true) {
//                    continue;
//                }
//                visit[i] = true;
//                path.push_back(nums[i]);
//                backtrace(res, path, visit, nums);
//                path.pop_back();
//                visit[i] = false;
//            }
//        }
//    }
//};
////int main()
////{
////    Solution_47 solution;
////    vector<int> nums{1, 1, 2};
////    vector<vector<int>> res = solution.permuteUnique(nums);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
//
////leetcode 78 子集
////给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
////说明：解集不能包含重复的子集。
////示例:
////输入: nums = [1,2,3]
////输出:
////[
////  [3],
////  [1],
////  [2],
////  [1,2,3],
////  [1,3],
////  [2,3],
////  [1,2],
////  []
////]
//class Solution_78 {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> path;
//        backtrace(nums, 0, path, res);
//        return res;
//    }
//private:
//    void backtrace(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& res) {
//        res.push_back(path);
//        for (int j = i; j < nums.size(); j++) {
//            path.push_back(nums[j]);
//            backtrace(nums, j + 1, path, res);
//            path.pop_back();
//        }
//    }
//};
////int main()
////{
////    Solution_78 solution;
////    vector<int> nums{1, 2, 3};
////    vector<vector<int>> res = solution.subsets(nums);
////    for (auto v : res) {
////        for (auto i : v) {
////            cout << i << " ";
////        }
////        cout << endl;
////    }
////    return 0;
////}
//
////leetcode 90
////给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
////说明：解集不能包含重复的子集。
////示例:
////输入: [1,2,2]
////输出:
////[
////  [2],
////  [1],
////  [1,2,2],
////  [2,2],
////  [1,2],
////  []
////]
//class Solution_90 {
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> path;
//        sort(nums.begin(), nums.end());
//        backtrace(nums, 0, path, res);
//        return res;
//    }
//private:
//    void backtrace(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& res) {
//        res.push_back(path);
//        for (int j = i; j < nums.size(); j++) {
//                if (j > i && nums[j] == nums[j - 1]) {
//                    continue;
//                }
//                path.push_back(nums[j]);
//                backtrace(nums, j + 1, path, res);
//                path.pop_back();
//        }
//    }
//};
//int main()
//{
//    Solution_90 solution;
//    vector<int> nums{1, 1, 2};
//    vector<vector<int>> res = solution.subsetsWithDup(nums);
//    for (auto v : res) {
//        for (auto i : v) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
