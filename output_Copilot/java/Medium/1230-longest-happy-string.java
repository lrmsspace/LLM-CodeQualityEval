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
        int[] count = new int[]{a, b, c};
        char[] ch = new char[]{'a', 'b', 'c'};
        while (true) {
            int index = -1;
            if (sb.length() >= 2 && sb.charAt(sb.length() - 1) == sb.charAt(sb.length() - 2)) {
                for (int i = 0; i < 3; i++) {
                    if (count[i] > 0 && ch[i] != sb.charAt(sb.length() - 1)) {
                        index = i;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < 3; i++) {
                    if (count[i] > 0) {
                        index = i;
                        break;
                    }
                }
            }
            if (index == -1) {
                break;
            }
            if (count[index] >= 2) {
                sb.append(ch[index]);
                sb.append(ch[index]);
                count[index] -= 2;
            } else {
                sb.append(ch[index]);
                count[index]--;
            }
        }
        return sb.toString();        
    }
}