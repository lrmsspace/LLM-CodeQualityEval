/**https://leetcode.com/problems/maximum-of-absolute-value-expression/ */
//Given two arrays of integers with equal lengths, return the maximum value of:
//|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
//where the maximum is taken over all 0 <= i, j < arr1.length.
// 
//Example 1:
//Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
//Output: 13
//Example 2:
//Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
//Output: 20
// 
//Constraints:
//	2 <= arr1.length == arr2.length <= 40000
//	-10^6 <= arr1[i], arr2[i] <= 10^6
class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = arr1[i] + arr2[i] + i;
            b[i] = arr1[i] + arr2[i] - i;
            c[i] = arr1[i] - arr2[i] + i;
            d[i] = arr1[i] - arr2[i] - i;
        }
        int max1 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE;
        int max2 = Integer.MIN_VALUE;
        int min2 = Integer.MAX_VALUE;
        int max3 = Integer.MIN_VALUE;
        int min3 = Integer.MAX_VALUE;
        int max4 = Integer.MIN_VALUE;
        int min4 = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            max1 = Math.max(max1, a[i]);
            min1 = Math.min(min1, a[i]);
            max2 = Math.max(max2, b[i]);
            min2 = Math.min(min2, b[i]);
            max3 = Math.max(max3, c[i]);
            min3 = Math.min(min3, c[i]);
            max4 = Math.max(max4, d[i]);
            min4 = Math.min(min4, d[i]);
        }
        return Math.max(Math.max(max1 - min1, max2 - min2), Math.max(max3 - min3, max4 - min4));       
    }
}