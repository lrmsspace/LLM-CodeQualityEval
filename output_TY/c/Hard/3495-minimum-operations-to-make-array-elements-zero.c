/*
 You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.
 In one operation, you can:
 Select two integers a and b from the array.
 Replace them with floor(a / 4) and floor(b / 4).
 Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.
 Example 1:
 Input: queries = [[1,2],[2,4]]
 Output: 3
 Explanation:
 For queries[0]:
 The initial array is nums = [1, 2].
 In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
 The minimum number of operations required is 1.
 For queries[1]:
 The initial array is nums = [2, 3, 4].
 In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 1].
 In the second operation, select nums[1] and nums[2]. The array becomes [0, 0, 0].
 The minimum number of operations required is 2.
 The output is 1 + 2 = 3.
 Example 2:
 Input: queries = [[2,6]]
 Output: 4
 Explanation:
 For queries[0]:
 The initial array is nums = [2, 3, 4, 5, 6].
 In the first operation, select nums[0] and nums[3]. The array becomes [0, 3, 4, 1, 6].
 In the second operation, select nums[2] and nums[4]. The array becomes [0, 3, 1, 1, 1].
 In the third operation, select nums[1] and nums[2]. The array becomes [0, 0, 0, 1, 1].
 In the fourth operation, select nums[3] and nums[4]. The array becomes [0, 0, 0, 0, 0].
 The minimum number of operations required is 4.
 The output is 4.
 Constraints:
 1 <= queries.length <= 105
 queries[i].length == 2
 queries[i] == [l, r]
 1 <= l < r <= 109
*/

long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    int i, j, k, l, r, n, m, count, sum, ans, *arr, *prefix, *suffix;
    long long result = 0;
    
    for (i = 0; i < queriesSize; i++) {
        l = queries[i][0];
        r = queries[i][1];
        
        n = r - l + 1;
        m = (r + l) / 2;
        
        arr = (int*)malloc(n * sizeof(int));
        prefix = (int*)malloc(n * sizeof(int));
        suffix = (int*)malloc(n * sizeof(int));
        
        for (j = 0; j < n; j++) {
            arr[j] = a[l + j];
        }
    }
    for (j = 0; j < n; j++) {
        prefix[j] = arr[j] - m + j;
    }   
    for (j = n - 1; j >= 0; j--) {
        suffix[j] = arr[j] - m + n - j - 1;
    }
    for (j = 0; j < n; j++) { 
        printf("%d ", min(prefix[j], suffix[j]));   
    }
    printf("\n");
    free(arr);
    free(prefix);
    free(suffix);
    return 0;
    
}