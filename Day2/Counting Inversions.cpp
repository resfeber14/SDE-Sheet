// Problem Link:  https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#


// Approach : Time Complexity: O(N*log(N)), Space Complexity: O(N)

long long merge(long long arr[],long long temp[],long long l,long long mid,long long r){
        long long int l1=l,r1=mid-1,l2=mid,r2=r;
        long long cnt=0;
        long long int k=l;
        while(l1<=r1 && l2<=r2){
            if(arr[l1]<=arr[l2]){
                temp[k]=arr[l1];
                k++;
                l1++;
            }
            else{
                temp[k]=arr[l2];
                cnt+= (mid-l1);
                l2++;
                k++;
            }
        }
        while(l1<=r1){
            temp[k]=arr[l1];
            l1++,k++;
        }
        while(l2<=r2){
            temp[k]=arr[l2];
            l2++,k++;
        }
        for(int x=l;x<=r;x++){
            arr[x]=temp[x];
        }
        return cnt;
    }
    
    long long mergesort(long long arr[],long long temp[], long long l,long long r){
        if(l>=r){
            return 0;
        }
        
        long long mid=(l+r)>>1;
        long long int inv=0;
        inv+=mergesort(arr,temp,l,mid);
        inv+= mergesort(arr,temp,mid+1,r);
        inv+=merge(arr,temp,l,mid+1,r);
        return inv;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long i=0;
        long long int temp[n];
        long long ans=mergesort(arr,temp,i,n-1);
        return ans;
    }
