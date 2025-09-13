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
        int n = s.length();
        int[] lastIndex = new int[26]; // Initialize lastIndex array with -1
        Arrays.fill(lastIndex, -1);
        int maxLength = 0;
        int start = 0;
        int vowelCount = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            int index = c - 'a';
            
            // If the vowel appears an odd number of times, move the start index
            if (lastIndex[index]!= -1 && lastIndex[index] >= start) {
                start = lastIndex[index] + 1;
            }
            
            // Update the last index of the current vowel
            lastIndex[index] = i;
            
            // Increase the count of vowels
            vowelCount += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')? 1 : 0;
            
            // Update the maximum length
            maxLength = Math.max(maxLength, i - start + 1);
        }
        
        return maxLength;
        
    }
}