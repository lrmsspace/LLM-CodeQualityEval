/**https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/ */
//Given an array of integers arr.
//We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
//Let's define a and b as follows:
//	a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
//	b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
//Note that ^ denotes the bitwise-xor operation.
//Return the number of triplets (i, j and k) Where a == b.
// 
//Example 1:
//Input: arr = [2,3,1,6,7]
//Output: 4
//Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
//Example 2:
//Input: arr = [1,1,1,1,1]
//Output: 10
// 
//Constraints:
//	1 <= arr.length <= 300
//	1 <= arr[i] <= 108
int countTriplets(int* arr, int arrSize) {
    int n = arrSize;
    int count = 0;
    int xor_sum = 0;
    int* prefix_xor = (int*)malloc(n * sizeof(int));
    
    // Calculate prefix XOR and store it in prefix_xor
    prefix_xor[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix_xor[i] = prefix_xor[i - 1] ^ arr[i];
    }
    
    // Iterate through each index i
    for (int i = 0; i < n - 2; i++) {
        xor_sum = prefix_xor[i];
        
        // Iterate through each index j (j > i)
        for (int j = i + 1; j < n - 1; j++) {
            // Check if xor_sum ^ prefix_xor[j] equals 0
            if (xor_sum ^ prefix_xor[j] == 0) {
                count += j - i;
            }
        }
    }
    
    free(prefix_xor);
    return count;
    
}