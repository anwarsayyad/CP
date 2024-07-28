#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> ans(nums);
        map<int,int> count;

        sort(ans.begin(),ans.end());

        for(int i=nums.size()-1;i>=0;i--)
            count[ans[i]]=i;
            ans.clear();
        for(int i=0;i<nums.size();i++)
            ans.push_back(count[nums[i]]);
        
        return ans;
    }
};