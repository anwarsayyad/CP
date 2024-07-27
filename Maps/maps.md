### `std::map` vs `std::unordered_map`

Both `std::map` and `std::unordered_map` are associative containers in C++ that store key-value pairs, but they differ in their underlying data structures, ordering, and time complexities.

#### **`std::map`**

**Description**:
- **Header**: `#include <map>`
- **Declaration**: `std::map<KeyType, ValueType>`
- **Sorting**: Maintains keys in a sorted order (default is ascending).
- **Underlying Data Structure**: Typically implemented as a self-balancing binary search tree (e.g., Red-Black Tree).

**Time Complexities**:

| Operation          | Time Complexity |
|--------------------|-----------------|
| **Insertion**      | `O(log N)`       |
| **Deletion**       | `O(log N)`       |
| **Search (Find)**  | `O(log N)`       |
| **Access (Operator[])** | `O(log N)`   |
| **Iteration**      | `O(N)`           |

**Usage Example**:
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 3;
    myMap["banana"] = 2;
    myMap["cherry"] = 5;

    auto it = myMap.find("banana");
    if (it != myMap.end()) {
        std::cout << "Found banana with value: " << it->second << std::endl;
    }

    for (const auto& pair : myMap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    return 0;
}
```

#### **`std::unordered_map`**

**Description**:
- **Header**: `#include <unordered_map>`
- **Declaration**: `std::unordered_map<KeyType, ValueType>`
- **Sorting**: Does not maintain any order for keys.
- **Underlying Data Structure**: Implemented as a hash table.

**Time Complexities**:

| Operation          | Time Complexity (Average) | Time Complexity (Worst Case) |
|--------------------|---------------------------|------------------------------|
| **Insertion**      | `O(1)`                     | `O(N)`                        |
| **Deletion**       | `O(1)`                     | `O(N)`                        |
| **Search (Find)**  | `O(1)`                     | `O(N)`                        |
| **Access (Operator[])** | `O(1)`                 | `O(N)`                        |
| **Iteration**      | `O(N)`                     | `O(N)`                        |

**Explanation**:
- **Average Case**: The average time complexity for operations is constant, `O(1)`, because hash table operations (insertion, deletion, and search) generally take constant time.
- **Worst Case**: In cases of hash collisions or poor hash function performance, the time complexity can degrade to `O(N)`, where `N` is the number of elements in the map. This is due to all elements being placed into a single bucket.

**Usage Example**:
```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;
    myMap["apple"] = 3;
    myMap["banana"] = 2;
    myMap["cherry"] = 5;

    auto it = myMap.find("banana");
    if (it != myMap.end()) {
        std::cout << "Found banana with value: " << it->second << std::endl;
    }

    for (const auto& pair : myMap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    return 0;
}
```

### Summary of Differences

- **Order**:
  - `std::map`: Sorted by keys.
  - `std::unordered_map`: No guaranteed order of keys.

- **Underlying Data Structure**:
  - `std::map`: Self-balancing binary search tree.
  - `std::unordered_map`: Hash table.

- **Performance**:
  - `std::map`: Logarithmic time complexities for insertion, deletion, and search.
  - `std::unordered_map`: Average constant time complexities for insertion, deletion, and search, but can degrade to linear time in the worst case due to hash collisions.

Both containers have their use cases. `std::map` is ideal when you need to maintain order and perform ordered operations, while `std::unordered_map` is better suited for scenarios where performance is critical and order is not a concern.