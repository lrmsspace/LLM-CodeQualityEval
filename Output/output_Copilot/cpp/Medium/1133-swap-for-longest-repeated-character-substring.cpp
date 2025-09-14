/**https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ */
//You are given a string text. You can swap two of the characters in the text.
//Return the length of the longest substring with repeated characters.
// 
//Example 1:
//Input: text = "ababa"
//Output: 3
//Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//Example 2:
//Input: text = "aaabaaa"
//Output: 6
//Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//Example 3:
//Input: text = "aaaaa"
//Output: 5
//Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
// 
//Constraints:
//	1 <= text.length <= 2 * 104
//	text consist of lowercase English characters only.
class Solution {
public:
    int maxRepOpt1(string text) {
        int count[26] = {0};
        for (char c : text) {
            count[c - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            char c = i + 'a';
            int maxLen = 0, curLen = 0, left = 0, right = 0, cnt = 0;
            while (right < text.size()) {
                if (text[right] == c) {
                    cnt++;
                    curLen++;
                    right++;
                } else if (cnt == 0) {
                    curLen++;
                    right++;
                } else {
                    cnt--;
                    curLen--;
                    left++;
                }
                maxLen = max(maxLen, curLen);
            }
            res = max(res, min(maxLen + 1, count[i]));
        }
        return res;        
    }
};