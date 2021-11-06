/*
Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

*/

/* 
Approach 1: Time Complexity:O(2*N)  Space Complxity: O(1)

*/


/*
Approach 2: Time Complexity:O(N)  Space Complxity: O(1)
If we want to find Nth node from the end,then we need to find (K-N+1)th node from the start.So we will create a start ,slow and fast pointer intially whose next will
point to the start of the LinkedList.

*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;
        for(int i=1;i<=n;i++){ // move fast pointer to the nth node from the start.Now we are left with (K-N) nodes and we wanna delete (K-N+1)th node from the start
            fast=fast->next;
        }
        while(fast->next){ // now move the fast and slow pointer (K-N) steps
            fast=fast->next;
            slow=slow->next;
        } 
  // Now slow pointer is at (K-N)th node and we wanna delete its next element
        slow->next=slow->next->next;// deleting the next element
        return start->next; // let's say if head is to deleted then we can't return head
    }
