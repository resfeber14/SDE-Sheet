// Problem Link:  https://leetcode.com/problems/max-consecutive-ones/

// Approach : Time complexity: O(N) Space Complexity: O(1)

int findMaxConsecutiveOnes(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        int cnt=0,i=0;
        while(i<n){
            if(arr[i]==0){
                ans=max(cnt,ans);
                cnt=0;
            }
            else{
                cnt++;
                ans=max(ans,cnt);
            }
            i++;
        }
        
        return ans;
    }
