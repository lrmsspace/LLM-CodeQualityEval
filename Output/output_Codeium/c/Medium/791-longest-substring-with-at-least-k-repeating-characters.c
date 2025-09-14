/**https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ */
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//if no such substring exists, return 0.
// 
//Example 1:
//Input: s = "aaabb", k = 3
//Output: 3
//Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//Example 2:
//Input: s = "ababbc", k = 2
//Output: 5
//Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of only lowercase English letters.
//	1 <= k <= 105
int longestSubstring(char* s, int k) {
    int result = 0;
    int count[26] = {0};
    int distinct = 0;
    int start = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 0) {
            distinct++;
        }
        count[s[i] - 'a']++;
        
        while (distinct > k) {
            if (count[s[start] - 'a'] == 1) {
                distinct--;
            }
            count[s[start] - 'a']--;
            start++;
        }
        
        result = fmax(result, i - start + 1);
    }
    
    return result;
}