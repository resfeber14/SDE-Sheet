// Problme Link:  https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

// Approach 1: Time Complexity: O(N*N*N) Space Complexity: O(1)
// Generate all the subarrays and store the largest length

void subArray(int arr[], int n)
{
    // Pick starting point
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";
 
            cout << endl;
        }
    }
}


// Approach 2: Time Complexity: O(N) Space Complexity: O(N)+O(N)

// Create a prefix sum array and store the index of that prefix sum in a map
// Now iterate over the prefix sum array and search if that element is present in the array or not.If yes then ans=max(ans,m[pre[i]-i)

int maxLen(int arr[], int n)
{
    // Your code here
    int pre[n+1];
    map<int,int> m;
    pre[0]=0;
    m[0]=0;
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+arr[i];
        m[pre[i+1]]=i+1;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        int x=m[pre[i]];
        ans=max(ans,x-i);
    }
    return ans;
}

// Approach 3: Time Complexity: O(N) Space Complexity: O(N)
// We don't need to have a prefix sum array.
// Take a map which will store the element and its index
// Take a sum variable store the running sum in it,if the current sum is present in the map,then ans=max(ans,i+1-m[sum])

int maxLen(int arr[], int n)
{
    // Your code here
    map<int,int> m;
    int sum=0;
    m[0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(m.find(sum)!=m.end()){
            ans=max(ans,i+1-m[sum]);
        }
        else{
            m[sum]=i+1;
        }
    }
    
    return ans;
}
