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
public:
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> size(n + 1, 1);
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    int x = find(parent, i);
                    int y = find(parent, j);
                    if (x != y) {
                        parent[x] = y;
                        size[y] += size[x];
                    }
                    y = find(parent, i / j);
                    if (x != y) {
                        parent[x] = y;
                        size[y] += size[x];
                    }
                }
            }
            if (isPrime) {
                primes.push_back(i);
            }
        }
        unordered_map<int, int> primeToIndex;
        for (int i = 0; i < primes.size(); i++) {
            primeToIndex[primes[i]] = i;
        }
        for (int num : nums) {
            for (int prime : primes) {
                if (prime > num) {
                    break;
                }
                if (num % prime == 0) {
                    int x = find(parent, num);
                    int y = find(parent, prime);
                    if (x != y) {
                        parent[x] = y;
                        size[y] += size[x];
                    }
                    while (num % prime == 0) {
                        num /= prime;
                    }
                }
            }
        }
        int res = 0;
        for (int num : nums) {
            res = max(res, size[find(parent, num)]);
        }
        return res;        
    }
};