/**https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/ */
//Given an array of integers arr.
//We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
//Let's define a and b as follows:
//	a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
//	b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
//Note that ^ denotes the bitwise-xor operation.
//Return the number of triplets (i, j and k) Where a == b.
// 
//Example 1:
//Input: arr = [2,3,1,6,7]
//Output: 4
//Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
//Example 2:
//Input: arr = [1,1,1,1,1]
//Output: 10
// 
//Constraints:
//	1 <= arr.length <= 300
//	1 <= arr[i] <= 108
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        // Count the number of pairs (i, j) where arr[i] ^ arr[j] == 0
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[arr[i]]++;
        }
        
        // Iterate over all possible pairs (i, j)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                count += map[arr[i] ^ arr[j]];
            }
        }
        
        // Iterate over all possible triplets (i, j, k)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                count -= map[arr[i] ^ arr[j]];
                count += map[arr[i] ^ arr[j] ^ arr[j + 1]];
            }
        }
        
        return count;
        
    }
};