// Problem Link:  https://practice.geeksforgeeks.org/problems/subset-sums2234/1#


// Approach : Time complexity: O(2^n) Space Complexity: O(2^N)

// Apply Inclusion exclusion principle. 

void solve(int i,int curr,vector<int> &v,vector<int> &arr,int n){
        if(i==n){
            v.push_back(curr);
            return ;
        }
        solve(i+1,curr,v,arr,n);
        solve(i+1,curr+arr[i],v,arr,n);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> v;
        solve(0,0,v,arr,n);
        return v;
        
    }
// Similar Problem :  https://leetcode.com/problems/subsets/

// Take a temp vector and traverse the array and push everytime and then call the recursion the pop back

void solve(int i,int n,vector<int> &arr,vector<vector<int> > &v,vector<int> temp){
        v.push_back(temp);
       for(int j=i;j<n;j++){
           temp.push_back(arr[j]);
           solve(j+1,n,arr,v,temp);
           temp.pop_back();
       }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> v;
        vector<int> temp;
        solve(0,arr.size(),arr,v,temp);
        return v;
    }

