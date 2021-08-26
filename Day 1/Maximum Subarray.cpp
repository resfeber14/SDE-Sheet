// Problem Link:  https://leetcode.com/problems/maximum-subarray/

// Approach : Time Complexity: O(N), Space Complexity: O(1)

// Here,we take 2 variables to store the curr subarray sum and largest subarray sum upto now.
// if the curr subarray sum <0 then we discard it bcoz if ahead we get something greater sum afterwards,then the current -ve subarray sum will only decrease its value
// So as soon as we get the current suabrray sum as -ve,we update the sum,and mark it 0.

int maxSubArray(vector<int>& arr) {
        int curr=0,ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            curr+=arr[i];
            ans=max(ans,curr);
            if(curr<0)
                curr=0;
        }
        return ans;
    }
