class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *head0 = 0, *head1 = 0, *head2 = 0;
        Node *tail0 = 0, *tail1 = 0, *tail2 = 0;
        
        Node* ptr = head;
        while(ptr!=0){
            if(ptr->data==0){
                if(head0!=0){
                    tail0->next = ptr;
                    tail0 = tail0->next;
                }
                else{
                    head0 = ptr;
                    tail0 = ptr;
                }
            }
            else if(ptr->data==1){
                if(head1!=0){
                    tail1->next = ptr;
                    tail1 = tail1->next;
                }
                else{
                    head1 = ptr;
                    tail1 = ptr;
                }
            } 
            else if(ptr->data==2){
                if(head2!=0){
                    tail2->next = ptr;
                    tail2 = tail2->next;
                }
                else{
                    head2 = ptr;
                    tail2 = ptr;
                }
            } 
            ptr = ptr->next;
        }
        
        // join the 3 lists
        if(tail0!=0) tail0->next = head1!=0?head1:head2;
        if(tail1!=0) tail1->next = head2;
        if(tail2!=0) tail2->next = 0;
        
        return head0!=0?head0:head1!=0?head1:head2;
        
    }
};