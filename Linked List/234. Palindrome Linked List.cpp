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
    bool isPalindrome(ListNode* head) {
        if(head==0 || head->next==0) return true;
        ListNode* fast = head;
        ListNode*slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow ->next;
        }
        if(fast) slow = slow->next;

        ListNode*left = 0, *cur = slow, *right = slow->next;

        while(cur){
            cur->next = left;
            left = cur;
            if(right==0) break;
            cur = right;
            right = right->next;
        }

        while(cur && head){
            if(cur->val!=head->val) return false;
            cur = cur->next;
            head = head->next;
        }
        return true;
    }
};