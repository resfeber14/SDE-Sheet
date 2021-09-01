// Problem Link:  https://practice.geeksforgeeks.org/problems/subset-sums2234/1#


// Approach : Time complexity: O(2^n) Space Complexity: O(1)

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
