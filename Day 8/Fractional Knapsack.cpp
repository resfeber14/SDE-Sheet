// Problem Link:  https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

// Approach: Time complexity: O(N*logN+ N) Space Complexity: O(1)
// Sort the array in the decreasing order of value per weight
// Now traverse and add the profit of the current element if W<=arr[i].weight
// else take the fractional part of it and break;


static bool comp(Item arr1,Item arr2){
        
        return double(arr1.value)/double(arr1.weight)>double(arr2.value)/double(arr2.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else{
                ans+= (double(arr[i].value)/double(arr[i].weight))*double(W);
                W=0;
                break;
            }
        }
        return ans;
    }
