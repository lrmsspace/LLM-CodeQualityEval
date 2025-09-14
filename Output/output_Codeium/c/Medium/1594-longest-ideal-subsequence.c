/**https://leetcode.com/problems/longest-ideal-subsequence/ */
//You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
//	t is a subsequence of the string s.
//	The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
//Return the length of the longest ideal string.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
// 
//Example 1:
//Input: s = "acfgbd", k = 2
//Output: 4
//Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
//Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
//Example 2:
//Input: s = "abcd", k = 3
//Output: 4
//Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
// 
//Constraints:
//	1 <= s.length <= 105
//	0 <= k <= 25
//	s consists of lowercase English letters.    
int longestIdealString(char* s, int k) {
    int dp[26] = {0}; // dp array to store the length of ideal subsequence ending with each character
    int max_length = 0; // variable to store the maximum length of ideal subsequence

    for (int i = 0; s[i]; i++) {
        int index = s[i] - 'a'; // calculate the index of the character in the alphabet
        int current_max = 0;

        // check all characters within the range [s[i] - k, s[i] + k]
        for (int j = index - k; j <= index + k; j++) {
            if (j >= 0 && j < 26) { // ensure j is within bounds
                current_max = current_max > dp[j] ? current_max : dp[j];
            }
        }

        dp[index] = current_max + 1; // update dp for the current character
        max_length = max_length > dp[index] ? max_length : dp[index]; // update max_length if needed
    }

    return max_length;
}

