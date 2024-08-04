/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==0) return 0;

        ListNode* left = 0;
        ListNode* cur = head;
        ListNode* right = head->next;

        while(cur){
            cur->next = left;
            left = cur;
            cur = right;
            if(right)
                right = right->next;
        }

        return left;
    }
};