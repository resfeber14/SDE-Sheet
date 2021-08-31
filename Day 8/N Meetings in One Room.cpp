// Problem Link:  https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

// Approach : Time Complexity: O(N*logN+ON) Space Complexity: O(N)

static bool comp(pair<int,int> &p1,pair<int,int> &p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        return p1.second<p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int s=-1,e=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i].first>e){
                s=v[i].first;
                e=v[i].second;
                ans++;
            }
        }
        return ans;
    }

// Modification of above problem:

// Problem Link:  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

static bool comp(vector<int> &v1,vector<int> &v2){
        if(v1[1]==v2[1]){
            return v1[0]<v2[0];
        }
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int n=arr.size();
        if(n==1)
            return 1;
        int s=arr[0][0],e=arr[0][1];
        int ans=1;
        int i;
        for(i=1;i<n;i++){
            if(arr[i][0]>e){
                ans++;
                s=arr[i][0];
                e=arr[i][1];
            }

        }
        return ans;
    }
