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
int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    int* answer = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;

    for (int i = 0; i <= numsSize - k; i++) {
        int freq[51] = {0}; // Frequency array for numbers 1 to 50
        int sum = 0;

        // Count frequencies in the current subarray
        for (int j = i; j < i + k; j++) {
            freq[nums[j]]++;
        }

        // Create a list of (value, frequency) pairs
        int pairs[51][2]; // pairs[i][0] = value, pairs[i][1] = frequency
        int count = 0;
        for (int j = 1; j <= 50; j++) {
            if (freq[j] > 0) {
                pairs[count][0] = j;
                pairs[count][1] = freq[j];
                count++;
            }
        }

        // Sort pairs by frequency and then by value
        for (int j = 0; j < count - 1; j++) {
            for (int l = j + 1; l < count; l++) {
                if (pairs[j][1] < pairs[l][1] || 
                   (pairs[j][1] == pairs[l][1] && pairs[j][0] < pairs[l][0])) {
                    int temp[2] = {pairs[j][0], pairs[j][1]};
                    pairs[j][0] = pairs[l][0];
                    pairs[j][1] = pairs[l][1];
                    pairs[l][0] = temp[0];
                    pairs[l][1] = temp[1];
                }
            }
        }

        // Calculate the x-sum
        for (int j = 0; j < x && j < count; j++) {
            sum += pairs[j][0] * pairs[j][1]; // Add value * frequency
        }

        answer[i] = sum;
    }

    return answer;
    
}