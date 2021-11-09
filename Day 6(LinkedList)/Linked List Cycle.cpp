/*
Problem Link: https://leetcode.com/problems/linked-list-cycle/


*/


// Approach 2: Time Complexity: O(N)  Space Complexity: O(1)
bool hasCycle(ListNode *head) {
        if(!head)
            return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return 1;
        }
        return 0;
    }
