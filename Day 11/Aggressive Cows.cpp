// Problem link:  https://www.spoj.com/problems/AGGRCOW/


// Approach: Time Complexity: O(n*n) Space Complexity:  O(1)

// Here we will try out all the possible spaces and find the maximum minimum gap



// Approach: Time Complxeity: O(2*n*log(n)) Space Complexity: O(1)
// Here we can apply Binary search on the gaps as if x gap is possible then x+1,x+2,.... will also be possible


int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,c;
    cin>>t;
    while(t--){
    	cin>>n>>c;
    	ll arr[n];
    	forn(i,n){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);
    	ll l=1,r=arr[n-1]-arr[0];
      ll ans;
    	for(int i=1;i<=r;i++){
    		ll cnt=1,curr=arr[0];
    		bool flag=false;
    		for(int j=1;j<n;j++){
    			if(curr+i<=arr[j]){
					cnt++;
					curr=arr[j];
				}
				if(cnt==c){
					flag=true;
					ans=i;
					break;
				}
    	}
    	if(!flag){
    		break;
    	}
    }
    cout<<ans<<"\n";
   }
    
    return 0;
}


ll isPossible(ll mid,ll c,ll arr[],ll n){
	ll x=1;
	ll curr=arr[0];
	for(int i=1;i<n;i++){
		if(curr+mid<=arr[i]){
			x++;
			curr=arr[i];
		}
		if(x==c){
			return true;
		}
	}
	return false;
}

ll solve(ll l,ll r,ll arr[],ll c,ll n){
	ll ans=INT_MAX;
	while(l<=r){
		ll mid= (l+r)>>1;
		if(isPossible(mid,c,arr,n)){
			ans=mid;
		    l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,c;
    cin>>t;
    while(t--){
    	cin>>n>>c;
    	ll arr[n];
    	forn(i,n){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);
    	ll l=1,r=arr[n-1]-arr[0];
    	cout<<solve(l,r,arr,c,n)<<"\n";
    }
    
    return 0;
}
