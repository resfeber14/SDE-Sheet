// Problem Link:  https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

// Approach : Time Complexity: O(2*N*logN+2*N) Space Complexity: O(1)

// Sort both arrays.We are sorting here bcoz we want to keep the track of time when trains are coming and leaving.
// And then keep a left pointer to starting of the array and keep moving right pointer everytime
// Check if arr[r]>dep[l],then this means lth indexed train has arrived,so we can successfully increment left and right pointer
// if arr[r]<=dep[l],this means the train hasn't departed yet,so we need another platform, so do cnt++ 

int findPlatform(int arr[], int dep[], int n){
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int l=0,r=1;
    	int ans=1,cnt=1;
    	while(r<n){
    	    if(arr[r]>dep[l]){
    	        l++;
    	    }
    	    else{
    	        cnt++;
    	    }
    	    ans=max(ans,cnt);
    	    r++;
    	}
    	return ans;
    }
