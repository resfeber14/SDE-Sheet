/*
Problem Link:  https://leetcode.com/problems/add-two-numbers/
Time complexity:O(max(N1,N2)) Space Complexity:O(max(N1,N2))
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* root=new ListNode();
        ListNode* head=root;
        
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry= sum/10;
            ListNode* temp=new ListNode(sum%10);
            root->next=temp;
            root=root->next;
        }
        
        return head->next;
    }
