/**https://leetcode.com/problems/rearrange-spaces-between-words/ */
//You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.
//Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
//Return the string after rearranging the spaces.
// 
//Example 1:
//Input: text = "  this   is  a sentence "
//Output: "this   is   a   sentence"
//Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
//Example 2:
//Input: text = " practice   makes   perfect"
//Output: "practice   makes   perfect "
//Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
// 
//Constraints:
//	1 <= text.length <= 100
//	text consists of lowercase English letters and ' '.
//	text contains at least one word.
char* reorderSpaces(char* text) {
    int n = strlen(text);
    int spaces = 0;
    for (int i = 0; i < n; ++i) {
        if (text[i] == ' ') {
            ++spaces;
        }
    }
    int words = 0;
    for (int i = 0; i < n; ++i) {
        if (text[i] != ' ' && (i == 0 || text[i-1] == ' ')) {
            ++words;
        }
    }
    int gap = words == 1 ? n - 1 : spaces / (words - 1);
    int extra = words == 1 ? 0 : spaces % (words - 1);
    char *ans = (char*)malloc(n + 1);
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (text[i] == ' ') {
            continue;
        }
        ans[idx++] = text[i];
        if (idx < words) {
            for (int j = 0; j < gap; ++j) {
                ans[idx++] = ' ';
            }
        }
    }
    while (idx < n - extra) {
        ans[idx++] = ' ';
    }
    ans[idx] = '\0';
    return ans;
}