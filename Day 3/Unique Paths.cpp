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

// Approach: There are overlapping subproblems,So apply DP:)

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



