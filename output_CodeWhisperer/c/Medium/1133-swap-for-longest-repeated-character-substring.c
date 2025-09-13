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
    int n = strlen(text);
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[text[i] - 'a']++;
    }
    int max = 0;
    for (int i = 0; i < 26; i++) {
        int left = 0, right = 0, cur = 0, maxCur = 0;
        while (right < n) {
            if (text[right] - 'a' == i) {
                cur++;
                right++;
            } else if (left == right || text[left] - 'a' != i) {
                left = right;
                right++;
                cur = 1;
            } else {
                if (right - left > count[i]) {
                    left++;
                } else {
                    cur++;
                    right++;
                }
            }
            maxCur = fmax(maxCur, cur);
        }
        max = fmax(max, maxCur);
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] == max) {
            return max;
        }
    }
    return max + 1;
}