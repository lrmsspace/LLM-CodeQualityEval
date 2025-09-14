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
    int count = 0;
    int target = arrSize / 4;
    
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        } else {
            count = 0;
        }
        
        if (count > target) {
            return arr[i];
        }
    }
    
    return arr[arrSize - 1];  // If no special integer found, return the last element
    
}