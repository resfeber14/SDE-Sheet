// Problem Link: https://leetcode.com/problems/subsets-ii/

// Approach 1: Time Complexity: O(2^N+2^N*log(2^N)) Space Complexity: O(2^N)
// Sort the array and apply Inclusion Exclusion Principle and store the elements in a set to get rid of the duplicates


void solve(int i,vector<int> temp,set<vector<int> > &s,vector<int> &arr){
       if(i==arr.size()){
           s.insert(temp);
           return;
       }
        temp.push_back(arr[i]);
        solve(i+1,temp,s,arr);
        temp.pop_back();
        solve(i+1,temp,s,arr);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int> > v;
        int n=arr.size();
        set<vector<int> > s;
        sort(arr.begin(),arr.end());
        vector<int> temp;
        solve(0,temp,s,arr);
        for(auto it:s){
            v.push_back(it);
        }
        return v;
    }

// Approach 2: Time Complexity: O(2^N*log(2^N)) Space Complexity: O(2^N * N) Space Complexity: O(2^N)

// Here we don't use set.Firstly sort the array
// Then if we are picking the duplicate element first time then pick it else don't
// eg: 2,2,2 here when we pick 2 and then again check if we can pick 2,then we can so (2,2) and similarly (2,2,2) but after when we have popped out the last two 2s,the we
// currently have (2),so if we want to push 2 of the 3rd index ,we can't bcoz we have earlier picked (2,2).So again we will be picking the same.
// SO to void this in for loop we are putting a condition check

 void solve(int i,vector<vector<int> > &v,vector<int> temp,vector<int> &arr){
        v.push_back(temp);
        for(int j=i;j<arr.size();j++){
            if(i!=j && arr[j]==arr[j-1]){ // ignoring the duplicate elements
                // it emans if we have 2,2 then pick 2,2 first time
                continue;
            }
            temp.push_back(arr[j]);
            solve(j+1,v,temp,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> v;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        solve(0,v,temp,arr);
        return v;
    }
