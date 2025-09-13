/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//	arr[0], arr[1], ..., arr[i] is the first part,
//	arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//	arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//	All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
// 
//Example 1:
//Input: arr = [1,0,1,0,1]
//Output: [0,3]
//Example 2:
//Input: arr = [1,1,0,1,1]
//Output: [-1,-1]
//Example 3:
//Input: arr = [1,1,0,0,1]
//Output: [0,2]
// 
//Constraints:
//	3 <= arr.length <= 3 * 104
//	arr[i] is 0 or 1
class Solution {
    public int[] threeEqualParts(int[] arr) {
        int n = arr.length;
        int[] res = {-1, -1};
        int ones = 0;
        for (int i = 0; i < n; i++) {
            ones += arr[i];
        }
        if (ones % 3 != 0) {
            return res;
        }
        if (ones == 0) {
            return new int[] {0, n - 1};
        }
        int k = ones / 3;
        int first = 0, second = 0, third = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                if (count == 0) {
                    first = i;
                } else if (count == k) {
                    second = i;
                } else if (count == 2 * k) {
                    third = i;
                }
                count++;
            }
        }
        while (third < n) {
            if (arr[first] == arr[second] && arr[second] == arr[third]) {
                first++;
                second++;
                third++;
            } else {
                return res;
            }
        }
        return new int[] {first - 1, second};
        
    }
}