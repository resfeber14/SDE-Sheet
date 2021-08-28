// Problem Link:  https://leetcode.com/problems/search-a-2d-matrix/

Approach 1: Time Complexity: O(N+log(M)) Space Complexity: O(N)

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


// Problem Link:   https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1#


// Approach 1: Time Complexity: O(N*M) Space Complexity: O(1)
// Simply,Traverse the whole matrix and check if the given no is present or not.


// Approach 2: Time Complexity: O(N*Log(M)) Space Complexity: O(1)
// Traverse row wise and for each row apply binary search to check if the given no is present or not


// Approach 3: Time Complexity: O(N) Space Complexity: O(1)
// take a variable and point it to arr[0][m-1],
// Now if(k>arr[i][j]) then,we need to go downwards as the matrix is sorted column wise and row wise. So i++;
// if(k<arr[i][j]) then, we need to go leftwards as columns are sorted.
// else return true;

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
