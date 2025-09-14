/**https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/ */
//Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
// 
//Example 1:
//Input: arr = [1,2,2,6,6,6,6,7,10]
//Output: 6
//Example 2:
//Input: arr = [1,1]
//Output: 1
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 105
int findSpecialInteger(int* arr, int arrSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int count = 0;
    int max= 0;
    for(i=0;i<arrSize;i++){
        count = 0;
        for(j=i;j<arrSize;j++){
            if(arr[i]==arr[j]){
                count++;
            }
            if(count>arrSize/4){
                return arr[i];
            }
        }
    }
    return -1;
}