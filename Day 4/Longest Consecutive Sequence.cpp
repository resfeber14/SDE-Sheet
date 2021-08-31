// Problem link:  https://leetcode.com/problems/longest-consecutive-sequence/

// Approach 1: Time Complexity: O(logN+N) Space Complexity: O(1)

// Sort the array and linearly iterate to get the sequence


int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int ans=1;
        int cnt=1;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==1){
                cnt++;
                ans=max(ans,cnt);
            }
            else if(arr[i]==arr[i-1]){
                continue;
            }
            else {
                cnt=1;
            }
        }
        
        return ans;
    }


// Approach 2:  Time Complexity: O(N)+O(N) Space Complexity: O(N)


// Store the elements in a map.If we get any element whose arr[i]-1 is present,then continue.
// else if arr[i]-1 is not present,then it means it is the smallest element if we start considering the consecutive elements.So we will now start a while loop to know
// how many maximum consecutive elements we can get if we start from arr[i].Hence anyhow we will max traverse O(N) again.


int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        map<int,int> m;
        int ans=1;
        if(arr.empty())
            return 0;
        sort(arr.begin(),arr.end());
        m[arr[0]]++;
        for(int i=1;i<arr.size();i++){
            if(m.find(arr[i]-1)!=m.end()){
                m[arr[i]]=m[arr[i]-1]+1;
            }
            else{
                m[arr[i]]=1;
            }
            ans=max(ans,m[arr[i]]);
        }
        return ans;
    }
