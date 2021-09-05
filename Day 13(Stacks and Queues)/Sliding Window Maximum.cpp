// Problem Link:  https://leetcode.com/problems/sliding-window-maximum/

// Approach : Time complexity: O(N*K) Space complexity: O(1)
// Traverse the array from i=0 to i<=n-k and then again run a loop from j=i to i+k-1 to find the maximum in every subarray of size k

// Approach: Time complexity: O(N)+ O(K) Space complexity: O(K)

// Have a list/deque and store in it the elements present in array of size k in decreasing order 
// The front will be the index of maximum element in array of size k

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> v;
        int n=arr.size();
        int i=0;
        list<int> l;
        while(i<k){
            while(!l.empty() && arr[l.back()]<=arr[i])
                l.pop_back();
            l.push_back(i);
            i++;
        }
        v.push_back(arr[l.front()]);
        i=1;
        while(i<=n-k){
            if(l.front()<i){
                l.pop_front();
            }
            while(!l.empty() && arr[l.back()]<=arr[i+k-1])
                l.pop_back();
            l.push_back(i+k-1);
            
            v.push_back(arr[l.front()]);
            
            i++;
        }
        return v;
    }
