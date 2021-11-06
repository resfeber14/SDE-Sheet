/*
Problem Link:  https://leetcode.com/problems/merge-two-sorted-lists/


*/

/* Approach 1: Time Complexity: O(N1+N2) , Space Complexity: O(N1+N2)

Make a new LinkedList and attach its next to the node if it is the smaller one and keep doing so

*/

/*
Approach 2: Start with the LL whose value is lesser.Then,keep moving until its value is smaller than than the other LinkedList value and also keep track of the last node
which was smaller than the Other LinkedList value so that when l1's value is greater we can point the tracked node to the node of the other LL.
And also we are considering that l1's value will always be lesser than that of l2.
So when l1's value is greater,swap l1 and l2

Time Complexity: O(N+M) Space Complexity:O(1)

*/

// Recursive approach:

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val > l2->val){
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
            
        l1->next= mergeTwoLists(l1->next,l2);
        return l1;
    }

// Iterative Approach:

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val> l2->val){ // swapping l1 and l2.Bcoz we are considering that always l1's node value will be lessser than that of l2's.
            ListNode* swap=l1;
            l1=l2;
            l2=swap;
        }
        ListNode* res=l1;
        while(l1 && l2){
            ListNode* temp=NULL;
            while(l1 && l1->val<=l2->val){ // run this loop until the l1's node value is lesser or equal to than that of l2's.
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            ListNode* swap=l1;
            l1=l2;
            l2=swap;
        }
        return res;
    }
