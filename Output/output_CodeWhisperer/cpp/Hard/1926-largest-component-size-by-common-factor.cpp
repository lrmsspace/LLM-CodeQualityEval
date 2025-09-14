/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//	There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//	There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.
// 
//Example 1:
//Input: nums = [4,6,15,35]
//Output: 4
//Example 2:
//Input: nums = [20,50,9,63]
//Output: 2
//Example 3:
//Input: nums = [2,3,6,7,4,12,21,39]
//Output: 8
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] <= 105
//	All the values of nums are unique.  
class Solution {
    private:
        // Union-Find data structure
        class UnionFind {
        private:
            vector<int> parent;
            vector<int> size;
        public:
            UnionFind(int n) {
                parent.resize(n);
                size.resize(n, 1);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]); // Path compression
                }
                return parent[x];
            }
            
            void unionSet(int x, int y) {
                int rootX = find(x);
                int rootY = find(y);
                
                if (rootX != rootY) {
                    // Union by size
                    if (size[rootX] < size[rootY]) {
                        parent[rootX] = rootY;
                        size[rootY] += size[rootX];
                    } else {
                        parent[rootY] = rootX;
                        size[rootX] += size[rootY];
                    }
                }
            }
            
            int getMaxSize() {
                int maxSize = 0;
                for (int s : size) {
                    maxSize = max(maxSize, s);
                }
                return maxSize;
            }
        };
        
        // Find all prime factors of a number
        vector<int> getPrimeFactors(int num) {
            vector<int> factors;
            
            // Check for divisibility by 2
            if (num % 2 == 0) {
                factors.push_back(2);
                while (num % 2 == 0) {
                    num /= 2;
                }
            }
            
            // Check for divisibility by odd numbers starting from 3
            for (int i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    factors.push_back(i);
                    while (num % i == 0) {
                        num /= i;
                    }
                }
            }
            
            // If num is a prime number greater than 2
            if (num > 2) {
                factors.push_back(num);
            }
            
            return factors;
        }
        
    public:
        int largestComponentSize(vector<int>& nums) {
            int n = nums.size();
            UnionFind uf(n);
            
            // Map to store prime factor to index mapping
            unordered_map<int, int> factorToIndex;
            
            for (int i = 0; i < n; i++) {
                vector<int> factors = getPrimeFactors(nums[i]);
                
                for (int factor : factors) {
                    if (factorToIndex.find(factor) == factorToIndex.end()) {
                        factorToIndex[factor] = i;
                    } else {
                        uf.unionSet(i, factorToIndex[factor]);
                    }
                }
            }
            
            return uf.getMaxSize();
        }
    };
    