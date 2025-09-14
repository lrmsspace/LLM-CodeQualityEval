/**https://leetcode.com/problems/minimum-additions-to-make-valid-string/ */
//Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.
//A string is called valid if it can be formed by concatenating the string "abc" several times.
// 
//Example 1:
//Input: word = "b"
//Output: 2
//Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".
//Example 2:
//Input: word = "aaa"
//Output: 6
//Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
//Example 3:
//Input: word = "abc"
//Output: 0
//Explanation: word is already valid. No modifications are needed. 
// 
//Constraints:
//	1 <= word.length <= 50
//	word consists of letters "a", "b" and "c" only. 
class Solution {
    public int addMinimum(String word) {
        int n = word.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            char c = word.charAt(i);
            if (c == 'a') {
                if (i + 1 < n && word.charAt(i + 1) == 'c') {
                    count++;
                    i++;
                } else if (i + 1 < n && word.charAt(i + 1) == 'b') {
                    if (i + 2 < n && word.charAt(i + 2) == 'c') {
                        i += 2;
                    } else {
                        count++;
                        i++;
                    }
                } else if (i + 1 < n && word.charAt(i + 1) == 'a') {
                    count += 2;
                    i++;
                } else {
                    count += 2;
                }
            } else if (c == 'b') {
                if (i + 1 < n && word.charAt(i + 1) == 'c') {
                    count++;
                    i++;
                } else if (i + 1 < n && word.charAt(i + 1) == 'a') {
                    count++;
                    i++;
                } else {
                    count += 2;
                }
            } else {
                if (i + 1 < n && word.charAt(i + 1) == 'a') {
                    count++;
                    i++;
                } else if (i + 1 < n && word.charAt(i + 1) == 'b') {
                    count++;
                    i++;
                } else {
                    count += 2;
                }
            }
        }
        return count;       
    }
}