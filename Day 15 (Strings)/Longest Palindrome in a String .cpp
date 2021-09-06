// Problem Link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#


// Approach 1: Time complexity: O(N*N*N) Space complexity: O(1) 
// take two pointers i,j where i is indicating the start of the string which we are considering and j be the end of the string.
// And again run a loop which will count if the substring i,j is palindrome or not,if it is then ans=max(curr,ans)


// Approach 2: Time complexity: O(N*N) Space complexity: O(N*N)
// Apply dp as if know the ans of smaller length we can get for larger length with the help of this

string longestPalin (string s) {
        // code here
        int n=s.length();
        int dp[n][n];
        int x=0,y=0;
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            int r=0,c=r+i;
            while(r<n && c<n){
                if(c-r==0){
                    dp[r][c]=1;
                }
                else if(c-r==1){
                    if(s[r]==s[c])
                        dp[r][c]=2;
                    else
                        dp[r][c]=0;
                }
                else{
                    if(s[r]==s[c]){
                        if(dp[r+1][c-1]!=0)
                            dp[r][c]=dp[r+1][c-1]+2;
                        else
                            dp[r][c]=0;
                    }
                    
                }
                if(ans<dp[r][c]){
                    ans=dp[r][c];
                    x=r;
                    y=c;
                }
                
                r++;
                c++;
            }
        }
        string str="";
        for(int i=x;i<=y;i++){
            str+=s[i];
        }
        return str;
    }
