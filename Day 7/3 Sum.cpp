// Problem Link:  https://leetcode.com/problems/3sum/
 
// Approach 1: Time Complexity: O(N*N*N*log(N)) Space Complexity: O(N) log(N) is for inserting an element into set
// Iterate over the array by creating 3 loops.
// Take a set push all the indices {a,b,c} where arr[a]+arr[b]+arr[c]==target
// Then push them into a vector and return it


// Approach 2: Time Complexity: O(N*N*log(N)) Space Complexity: O(N)
// Create a set and a map,insert the frequency of each element in the map
// in loop of arr[i],do m[arr[i]]-- and in j loop do m[arr[j]]--,then in map search for k-arr[i]-arr[j],if there is such triplet,store it into set in sorted form .
// when j loop ends do m[arr[j]]++ and when i loop ends m[arr[i]]++
// At last insert all the triplets in the vector


// Approach 3: Use 2 Pointer  Time Complexity: O(N*N) Space Complexity: O(N)
// Sort the array
// Traverse the array.Since array is sorted take l=i,r=n-1
// if the arr[l]+arr[r]+arr[i]>k ,then we need to reduce the sum of arr[l]+arr[r].Since the array is sorted we can do this by r--
// Similarly, if arr[l]+arr[r]+arr[i]<k ,then we need to increase the sum of arr[l]+arr[r].Since the array is sorted we can do this by l++
// else if arr[l]+arr[r]+arr[i]==k , push it into the vector.then increment l till arr[l]!=arr[l+1] and decrement r till arr[r]!=arr[r-1], since we do not want duplicates

vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int> > v;
        for(int i=0;i<n-2;i++){
            if(i>0 && arr[i]==arr[i-1])
                continue;
            int x=arr[i];
            int j=i+1,k=n-1;;
            while(j<k){
                if(arr[j]+arr[k]+x>0){
                    k--;
                }
                else if(arr[j]+arr[k]+x<0){
                    j++;
                }
                else{
                    v.push_back({x,arr[j],arr[k]});
                    while(j+1<n && arr[j]==arr[j+1]){
                        j++;
                    }
                    while(k-1>=0 && arr[k]==arr[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return v;
    }
