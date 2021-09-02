// Problem Link: https://leetcode.com/problems/n-queens/

// Approach : Time Complexity : IDK 

// Explore all the possibilities


bool canWePlace(int row,int col,vector<string> &temp,int n){
        int i=0,j;
        for(int i=0;i<row;i++){
            if(temp[i][col]=='Q')
                return false;
        }
        i=row,j=col;
        while(i>=0 && i<n && j>=0 && j<n){
            if(temp[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(i>=0 && i<n && j>=0 && j<n){
            if(temp[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    
    void solve(int r,vector<string> &temp,vector<vector<string> > &v,int n){
        
        if(r==n){
            v.push_back(temp);
            return false;
        }
        for(int i=0;i<n;i++){
            if(canWePlace(r,i,temp,n)){
                temp[r][i]='Q';
                solve(r+1,temp,v,n);
                temp[r][i]='.';
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > v;
        string s="";
        for(int i=0;i<n;i++)
            s+=".";
        vector<string > temp(n,s);
        solve(0,temp,v,n);
        return v;
    }


// Approach 2: 
// There is an optimisaton
// Instead of applying while loop while checking that whether we can place at a certain cell or not
// Create an array for checking whether keeping queen at a particular is safe from left Diagonal or not.
// Create an array for checking whether keeping queen at a particular is safe from right Diagonal or not.
// Create an array for checking whether keeping queen at a particular is safe from columns or not.
// This will only take extra space but will check if we can place or not in a particular cell or not in O(1) time compexity


void solve(int r,vector<string> &temp,vector<vector<string> > &v,int n,vector<int> &leftDia,vector<int> &rightDia,vector<int> &col){
        
        if(r==n){
            v.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(leftDia[r+i]==-1 && rightDia[(n-1)+(i-r)]==-1 && col[i]==-1){
                temp[r][i]='Q';
                leftDia[r+i]=1;
                rightDia[n-1+i-r]=1;
                col[i]=1;
                solve(r+1,temp,v,n,leftDia,rightDia,col);
                temp[r][i]='.';
                leftDia[r+i]=-1;
                rightDia[n-1+i-r]=-1;
                col[i]=-1;
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > v;
        string s="";
        for(int i=0;i<n;i++)
            s+=".";
        vector<int> leftDia(2*n,-1);
        vector<int> rightDia(2*n,-1);
        vector<int> col(n,-1);
        vector<string > temp(n,s);
        solve(0,temp,v,n,leftDia,rightDia,col);
        return v;
    }
