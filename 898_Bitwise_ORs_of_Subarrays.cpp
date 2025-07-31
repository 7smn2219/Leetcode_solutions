class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<bitset<32>> seen, current; // Using bitset to represent bitwise ORs
        int result = 0;
        for (int num : arr) {
            unordered_set<bitset<32>> next; // To store the next set of ORs
            next.insert(bitset<32>(num)); // Start with the current number as a new subarray

            for (const auto& s : current) {
                bitset<32> new_or = s | bitset<32>(num); // Perform bitwise OR with the current number
                next.insert(new_or); // Add the new OR to the next set
            }

            // Merge the current set of ORs with the next set
            current = move(next);   
            // Add all current ORs to the seen set
            seen.insert(current.begin(), current.end());
        }
        return seen.size();
    }
};

/*
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
Example 3:

Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] <= 109
*/