// Problem Link:  https://leetcode.com/problems/two-sum/

// Approach 1: Time complexity: O(N*N) Space Complexity: O(1)
// For every ith element,check if in the right half whether k-arr[i] is present or not

// Approach 2: Time complexity: O(N) Space Complexity: O(N)

// For every i,check if k-arr[i] is present or not in the hashmap,if it isn't present,then add it into the map,else that is the pair return it

vector<int> twoSum(vector<int>& arr, int k) {
        vector<int> v;
        map<int,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int x=k-arr[i];
            if(m.find(x)!=m.end()){
                v.push_back(m[x]);
                v.push_back(i);
                return v;
            }
            else{
                m[arr[i]]=i;
            }
        }
        
        return v;
    }
