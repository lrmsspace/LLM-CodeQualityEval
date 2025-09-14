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
 nums.length == n
 1 <= n <= 105
 1 <= nums[i] <= 109
 1 <= x <= k <= nums.length
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    long long* answer = (long long*)malloc((numsSize - k + 1) * sizeof(long long));
    *returnSize = numsSize - k + 1;

    for (int i = 0; i <= numsSize - k; i++) {
        int count[100001] = {0}; // Assuming nums[i] <= 10^9, we can use a smaller range
        long long sum = 0;

        // Count occurrences in the current subarray
        for (int j = i; j < i + k; j++) {
            count[nums[j]]++;
        }

        // Create an array of pairs (value, frequency)
        int freq[100001][2];
        int index = 0;
        for (int j = 0; j < 100001; j++) {
            if (count[j] > 0) {
                freq[index][0] = j; // value
                freq[index][1] = count[j]; // frequency
                index++;
            }
        }

        // Sort by frequency and then by value
        qsort(freq, index, sizeof(freq[0]), [](const void* a, const void* b) {
            if (((const int(*)[2])a)[0][1] != ((const int(*)[2])b)[0][1]) {
                return ((const int(*)[2])b)[0][1] - ((const int(*)[2])a)[0][1]; // sort by frequency descending
            }
            return ((const int(*)[2])b)[0][0] - ((const int(*)[2])a)[0][0]; // sort by value descending
        });

        // Calculate x-sum
        for (int j = 0; j < x && j < index; j++) {
            sum += freq[j][0] * freq[j][1];
        }

        answer[i] = sum;
    }

    return answer;    
}