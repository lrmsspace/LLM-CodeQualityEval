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
        int countOnes = 0;
        for (int num : arr) {
            countOnes += num;
        }
        if (countOnes == 0) {
            return new int[] {0, n - 1};
        }
        if (countOnes % 3!= 0) {
            return new int[] {-1, -1};
        }
        int targetOnes = countOnes / 3;
        int i = 0;
        while (i < n && arr[i] == 0) {
            i++;
        }
        int j = i;
        while (j < n && arr[j] == 1) {
            j++;
        }
        int k = j;
        while (k < n && arr[k] == 0) {
            k++;
        }
        int l = k;
        while (l < n && arr[l] == 1) {
            l++;
        }
        int m = l;
        while (m < n && arr[m] == 0) {
            m++;
        }
        if (i + targetOnes!= j || j + targetOnes!= k || k + targetOnes!= l || l + targetOnes!= m) {
            return new int[] {-1, -1};
        }
        return new int[] {i, i + targetOnes - 1, j, j + targetOnes - 1, k, k + targetOnes - 1, l, l + targetOnes - 1, m, m + targetOnes - 1};
        
    }
}