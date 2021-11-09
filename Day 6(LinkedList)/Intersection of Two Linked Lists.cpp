/*
Problem Link:  https://leetcode.com/problems/intersection-of-two-linked-lists/


*/


/*
Approach 1: Time Complexity: O(N*M) Space Complexity: O(1)
Approach: For every node in the first LinkedList ,we check if it is present in the second LinkedList.


*/
ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* dummy=l1;
        while(dummy){
            ListNode* temp=l2;
            while(temp){
                if(temp==dummy){
                    return temp;
                }
                temp=temp->next;
            }
            dummy=dummy->next;
        }
        return NULL;
    }


/*
Approach 2: Time Complexity: O(N+M) Space Complexity: O(N)
Approach : We will first traverse the first LL and will hash each node in a map.
Then we will traverse the second LL and check if that node is present in the map,then if it is present,then that's the intersection point and we will return that node
else will continue traversing

*/
 ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* dummy1=l1;
        ListNode* dummy2=l2;
        map<ListNode*,int> m;
        while(dummy1){ // hash the nodes of first LinkedList
            m[dummy1]++;
            dummy1=dummy1->next;
        } 
        while(dummy2){ // for every node,check if that node is present in map(i.e. present in the first LL)
            if(m.count(dummy2)){
                return dummy2;
            }
            dummy2=dummy2->next;
        }
        return NULL;
    }

/*
Approach 3:
Time Complexity: O(N+M+N) Space Complexity: O(1)

*/

