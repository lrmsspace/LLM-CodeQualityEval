/**https://leetcode.com/problems/beautiful-arrangement/ */
//Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
//	perm[i] is divisible by i.
//	i is divisible by perm[i].
//Given an integer n, return the number of the beautiful arrangements that you can construct.
// 
//Example 1:
//Input: n = 2
//Output: 2
//Explanation: 
//The first beautiful arrangement is [1,2]:
//    - perm[1] = 1 is divisible by i = 1
//    - perm[2] = 2 is divisible by i = 2
//The second beautiful arrangement is [2,1]:
//    - perm[1] = 2 is divisible by i = 1
//    - i = 2 is divisible by perm[2] = 1
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 15    
class Solution {
    public:
        int countArrangement(int n) {
            // Start backtracking from position 1 with no numbers used (mask = 0)
            return backtrack(n, 1, 0);
        }
        
    private:
        int backtrack(int n, int position, int mask) {
            // If we've filled all positions, we've found a valid arrangement
            if (position > n) {
                return 1;
            }
            
            int count = 0;
            
            // Try placing each number from 1 to n at the current position
            for (int i = 1; i <= n; i++) {
                // Skip if this number is already used
                if ((mask & (1 << (i - 1))) != 0) {
                    continue;
                }
                
                // Check if placing i at position 'position' satisfies the beautiful arrangement condition
                if (i % position == 0 || position % i == 0) {
                    // Mark i as used and continue backtracking
                    count += backtrack(n, position + 1, mask | (1 << (i - 1)));
                }
            }
            
            return count;
        }
    };
    