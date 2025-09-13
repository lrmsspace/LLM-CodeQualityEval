/*
 You are given a string s consisting of lowercase English letters ('a' to 'z'). 
 Your task is to:
 Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
 Find the consonant (all other letters excluding vowels) with the maximum frequency.
 Return the sum of the two frequencies.
 Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
 The frequency of a letter x is the number of times it occurs in the string.
 Example 1:
 Input: s = "successes"
 Output: 6
 Explanation:
 The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
 The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
 The output is 2 + 4 = 6.
 Example 2:
 Input: s = "aeiaeia"
 Output: 3
 Explanation:
 The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
 There are no consonants in s. Hence, maximum consonant frequency = 0.
 The output is 3 + 0 = 3.
 Constraints:
 1 <= s.length <= 100
 s consists of lowercase English letters only.
*/

class Solution {
    public int maxFreqSum(String s) {
        int[] vowelCount = new int[5]; // a, e, i, o, u
        int[] consonantCount = new int[21]; // b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, y, z

        for (char c : s.toCharArray()) {
            if (c == 'a') {
                vowelCount[0]++;
            } else if (c == 'e') {
                vowelCount[1]++;
            } else if (c == 'i') {
                vowelCount[2]++;
            } else if (c == 'o') {
                vowelCount[3]++;
            } else if (c == 'u') {
                vowelCount[4]++;
            } else {
                consonantCount[c - 'b']++;
            }
        }

        int maxVowelFreq = 0;
        for (int count : vowelCount) {
            maxVowelFreq = Math.max(maxVowelFreq, count);
        }

        int maxConsonantFreq = 0;
        for (int count : consonantCount) {
            maxConsonantFreq = Math.max(maxConsonantFreq, count);
        }

        return maxVowelFreq + maxConsonantFreq;
        
    }
}