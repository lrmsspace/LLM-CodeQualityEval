/**https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/ */
//You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
//Return the largest possible value of num after any number of swaps.
// 
//Example 1:
//Input: num = 1234
//Output: 3412
//Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
//Swap the digit 2 with the digit 4, this results in the number 3412.
//Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
//Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
//Example 2:
//Input: num = 65875
//Output: 87655
//Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
//Swap the first digit 5 with the digit 7, this results in the number 87655.
//Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
// 
//Constraints:
//	1 <= num <= 109
class Solution {
    public int largestInteger(int num) {
        StringBuilder sb = new StringBuilder(String.valueOf(num));
        int n = sb.length();
        int[] even = new int[n];
        int[] odd = new int[n];
        for (int i = 0; i < n; i++) {
            if ((sb.charAt(i) - '0') % 2 == 0) {
                even[i] = sb.charAt(i) - '0';
            } else {
                odd[i] = sb.charAt(i) - '0';
            }
        }
        Arrays.sort(even);
        Arrays.sort(odd);
        StringBuilder ans = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            if ((sb.charAt(i) - '0') % 2 == 0) {
                ans.append(even[i]);
            } else {
                ans.append(odd[i]);
            }
        }
        return Integer.parseInt(ans.toString());        
    }
}