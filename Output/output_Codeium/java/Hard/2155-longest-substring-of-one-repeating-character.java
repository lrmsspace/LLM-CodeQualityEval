/**https://leetcode.com/problems/longest-substring-of-one-repeating-character/ */
//You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
//The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
//Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.
// 
//Example 1:
//Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
//Output: [3,3,4]
//Explanation: 
//- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
//- 2nd query updates s = "bbbccc". 
//  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
//- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
//Thus, we return [3,3,4].
//Example 2:
//Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
//Output: [2,3]
//Explanation:
//- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
//- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
//Thus, we return [2,3].
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
//	k == queryCharacters.length == queryIndices.length
//	1 <= k <= 105
//	queryCharacters consists of lowercase English letters.
//	0 <= queryIndices[i] < s.length
class Solution {
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int n = s.length();
        int[] res = new int[queryIndices.length];
        int[] last = new int[26];
        Arrays.fill(last, -1);
        int pre = -1;
        for (int i = 0; i < n; i++) {
            int cur = s.charAt(i) - 'a';
            last[cur] = i;
            if (pre != -1 && cur != pre) {
                int len = i - last[pre] - 1;
                for (int j = 0; j < queryIndices.length; j++) {
                    if (queryIndices[j] >= last[pre] + 1 && queryIndices[j] < i) {
                        res[j] = Math.max(res[j], len);
                    }
                }
            }
            pre = cur;
        }
        for (int i = 0; i < queryIndices.length; i++) {
            char c = queryCharacters.charAt(i);
            int idx = queryIndices[i];
            if (idx < s.length()) {
                s = s.substring(0, idx) + c + s.substring(idx + 1);
            }
        }
        pre = -1;
        for (int i = 0; i < n; i++) {
            int cur = s.charAt(i) - 'a';
            last[cur] = i;
            if (pre != -1 && cur != pre) {
                int len = i - last[pre] - 1;
                for (int j = 0; j < queryIndices.length; j++) {
                    if (queryIndices[j] >= last[pre] + 1 && queryIndices[j] < i) {
                        res[j] = Math.max(res[j], len);
                    }
                }
            }
            pre = cur;
        }
        return res;
    }
}