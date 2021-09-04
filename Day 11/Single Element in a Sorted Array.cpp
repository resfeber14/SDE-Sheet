// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

// Approach 1: Time complexity: O(N) Space Complexity: O(1)
// Since the array is sorted simply traverse the array and compare the current element with the adjacent element or traverse and find xor

// Approach 2: Time complexity: O(logN) Space Complexity: O(1)

// Here we can apply Binary search as array is sorted 
// How to apply? Just check if arr[mid]==arr[mid-1] then if mid is odd index (for eg: 3) So 2,3 are equal elements and 0,1 will be.So in this case we should do l=mid+1
// else id arr[mid]==arr[mid-1] and mid is even (for eg: 4) then (4,3),(2,1) or (4,3) , (0,1) will make pair as at these indices elements are same.So do r=mid-1 as the answer lies
// in the LHS
// Similarly do it when arr[mid]==arr[mid+1] and mid id even or odd


int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return arr[0];
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)>>1;
            cout<<mid<<" ";
            if(mid==0 && mid<n-1){
                if(arr[mid]!=arr[mid+1])
                    return arr[mid];
                l=mid+1;
            }
            else if(mid>0 && mid==n-1){
                if(arr[mid]!=arr[mid-1])
                    return arr[mid];
                r=mid-1;
            }
            else{
                if(arr[mid]!= arr[mid+1] && arr[mid]!=arr[mid-1]){
                    return arr[mid];
                }
                else if(arr[mid]==arr[mid-1]){
                    if(mid%2==0){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else if(arr[mid]==arr[mid+1]){
                    if(mid%2==0){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
            }
        }
        return 0;
    }
