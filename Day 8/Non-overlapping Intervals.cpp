/*
Problem Link: https://leetcode.com/problems/non-overlapping-intervals/
*/

#define s second
#define f first
class Solution {
public:
    static bool comp(pair<int,pair<int,int > > &p1,pair<int,pair<int,int > > &p2){
        return p1.s.f<p2.s.f;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,pair<int,int > > > arr; // start time ,finish time, index
        int n=intervals.size();
        for(int i=0;i<n;i++){
            arr.push_back({intervals[i][0],{intervals[i][1],i+1}});
        }
        sort(arr.begin(),arr.end(),comp);
      /*  for(int i=0;i<arr.size();i++){
            cout<<arr[i].f<<" "<<arr[i].s.f<<"\n";
        }*/
        int ans=0;
        int e=arr[0].s.f;
        for(int i=1;i<arr.size();i++){
            if(e<=arr[i].f){
                e=arr[i].s.f;
            }
            else
                ans++;
        }
        return ans;
    }
};
