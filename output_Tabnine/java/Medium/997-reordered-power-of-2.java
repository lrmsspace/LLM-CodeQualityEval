/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.
// 
//Example 1:
//Input: n = 1
//Output: true
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//	1 <= n <= 109
class Solution {
    public boolean reorderedPowerOf2(int n) {
        String nStr = String.valueOf(n);
        int[] nCount = new int[10];
        for (char c : nStr.toCharArray()) {
            nCount[c - '0']++;
        }
        for (int i = 0; i < 31; i++) {
            int[] count = nCount.clone();
            int pow = 1;
            while (count[0] > 0) {
                pow *= 2;
                count[0]--;
                if (count[count.length - 1] > 0) {
                    count[count.length - 1]--;
                }
                if (Arrays.equals(count, nCount)) {
                    return true;
                }
            }
        }
        return false;
        
    }
}