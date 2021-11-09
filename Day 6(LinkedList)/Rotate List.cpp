/*
Problem Link: https://leetcode.com/problems/rotate-list/
Time Complexity: O(N+(n%K)) Space Complexity: O(1)

*/
/* Approach: Find the length of LinkedList
Then Connect the tail of LL to the head;
and then do int shift=len-k;
then keep traversing till we shift>1
When shift==1,Break the link and return the next node

*/
ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int n=1;
        ListNode* root=head;
        while(root->next){
            root=root->next;
            n++;
        }
        k%=n;
        if(k==0)
            return head;
        root->next=head;
        int p=n-k;
        root=head;
        while(p>1){
            root=root->next;
            p--;
        }
        ListNode* current_front=root->next;
        root->next=0;
        return current_front;
    }
