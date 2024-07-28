### Optimized Approach

1. **Count Occurrences**: Count the occurrences of each number in the array.
2. **Calculate Smaller Counts**: Calculate the cumulative counts of elements smaller than each unique value.
3. **Map Results**: Map the results back to the original array.

### Detailed Solution

Here's the optimized solution step-by-step, and its corresponding C++ code:

```cpp

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
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
```

### Explanation

1. **Count Occurrences**

   ```cpp
   unordered_map<int, int> countMap;
   for (int num : nums) {
       countMap[num]++;
   }
   ```

   - Use an unordered map (`countMap`) to count the occurrences of each number in the array.

2. **Calculate Smaller Counts**

   ```cpp
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
   ```

   - Create a vector of unique numbers from `countMap` and sort it.
   - Use another unordered map (`smallerCountMap`) to store the number of elements smaller than each unique number.
   - Iterate through the sorted unique numbers to compute and store cumulative counts of elements smaller than each number.

3. **Map Results Back to Original Array**

   ```cpp
   for (int i = 0; i < nums.size(); i++) {
       ans[i] = smallerCountMap[nums[i]];
   }
   ```

   - Use the `smallerCountMap` to look up and populate the result vector `ans` with the count of smaller elements for each original number.

### Time Complexity

- **Counting Occurrences**: O(n), where `n` is the size of the input array.
- **Sorting Unique Numbers**: O(k log k), where `k` is the number of unique elements.
- **Building the Result**: O(n).
