// Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

// Approach: Time complexity: O(N)+ O(N) Space Complexity: O(N)

// Here for every element just find its next greater element to the left
// In the stack,store the indices.
// Basically, One by one we are considering each element as the smallest element upto that index and then we are finding how many else were consecutively smaller than it
// and we pop all such elements.
vector <int> calculateSpan(int arr[], int n){
       vector <int> v;
       stack<int > s;
       for(int i=0;i<n;i++){
           while(!s.empty() && arr[s.top()]<=arr[i]){
               s.pop();
           }
           if(s.empty()){
               v.push_back(i+1);
           }
           else{
               v.push_back(i-s.top());
           }
           s.push(i);
       }
       return v;
    }
