/**https://leetcode.com/problems/split-two-strings-to-make-palindrome/ */
//You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.
//When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.
//Return true if it is possible to form a palindrome string, otherwise return false.
//Notice that x + y denotes the concatenation of strings x and y.
// 
//Example 1:
//Input: a = "x", b = "y"
//Output: true
//Explaination: If either a or b are palindromes the answer is true since you can split in the following way:
//aprefix = "", asuffix = "x"
//bprefix = "", bsuffix = "y"
//Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.
//Example 2:
//Input: a = "xbdef", b = "xecab"
//Output: false
//Example 3:
//Input: a = "ulacfd", b = "jizalu"
//Output: true
//Explaination: Split them at index 3:
//aprefix = "ula", asuffix = "cfd"
//bprefix = "jiz", bsuffix = "alu"
//Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.
// 
//Constraints:
//	1 <= a.length, b.length <= 105
//	a.length == b.length
//	a and b consist of lowercase English letters
class Solution {
public:
bool checkPalindromeFormation(string a, string b) {
    // Check if we can form a palindrome with a_prefix + b_suffix
    if (canFormPalindrome(a, b)) {
        return true;
    }
    
    // Check if we can form a palindrome with b_prefix + a_suffix
    if (canFormPalindrome(b, a)) {
        return true;
    }
    
    return false;
}

bool canFormPalindrome(string a, string b) {
    int n = a.length();
    int left = 0, right = n - 1;
    
    // Check if the characters match from outside to inside
    // We're checking if a_prefix + b_suffix can form a palindrome
    while (left < right && a[left] == b[right]) {
        left++;
        right--;
    }
    
    // If we've reached the middle or crossed over, it's already a palindrome
    if (left >= right) {
        return true;
    }
    
    // Check if the remaining middle part in string a is a palindrome
    if (isPalindrome(a, left, right)) {
        return true;
    }
    
    // Check if the remaining middle part in string b is a palindrome
    if (isPalindrome(b, left, right)) {
        return true;
    }
    
    return false;
}

bool isPalindrome(string s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
    
};
