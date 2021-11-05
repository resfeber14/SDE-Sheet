/*
Problem Link: https://leetcode.com/problems/reverse-linked-list/

Time Complexity:O(N)
Space Complexity: O(1)

*/

ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        ListNode* root=head;
        ListNode* prev=NULL;
        ListNode* next=root->next;
        while(root){ 
            root->next=prev; 
            prev=root; 
            root=next; 
            if(next)
               next=next->next;
        }
       return prev;
    }
