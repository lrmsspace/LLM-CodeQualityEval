/**https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/ */
//Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
// 
//Example 1:
//Input: n = 13, k = 2
//Output: 10
//Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//Example 2:
//Input: n = 1, k = 1
//Output: 1
// 
//Constraints:
//	1 <= k <= n <= 109  
class Solution {
    public:
        int findKthNumber(int n, int k) {
            int current = 1; // Start with the smallest number (1)
            k--; // Since we're already at 1, we need to find the (k-1)th number after 1
            
            while (k > 0) {
                // Calculate how many nodes are in the subtree starting with current
                long long count = countNodes(n, current, current + 1);
                
                if (k >= count) {
                    // If k is greater than or equal to the count, skip this subtree
                    k -= count;
                    current++; // Move to the next sibling
                } else {
                    // If k is less than the count, the kth number is in this subtree
                    k--;
                    current *= 10; // Move to the first child
                }
            }
            
            return current;
        }
        
    private:
        // Count the number of nodes in the range [n1, n2) and <= n
        long long countNodes(int n, long long n1, long long n2) {
            long long count = 0;
            
            // Count nodes level by level
            while (n1 <= n) {
                // Add the number of nodes at this level
                count += min((long long)n + 1, n2) - n1;
                
                // Move to the next level
                n1 *= 10;
                n2 *= 10;
            }
            
            return count;
        }
    };
    