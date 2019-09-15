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
//int res = 0;
//vector<int>p;
//
//void swap(int &a,int &b)
//  {
//      int temp;
//      temp=a;
//      a=b;
//      b=temp;
//  }
//
//void backtrack(vector<int> &nums,int i)
//{
//    if(i==nums.size()){
//        bool flag = true;
//        for(int k = 0;k < i-1;k++){
//            if(p[k]==1 &&(nums[k] > nums[k+1]))
//                flag = true;
//            else if(p[k] == 0 &&(nums[k] < nums[k+1]))
//                flag = true;
//            else
//                return;
//        }
//        if(flag) res++;
//    }
//    for(int j=i;j<nums.size();j++){
//        swap(nums[i],nums[j]);
//        backtrack(nums,i+1);
//        swap(nums[i],nums[j]);
//    }
//}
//
//int main(){
//    int n;
//    cin>>n;
//    for(int i = 0;i < n-1;i++){
//        int temp;
//        cin >> temp;
//        p.push_back(temp);
//    }
//    vector<int>nums;
//
//    for(int i = 1;i < n+1;i++)
//        nums.push_back(i);
//    backtrack(nums,0);
//    cout<< res%(1000000000+7);
//    return 0;
//}
