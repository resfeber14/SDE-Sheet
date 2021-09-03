// Problem Link:  https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

// Approach: Time complexity: O(log(2^32)* N*log(M))= O(32*N*log(M)) Space complexity: O(1)

// Here we are considering our answer lies between 0 to 1e9
// Now we are finding the mid and checking how many elements are <= mid
// Now we are returning l,bcoz let's assume that [[1],[2], [3]] is the matrix and we want to find no of elements <=2.So we find mid=(0+2)/2 =1.so now l=mid+1=2 and r=2
// Now r=mid-1 = 1. l>r break; And l=2
// Similarly for low

int median(vector<vector<int>> &arr, int r, int c){
        int low=0,high=1000000000;
        int anss=0;
        int mid=0;
        while(low<=high){
            mid=(high-low)/2 + low;
            int ans=0;
            for(int i=0;i<r;i++){
                int l=0,r=c-1,x=-1;
              // Rowwise sorted that's why we are applying binary search rowwise
                while(l<=r){
                    int mid1= (l+r)>>1;
                    if(arr[i][mid1]>mid){
                        r=mid1-1;
                    }
                    else if(arr[i][mid1]<=mid){
                        l=mid1+1;
                    }
                }
                
                ans+=l;
            }
            if(ans>(r*c)/2 ){
                high=mid-1;
            }
            else if(ans<= (r*c)/2 ){
                low=mid+1;
            }
            
        }
        return low;
    }
