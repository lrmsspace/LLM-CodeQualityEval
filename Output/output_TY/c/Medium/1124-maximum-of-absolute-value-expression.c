/**https://leetcode.com/problems/maximum-of-absolute-value-expression/ */
//Given two arrays of integers with equal lengths, return the maximum value of:_x000D_
//_x000D_
//|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|_x000D_
//_x000D_
//where the maximum is taken over all 0 <= i, j < arr1.length._x000D_
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
int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size){
    int i, j, k, l, max = 0;
    for (i = -1; i <= 1; i += 2) {
        for (j = -1; j <= 1; j += 2) {
            for (k = -1; k <= 1; k += 2) {
                for (l = -1; l <= 1; l += 2) {
                    int sum = 0;
                    for (int m = 0; m < arr1Size; m++) {
                        sum += abs(arr1[m] * i + arr2[m] * j + m * k) * l;
                    }
                }
            }
        }
    }
    return max;
}