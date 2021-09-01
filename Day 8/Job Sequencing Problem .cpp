// Problem Link:  https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// Approach: Time complexity: O(N*logN+N*N) Space Complexity: O(N)

// Sort the array according to decreasing amount of profit.Create an array of size n+1 to store if on that day some work has been completed or not
// Initialise that array with -1 which shows no work has been done on the particular day
// Then traverse the array check if there is any day on which we can complete the current task <=deadline
// Here we are traversing backwards bcoz we want each job to be completed late as possible so that afterwards if we get a job we can complete it easily
// eg (10,5) (6,1) here if we complete the task 1 first we get 10 profit and now if we want to do the job 2 we can't since its deadline has passed.
// So if we are taking the job 1 first as its profit is more(10>6) we should complete it as late as possible so that we can save the other days for the jobs having lesser deadline


static bool comp(Job &arr1,Job &arr2){
        if(arr1.profit==arr2.profit){
            return arr1.dead>arr2.dead;
        }
        return arr1.profit>=arr2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int ans=0,cnt=0;
        int done[n+1];
        for(int i=0;i<=n;i++){
            done[i]=-1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(done[j]==-1){
                    done[j]=arr[i].id;
                    ans+= arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        vector<int> v;
        v.push_back(cnt);
        v.push_back(ans);
        return v;
    } 

