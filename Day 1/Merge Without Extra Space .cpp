// Problem Link:  https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#



// Approach 1: Time Complexity: O(N+M) Space Complexity: O(N*M)

// Here we take a vector in which insert the elements from the two arrays in a sorted manner.
// After this,we traverse the vector and put n elements in the first array and rest m in the second array

void merge(long long arr1[], long long arr2[], int n, int m) { 
            int i=0,j=0;
            vector<int> v;
            while(i<n && j<m){
                if(arr1[i]>arr2[j]){
                    v.push_back(arr2[j]);
                    j++;
                }
                else{
                    v.push_back(arr1[i]);
                    i++;
                }
            }
            while(i<n){
                v.push_back(arr1[i]);
                i++;
            }
            while(j<m){
                v.push_back(arr2[j]);
                j++;
            }
        
        for(int i=0;i<n;i++){
            arr1[i]=v[i];
        }
        for(int i=0;i<m;i++){
            arr2[i]=v[i+n];
        }
    }


// Approach 2: Time Complexity: O((N*log(N)+(M*log(M)) Space Complexity: O(1)

// Here we maintain 2 pointers, one pointing at the end of the first array and the second at the starting of the second array
// If we get arr1[i]>arr2[j] => swap(arr1[i],arr2[j]) , i--,j++;
// If we get arr2[j]<=arr1[i], it means if the current arr1[j]>=arr1[i],then all the elements right to j in arr2 will also be greater than arr1[i].So, we don't need to traverse
// And hence we break the loop

void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=n-1,j=0;
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i],arr2[j]);
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
           sort(arr1,arr1+n);
           sort(arr2,arr2+m);
    }
