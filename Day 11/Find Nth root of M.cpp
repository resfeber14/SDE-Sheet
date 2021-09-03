// Problem Link:  https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1#

int solve(long long int l,long long int r,int n,int m){
	    int ans=-1;
	    while(l<=r){
	        
	        long long int mid=(l+r)>>1;
	        
	        long long int temp=1;
	        for(int i=1;i<=n;i++){
	            temp*= mid;
	            if(temp>m){
	                temp=INT_MAX;
	                break;
	            }
	        }
	       // cout<<mid<<" "<<temp<<"\n";
	        if(temp>m){
	             r=mid-1;
	        }
	        else if(temp<m){
	            l=mid+1;
	        }
	        else{
	            return mid;
	        }
	    }
	    return -1;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long int l=1,r=m;
	    return solve(l,r,n,m);
	}  
