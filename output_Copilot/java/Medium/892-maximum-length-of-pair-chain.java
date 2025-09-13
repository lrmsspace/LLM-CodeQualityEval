/**https://leetcode.com/problems/maximum-length-of-pair-chain/ */
//You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
//A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
//Return the length longest chain which can be formed.
//You do not need to use up all the given intervals. You can select pairs in any order.
// 
//Example 1:
//Input: pairs = [[1,2],[2,3],[3,4]]
//Output: 2
//Explanation: The longest chain is [1,2] -> [3,4].
//Example 2:
//Input: pairs = [[1,2],[7,8],[4,5]]
//Output: 3
//Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
// 
//Constraints:
//	n == pairs.length
//	1 <= n <= 1000
//	-1000 <= lefti < righti <= 1000
class Solution {
    public int findLongestChain(int[][] pairs) {
        // Sort the pairs based on the second element of each pair
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));
        
        int count = 0; // To count the number of pairs in the longest chain
        int lastEnd = Integer.MIN_VALUE; // To keep track of the end of the last pair in the chain
        
        for (int[] pair : pairs) {
            // If the start of the current pair is greater than the end of the last pair in the chain
            if (pair[0] > lastEnd) {
                count++; // Increment the count of pairs in the chain
                lastEnd = pair[1]; // Update the end of the last pair in the chain
            }
        }
        
        return count; // Return the length of the longest chain        
    }
}