/**https://leetcode.com/problems/number-of-good-ways-to-split-a-string/ */
//You are given a string s.
//A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
//Return the number of good splits you can make in s.
// 
//Example 1:
//Input: s = "aacaba"
//Output: 2
//Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
//("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
//("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
//("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
//("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
//("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
//Example 2:
//Input: s = "abcd"
//Output: 1
//Explanation: Split the string as follows ("ab", "cd").
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only lowercase English letters.
class Solution {
    public int numSplits(String s) {
        int n = s.length();
        int leftCount = 0, rightCount = 0;
        int leftDistinct = 0, rightDistinct = 0;
        int goodSplits = 0;
        
        Map<Character, Integer> leftMap = new HashMap<>();
        Map<Character, Integer> rightMap = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            leftMap.put(c, leftMap.getOrDefault(c, 0) + 1);
            rightMap.put(c, rightMap.getOrDefault(c, 0) + 1);
            
            if (leftMap.get(c) == 1) {
                leftDistinct++;
            }
            if (rightMap.get(c) == 1) {
                rightDistinct++;
            }
            
            if (i > 0) {
                leftCount = leftMap.get(s.charAt(i - 1));
                rightCount = rightMap.get(s.charAt(n - i));
                
                if (leftCount == 1) {
                    leftDistinct--;
                }
                if (rightCount == 1) {
                    rightDistinct--;
                }
            }
            
            if (leftDistinct == rightDistinct) {
                goodSplits++;
            }
        }
        
        return goodSplits;
        
    }
}