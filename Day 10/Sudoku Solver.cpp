// Problem :


// Approach 1:
// Try all combinations

bool canWePut(char num,int i,int j,vector<vector<char> > &arr){
        for(int x=0;x<9;x++){
            if(arr[i][x]==num){
                return false;
            }
        }
        for(int x=0;x<9;x++){
            if(arr[x][j]==num){
                return false;
            }
        }
        int row= (i/3)*3,col= (j/3)*3;
        for(int r=row;r<row+3;r++){
            for(int c=col;c<col+3;c++){
                if(arr[r][c]==num){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(int i,int j,vector<vector<char> > &arr){
        
        if(i==9){
            return true;
        }
        
        if(j==9){
            return solve(i+1,0,arr);
        }
        
        if(arr[i][j]!='.'){
            return solve(i,j+1,arr);
        }
        for(int num=1;num<10;num++){
            char x=num+'0';
            if(canWePut(x,i,j,arr)){
                arr[i][j]=num+'0';
                if(solve(i,j+1,arr)){
                    return true;
                }
                arr[i][j]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }


// Approach 2: Optimisation
// In the check function,just run the loop 0...9 

bool canWePut(char num,int i,int j,vector<vector<char> > &arr){
        int row= (i/3)*3 ,col=(j/3)*3;
        for(int x=0;x<9;x++){
            if(arr[i][x]==num)
                return false;
            if(arr[x][j]==num)
                return false;
            if(arr[row+(x/3)][col+ (x%3)]==num)
                return false;
        }
        return true;
    }
    
    bool solve(int i,int j,vector<vector<char> > &arr){
        
        if(i==9){
            return true;
        }
        
        if(j==9){
            return solve(i+1,0,arr);
        }
        
        if(arr[i][j]!='.'){
            return solve(i,j+1,arr);
        }
        for(int num=1;num<10;num++){
            char x=num+'0';
            if(canWePut(x,i,j,arr)){
                arr[i][j]=num+'0';
                if(solve(i,j+1,arr)){
                    return true;
                }
                arr[i][j]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
