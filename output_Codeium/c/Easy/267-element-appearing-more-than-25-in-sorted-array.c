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
int findSpecialInteger(int* arr, int arrSize) {
    
    int target = arrSize / 4;
    int left = 0, right = 0, count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == arr[right]) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            left = right;
            count = 1;
        }
        right++;
    }
    return arr[left];
}
