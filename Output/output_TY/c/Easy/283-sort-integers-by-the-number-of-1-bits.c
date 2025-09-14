/**https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/ */
//You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
//Return the array after sorting it.
// 
//Example 1:
//Input: arr = [0,1,2,3,4,5,6,7,8]
//Output: [0,1,2,4,8,3,5,6,7]
//Explantion: [0] is the only integer with 0 bits.
//[1,2,4,8] all have 1 bit.
//[3,5,6] have 2 bits.
//[7] has 3 bits.
//The sorted array by bits is [0,1,2,4,8,3,5,6,7]
//Example 2:
//Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
//Output: [1,2,4,8,16,32,64,128,256,512,1024]
//Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
// 
//Constraints:
//	1 <= arr.length <= 500
//	0 <= arr[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
    int i, j, temp, count, max, min, max_index, min_index;
    int* result = (int*)malloc(sizeof(int) * arrSize);
    for (i = 0; i < arrSize; i++) {
        result[i] = arr[i];
    }
    for (i = 0; i < arrSize - 1; i++) {
        max = result[i];
        max_index = i;
    }
    for (i = 0; i < arrSize - 1; i++) {
        min = result[i];
        min_index = i;
    }
    for (i = 0; i < arrSize - 1; i++) {
        for (j = i + 1; j < arrSize; j++) {
            count = 0;
            temp = result[j];
            while (temp) {
                count += temp % 2;
                temp = temp / 2;
            }
            if (count > max) {
                max = count;
                max_index= j;
            }
        }
    }
    result[max_index] = result[i];
    result[i] = max;
    return result;
}
