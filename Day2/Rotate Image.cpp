// Problem Link:  https://leetcode.com/problems/rotate-image/

// Approach:  Time Complexity: O(N*M) , Space Complexity: O(1)

// Take Transpose of the matrix.
// Reverse each row



void rotate(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        // Transpose of the matrix.
        // Taking one half and swapping.
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            // reverse each row
            int l=0,r=m-1;
            while(l<r){
                swap(arr[i][l],arr[i][r]);
                l++;
                r--;
            }
        }
    }
