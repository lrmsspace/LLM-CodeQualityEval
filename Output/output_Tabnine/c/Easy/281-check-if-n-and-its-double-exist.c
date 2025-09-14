/**https://leetcode.com/problems/check-if-n-and-its-double-exist/ */
//Given an array arr of integers, check if there exist two indices i and j such that :
//	i != j
//	0 <= i, j < arr.length
//	arr[i] == 2 * arr[j]
// 
//Example 1:
//Input: arr = [10,2,5,3]
//Output: true
//Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
//Example 2:
//Input: arr = [3,1,7,11]
//Output: false
//Explanation: There is no i and j that satisfy the conditions.
// 
//Constraints:
//	2 <= arr.length <= 500
//	-103 <= arr[i] <= 103
bool checkIfExist(int* arr, int arrSize) {
    int* map = calloc(1001, sizeof(int)); // Using a map to store the count of each number
    for (int i = 0; i < arrSize; i++) {
        int target = arr[i] / 2;
        if (map[arr[i]] > 0 || (target!= arr[i] && map[target] > 0)) {
            free(map);
            return true;
        }
        map[arr[i]]++;
    }
    free(map);
    return false;  // No pair found that satisfies the condition
    
}