
### Explanation
1. **Function Definition**

   ```cpp
   bool containsDuplicate(vector<int>& nums)
   ```

   - This function takes a reference to a vector of integers (`nums`) and returns a boolean value (`true` or `false`).

2. **Initialize Hash Map**

   ```cpp
   unordered_map<int, int> mapp;
   ```

   - An `unordered_map` named `mapp` is created. This hash map will be used to store each number from the vector as the key and its count (the number of times it appears) as the value.

3. **Count Occurrences**

   ```cpp
   for(int num: nums){
       mapp[num]++;
   }
   ```

   - This `for` loop iterates through each element in the vector `nums`. For each element `num`, it increments its count in the `mapp` hash map.
   - If `num` is encountered for the first time, it is added to `mapp` with a count of 1.
   - If `num` is already present in `mapp`, its count is incremented by 1.

4. **Check for Duplicates**

   ```cpp
   for(auto& pair: mapp){
       if(pair.second >= 2){
           return true;
       }
   }
   ```

   - This `for` loop iterates through each entry (key-value pair) in the `mapp` hash map.
   - `pair.first` is the number from `nums`, and `pair.second` is its count.
   - If any count (`pair.second`) is 2 or greater, it indicates that the number appears at least twice in the array.
   - In such a case, the function immediately returns `true`, indicating that there are duplicates in the array.

5. **Return False if No Duplicates**

   ```cpp
   return false;
   ```

   - If the loop completes without finding any count of 2 or more, it means every number in `nums` is unique.
   - The function returns `false`, indicating that no duplicates were found.

### Summary

- **Time Complexity**: \(O(n)\), where \(n\) is the number of elements in `nums`. This is because both inserting elements into the hash map and checking for duplicates involve linear operations relative to the number of elements.
- **Space Complexity**: \(O(n)\), where \(n\) is the number of unique elements in `nums`. This is the space required for the hash map to store counts of each unique element.

This approach efficiently determines if any element in the array appears more than once by using a hash map to track the occurrences of each element.