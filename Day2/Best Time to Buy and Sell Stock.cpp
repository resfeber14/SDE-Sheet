// Problem Link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Approach 1: Brute Force ,Time Complexity: O(N*N), Space Complexity: O(1)

// Try all possible combinations


// Approach 2: Time Complexity: O(N), Space Complexity: O(1)

// Take a variable called sell=arr[0].
// Now traverse the array,sell=min(arr[i],sell). And check if we can get the maximum by selling the current.

int maxProfit(vector<int>& prices) {
        int minn=INT_MAX,profit=0;
        minn=min(prices[0],minn);
        for(int i=1;i<prices.size();i++){
            minn=min(minn,prices[i]);
            profit=max(prices[i]-minn,profit);
        }
        return profit;
    }

// Different Implementation :

int maxProfit(vector<int>& arr) {
        int n=arr.size(),buy=arr[0],sell=arr[0],ans=0;
        for(int i=1;i<n;i++){
            sell=max(arr[i],sell);
            ans=max(ans,sell-buy);
            if(buy>arr[i]){
                buy=arr[i];
                sell=arr[i];
            }
            
        }
        return ans;
    }
