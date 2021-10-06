/*
Problem Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Approach 1: Use hash map

Approach 2: Optimal Approach
Traverse the array and mark the arr[abs(arr[i]-1] as negative that means arr[abs(arr[i]-1]*-1 .This will indicate that the element is visited.
And if we find any arr[abs(arr[i]-1] which is -ve then it means that element has already been visited.So we push into our final vector
[4,3,2,7,8,2,3,1]
First iteration  [4,3,2,-7,8,2,3,1]  (As arr[0]=4 ,arr[4-1]=7 .so to mark this 4 visited we flip its sign
Second iteration:  [4,3,-2,-7,8,2,3,1] (As arr[1]=3 and arr[3-1]=2 so flip its sign
Third iteration [4,-3,-2,-7,8,2,3,1]  (abs(arr[2])=2 now arr[2-1]=3 which is non negative i.e. we haven't visited it earlier.So mark it as visited by flipping its sign
Fourth iteration: [4,-3,-2,-7,8,2,-3,1]  (abs[arr[3])=7 arr[7-1] flip its sign
Fifth iteration: [4,-3,-2,-7,8,2,-3,-1]  (abs(arr[4]=8 arr[8-1]=1 so flip its sign
Sixth iteration: [4,-3,-2,-7,8,2,-3,-1] (abs(arr[5]=2 but arr[2-1] has already been mark visited so we are visiting it again hence push it into the vector
Seventh iteration: [4,-3,-2,-7,8,2,-3,-1]  (abs(arr[6])=3 arr[3-1]<0 hence also push it into the array
Eighth iteration [-4,-3,-2,-7,8,2,-3,-1] (abs(arr[7])=1 arr[1-1]>0 hence mark it visited

*/
for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                v.push_back(abs(arr[i]));
                            
            }
            else
                arr[abs(arr[i])-1]=-1*arr[abs(arr[i])-1];
        }
        return v;

