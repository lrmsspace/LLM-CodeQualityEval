/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder sb = new StringBuilder();
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);
        if (a > 0) pq.offer(new int[]{a, 0});
        if (b > 0) pq.offer(new int[]{b, 1});
        if (c > 0) pq.offer(new int[]{c, 2});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            if (cur[0] > 0) {
                sb.append((char)(cur[1] + 'a'));
                if (--cur[0] > 0) pq.offer(cur);
            }
            if (pq.isEmpty()) break;
            int[] next = pq.poll();
            if (next[0] > 0) {
                sb.append((char)(next[1] + 'a'));
                if (--next[0] > 0) pq.offer(next);
            }
        }
        return sb.toString();
    }
}