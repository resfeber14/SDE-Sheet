// Approx same as Next Permutations

// Same as next permutation
    int nextGreaterElement(int n1) {
      //  int n=arr.size();
        if(n1==INT_MAX)
            return -1;
        vector<int> arr;
        
        int x=n1;
        while(x){
            int p=x%10;
            arr.push_back(p);
            x/=10;
        }
        reverse(arr.begin(),arr.end());
        int n=arr.size();
        int ind1=-1,ind2=-1;
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                ind1=i-1;
                break;
            }
        }
        if(ind1==-1){
            return -1;
        }
        else{
            int j=n-1;
            while(1){
                if(arr[j]>arr[ind1]){
                    ind2=j;
                    break;
                    }
                j--;
            }
            swap(arr[ind2],arr[ind1]);
            int i=ind1+1;
            j=n-1;
            // reversing the right part
            while(i<j){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
       long long int num=0;
        for(int i=0;i<n;i++){
            num=num*10+arr[i];
        }
        if(num<=INT_MAX)
        return num;
        return -1;
    }
