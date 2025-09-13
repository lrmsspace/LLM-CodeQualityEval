/*
 You are given a string caption of length n. A good caption is a string where every character appears in groups of at least 3 consecutive occurrences.
 For example:
 "aaabbb" and "aaaaccc" are good captions.
 "aabbb" and "ccccd" are not good captions.
 You can perform the following operation any number of times:
 Choose an index i (where 0 <= i < n) and change the character at that index to either:
 The character immediately before it in the alphabet (if caption[i] != 'a').
 The character immediately after it in the alphabet (if caption[i] != 'z').
 Your task is to convert the given caption into a good caption using the minimum number of operations, and return it. If there are multiple possible good captions, return the lexicographically smallest one among them. If it is impossible to create a good caption, return an empty string "".
 Example 1:
 Input: caption = "cdcd"
 Output: "cccc"
 Explanation:
 It can be shown that the given caption cannot be transformed into a good caption with fewer than 2 operations. The possible good captions that can be created using exactly 2 operations are:
 "dddd": Change caption[0] and caption[2] to their next character 'd'.
 "cccc": Change caption[1] and caption[3] to their previous character 'c'.
 Since "cccc" is lexicographically smaller than "dddd", return "cccc".
 Example 2:
 Input: caption = "aca"
 Output: "aaa"
 Explanation:
 It can be proven that the given caption requires at least 2 operations to be transformed into a good caption. The only good caption that can be obtained with exactly 2 operations is as follows:
 Operation 1: Change caption[1] to 'b'. caption = "aba".
 Operation 2: Change caption[1] to 'a'. caption = "aaa".
 Thus, return "aaa".
 Example 3:
 Input: caption = "bc"
 Output: ""
 Explanation:
 It can be shown that the given caption cannot be converted to a good caption by using any number of operations.
 Constraints:
 1 <= caption.length <= 5 * 104
 caption consists only of lowercase English letters.
*/

class Solution {
    public String minCostGoodCaption(String caption) {
        int n = caption.length();
        char[] chars = caption.toCharArray();
        int[] count = new int[26];
        for (char c : chars) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] >= 3) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < n; j++) {
                    sb.append((char) ('a' + i));
                }
                return sb.toString();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (chars[i] - 'a' != j) {
                    char original = chars[i];
                    chars[i] = (char) ('a' + j);
                    boolean valid = true;
                    for (int k = 0; k < 26; k++) {
                        if (count[k] >= 3) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        StringBuilder sb = new StringBuilder();
                        for (char c : chars) {
                            sb.append(c);
                        }
                        return sb.toString();
                    }
                    chars[i] = original;
                }
            }
        }
        return "";        
    }
}