/*
 You are given an array nums of n integers and two integers k and x.
 The x-sum of an array is calculated by the following procedure:
 Count the occurrences of all elements in the array.
 Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
 Calculate the sum of the resulting array.
 Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
 Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
 Example 1:
 Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 Output: [6,10,12]
 Explanation:
 For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
 For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
 For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 Example 2:
 Input: nums = [3,8,7,8,7,5], k = 2, x = 2
 Output: [11,15,15,15,12]
 Explanation:
 Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 Constraints:
 1 <= n == nums.length <= 50
 1 <= nums[i] <= 50
 1 <= x <= k <= nums.length
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int value;
    int count;
} ElementCount;

int compare(const void* a, const void* b) {
    ElementCount* elemA = (ElementCount*)a;
    ElementCount* elemB = (ElementCount*)b;
    if (elemA->count == elemB->count) {
        return elemB->value - elemA->value;
    }
    return elemB->count - elemA->count;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i <= numsSize - k; i++) {
        int count[51] = {0};
        for (int j = i; j < i + k; j++) {
            count[nums[j]]++;
        }

        ElementCount elements[51];
        int elemCount = 0;

        for (int j = 1; j <= 50; j++) {
            if (count[j] > 0) {
                elements[elemCount].value = j;
                elements[elemCount].count = count[j];
                elemCount++;
            }
        }

        qsort(elements, elemCount, sizeof(ElementCount), compare);

        int sum = 0;
        int toConsider = (x < elemCount) ? x : elemCount;

        for (int j = 0; j < toConsider; j++) {
            sum += elements[j].value * elements[j].count;
        }

        result[i] = sum;
    }

    return result;
}

