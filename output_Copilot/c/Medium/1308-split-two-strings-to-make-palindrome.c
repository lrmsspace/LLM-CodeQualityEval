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
bool checkPalindromeFormation(char* a, char* b) {
    int len = strlen(a);
    int i = 0, j = len - 1;
    while (i < j && a[i] == b[j]) {
        i++;
        j--;
    }
    if (i >= j) {
        return true;
    }
    int i1 = i, j1 = j;
    while (i1 < j1 && b[i1] == b[j1]) {
        i1++;
        j1--;
    }
    if (i1 >= j1) {
        return true;
    }
    int i2 = i, j2 = j;
    while (i2 < j2 && a[i2] == a[j2]) {
        i2++;
        j2--;
    }
    if (i2 >= j2) {
        return true;
    }
    int i3 = i, j3 = j;
    while (i3 < j3 && a[i3] == b[i3]) {
        i3++;
        j3--;
    }
    if (i3 >= j3) {
        return true;
    }
    return false;    
}