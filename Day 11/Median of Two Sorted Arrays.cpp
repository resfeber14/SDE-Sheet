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



