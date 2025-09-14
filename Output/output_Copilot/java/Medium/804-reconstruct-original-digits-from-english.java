/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
class Solution {
    public String originalDigits(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        int[] digits = new int[10];
        digits[0] = count['z' - 'a']; // zero
        digits[2] = count['w' - 'a']; // two
        digits[4] = count['u' - 'a']; // four
        digits[6] = count['x' - 'a']; // six
        digits[8] = count['g' - 'a']; // eight

        digits[3] = count['h' - 'a'] - digits[8]; // three
        digits[5] = count['f' - 'a'] - digits[4]; // five
        digits[7] = count['s' - 'a'] - digits[6]; // seven
        digits[1] = count['o' - 'a'] - digits[0] - digits[2] - digits[4]; // one
        digits[9] = (count['i' - 'a'] - digits[5] - digits[6] - digits[8]); // nine

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digits[i]; j++) {
                result.append(i);
            }
        }
        
        return result.toString();        
    }
}