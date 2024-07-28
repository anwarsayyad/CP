### Code Breakdown and Explanation

```cpp
#include<bits/stdc++.h>
using namespace std;
```

- **Includes** the standard library header file `<bits/stdc++.h>`, which includes most of the standard C++ libraries. `using namespace std;` allows using standard library features without prefixing them with `std::`.

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
```

- **Defines** a class `Solution` with a public method `smallerNumbersThanCurrent` that takes a vector of integers `nums` and returns a vector of integers.

```cpp
        vector<int> ans(nums);
```

- **Creates** a copy of the input vector `nums` named `ans`. This is used to manipulate and sort the values for comparison.

```cpp
        map<int,int> count;
```

- **Declares** a map `count` where each key is an integer from the `nums` vector, and each value is the number of elements smaller than the key.

```cpp
        sort(ans.begin(), ans.end());
```

- **Sorts** the `ans` vector in ascending order. This helps in determining the number of elements smaller than each element in the original vector.

```cpp
        for(int i = nums.size() - 1; i >= 0; i--)
            count[ans[i]] = i;
```

- **Iterates** from the end of the sorted `ans` vector to the beginning. For each element `ans[i]`, it sets the `count` map entry `count[ans[i]]` to the index `i`. This index represents the count of elements smaller than `ans[i]`.

```cpp
        ans.clear();
```

- **Clears** the `ans` vector to reuse it for storing the final results. This empties the vector, preparing it for the next use.

```cpp
        for(int i = 0; i < nums.size(); i++)
            ans.push_back(count[nums[i]]);
```

- **Fills** the `ans` vector with the counts of smaller numbers for each element in the original `nums` vector. For each `nums[i]`, it looks up `count[nums[i]]` and appends it to `ans`.

```cpp
        return ans;
    }
};
```

- **Returns** the `ans` vector, which now contains the number of elements smaller than each element in the original `nums` vector.

---

### Summary

1. **Copy and Sort**: The solution creates a sorted copy of the input vector `nums`.
2. **Count Elements**: It uses a map to record the index of each element in the sorted vector, which corresponds to the count of smaller elements.
3. **Map Lookup**: It then clears the `ans` vector and fills it with the number of smaller elements for each original element.
4. **Return Result**: Finally, it returns the populated `ans` vector.