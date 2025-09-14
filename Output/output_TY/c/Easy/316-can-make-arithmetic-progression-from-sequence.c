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
bool canMakeArithmeticProgression(int* arr, int arrSize){
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < arrSize; i++) {
        min = min < arr[i] ? min : arr[i];
        max = max > arr[i] ? max : arr[i];
    }
    int d = (max - min) / (arrSize - 1);
    if (d == 0) return true;
    int* hash =(int*)malloc(sizeof(int) * (max - min));
    memset(hash, 0, sizeof(int) * (max - min));
    for (int i = 0; i < arrSize; i++) {
        hash[arr[i] - min]++;
    }
    int count = 0;
    for (int i = 0; i < max - min; i++) {
        if (hash[i] == 0) continue;
        if (hash[i] > 1) count += hash[i] - 1;
    }
    return count <= 1;
}