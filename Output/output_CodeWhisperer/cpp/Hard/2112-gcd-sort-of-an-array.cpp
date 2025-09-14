/**https://leetcode.com/problems/gcd-sort-of-an-array/ */
//You are given an integer array nums, and you can perform the following operation any number of times on nums:
//	Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
//Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.
// 
//Example 1:
//Input: nums = [7,21,3]
//Output: true
//Explanation: We can sort [7,21,3] by performing the following operations:
//- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
//- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
//Example 2:
//Input: nums = [5,2,6,2]
//Output: false
//Explanation: It is impossible to sort the array because 5 cannot be swapped with any other element.
//Example 3:
//Input: nums = [10,5,9,3,15]
//Output: true
//We can sort [10,5,9,3,15] by performing the following operations:
//- Swap 10 and 15 because gcd(10,15) = 5. nums = [15,5,9,3,10]
//- Swap 15 and 3 because gcd(15,3) = 3. nums = [3,5,9,15,10]
//- Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,10,15]
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	2 <= nums[i] <= 105 
class Solution {
    public:
        bool gcdSort(vector<int>& nums) {
            // Find the maximum number in the array
            int maxNum = *max_element(nums.begin(), nums.end());
            
            // Initialize Union-Find data structure
            UnionFind uf(maxNum + 1);
            
            // For each number in the array, connect it with all its prime factors
            for (int num : nums) {
                int temp = num;
                for (int factor = 2; factor * factor <= temp; factor++) {
                    if (temp % factor == 0) {
                        // Connect the number with its factor
                        uf.unionSets(num, factor);
                        
                        // Remove all occurrences of this factor
                        while (temp % factor == 0) {
                            temp /= factor;
                        }
                    }
                }
                
                // If there's a remaining prime factor greater than sqrt(num)
                if (temp > 1) {
                    uf.unionSets(num, temp);
                }
            }
            
            // Create a sorted copy of the array
            vector<int> sortedNums = nums;
            sort(sortedNums.begin(), sortedNums.end());
            
            // Check if each element can be swapped to its correct position
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != sortedNums[i] && !uf.connected(nums[i], sortedNums[i])) {
                    return false;
                }
            }
            
            return true;
        }
        
    private:
        // Union-Find data structure
        class UnionFind {
        private:
            vector<int> parent;
            
        public:
            UnionFind(int size) {
                parent.resize(size);
                
                // Initialize each element as its own parent
                for (int i = 0; i < size; i++) {
                    parent[i] = i;
                }
            }
            
            // Find the root of the set with path compression
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }
            
            // Union two sets
            void unionSets(int x, int y) {
                parent[find(x)] = find(y);
            }
            
            // Check if two elements are in the same set
            bool connected(int x, int y) {
                return find(x) == find(y);
            }
        };
    };
    