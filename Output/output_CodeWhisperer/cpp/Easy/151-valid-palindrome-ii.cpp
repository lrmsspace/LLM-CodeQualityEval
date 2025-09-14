/**https://leetcode.com/problems/valid-palindrome-ii/ */
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.
// 
//Example 1:
//Input: s = "aba"
//Output: true
//Example 2:
//Input: s = "abca"
//Output: true
//Explanation: You could delete the character 'c'.
//Example 3:
//Input: s = "abc"
//Output: false
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
class Solution {
public:
    bool validPalindrome(string s) 
    {
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                int left1 = left, right1 = right - 1;
                int left2 = left + 1, right2 = right;
                while (left1 < right1 && s[left1] == s[right1])
                {
                    left1++;
                    right1--;
                }
                while (left2 < right2 && s[left2] == s[right2])
                {
                    left2++;
                    right2--;
                }
                return left1 >= right1 || left2 >= right2;
            }
            left++;
            right--;
        }
        return true;
    }
};