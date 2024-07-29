
### Logic Explanation

1. **Initialize Hash Map**:
   - **Purpose**: To count occurrences of each number in the array.
   - **Data Structure**: `unordered_map<int, int> mapp;`
     - Key: The number from the array.
     - Value: The count of how many times this number has appeared.

2. **Count Occurrences**:
   - **Loop**: `for(int num: nums)`
   - **Purpose**: To process each element in the `nums` array.
   - **Action**: `mapp[num]++`
     - **Explanation**: For each number in the array, increment its count in the hash map. If a number is seen for the first time, it is added to the hash map with a count of 1. If it’s seen again, its count is incremented.

3. **Check for Duplicates**:
   - **Loop**: `for(auto& pair: mapp)`
   - **Purpose**: To check if any number has a count of 2 or more.
   - **Condition**: `if(pair.second >= 2)`
     - **Explanation**: `pair.second` represents the count of a particular number. If any number’s count is 2 or more, it means the number is a duplicate.
   - **Action**: `return true;`
     - **Explanation**: If a duplicate is found (i.e., any number appears at least twice), return `true`.

4. **Return False**:
   - **Action**: `return false;`
   - **Purpose**: If the loop finishes without finding any duplicates (i.e., all numbers are unique), return `false`.

### Summary

- **Time Complexity**: \(O(n)\), where \(n\) is the number of elements in the `nums` array. This is because inserting into and looking up in the hash map each take average constant time.
- **Space Complexity**: \(O(n)\), where \(n\) is the number of unique elements in `nums`. This is due to the space used by the hash map to store counts.
