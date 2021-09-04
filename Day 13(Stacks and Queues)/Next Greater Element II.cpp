// Problem Link: https://leetcode.com/problems/next-greater-element-ii/

// Approach: Time complexity: O(N)+O(N), Space complexity: O(1)

// Basically here we are traversing from 2*n-1 bcoz we also want to consider the previous as well as right elements of the vector So we are doing this so that we can get
        // the next greater in the stack

vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> v(n,-1);
        
        stack<int> s;
        
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && s.top()<=arr[i%n]){
                s.pop();
            }
            if(i<n) {
                if(!s.empty()) 
                    v[i] = s.top(); 
            }
            s.push(arr[i%n]);
        }
        return v;
    }
