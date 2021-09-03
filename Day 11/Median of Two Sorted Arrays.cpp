// Problem Link:  https://leetcode.com/problems/median-of-two-sorted-arrays/


// Approach 1: Time complexity: O(N+M) Space Complexity: O(1)
// Linearly traverse the arrays and keep a count variable.Keep checking if the count is equal to the array's index at which median will be found,then add it into anoter variable

double solve(vector<int>& arr1, vector<int>& arr2){
        double ans;
        int cnt=-1;
        int n=arr1.size()+arr2.size();
        int i=0,j=0;
        bool flag=false;
        if(n%2==0)
            flag=true;
        while(i<arr1.size() && j<arr2.size()){
            cnt++;
            if(cnt==(n)/2){
                ans= ans+  (double)min(arr1[i],arr2[j]);
                if(flag)
                    ans=ans/2.0;
                return ans;
            }
            else if(flag){
                if(cnt==(n)/2 -1){
                    ans=ans+ (double)min(arr1[i],arr2[j]);
                    
                }
            }
            if(arr1[i]>arr2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        while(i<arr1.size()){
            cnt++;
            if(cnt==(n)/2){
                ans= ans+ (double)arr1[i];
                if(flag)
                    ans=ans/2.0;
                return ans;
            }
            
            else if(flag && cnt==(n)/2-1){
                ans= ans+(double)arr1[i];
            }
            i++;
        }
        while(j<arr2.size()){
            cnt++;
            if(cnt==(n)/2){
                ans= ans+ (double)arr2[j];
                if(flag)
                    ans=ans/2.0;
                return ans;
            }
            else if(flag && cnt==(n)/2-1){
                ans= ans+(double)arr2[j];
            }
            j++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        return solve(arr1,arr2);
    }

// Approach 2: Time complexity: O(N+M) Space Complexity: O(1)

// To solve this problem, we need to understand "What is the use of median". In statistics, the median is used for dividing a set into two equal length subsets, 
// that one subset is always greater than the other. If we understand the use of median for dividing, we are very close to the answer.

// Here we can divide the arrays into 2 parts and then return the median
// Like dividing the array such that first x elements and first n-x elements will be there in the first part


double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        if(n>m){ // Why n >= m? Because I have to make sure cut2 is non-nagative since 0 <= cut1 <= n and cut2 = (m + n + 1)/2 - cut2. If n > m , then j may be nagative, 
                // that will lead to wrong result.
            return findMedianSortedArrays(arr2,arr1);
        }
        int l=0,r=n;
        while(l<=r){
            int cut1=(l+r)>>1;
            int cut2= (n+m+1)/2 - cut1;
            int left1= (cut1==0) ?INT_MIN: arr1[cut1-1];  // Checking if in the left side whether we have taken  element from the first array 
            int left2= (cut2==0)?INT_MIN: arr2[cut2-1]; // Checking if in the left side whether we have taken  element from the second array 
            int right1= (cut1==n) ? INT_MAX: arr1[cut1]; // Checking if in the right side whether we have taken all the elements from the first array 
            int right2= (cut2==m) ? INT_MAX : arr2[cut2]; // Checking if in the right side whether we have taken all the elements from the second array 
            if(left1<=right2 && left2<=right1){ 
                double x= max(left1,left2);
                double y= min(right1,right2);
                if((n+m)%2==0){
                    return (x+y)/2.0;
                }
                else{
                    return min(x,y);
                }
            }
            else if(left1>right2){
                r=cut1-1;
            }
            else if(left2>right1){
                l=cut1+1;
            }
        }
        return 0.0;
    }


