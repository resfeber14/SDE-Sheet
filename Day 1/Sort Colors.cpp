// Problem Link:  https://leetcode.com/problems/sort-colors/


// Problem Statement: 

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
//with the colors in the order red, white, and blue.We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.

// Approach 1: Time Complexity: O(NlogN), Space Complexity: O(1): Sort the array

// Approach 2: Time Complexity: O(2*N), Space Complexity: O(1):  Take three variables and keep count of 0,1,2 in it.And in another pass insert that no of 0s,that no of 1s
// and that no of 2s.

void sortColors(vector<int>& arr) {
        int a=0,b=0,c=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)
                a++;
            else if(arr[i]==1)
                b++;
            else
                c++;
        }
        for(int i=0;i<arr.size();i++){
            if(a>0){
                arr[i]=0;
                a--;
            }
            else if(b>0){
                arr[i]=1;
                b--;
            }
            else{
                arr[i]=2;
                c--;
            }
        }
    }

// Approach 2: Dutch National Flag Algorithm
// Take 3 variables: low=0,mid=0 and high=n-1.
// Case 1: If arr[mid]==0, swap(arr[l],arr[mid]). low++,mid++
// Case 2: If arr[mid]==1,mid++
// Case 3: If arr[mid]==2, swap(arr[mid],arr[high]) .  high--

// Now the sequence will be such that all the indexes i the left of low will contain 0, indexes to the right of high will contain 2 and between low and mid will contain 1.


void sortColors(vector<int>& arr) {
        int low=0,mid=0,high=arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }

