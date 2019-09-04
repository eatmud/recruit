//#include <vector>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};
//class Solution {
//public:
//    ListNode* deleteDuplication(ListNode* pHead)
//    {
//        if (!pHead || !pHead->next)
//            return pHead;
//        ListNode* newhead = new ListNode(-1);
//        newhead->next = pHead;
//        ListNode* pre = newhead;
//        ListNode* cur = pHead;
//        ListNode* next = pHead->next;
//        while (cur && next) {
//            if (cur->val == next->val){
//                while (next && cur->val == next->val) {
//                    next = next->next;
//                    pre->next = next;
//                    cur = next;
//                }
//            } else {
//                pre = cur;
//                cur = next;
//           }
//           if(cur) {
//                next = cur->next;
//           }
//        }
//        return newhead->next;
//    }
//};
//int main()
//{
//    ListNode *head = new ListNode(1);
//    ListNode *temp = head;
//    temp->next = new ListNode(2);
//    temp = temp->next;
//    temp->next = new ListNode(3);
//    temp = temp->next;
//    temp->next = new ListNode(3);
//    temp = temp->next;
//    temp->next = new ListNode(4);
//    temp = temp->next;
//    temp->next = new ListNode(4);
//    temp = temp->next;
//    temp->next = new ListNode(5);
//    temp = temp->next;
//
//    temp = head;
//    while (temp)
//    {
//      cout << temp->val << " ";
//      temp = temp->next;
//    }
//    cout << endl;
//
//    Solution s;
//    ListNode * p = s.deleteDuplication(head);
//
//    temp = p;
//    while (temp)
//    {
//        cout << temp->val << " ";
//        temp = temp->next;
//    }
//    cout << endl;
//
//
//    temp = head;
//    while (temp)
//    {
//        cout << temp->val << " ";
//        temp = temp->next;
//    }
//    cout << endl;
//}
