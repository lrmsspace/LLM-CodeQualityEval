/**https://leetcode.com/problems/russian-doll-envelopes/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.
// 
//Example 1:
//Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//Output: 3
//Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//Example 2:
//Input: envelopes = [[1,1],[1,1],[1,1]]
//Output: 1
// 
//Constraints:
//	1 <= envelopes.length <= 105
//	envelopes[i].length == 2
//	1 <= wi, hi <= 105
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        // Sort the envelopes by width in ascending order and by height in descending order if widths are equal
        Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        
        // Extract the heights from the sorted envelopes
        int n = envelopes.length;
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = envelopes[i][1];
        }
        
        // Find the length of the longest increasing subsequence in heights
        return lengthOfLIS(heights);        
    }
}