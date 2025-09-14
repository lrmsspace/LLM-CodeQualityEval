/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

int maxSubstrings(char* word) {
    int i, j, k, n, m, cnt, ans, len, flag;
    n = strlen(word);
    ans = 0;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = i; j < n; j++) {
            if (word[j] != word[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            continue;
        }
        len = j - i;
        if (len < 4) {
            continue;
        }
        cnt = 1;
        for (k = i + 1; k < n; k++) {
            if (word[k] == word[i]) {
                cnt++;
            } else {
                break;
            }
        }
    }
    
    return ans;
}