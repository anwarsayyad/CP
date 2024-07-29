#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mapp;
        for(int num: nums){
            mapp[num]++;
        }
        for(auto& pair: mapp){
            if(pair.second >= 2){
                return true;
            }
        }

        return false;
    }
};