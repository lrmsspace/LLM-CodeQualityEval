/**https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/ */
//You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.
//	For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
//Given the string word, return the minimum total distance to type such string using only two fingers.
//The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.
//Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.
// 
//Example 1:
//Input: word = "CAKE"
//Output: 3
//Explanation: Using two fingers, one optimal way to type "CAKE" is: 
//Finger 1 on letter 'C' -> cost = 0 
//Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
//Finger 2 on letter 'K' -> cost = 0 
//Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
//Total distance = 3
//Example 2:
//Input: word = "HAPPY"
//Output: 6
//Explanation: Using two fingers, one optimal way to type "HAPPY" is:
//Finger 1 on letter 'H' -> cost = 0
//Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
//Finger 2 on letter 'P' -> cost = 0
//Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
//Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
//Total distance = 6
// 
//Constraints:
//	2 <= word.length <= 300
//	word consists of uppercase English letters.
class Solution {
    public int minimumDistance(String word) {
        int[][] dp = new int[word.length()][26];
        Arrays.fill(dp[0], Integer.MAX_VALUE);
        dp[0][word.charAt(0) - 'A'] = 0;
        for (int i = 1; i < word.length(); i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            for (int j = 0; j < 26; j++) {
                if (dp[i - 1][j] != Integer.MAX_VALUE) {
                    int dis = Math.abs(j - (word.charAt(i) - 'A'));
                    dp[i][word.charAt(i) - 'A'] = Math.min(dp[i][word.charAt(i) - 'A'], dp[i - 1][j] + dis);
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
            res = Math.min(res, dp[word.length() - 1][i]);
        }
        return res; 
        }
}