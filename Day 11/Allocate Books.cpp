// Problem Link:  https://www.interviewbit.com/problems/allocate-books/


// Approach : Time Complexity: O(n*log(n)) Space Complexity: O(1)

// SInce if we allot maximum x no. of pages can be allocated to student then,x+1,x+2,x+3,... can also be
// So we can apply binary search

bool isPossible(long long int mid,vector<int> &arr,int k){
    long long int curr=arr[0];
    int cnt=1;
    for(int i=1;i<arr.size();i++){
        if(curr+arr[i]>mid){
            cnt++;
            curr=arr[i];
        }
        else{
            curr+=arr[i];
        }
    }
    return cnt<=k;
}

int solve(long long int l,long long int r,vector<int> &arr,int k){
    int ans;
    while(l<=r){
        long long int mid= (l+r)>>1;
        if(isPossible(mid,arr,k)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int Solution::books(vector<int> &arr, int k) {
    long long int l=INT_MIN;
    int n=arr.size();
    if(n<k){
        return -1;
    }
    long long int r=0;
    for(int i=0;i<n;i++){
        r+=arr[i];
        if(l<arr[i]){
            l=arr[i];
        }
    }
    return solve(l,r,arr,k);
}

