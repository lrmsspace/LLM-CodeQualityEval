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

int minimumCost(char* target, char** words, int wordsSize, int* costs, int costsSize) {

    int minCost = INT_MAX;
    int targetLength = strlen(target);
    int wordLength = strlen(words[0]);
    
    // Create a 2D array dp to store the minimum cost to form each substring of target
    int dp[targetLength + 1][targetLength + 1];
    
    // Initialize the dp array with large values
    for (int i = 0; i <= targetLength; i++) {
        for (int j = 0; j <= targetLength; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // Initialize the dp array with 0 for the empty substring
    for (int i = 0; i <= targetLength; i++) {
        dp[i][0] = 0;
    }
    // Fill the dp array using the given cost information
    for (int i = 1; i <= targetLength; i++) {
        for (int j = 1; j <= targetLength; j++) {
            if (target[i - 1] == words[0][j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + costs[0];
            }
        }
    }
    // Find the minimum cost to form the target substring
    for (int i = 1; i < wordsSize; i++) {
        int cost = costs[i];
        int wordLength = strlen(words[i]);
        for (int j = 1; j <= targetLength; j++) {
            for (int k = 1; k <= targetLength - j + 1; k++) {
                if (strncmp(target + j - 1, words[i], wordLength) == 0) {
                    dp[j + wordLength - 1][j + k - 1] = min(dp[j + wordLength - 1][j + k - 1], dp[j - 1][j + k - 1] + cost);
                }
            }
        }
    }
    // Return the minimum cost if it is possible to form the target substring, otherwise return -1
    return dp[targetLength][0] == INT_MAX? -1 : dp[targetLength][0];
    
}