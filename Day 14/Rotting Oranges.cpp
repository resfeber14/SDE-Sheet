// Problem Link: https://leetcode.com/problems/rotting-oranges/

// Approach: Time complexity: O(N*M*4) Space Complexity: O(N*M)
// Time complexity is this bcoz suppose you have 4*4 matrix and 0*0 is rotten then at a time if it is rotten ,then it will rotten agal bagal.So for every cell we will check in all
// the 4 directions .So N*M*4
int orangesRotting(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        queue<pair<int,int> > q;
        int tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==2){
                    q.push({i,j});
                }
                else if(arr[i][j]==1)
                    tot++;
            }
        }
        int rot=0;
        int ans=0;
        while(!q.empty()){
            int cnt=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first,y=p.second;
                for(int k=0;k<4;k++){
                    int xx=x+dx[k],yy=y+dy[k];
                    if(xx>=0 && xx<n && yy>=0 && yy<m && arr[xx][yy]==1){
                        q.push({xx,yy});
                        arr[xx][yy]=2;
                        cnt++;
                    }
                }
            }
            rot+=cnt;
            if(cnt>0){
                ans++;
            }
        }
        if(rot==tot)
        return ans;
        return -1;
    }
