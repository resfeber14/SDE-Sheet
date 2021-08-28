// Problem Link: https://leetcode.com/problems/unique-paths/

// Approach: Time Complexity: Exponential
// Brute force: Try all possible combinations

int solve(int i,int j,int n,int m){
        if(i>n || j>m){
            return 0;
        }
        if(i==n && j==m){
            return 1;
        }
        
        return solve(i+1,j,n,m)+solve(i,j+1,n,m);
    }
    int uniquePaths(int n, int m) {
        return solve(0,0,n-1,m-1);
    }

// Approach: Time Complexity: O(N*M) Space complexity: O(N*M)
// There are overlapping subproblems,So apply DP:)

int solve(int i,int j,int n,int m,vector<vector<int> > &dp){
        if(i>n || j>m){
            return 0;
        }
        if(i==n && j==m){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=solve(i+1,j,n,m,dp)+solve(i,j+1,n,m,dp);
    }
    int uniquePaths(int n, int m) {
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return solve(0,0,n-1,m-1,dp);
    }


// Approach 3: PnC approach  Time Complexity: O(N-1) or O(M-1) Space complexity: O(1)
// Here we can observe that for every path from 0,0 to n-1,m-1 we are going n-1 steps down and m-1 steps right
// So we have total (n-1+m-1) options in which we need to choose m-1 or n-1 stuffs

// So (m+n-2)C(n-1) or (m+n-2)C(m-1)

int uniquePaths(int n, int m) {
        double res=1;
        int N=n+m-2;
        int r=m-1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;  // For eg: 10C3,we will first (10-3+1)*(10-3+2)*(10-3+1)/(1*2*3) Answer 
        }
        return (int)res;
    }

