// Problem Link:  https://leetcode.com/problems/search-in-rotated-sorted-array/

// Approach: Time complexity: O(N) Space Complexity: O(1)
// Linearly traverse the array

// Approach 2: Time complexity: O(logN) Space Complexity: O(1)

// Check which part of the array is sorted whether its right half or the right half
// If left half is sorted then check if target lies in left side or in the right side


int search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(arr[mid]==target)
                return mid;
                // checking if left half is sorted or not 
            if(arr[l]<=arr[mid]){
                    // if target lies on the left half or not
                if(target>=arr[l] && target<arr[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
                // // checking if right half is sorted or not 
            else if(arr[mid]<=arr[r]){
                     // if target lies on the right half or not
                if(target>arr[mid] && target<=arr[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
