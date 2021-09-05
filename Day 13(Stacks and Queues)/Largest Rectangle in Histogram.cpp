// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Approach 1: Time complexity: O(N*N) Space Complexity: O(4*n)
// Traverse the whole array Linearly for finding next smaller element to the left and to the right of the current element and find the current maximum
// Rectangle of the histogram and thus find the maximum one

// Approach 2: Time complexity: O(N) Space Complexity: O(3*n)
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
    
// Approach 2: Time complexity: O(N) +O(N) Space complexity: O(N)
// Here we can push the elemets into the stack if it is empty or it is greater than the element at the top of the stack
// else if the element at the top of the stack is greater than or equal to the current element , We have found the next smaller element at the right,i.e. arr[i] for the 
// element at the top of the stack.Now we pop the stack
// And if there is still an element in the top of the stack then it will be the obviously lesser than what was earlier in the top of the stack which we currently popped
// then that will be the nearest smaller to the left then width will be (i-s.top()-1)
// else if the stack becomes empty after popping then Consider width will be i


int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[s.top()]>=arr[i])){
                int curr_height= arr[s.top()];
                s.pop();
                int width;
                if(s.empty())
                    width=i;
                else
                    width= i-s.top()-1;
                ans= max(ans,width*curr_height);
                }
            s.push(i);
        }
        return ans;
    }
