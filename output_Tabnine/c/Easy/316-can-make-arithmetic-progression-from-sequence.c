/**https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/ */
//A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
//Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
// 
//Example 1:
//Input: arr = [3,5,1]
//Output: true
//Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
//Example 2:
//Input: arr = [1,2,4]
//Output: false
//Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
// 
//Constraints:
//	2 <= arr.length <= 1000
//	-106 <= arr[i] <= 106
bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    for (int i = 0; i < arrSize; i++) {
        minNum = min(minNum, arr[i]);
        maxNum = max(maxNum, arr[i]);
    }
    
    int diff = (maxNum - minNum) / (arrSize - 1);
    if (diff == 0) {
        return false;
    }
    
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i]!= diff) {
            return false;
        }
    }
    
    return true;
    
}