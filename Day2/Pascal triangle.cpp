// Problem Link: https://leetcode.com/problems/pascals-triangle/


// Approach : Time Complexity: O(N*N), Space Complexity: O(N*N)
 vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            v[i].resize(i+1);
            v[i][0]=1,v[i][i]=1;
            for(int j=1;j<i;j++){
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
        return v;
    }
    
    // Problem type: 2: We are asked to print the element of rth row and jth col
    // Then we only need to C(r-1,c-1)
    Time Complexity: O(N), Space Complexity: 1
    
    
    
    // Problem type:3 Print the rth row of the Pascal Triangle
    // Time Complexity: O(N), Space Complexity: O(N)
    
    // C(n,0)=1, C(n,1) = (n)/1  ,C(n,2) =(n*(n-1))/(1*2)  , C(n,3)=(n*(n-1)*(n-2))/(1*2*3) .......
    
    int solve(int k){
      int res=1;
      for(int i=0;i<k;i++){
            res*= (n-i)
            res/=(i+1);
       }
       return res;
    }
    
    
    
    
   
