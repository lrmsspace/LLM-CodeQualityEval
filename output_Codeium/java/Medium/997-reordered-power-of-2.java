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
        String str = String.valueOf(n);
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        do {
            if (chars[0] != '0' && isPowerOfTwo(Integer.parseInt(new String(chars)))) {
                return true;
            }
        } while (permutation(chars));
        return false;
    }

    private boolean permutation(char[] chars) {
        int i = chars.length - 2;
        while (i >= 0 && chars[i] >= chars[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = chars.length - 1;
        while (j > i && chars[j] <= chars[i]) {
            j--;
        }
        swap(chars, i, j);
        int left = i + 1, right = chars.length - 1;
        while (left < right) {
            swap(chars, left, right);
            left++;
            right--;
        }
        return true;
    }

    private void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }

    private boolean isPowerOfTwo(int num) {
        return (num > 0) && (num & (num - 1)) == 0;
    }
}