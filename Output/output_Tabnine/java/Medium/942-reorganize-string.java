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
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.offer(i);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {
            int max1 = pq.poll();
            if (pq.isEmpty()) {
                if (count[max1] > 1) {
                    return "";
                }
                sb.append((char) (max1 + 'a'));
                break;
            }
            int max2 = pq.poll();
            sb.append((char) (max1 + 'a')).append((char) (max2 + 'a'));
            count[max1]--;
            count[max2]--;
            if (count[max1] > 0) {
                pq.offer(max1);
            }
            if (count[max2] > 0) {
                pq.offer(max2);
            }
        }
        return sb.toString();
        
    }
}