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
int maxRepOpt1(char* text) {
    int len = strlen(text);
    int count[26] = {0};
    int max = 0;
    int maxCount = 0;
    int start = 0;
    for (int i = 0; i < len; i++) {
        count[text[i] - 'a']++;
        maxCount = maxCount > count[text[i] - 'a'] ? maxCount : count[text[i] - 'a'];
        if (i - start + 1 - maxCount > 1) {
            count[text[start] - 'a']--;
            start++;
        }
        max = max > i - start + 1 ? max : i - start + 1;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            max = max > maxCount + 1 ? max : maxCount + 1;
        } else {
            max = max > count[i] ? max : count[i];
        }
    }
    return max;    
}