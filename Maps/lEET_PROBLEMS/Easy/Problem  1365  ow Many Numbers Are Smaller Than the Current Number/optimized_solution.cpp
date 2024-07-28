#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> SmallerNumberThenCurrent(vector<int> nums){
        vector<int> ans(nums.size());
        unordered_map<int, int> countMap;
        
        // Step 1: Count occurrences of each number
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Step 2: Calculate smaller counts for each unique number
        vector<int> sortedUniqueNumbers(countMap.size());
        int index = 0;
        for (auto& pair : countMap) {
            sortedUniqueNumbers[index++] = pair.first;
        }
        sort(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end());
        
        unordered_map<int, int> smallerCountMap;
        int smallerCount = 0;
        for (int num : sortedUniqueNumbers) {
            smallerCountMap[num] = smallerCount;
            smallerCount += countMap[num];
        }
        
        // Step 3: Map results back to the original array
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = smallerCountMap[nums[i]];
        }
        
        return ans;
    }
        
};