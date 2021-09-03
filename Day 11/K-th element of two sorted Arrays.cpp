// Problem Link:  https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#


// Approach 1: Time Complexity: O(log(min(n,m))) Space Complexity: O(1)

// Same as find the median of  2 sorted arrays

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m){
            return kthElement(arr2,arr1,m,n,k);
        }
  // We are taking low =max(k-m,0) bcoz there is a possibility that k will be >m so,while dividing the arrays into 2 parts,we need to take some elmeents from the arr1.
  // So, we are taking low=max(k-m,0)
  // We are taking r= min(k,n) bcoz there is a possibility that we need to take k elements from the array 1 
  // and if k<n then also we can only take at max k elements as we are making the size of one part of an array=k
        int l=max(k-m,0),r=min(k,n);
        while(l<=r){
            int cut1=(l+r)>>1;
            int cut2= k-cut1;
            int left1= cut1==0? INT_MIN: arr1[cut1-1];
            int left2= cut2==0 ? INT_MIN : arr2[cut2-1];
            int right1= cut1==n ? INT_MAX : arr1[cut1]; 
            int right2= cut2==m ? INT_MAX: arr2[cut2];
            if(left1<=right2 && left2<=right1){
                return max(left1,left2);
            }
            else if(left1>right2){
                r=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return -1;
    }
