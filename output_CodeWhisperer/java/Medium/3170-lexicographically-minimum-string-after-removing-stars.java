/*
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
 You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
 While there is a '*', do the following operation:
 Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
 Return the lexicographically smallest resulting string after removing all '*' characters.
 Example 1:
 Input: s = "aaba*"
 Output: "aab"
 Explanation:
 We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 Example 2:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no '*' in the string.
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters and '*'.
 The input is generated such that it is possible to delete all '*' characters.
*/

class Solution {
    public String clearStars(String s) {
        int n = s.length();
        char[] arr = s.toCharArray();
        int[] last = new int[26];
        Arrays.fill(last, -1);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (arr[i] == '*') {
                list.add(i);
            } else {
                last[arr[i] - 'a'] = i;
            }
        }
        for (int i : list) {
            int j = 0;
            while (j < 26 && last[j] == -1) {
                j++;
            }
            for (int k = 0; k < 26; k++) {
                if (last[k] != -1 && (j == 26 || last[k] < last[j])) {
                    j = k;
                }
            }
            arr[last[j]] = '*';
            arr[i] = '*';
            last[j] = -1;
        }
        StringBuilder sb = new StringBuilder();
        for (char c : arr) {
            if (c != '*') {
                sb.append(c);
            }
        }
        return sb.toString();        
    }
}