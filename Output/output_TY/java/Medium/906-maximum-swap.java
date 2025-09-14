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
        String numStr = String.valueOf(num);
        char[] numChar = numStr.toCharArray();
        int[] max = new int[numChar.length];
        int[] min = new int[numChar.length];
        int maxIndex = numChar.length - 1;
        int minIndex = numChar.length - 1;
        for (int i = numChar.length - 1; i >= 0; i--) {
            if (numChar[i] > numChar[maxIndex]) {
                maxIndex = i;
            }
            max[i] = maxIndex;
        }
        for (int i = 0; i < numChar.length; i++) {
            if (numChar[i] < numChar[minIndex]) {
                minIndex = i;
            }
            min[i] = minIndex;
        }
        for (int i = 0; i < numChar.length; i++) {
            if (max[i] != min[i]) {
                char temp = numChar[max[i]];
                numChar[max[i]] = numChar[min[i]];
                numChar[min[i]] = temp;
                break;
            }
        }
        return Integer.parseInt(String.valueOf(numChar));

    }
}