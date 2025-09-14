/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].

bool isPalindrome(int n) {
    int reversed = 0;
    int temp = n;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    return n == reversed;
}

char* nearestPalindromic(char* n) {
    int num = atoi(n);
    int pre = num - 1, next = num + 1;
    while (pre > 0 && !isPalindrome(pre)) pre--;
    while (!isPalindrome(next)) next++;
    if (num - pre <= next - num) return itoa(pre);
    else return itoa(next);
}   