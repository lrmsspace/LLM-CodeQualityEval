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
int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
    for (int i = 0; i < arr1Size; i++) {
        max1 = fmax(max1, arr1[i] + arr2[i] + i);
        max2 = fmax(max2, arr1[i] + arr2[i] - i);
        max3 = fmax(max3, arr1[i] - arr2[i] + i);
        max4 = fmax(max4, arr1[i] - arr2[i] - i);
        min1 = fmin(min1, arr1[i] + arr2[i] + i);
        min2 = fmin(min2, arr1[i] + arr2[i] - i);
        min3 = fmin(min3, arr1[i] - arr2[i] + i);
        min4 = fmin(min4, arr1[i] - arr2[i] - i);
    }
    return fmax(fmax(max1 - min1, max2 - min2), fmax(max3 - min3, max4 - min4));    
}