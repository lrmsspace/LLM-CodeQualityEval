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
int maxRepOpt1(char * text){
    int ans = 0;
    for (int i = 0; text[i]; i++) {
        int cnt = 0;
        int j = i;
        while (text[j] == text[i]) {
            cnt++;
            j++;
        }
        ans = max(ans, cnt);
        if (text[j] == text[i - 1]) {
            int k = i - 1;
            while (text[k]== text[i - 1]) {
                cnt++;
                k--;
            }
        }
    }
    return ans;
}