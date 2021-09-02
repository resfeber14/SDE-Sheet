// Problem Link:  https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// Approach: Consider all the possibilities


void solve(int i,int j,string s,vector<vector<int> > &arr,int n,vector<vector<bool>> &visited,vector<string> &v){
        
        if(i==n-1 && j==n-1){
            v.push_back(s);
            return;
        }
        visited[i][j]=1;
        
        for(int k=0;k<4;k++){
            if(k==0){
                int x= i+1,y=j;
                if(x>=0 && y>=0 && x<n && j<n && arr[x][y]!=0 && !visited[x][y]){
                    solve(x,y,s+"D",arr,n,visited,v);
                }
            }
            if(k==1){
                int x= i,y=j-1;
                if(x>=0 && y>=0 && x<n && j<n && arr[x][y]!=0 && !visited[x][y]){
                    solve(x,y,s+"L",arr,n,visited,v);
                }
            }
            if(k==2){
                int x= i,y=j+1;
                if(x>=0 && y>=0 && x<n && j<n && arr[x][y]!=0 && !visited[x][y]){
                    solve(x,y,s+"R",arr,n,visited,v);
                }
            }
            if(k==3){
                int x= i-1,y=j;
                if(x>=0 && y>=0 && x<n && j<n && arr[x][y]!=0 && !visited[x][y]){
                    solve(x,y,s+"U",arr,n,visited,v);
                }
            }
        }
        visited[i][j]=0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v;
        string s="";
        if(m[0][0]==0){
            return v;
        }
        vector<vector<bool> > visited(n,vector<bool> (n,0));
        solve(0,0,s,m,n,visited,v);
        return v;
    }
