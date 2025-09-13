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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[256] = {0};
    int b[256] = {0};
    int c[256] = {0};
    int d[256] = {0};
    int e[256] = {0};
    int f[256] = {0};
    int g[256] = {0};
    int h[256] = {0};
    double ans = 0;
    double *ret = (double *)malloc(sizeof(double) * 5);
    int head = 0;
    int tail = 0;
    int queue[256];
    for(i = 0; i < 256; i++) {
        queue[tail] = i;
        tail++;
    }
    for(i = 0; i < 256; i++) {
        a[i] = count[i];
    }
    for(i = 0; i < 256; i++) {
        if(a[i] > 0) {
            b[head] = i;
            head++;
        }
    }
    ret[0] = b[0];
    ret[1] = b[head - 1];
    for(i = 0; i < 256; i++) {
        c[i] = a[i];
    }
    for(i = 0; i < 256; i++) {
        d[i] = c[i];
    }
    for(i = 0; i < 256; i++) {
        e[i] = c[i];
    }
    for(i = 0; i < 256; i++) {
        f[i] = c[i];
    }
    for(i = 0; i < 256; i++) {
        g[i] = c[i];
    }
    for(i = 0; i < 256; i++) {
        h[i] = c[i];
    }
    for(i = 0; i < 256; i++) {
        if(c[i] > 0) {
            j = i;
            break;
        }
    }
    for(i = 255; i >= 0; i--) {
        if(c[i] > 0) {
            k = i;
            break;
        }
               
}