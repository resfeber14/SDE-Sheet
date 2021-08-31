


// Approach 1: Time complexity: O(N*N*N) Space Complexity: O(N)
// Generate all the subarrays



// Approach 2: Time complexity: O(N) Space Complexity: O(N)

// if 0....x xor is y and x+1....j is k and xor 0....j xor is XR then, XR=y^k => y= k ^XR so the ans will be no of times y has appeared+ no of times XR==k

int solve(vector<int> &arr,int k){
	int n=arr.size();
	map<int,int> m;
	int ans=0;
	int curr=0;
	for(int i=0;i<n;i++){
		curr= curr ^ arr[i];
		
		if(curr==k){
			ans++;
		}
		int p= curr ^ k;  
		if(m.find(p)!=m.end()){
			ans+= m[p];
		}
		m[curr]++;
	}
	return ans;
}
