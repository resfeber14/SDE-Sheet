/*
Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/

*/
/*
Approach 1: Time complexity:O(N) Space Complexity:O(1)
Count the nodes in one traversal
then in the next traversal print the n/2 th node


/*
 Approach 2: Time Complexity:O(N) Space Complexity: O(1)

    We need to use a slow and a fast pointer
    When traversing the list with a pointer slow, make another pointer fast that traverses twice as fast. When fast reaches the end of the list, slow must be in the middle.
    Speed of slow pointer is v and the speed of the fast pointer is 2*v.
    So when fast will reach at the last node,Slow will be reaching in the mid
    

*/
ListNode* middleNode(ListNode* head) {
       ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){ // if the fast is NULL or next node of fast is NULL,then we have got the middle of the LL,so just break
            slow=slow->next;
            fast=fast->next->next;
           
        }
        return slow; // if for even no of nodes,if we are asked to return (n/2 +1)th node,return slow,else if we need to return (n/2 th),return the node previous to slow
  // for this we can keep a  prev pointer to store the previous of slow pointer
    }
