// Problem Link:  https://leetcode.com/problems/4sum/

// Approach 1: Time Complexity: O(N*N*N*log(N)) Space Complexity: O(N)
// Run 3 loops and then apply binary search to check if (k-(arr[i]+arr[j]+arr[k])) is present or not
// Store all those quadraplets in a set to get unique ones.
// now push into a vector and return

// Approach 2: Time Complexity: O(N*N*N) Space Complexity: O(N)

// Run 2 loops and take 2 pointers to check if that pair's sum is equal to k-arr[i]-arr[j] or not.If there is such pair store it,and increment l and r pointer till they
// are not equal to the current l and r
// for eg: 2 3 2 3 2 3 k=10
// if take i=0,j=1,then l=2,r=5 2+3= -(arr[i]+arr[j]) 
// Now we can't just increment the l and decrement r ,bcoz we will stil get {2,3} since in question there is written that we can't use the same pair
// So we are incrementing l and r toll they are not equal tothe current one

// We are also not taking the same element everytime  by writing if(i>0 && arr[i]==arr[i-1]) continue;
// As for eg: 2 2 2 3 3 k=10
// firstly (0,1,3,4) will be the pair i.e. (2,2,3,3)
// but again for i if will take index i,then it will give the same pair  (1,2,3.4) and the element will be the same (2,2,3,3) so this we can't take as written in the question

vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        int n=arr.size();
        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            // To avoid duplicates of i
            if(i>0 && arr[i]==arr[i-1])
                continue;
            for(int j=i+1;j<n-2;j++){
              // To avoid duplicates of j
                if(arr[j]==arr[j-1] && j-i>1)
                    continue;
                int l=j+1,r=n-1;
                int x=tar-arr[j]-arr[i];
                while(l<r){
                    if(arr[l]+arr[r]>x){
                        r--;
                    }
                    else if(arr[l]+arr[r]<x){
                        l++;
                    }
                    else if(arr[l]+arr[r]==x){
                        cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<x<<"\n";
                        v.push_back({arr[i],arr[j],arr[l],arr[r]});
                        while(l<r && arr[l]==arr[l+1])
                            l++;
                        while(l<r && arr[r]==arr[r-1])
                            r--;
                        l++,r--;
                    }
                }
            }
        }
        return v;
    }
