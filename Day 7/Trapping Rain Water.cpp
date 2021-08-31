// Problem Link:  https://leetcode.com/problems/trapping-rain-water/


// Approach 1:  Time Complexity: O(N)*4 Space Complexity: 3*O(N)

// Here,we are considering the current element as of minimum height.We are finding the prefix max height array and suffix maximum height array
// Then we find the height of water it can contribute as min(maxLeft[i],maxRight[i])-arr[i]
// And then we are returning the summation

int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2)
            return 0;
        int l[n],r[n];
        l[0]=height[0],r[n-1]=height[n-1];
        int maxx=l[0];
        for(int i=1;i<n;i++){
            if(maxx<height[i]){
                maxx=height[i];
            }
            l[i]=maxx;
        }
        maxx=r[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxx<height[i]){
                maxx=height[i];
            }
            r[i]=maxx;
        }
        int w[n];
        for(int i=0;i<n;i++){
            w[i]= min(l[i],r[i])-height[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= w[i];
        }
        return ans;
    }


// Approach 2:
// Basically we are doing ans+= min(leftMax,rightMax)-height[i] in the above approach.We can implement the above approach without O(N) space
// Here we can convert min(leftMax,rightMax) by comparing left and right part
// if the arr[left]<=arr[r],this ensures that if the current height building stores the water it won't flow down as in the right there is something which wil not let that do
// and vice versa
// Here also we are storing the height of water stored by each building but at the same time we are ensuring by applying some if else check that if we store some water currently
// in that particular index it doesn't flow

int trap(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int leftMax=0,rightMax=0,l=0,r=n-1;
        while(l<=r){
            if(arr[l]<=arr[r]){
                leftMax=max(leftMax,arr[l]);
                ans+=(leftMax-arr[l]);
                l++;
            }
            else{
                rightMax=max(rightMax,arr[r]);
                ans+= (rightMax-arr[r]);
                r--;
            }
        }
        return ans;
    }

