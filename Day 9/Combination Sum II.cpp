// Problem Link:  https://leetcode.com/problems/combination-sum-ii/

// Approach : Time complexity: O(2^n*n *log(2^n))) Space Complexity: unknown 

// Sort the array
// Make a set of vector.Insert every possible combiation.Set of vector will amke sure no duplicate combination is inserted
// now push all the elements of set into a vector of vector and return
void solve(set<vector<int>> &v,int k,int i,vector<int> &temp,vector<int>& arr){
        if(i==arr.size()){
            if(k==0){
                v.insert(temp);
            }
            return;
        }
        if(arr[i]<=k){
            temp.push_back(arr[i]);
            solve(v,k-arr[i],i+1,temp,arr);
            temp.pop_back();
        }
        solve(v,k,i+1,temp,arr);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        vector<int> temp;
        set<vector<int> > s;
        solve(s,k,0,temp,arr);
        for(auto it: s){
            v.push_back(it);
        }
        return v;
    }

// Approach 2: time complexity: O(2^n * n)   Space Complexity: Unknown

// Same as subsets II
// Sort the array and run a loop to check if the current element is less than the k or not.if yes then take it
// else don't take it


void solve(int i,int k,vector<int> temp,vector<vector<int> > &v,vector<int> &arr){
        if(k==0){
                v.push_back(temp);
                return;
            }
        for(int j=i;j<arr.size();j++){
            if(i!=j && arr[j]==arr[j-1])
                continue;
            if(k>=arr[j]){
                temp.push_back(arr[j]);
                solve(j+1,k-arr[j],temp,v,arr);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int> > v;
        vector<int> temp;
        solve(0,target,temp,v,arr);
        return v;
    }
