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
    int min_deviation = INT_MAX;
    int max_val;
    int* heap = (int*)malloc(numsSize * sizeof(int));
    int heap_size = 0;

    // Initialize the heap and adjust numbers
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 != 0) {
            nums[i] *= 2;
        }
        heap[heap_size++] = nums[i];
        if (nums[i] < min_deviation) {
            min_deviation = nums[i];
        }
    }

    // Build max heap
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        int current = i;
        while (2 * current + 1 < heap_size) {
            int largest = 2 * current + 1;
            if (largest + 1 < heap_size && heap[largest] < heap[largest + 1]) {
                largest++;
            }
            if (heap[current] >= heap[largest]) break;
            int temp = heap[current];
            heap[current] = heap[largest];
            heap[largest] = temp;
            current = largest;
        }
    }

    // Minimize deviation
    do {
        max_val = heap[0];
        if (max_val - min_deviation < min_deviation) {
            min_deviation = max_val - min_deviation;
        }
        if (max_val % 2 == 1) break;
        max_val /= 2;
        heap[0] = max_val;
        int current = 0;
        while (2 * current + 1 < heap_size) {
            int largest = 2 * current + 1;
            if (largest + 1 < heap_size && heap[largest] < heap[largest + 1]) {
                largest++;
            }
            if (heap[current] >= heap[largest]) break;
            int temp = heap[current];
            heap[current] = heap[largest];
            heap[largest] = temp;
            current = largest;
        }
    } while (max_val % 2 == 0);

    free(heap);
    return min_deviation;
}