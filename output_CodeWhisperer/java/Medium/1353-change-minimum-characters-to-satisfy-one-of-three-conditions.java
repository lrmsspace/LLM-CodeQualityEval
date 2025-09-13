/**https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/ */
//You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
//Your goal is to satisfy one of the following three conditions:
//	Every letter in a is strictly less than every letter in b in the alphabet.
//	Every letter in b is strictly less than every letter in a in the alphabet.
//	Both a and b consist of only one distinct letter.
//Return the minimum number of operations needed to achieve your goal.
// 
//Example 1:
//Input: a = "aba", b = "caa"
//Output: 2
//Explanation: Consider the best way to make each condition true:
//1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
//2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
//3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
//The best way was done in 2 operations (either condition 1 or condition 3).
//Example 2:
//Input: a = "dabadd", b = "cda"
//Output: 3
//Explanation: The best way is to make condition 1 true by changing b to "eee".
// 
//Constraints:
//	1 <= a.length, b.length <= 105
//	a and b consist only of lowercase letters.
class Solution {
    public int minCharacters(String a, String b) {
        int[] freqA = new int[26];
        int[] freqB = new int[26];
        for (char c : a.toCharArray()) {
            freqA[c - 'a']++;
        }
        for (char c : b.toCharArray()) {
            freqB[c - 'a']++;
        }
        
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
            res = Math.min(res, a.length() + b.length() - freqA[i] - freqB[i]);
        }
        
        for (int i = 1; i < 26; i++) {
            freqA[i] += freqA[i - 1];
            freqB[i] += freqB[i - 1];
        }
        
        for (int i = 0; i < 25; i++) {
            res = Math.min(res, freqA[i] + b.length() - freqB[i]);
            res = Math.min(res, freqB[i] + a.length() - freqA[i]);
        }
        
        return res;      
    }
}