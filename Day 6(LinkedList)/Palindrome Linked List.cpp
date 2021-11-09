/*
Problem Link:  https://leetcode.com/problems/palindrome-linked-list/

*/
/* Approach: Step 1: Find the middle of LL
Step 2: Reverse the LinkedList just after the middle part
Step 3: Keep 1 pointer at the start and other just after the mid.If the node values aren't equal,Return false
else int the end return true

*/
ListNode* reverseLinkedList(ListNode* slow){
        ListNode* root=slow->next;
        ListNode* prev=NULL;
        ListNode* next=slow->next;
        while(root){
            next=next->next;
            root->next=prev;
            prev=root;
            root=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverseLinkedList(slow);
        ListNode* front=head;
        ListNode* prev=slow->next;
        while(prev){
           if(front->val!=prev->val)
                return 0;
            front=front->next;
            prev=prev->next;
        }
        return 1;
    }
