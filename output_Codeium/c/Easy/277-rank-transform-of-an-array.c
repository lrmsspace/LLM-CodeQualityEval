/**https://leetcode.com/problems/rank-transform-of-an-array/ */
//Given an array of integers arr, replace each element with its rank.
//The rank represents how large the element is. The rank has the following rules:
//	Rank is an integer starting from 1.
//	The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
//	Rank should be as small as possible.
// 
//Example 1:
//Input: arr = [40,10,20,30]
//Output: [4,1,2,3]
//Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
//Example 2:
//Input: arr = [100,100,100]
//Output: [1,1,1]
//Explanation: Same elements share the same rank.
//Example 3:
//Input: arr = [37,12,28,9,100,56,80,5,12]
//Output: [5,3,4,2,8,6,7,1,3]
// 
//Constraints:
//	0 <= arr.length <= 105
//	-109 <= arr[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    if (arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int *sortedArr = (int *)malloc(arrSize * sizeof(int));
    memcpy(sortedArr, arr, arrSize * sizeof(int));
    qsort(sortedArr, arrSize, sizeof(int), cmp);
    
    int *rank = (int *)malloc(arrSize * sizeof(int));
    int *rankMap = (int *)malloc(arrSize * sizeof(int));
    
    int currentRank = 1;
    rankMap[0] = currentRank;
    for (int i = 1; i < arrSize; i++) {
        if (sortedArr[i] != sortedArr[i - 1]) {
            currentRank++;
        }
        rankMap[i] = currentRank;
    }
    
    for (int i = 0; i < arrSize; i++) {
        int *pos = (int *)bsearch(&arr[i], sortedArr, arrSize, sizeof(int), cmp);
        rank[i] = rankMap[pos - sortedArr];
    }
    
    *returnSize = arrSize;
    free(sortedArr);
    free(rankMap);
    
    return rank;
}
    