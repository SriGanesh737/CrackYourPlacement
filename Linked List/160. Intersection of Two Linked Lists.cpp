/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode node;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
              node*h1=headA,*h2=headB;
              while(h1!=0 && h2!=0){
                h1 = h1->next;
                h2 = h2->next;
              }

            if(h1==0){
                h1 = headB;
                while(h2!=0) {
                    h2 = h2->next;
                    h1 = h1->next;
                }
                h2 = headA;
                while(h1!=h2) {
                    h1=h1->next;
                    h2 = h2->next;
                }
                return h1;
            }
            else{
                h2 = headA;
                while(h1!=0){
                    h1 = h1->next;
                    h2 = h2->next;
                }
                h1 = headB;
                while(h1!=h2) {
                    h1=h1->next;
                    h2 = h2->next;
                }
                return h1;
            }
        return 0;
    }
};