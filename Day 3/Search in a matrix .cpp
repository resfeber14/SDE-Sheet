// Problem Link:  https://leetcode.com/problems/search-a-2d-matrix/

// Approach 1: Time Complexity: O(N+log(M)) Space Complexity: O(N)

bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n=arr.size(),m=arr[0].size();
        int temp[n];
        for(int i=0;i<n;i++){
            temp[i]=arr[i][m-1];
        }
        int ind= lower_bound(temp,temp+n,k)-temp;
        cout<<ind<<" ";
        if(ind==n)
            return false;
        if(binary_search(arr[ind].begin(),arr[ind].end(),k))
            return true;
        return false;
    }

// Approach 2: Time Complexity: O(log(N*M)+O(N*M)) Space Complexity: O(N*M)

// As the rows and col are sorted and also every last element in row is leeser than the first element of the next row,the we can say if we store all the elements in an array 
// of size nxm and apply binary search,then it will work


// Approach 3: Time Complexity: O(log(N*M)) Space Complexity: O(1)

// Instead of storing it , we can determine also by applying binary search to the whole matrix without storing all the elments.
// By assuming that we are numbering each element from 0. So we can also find the row and col no from its imaginary numbering.

bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n=arr.size(),m=arr[0].size();
        int l=0,r=n*m-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int row= mid/m,col= mid%m;
            if(arr[row][col]>k){
                r=mid-1;
            }
            else if(arr[row][col]<k){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }

// Problem Link:   https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1#
// https://leetcode.com/problems/search-a-2d-matrix-ii/


// Approach 1: Time Complexity: O(N*M) Space Complexity: O(1)
// Simply,Traverse the whole matrix and check if the given no is present or not.


// Approach 2: Time Complexity: O(N*Log(M)) Space Complexity: O(1)
// Traverse row wise and for each row apply binary search to check if the given no is present or not


// Approach 3: Time Complexity: O(N) Space Complexity: O(1)
// take a variable and point it to arr[0][m-1],
// Now if(k>arr[i][j]) then,we need to go downwards as the matrix is sorted column wise and row wise. So i++;
// if(k<arr[i][j]) then, we need to go leftwards as columns are sorted.
// else return true;

// This approach will work on both the problems

int matSearch (vector <vector <int>> &arr, int n, int m, int k){
	    int i=0,j=m-1;
	    while(i>=0 && j>=0 && i<n && j<m){
	        if(k>arr[i][j]){
	            i++;
	        }
	        else if(k<arr[i][j]){
	            j--;
	        }
	        else{
	            return 1;
	        }
	    }
	    return 0;
	}
