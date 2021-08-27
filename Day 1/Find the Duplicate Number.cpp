// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

// Approach 1: Time Complexity: O(N*logN) ,Space Complexity: O(1)

// Sort the array and compare the adjacent elements,if they are equal return that element

// Approach 2: Time Complexity: O(N) ,Space Complexity: O(N)

// Take a frequecy array or mao,and store the count of each element,if the count of any element exceeds 1,then return 1

// Approach 3:  Time Complexity: O(N) ,Space Complexity: O(1)

// Hare Tortoise Method: Take 2 pointers, Point the first variable slow to the first element of the array and fast variable to the arr[arr[0]]


// Now keep moving the slow pointer as : slow=arr[slow] and the fast pointer as:   fast=arr[arr[fast]] till slow!=fast
// Now when loop breaks,then both the pointers fast and slow will be pointing to the same element.
// We can see if the fast and slow pointers are meeting at a point,Then as we know fast's speed is more than slow and they are meeting at a point,then fast must have travelled
// some k*cycle length distance
// Now say fast and slow is meeting at some element,then say the distance of that element from the first element is 'a',and the distance of the duplicate element from the first 
// element is x.
// Then,in the second iteration fast pointer and slow pointer will cover x distance to reach the duplicate element(their speed is same now)
//  Now the meeting point will be the duplicate element

int findDuplicate(vector<int>& arr) {
        int n=arr.size();
        int slow=arr[0],fast=arr[arr[0]];
        while(slow!=fast){
            cout<<slow<<" "<<fast<<"\n";
            slow=arr[slow];
            fast=arr[arr[fast]];
        }
        cout<<fast<<" "<<slow<<"\n";
        fast=0;
        while(fast!=slow){
            slow=arr[slow];
            fast=arr[fast];
        }
        return slow;
    }
