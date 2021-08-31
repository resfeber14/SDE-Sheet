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
