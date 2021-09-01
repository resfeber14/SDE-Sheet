// Problem Link: https://leetcode.com/problems/combination-sum/

// Approach : Time Complexity: O(2^n * n) Space Complexity: Cannot predict
// Apply Inclusion exclusion principle:)


void solve(int i,int curr,vector<int> temp,int k,vector<vector<int> > &v,vector<int> &arr){
        if(i==arr.size()){
            if(k==curr){
                v.push_back(temp);
            }
            return ;
        }
        if(curr==k){
            v.push_back(temp);
            
            return;
        }
        if(curr+arr[i]<=k){
            temp.push_back(arr[i]);
            solve(i,curr+arr[i],temp,k,v,arr);
            temp.pop_back();
            
        }
        solve(i+1,curr,temp,k,v,arr);
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int> > v;
        vector<int> temp;
        solve(0,0,temp,target,v,arr);
        return v;
    }
