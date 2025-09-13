/*
 You are given a string target, an array of strings words, and an integer array costs, both arrays of the same length.
 Imagine an empty string s.
 You can perform the following operation any number of times (including zero):
 Choose an index i in the range [0, words.length - 1].
 Append words[i] to s.
 The cost of operation is costs[i].
 Return the minimum cost to make s equal to target. If it's not possible, return -1.
 Example 1:
 Input: target = "abcdef", words = ["abdef","abc","d","def","ef"], costs = [100,1,1,10,5]
 Output: 7
 Explanation:
 The minimum cost can be achieved by performing the following operations:
 Select index 1 and append "abc" to s at a cost of 1, resulting in s = "abc".
 Select index 2 and append "d" to s at a cost of 1, resulting in s = "abcd".
 Select index 4 and append "ef" to s at a cost of 5, resulting in s = "abcdef".
 Example 2:
 Input: target = "aaaa", words = ["z","zz","zzz"], costs = [1,10,100]
 Output: -1
 Explanation:
 It is impossible to make s equal to target, so we return -1.
 Constraints:
 1 <= target.length <= 5 * 104
 1 <= words.length == costs.length <= 5 * 104
 1 <= words[i].length <= target.length
 The total sum of words[i].length is less than or equal to 5 * 104.
 target and words[i] consist only of lowercase English letters.
 1 <= costs[i] <= 104
*/

class Solution {
    public int minimumCost(String target, String[] words, int[] costs) {
        int m = target.length();
        int n = words.length;

        // dp[i] will store the minimum cost to construct target[0..i]
        int[] dp = new int[m + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                String word = words[j];
                int cost = costs[j];

                // If the word can be used to construct target[0..i]
                if (i >= word.length() && target.substring(i - word.length(), i).equals(word)) {
                    dp[i] = Math.min(dp[i], dp[i - word.length()] + cost);
                }
            }
        }

        return dp[m] == Integer.MAX_VALUE ? -1 : dp[m];
    }
}