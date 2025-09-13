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
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int mid = len / 2;
        bool isEven = len % 2 == 0;
        
        // Find the closest palindrome

        // Case 1: If the middle digit is 9, decrease it by 1 and increase the digits on both sides
        if (n[mid] == '9') {
            for (int i = mid - 1; i >= 0; i--) {
                if (n[i]!= '9') {
                    n[i] = n[mid] = char(n[i] - '0' + 1);
                    for (int j = i + 1; j < mid; j++) {
                        n[j] = n[mid - j - 1] = n[i];
                    }
                    return n;
                }
            }
        }
        
        // Case 2: If the middle digit is 0, increase it by 1 and decrease the digits on both sides
        else if (n[mid] == '0') {
            for (int i = mid - 1; i >= 0; i--) {
                if (n[i]!= '0') {
                    n[i] = n[mid] = char(n[i] - '0' + 1);
                    for (int j = i + 1; j < mid; j++) {
                        n[j] = n[mid - j - 1] = n[i];
                    }
                    return n;
                }
            }
        }
        
        // Case 3: If the middle digit is not 0 or 9, simply increase or decrease the middle digit accordingly
        else {
            n[mid] = char(n[mid] - '0' + (isEven? 1 : -1));
            return n;
        }
        
        return ""; // This line should never be reached
        
    }
};