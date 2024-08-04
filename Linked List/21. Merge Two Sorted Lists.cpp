/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if(list1==0) return list2;
    if(list2==0) return list1;
    
    node* head;
    if(list1->val<list2->val) {
        head = list1;
        list1 = list1->next;
        }
    else {
        head = list2;
        list2 = list2->next;
    }

    node*ans = head;

    while(list1 && list2){
        if(list1->val<list2->val) {
            head->next = list1;
            list1 = list1->next;
        }
        else {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }

    if(list1) head -> next = list1;
    else head -> next = list2;

    return ans;
}