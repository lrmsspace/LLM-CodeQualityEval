/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
class Solution {
    public String reorganizeString(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.offer(new int[]{count[i], i});
            }
        }
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            sb.append((char) (curr[1] + 'a'));
            curr[0]--;
            if (curr[0] > 0) {
                pq.offer(curr);
            }
            if (pq.isEmpty()) {
                break;
            }
            int[] next = pq.poll();
            sb.append((char) (next[1] + 'a'));
            next[0]--;
            if (next[0] > 0) {
                pq.offer(next);
            }
        }
        return sb.length() == s.length() ? sb.toString() : "";
    }
}