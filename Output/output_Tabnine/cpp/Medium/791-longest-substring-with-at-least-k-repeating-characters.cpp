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
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n < k) return 0;
        
        vector<int> freq(26, 0);
        int left = 0, right = 0, maxLen = 0;
        
        while (right < n) {
            freq[s[right] - 'a']++;
            right++;
            
            while (right - left >= k && freq[s[left] - 'a'] < k) {
                freq[s[left] - 'a']--;
                left++;
            }
            
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
        
    }
};