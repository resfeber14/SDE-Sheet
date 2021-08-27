// Problem Link: https://leetcode.com/problems/next-permutation/

Approach: Time Complexity: O(N) Space Complexity: O(1)

// Start from its last element, traverse backward to find the first one with index i that satisfy num[i-1] < num[i]. So, elements from num[i] to num[n-1] is reversely sorted.
// To find the next permutation, we have to swap some numbers at different positions, to minimize the increased amount, 
// we have to make the highest changed position as high as possible. Notice that index larger than or equal to i is not possible as num[i,n-1] is reversely sorted.
// So, we want to increase the number at index i-1, clearly, swap it with the smallest number between num[i,n-1] that is larger than num[i-1]. 
// For example, original number is 121543321, we want to swap the '1' at position 2 with '2' at position 7.
// The last step is to make the remaining higher position part as small as possible, we just have to reversely sort the num[i,n-1]

void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int ind1=-1,ind2=-1;
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                ind1=i-1;
                break;
            }
        }
        if(ind1==-1){
            reverse(arr.begin(),arr.end());
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
    }
