/*
 You are given a binary string s and an integer k.
 A binary string satisfies the k-constraint if either of the following conditions holds:
 The number of 0's in the string is at most k.
 The number of 1's in the string is at most k.
 Return an integer denoting the number of substrings of s that satisfy the k-constraint.
 Example 1:
 Input: s = "10101", k = 1
 Output: 12
 Explanation:
 Every substring of s except the substrings "1010", "10101", and "0101" satisfies the k-constraint.
 Example 2:
 Input: s = "1010101", k = 2
 Output: 25
 Explanation:
 Every substring of s except the substrings with a length greater than 5 satisfies the k-constraint.
 Example 3:
 Input: s = "11111", k = 1
 Output: 15
 Explanation:
 All substrings of s satisfy the k-constraint.
 Constraints:
 1 <= s.length <= 50 
 1 <= k <= s.length
 s[i] is either '0' or '1'.
*/

int countKConstraintSubstrings(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    int left = 0;
    int right = 0;
    int zero = 0;
    int one = 0;
    
    while(right < n) {
        if(s[right] == '0') {
            zero++;
        } else {
            one++;
        }
        
        while(zero > k || one > k) {
            if(s[left] == '0') {
                zero--;
            } else {
                one--;
            }
            left++;
        }
        
        count += right - left + 1;
        right++;
    }

    return count;
    
}