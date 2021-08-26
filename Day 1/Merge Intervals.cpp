// Problem Link:  https://leetcode.com/problems/merge-intervals/

// Approach : Time Complexity: O(N*log(N)+O(N)) Space Complexity: O(N)

// Here, we are first sorting the array as we want the to be merged elements to be near
// Hence when we get in which the current temp[1]>= curr[0], then push into current temp[1]=max(temp[1],curr[1])
// Else we know that the current[0]> temp[1],so we need to put the temp into the vector and update the current value

vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int> > v;
        int n=arr.size();
        if(n==0){
            return v;
        }
        sort(arr.begin(),arr.end());
        vector<int> temp={arr[0][0],arr[0][1]};
        for(auto it:arr){
            if(it[0]<=temp[1]){
                temp[1]=max(it[1],temp[1]);
            }
            else{
                v.push_back(temp);
                temp=it;
            }
        }
        v.push_back(temp);
        return v;
    }
