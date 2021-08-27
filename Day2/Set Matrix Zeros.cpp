// Problem Link: https://leetcode.com/problems/set-matrix-zeroes/

// Approach 1: Time Complexity: O(N*M)  Space Complexity: O(N)+O(M)
// Take 2 sets,1 for storing the row where arr[i][j]==0 and other to store the col  where arr[i][j]==0.Traverse the matrix,and if arr[i][j]==0 then 
// insert i into the 'row' set and j in 'col' set.
// Traverse the matrix again and set the arr[i][j]==0 if i is present in the 'row' set.
// Traverse the matrix again and set the arr[i][j]==0 if j is present in the 'col' set.


void setZeroes(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        set<int> row;
        set<int> col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){1 t
                if(arr[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it:col){
            int x=it;
            for(int i=0;i<n;i++){
                arr[i][x]=0;
            }
        }
        for(auto it:row){
            int x=it;
            for(int i=0;i<m;i++){
                arr[x][i]=0;
            }
        }       
    }

// Approach 2: Time Complexity: O(N*M)  Space Complexity: O(1)
// Without taking 2 separate sets for storing which cell is 0.Take the first row and col to store this.
// Take And for knowing if any cell in the first row or col is 0 or not,Take two bool variables and intialise it to 0.
// Traverse the matrix from  1 to n and 1 to m to store which cell is 0 and store it intp the first rpw and col of the matrix.
// Again traverse the matrix to convert each to 0 if(arr[i][0]==0 || arr[0][j]==0)
// if row flag is true,then traverse the first row and mark each of them to 0.
// if col flag is true,then traverse the first col and mark each of them to 0.

void setZeroes(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        bool flag1=false,flag2=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    if(i==0)
                        flag1=true;
                    if(j==0)
                        flag2=true;
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
         if(flag2){
             for(int i=0;i<n;i++)
                 arr[i][0]=0;
         } 
        if(flag1){
             for(int i=0;i<m;i++)
                 arr[0][i]=0;
        }
    }
