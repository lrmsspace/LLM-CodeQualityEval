/**https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/ */
//You are given a string s that consists of only digits.
//Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are in descending order and the difference between numerical values of every two adjacent substrings is equal to 1.
//	For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. The values are in descending order and adjacent values differ by 1, so this way is valid.
//	Another example, the string s = "001" can be split into ["0", "01"], ["00", "1"], or ["0", "0", "1"]. However all the ways are invalid because they have numerical values [0,1], [0,1], and [0,0,1] respectively, all of which are not in descending order.
//Return true if it is possible to split s​​​​​​ as described above, or false otherwise.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "1234"
//Output: false
//Explanation: There is no valid way to split s.
//Example 2:
//Input: s = "050043"
//Output: true
//Explanation: s can be split into ["05", "004", "3"] with numerical values [5,4,3].
//The values are in descending order with adjacent values differing by 1.
//Example 3:
//Input: s = "9080701"
//Output: false
//Explanation: There is no valid way to split s.
// 
//Constraints:
//	1 <= s.length <= 20
//	s only consists of digits.
class Solution {
public:
    bool splitString(string s) {
        int n = s.size();
        if (n < 3) return false;
        
        // Sort the string in descending order
        sort(s.begin(), s.end(), greater<char>());
        
        // Check if the numerical values of the substrings are in descending order and the difference between numerical values of every two adjacent substrings is equal to 1
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) return false; // If two adjacent digits are the same, it's not possible to split the string
            int diff = abs(s[i] - s[i + 1]);
            if (diff!= 1) return false; // If the difference between adjacent digits is not 1, it's not possible to split the string
        }
        
        return true; // If all conditions are met, it's possible to split the string into non-empty substrings with the given conditions
        
    }
};