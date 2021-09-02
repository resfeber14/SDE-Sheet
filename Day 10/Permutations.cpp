// Problem Link: https://leetcode.com/problems/permutations/

// Approach : Time complexity: O(n*n!) Space Complexity: O(N)

// Here we are taking all the possibilities

 void solve(vector<int> &temp,vector<vector<int> > &v,map<int,int> &m,vector<int> &arr){
        
        if(temp.size()==arr.size()){
            v.push_back(temp);
            return;
        }
        
        
        for(int j=0;j<arr.size();j++){
            if(m[arr[j]]==0){
                m[arr[j]]=1;
                temp.push_back(arr[j]);
                solve(temp,v,m,arr);
                m[arr[j]]=0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> v;
        int n=arr.size();
        vector<int> temp;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]=0;
        }
        solve(temp,v,m,arr);
        
        return v;
    }


// Approach 2: Time Complexity:

// Here we are swapping characters at each index and call the recursion and on returning back we are swapping back to restore the original array


void solve(vector<vector<int>> &v,vector<int> &arr,int i){
        if(i==arr.size()){
            v.push_back(arr);
            return;
        }
        for(int j=i;j<arr.size();j++){
            swap(arr[i],arr[j]);
            solve(v,arr,i+1);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> v;
        int n=arr.size();
        solve(v,arr,0);
        return v;
    }
