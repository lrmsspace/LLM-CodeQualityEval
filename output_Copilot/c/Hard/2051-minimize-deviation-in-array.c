/**https://leetcode.com/problems/minimize-deviation-in-array/ */
//You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//	If the element is even, divide it by 2.
//	
//		For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//	
//	
//	If the element is odd, multiply it by 2.
//	
//		For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//	
//	
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.
// 
//Example 1:
//Input: nums = [1,2,3,4]
//Output: 1
//Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
//Example 2:
//Input: nums = [4,1,5,20,3]
//Output: 3
//Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
//Example 3:
//Input: nums = [2,10,8]
//Output: 3
// 
//Constraints:
//	n == nums.length
//	2 <= n <= 5 * 104
//	1 <= nums[i] <= 109
int minimumDeviation(int* nums, int numsSize) {
    int max = 0;
    int min = INT_MAX;
    int res = INT_MAX;
    int i;
    int* heap = (int*)malloc(sizeof(int) * numsSize * 2);
    int heapSize = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 1) {
            heap[heapSize++] = nums[i] * 2;
            if (nums[i] * 2 > max) {
                max = nums[i] * 2;
            }
            if (nums[i] * 2 < min) {
                min = nums[i] * 2;
            }
        }
        else {
            heap[heapSize++] = nums[i];
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
    }
    if (max % 2 == 1) {
        heap[heapSize++] = max;
    }
    while (heapSize > 0) {
        qsort(heap, heapSize, sizeof(int), cmp);
        int cur = heap[heapSize - 1];
        if (cur % 2 == 1) {
            break;
        }
        heap[heapSize - 1] /= 2;
        if (heap[heapSize - 1] < min) {
            min = heap[heapSize - 1];
        }
        if (heap[heapSize - 1] > max) {
            max = heap[heapSize - 1];
        }
        if (max - min < res) {
            res = max - min;
        }
        if (heap[heapSize - 1] % 2 == 1) {
            heap[heapSize++] = heap[heapSize - 1];
        }
    }
    return res;    
}