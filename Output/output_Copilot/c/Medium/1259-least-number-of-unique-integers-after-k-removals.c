/**https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/ */
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
// 
//Example 1:
//Input: arr = [5,5,4], k = 1
//Output: 1
//Explanation: Remove the single 4, only 5 is left.
//Example 2:
//Input: arr = [4,3,1,1,3,3,2], k = 3
//Output: 2
//Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
// 
//Constraints:
//	1 <= arr.length <= 10^5
//	1 <= arr[i] <= 10^9
//	0 <= k <= arr.length

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);

}

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){ 

    // Step 1: Count the frequency of each integer
    int freq[100001] = {0};
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i]]++;
    }

    // Step 2: Store frequencies in a separate array and sort them
    int freqCount[100001] = {0};
    int uniqueCount = 0;
    for (int i = 0; i < 100001; i++) {
        if (freq[i] > 0) {
            freqCount[uniqueCount++] = freq[i];
        }
    }
    qsort(freqCount, uniqueCount, sizeof(int), (int (*)(const void*, const void*))compare);

    // Step 3: Remove elements with the smallest frequencies
    for (int i = 0; i < uniqueCount; i++) {
        if (k >= freqCount[i]) {
            k -= freqCount[i];
            freqCount[i] = 0;
        } else {
            break;
        }
    }

    // Step 4: Count the remaining unique integers
    int result = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (freqCount[i] > 0) {
            result++;
        }
    }

    return result;
}
