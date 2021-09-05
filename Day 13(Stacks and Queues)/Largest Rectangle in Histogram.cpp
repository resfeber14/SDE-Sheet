// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Approach 1: Time complexity: O(n*n) Space Complexity: O(4*n)
// Traverse the whole array Linearly for finding next smaller element to the left and to the right of the current element and find the current maximum
// Rectangle of the histogram and thus find the maximum one

// Approach 2: Time complexity: O(n*n) Space Complexity: O(4*n)
// We are considering the current element's height to be the maximum height and find next smaller element to its left and right
// Use stack to find the next smaller element to the left and to the right of the current element 

int largestRectangleArea(vector<int>& arr) {
    int n=arr.size();
        vector<int> v1,v2;
        stack<int> s1,s2;
        
        // finding next smaller element to the left
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[i]<=arr[s1.top()]){
                s1.pop();
            }
            if(s1.empty()){
                v1.push_back(-1);
            }
            else{
                v1.push_back(s1.top());
            }
            
            s1.push(i);
        }
       
        // finding next smaller element to the right
        for(int i=n-1;i>=0;i--){
            if(s2.empty()){
                v2.push_back(n);
            }
           
                while(!s2.empty() && arr[i]<=arr[s2.top()]){
                    s2.pop();
                }
                if(s2.empty()){
                    v2.push_back(n);
                }
                else{
                    v2.push_back(s2.top());
                }
            
            s2.push(i);
        }
        reverse(v2.begin(),v2.end());
       
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            int curr=v2[i]-v1[i]-1;
            cnt= curr*arr[i];
            ans=max(cnt,ans);
        }
       
        return ans;
    }    
    
