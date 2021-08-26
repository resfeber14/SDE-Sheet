// Problem Link:  https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

// Problem Statement

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
// Find these two numbers.

// Approach 1: Time Complexity: O(N), Space Complexity: O(N)

// To get the repeating element, store the frequency of array in a map.
// For getting the missing element, find the sum of 1...N and find the sum of the array. Then the missing element will be abs(sum of array-repeating element-sum(1..N))

int *findTwoElement(int *arr, int n) {
        // code here
        int *a= new int(2);
        map<int,int> m;
        long long int sum=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            if(m[arr[i]]==2){
                a[0]=arr[i];
            }
            sum+=arr[i];
        }
        long long int curr= (1LL*n*(n+1))/2;
        a[1]= abs(sum-a[0]-curr);
        return a;
    }
    
    // Approach 2: Time Complexity: O(N) , Space Complexity: O(1)
    
    
    
