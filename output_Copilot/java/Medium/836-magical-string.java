/**https://leetcode.com/problems/magical-string/ */
//A magical string s consists of only '1' and '2' and obeys the following rules:
//	The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string s itself.
//The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.
//Given an integer n, return the number of 1's in the first n number in the magical string s.
// 
//Example 1:
//Input: n = 6
//Output: 3
//Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 105
class Solution {
    public int magicalString(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int[] s = new int[n + 1];
        s[0] = 1; // First element is always 1
        s[1] = 2; // Second element is always 2
        int count = 1; // Count of '1's, starting with the first element

        for (int i = 2; i < n; i++) {
            s[i] = (s[i - 1] == 1) ? 2 : 1; // Alternate between 1 and 2
            if (s[i] == 1) count++; // Increment count if the current element is '1'
            if (i >= s[i - 2]) { // Check if we need to stop generating more elements
                break;
            }
        }

        return count;        
    }
}