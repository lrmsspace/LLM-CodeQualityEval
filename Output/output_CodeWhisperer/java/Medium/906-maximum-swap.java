/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.
// 
//Example 1:
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//Example 2:
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//Constraints:
//	0 <= num <= 108
class Solution {
    public int maximumSwap(int num) {
        char[] chars = Integer.toString(num).toCharArray();
        int[] last = new int[10];
        for (int i = 0; i < chars.length; i++) {
            last[chars[i] - '0'] = i;
        }
        for (int i = 0; i < chars.length; i++) {
            for (int j = 9; j > chars[i] - '0'; j--) {
                if (last[j] > i) {
                    char tmp = chars[i];
                    chars[i] = chars[last[j]];
                    chars[last[j]] = tmp;
                    return Integer.parseInt(new String(chars));
                }
            }
        }
        return num;      
    }
}