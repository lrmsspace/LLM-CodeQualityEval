/**https://leetcode.com/problems/statistics-from-a-large-sample/ */
//You are given a large sample of integers in the range [0, 255]. Since the sample is so large, it is represented by an array count where count[k] is the number of times that k appears in the sample.
//Calculate the following statistics:
//	minimum: The minimum element in the sample.
//	maximum: The maximum element in the sample.
//	mean: The average of the sample, calculated as the total sum of all elements divided by the total number of elements.
//	median:
//	
//		If the sample has an odd number of elements, then the median is the middle element once the sample is sorted.
//		If the sample has an even number of elements, then the median is the average of the two middle elements once the sample is sorted.
//	
//	
//	mode: The number that appears the most in the sample. It is guaranteed to be unique.
//Return the statistics of the sample as an array of floating-point numbers [minimum, maximum, mean, median, mode]. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: count = [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
//Output: [1.00000,3.00000,2.37500,2.50000,3.00000]
//Explanation: The sample represented by count is [1,2,2,2,3,3,3,3].
//The minimum and maximum are 1 and 3 respectively.
//The mean is (1+2+2+2+3+3+3+3) / 8 = 19 / 8 = 2.375.
//Since the size of the sample is even, the median is the average of the two middle elements 2 and 3, which is 2.5.
//The mode is 3 as it appears the most in the sample.
//Example 2:
//Input: count = [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
//Output: [1.00000,4.00000,2.18182,2.00000,1.00000]
//Explanation: The sample represented by count is [1,1,1,1,2,2,2,3,3,4,4].
//The minimum and maximum are 1 and 4 respectively.
//The mean is (1+1+1+1+2+2+2+3+3+4+4) / 11 = 24 / 11 = 2.18181818... (for display purposes, the output shows the rounded number 2.18182).
//Since the size of the sample is odd, the median is the middle element 2.
//The mode is 1 as it appears the most in the sample.
// 
//Constraints:
//	count.length == 256
//	0 <= count[i] <= 109
//	1 <= sum(count) <= 109
//	The mode of the sample that count represents is unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* sampleStats(int* count, int countSize, int* returnSize) {
    double* result = (double*)malloc(5 * sizeof(double));
    *returnSize = 5;
    
    int total = 0, sum = 0, maxIndex = 0, minIndex = 0;
    for (int i = 0; i < countSize; i++) {
        total += count[i];
        sum += i * count[i];
        if (count[i] > count[maxIndex]) {
            maxIndex = i;
        }
        if (count[minIndex] == 0 || count[i] < count[minIndex]) {
            minIndex = i;
        }
    }
    result[0] = (double)minIndex;
    result[1] = (double)maxIndex;
    result[2] = (double)sum / total;
    int mid = total / 2;
    int left = 0, right = 0;
    for (int i = 0; i < countSize; i++) {
        left += count[i];
        if (left >= mid) {
            right = left - count[i];
            break;
        }
    }
    if (total % 2 == 0) {
        result[3] = (double)(right + left - count[right]) / 2;
    } else {
        result[3] = (double)right;
    }
    result[4] = (double)maxIndex;
    
    return result;
}