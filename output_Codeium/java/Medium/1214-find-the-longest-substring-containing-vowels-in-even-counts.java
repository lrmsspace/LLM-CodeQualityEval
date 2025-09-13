/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// 
//Example 1:
//Input: s = "eleetminicoworoep"
//Output: 13
//Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//Example 2:
//Input: s = "leetcodeisgreat"
//Output: 5
//Explanation: The longest substring is "leetc" which contains two e's.
//Example 3:
//Input: s = "bcbcbc"
//Output: 6
//Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
// 
//Constraints:
//	1 <= s.length <= 5 x 10^5
//	s contains only lowercase English letters.
class Solution {
    public int findTheLongestSubstring(String s) {
        int maxLen = 0, currLen = 0;
        int[] vowels = new int[5];
        Map<String, Integer> map = new HashMap<>();
        map.put("", 0);
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') vowels[0]++;
            else if (s.charAt(i) == 'e') vowels[1]++;
            else if (s.charAt(i) == 'i') vowels[2]++;
            else if (s.charAt(i) == 'o') vowels[3]++;
            else if (s.charAt(i) == 'u') vowels[4]++;
            
            currLen++;
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < 5; j++) {
                if (vowels[j] % 2 == 1) {
                    sb.append((char)('a' + j));
                }
            }
            if (map.containsKey(sb.toString())) {
                maxLen = Math.max(maxLen, currLen - map.get(sb.toString()));
            }
            map.put(sb.toString(), i + 1);
        }
        
        return maxLen;
    }
}