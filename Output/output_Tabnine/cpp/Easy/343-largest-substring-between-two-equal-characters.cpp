/**https://leetcode.com/problems/largest-substring-between-two-equal-characters/ */
//Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aa"
//Output: 0
//Explanation: The optimal substring here is an empty substring between the two 'a's.
//Example 2:
//Input: s = "abca"
//Output: 2
//Explanation: The optimal substring here is "bc".
//Example 3:
//Input: s = "cbzxy"
//Output: -1
//Explanation: There are no characters that appear twice in s.
// 
//Constraints:
//	1 <= s.length <= 300
//	s contains only lowercase English letters.
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int maxLen = -1;
        unordered_map<char, int> lastIndex;
        
        for (int i = 0; i < n; ++i) {
            if (lastIndex.find(s[i])!= lastIndex.end()) {
                maxLen = max(maxLen, i - lastIndex[s[i]] - 1);
            }
            lastIndex[s[i]] = i;
        }
        
        return maxLen;
        
    }
};