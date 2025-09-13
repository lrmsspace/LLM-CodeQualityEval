/**https://leetcode.com/problems/prime-pairs-with-target-sum/ */
//You are given an integer n. We say that two integers x and y form a prime number pair if:
//	1 <= x <= y <= n
//	x + y == n
//	x and y are prime numbers
//Return the 2D sorted list of prime number pairs [xi, yi]. The list should be sorted in increasing order of xi. If there are no prime number pairs at all, return an empty array.
//Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.
// 
//Example 1:
//Input: n = 10
//Output: [[3,7],[5,5]]
//Explanation: In this example, there are two prime pairs that satisfy the criteria. 
//These pairs are [3,7] and [5,5], and we return them in the sorted order as described in the problem statement.
//Example 2:
//Input: n = 2
//Output: []
//Explanation: We can show that there is no prime number pair that gives a sum of 2, so we return an empty array. 
// 
//Constraints:
//	1 <= n <= 106
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findPrimePairs(int n, int* returnSize, int** returnColumnSizes) {
    int count = 0;
    int* primeList = (int*)malloc(n * sizeof(int));
    int* primeListSizes = (int*)malloc(n * sizeof(int));
    for (int i = 2; i <= n; i++) {
        int isPrime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primeList[count] = i;
            primeListSizes[count] = 1;
            count++;
        }
    }

    int** result = (int**)malloc(count * sizeof(int*));
    int* resultColumnSizes = (int*)malloc(count * sizeof(int));
    int resultIndex = 0;
    for (int i = 0; i < count; i++) {
        for (int j = count - 1; j >= i; j--) {
            if (primeList[i] + primeList[j] == n) {
                int* pair = (int*)malloc(2 * sizeof(int));
                pair[0] = primeList[i];
                pair[1] = primeList[j];
                result[resultIndex] = pair;
                resultColumnSizes[resultIndex] = 2;
                resultIndex++;
                break;
            }
        }
    }

    *returnSize = resultIndex;
    *returnColumnSizes = resultColumnSizes;

    return result;
    
}