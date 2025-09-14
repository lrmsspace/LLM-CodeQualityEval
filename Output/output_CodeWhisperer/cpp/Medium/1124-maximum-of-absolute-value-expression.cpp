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
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> a(n), b(n), c(n), d(n);
        for (int i = 0; i < n; i++) {
            a[i] = arr1[i] + arr2[i] + i;
            b[i] = arr1[i] + arr2[i] - i;
            c[i] = arr1[i] - arr2[i] + i;
            d[i] = arr1[i] - arr2[i] - i;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, max(max(a[i], b[i]), max(c[i], d[i])) - min(min(a[j], b[j]), min(c[j], d[j])));
            }
        }
        return res;       
    }
};