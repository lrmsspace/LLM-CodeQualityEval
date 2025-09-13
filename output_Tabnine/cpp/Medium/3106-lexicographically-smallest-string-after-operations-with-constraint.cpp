/*
 You are given a string s and an integer k.
 Define a function distance(s1, s2) between two strings s1 and s2 of the same length n as:
 The sum of the minimum distance between s1[i] and s2[i] when the characters from 'a' to 'z' are placed in a cyclic order, for all i in the range [0, n - 1].
 For example, distance("ab", "cd") == 4, and distance("a", "z") == 1.
 You can change any letter of s to any other lowercase English letter, any number of times.
 Return a string denoting the lexicographically smallest string t you can get after some changes, such that distance(s, t) <= k.
 Example 1:
 Input: s = "zbbz", k = 3
 Output: "aaaz"
 Explanation:
 Change s to "aaaz". The distance between "zbbz" and "aaaz" is equal to k = 3.
 Example 2:
 Input: s = "xaxcd", k = 4
 Output: "aawcd"
 Explanation:
 The distance between "xaxcd" and "aawcd" is equal to k = 4.
 Example 3:
 Input: s = "lol", k = 0
 Output: "lol"
 Explanation:
 It's impossible to change any character as k = 0.
 Constraints:
 1 <= s.length <= 100
 0 <= k <= 2000
 s consists only of lowercase English letters.
*/

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.length();
        int minDist = INT_MAX;
        int minIndex = -1;
        
        // Find the minimum distance and its index
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                int dist = 0;
                for (int l = 0; l < n; ++l) {
                    int diff = abs(s[l] - ('a' + j));
                    dist += min(diff, 26 - diff);
                }
                if (dist < minDist) {
                    minDist = dist;
                    minIndex = i;
                }
            }
        }
        // Change the character at the minimum index to the next lowercase English letter
        s[minIndex] = 'a' + (s[minIndex] - 'a' + 1) % 26;
        
        // Return the lexicographically smallest string after some changes
        for (int i = minIndex + 1; i < n; ++i) {
            s[i] = 'a';
        }
        return s;           
        
    }
};