/**https://leetcode.com/problems/minimum-interval-to-include-each-query/ */
//You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
//You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
//Return an array containing the answers to the queries.
// 
//Example 1:
//Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
//Output: [3,3,1,4]
//Explanation: The queries are processed as follows:
//- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
//- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
//- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
//- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
//Example 2:
//Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
//Output: [2,-1,4,6]
//Explanation: The queries are processed as follows:
//- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
//- Query = 19: None of the intervals contain 19. The answer is -1.
//- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
//- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
// 
//Constraints:
//	1 <= intervals.length <= 105
//	1 <= queries.length <= 105
//	intervals[i].length == 2
//	1 <= lefti <= righti <= 107
//	1 <= queries[j] <= 107
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* queries, int queriesSize, int* returnSize) {
       *returnSize = queriesSize;
        int* res = (int*)malloc(sizeof(int) * queriesSize);
        int* idx = (int*)malloc(sizeof(int) * queriesSize);
        for (int i = 0; i < queriesSize; i++) {
            idx[i] = i;
        }
        qsort(idx, queriesSize, sizeof(int), cmp);
        int* sortedQueries = (int*)malloc(sizeof(int) * queriesSize);
        for (int i = 0; i < queriesSize; i++) {
            sortedQueries[i] = queries[idx[i]];
        }
        int* sortedIntervals[intervalsSize];
        for (int i = 0; i < intervalsSize; i++) {
            sortedIntervals[i] = (int*)malloc(sizeof(int) * 3);
            sortedIntervals[i][0] = intervals[i][0];
            sortedIntervals[i][1] = intervals[i][1];
            sortedIntervals[i][2] = i;
        }
        qsort(sortedIntervals, intervalsSize, sizeof(int*), cmp2);
        int* sortedRes = (int*)malloc(sizeof(int) * intervalsSize);
        int* pq = (int*)malloc(sizeof(int) * (intervalsSize + 1));
        int pqSize = 0;
        int j = 0;
        for (int i = 0; i < queriesSize; i++) {
            while (j < intervalsSize && sortedIntervals[j][0] <= sortedQueries[i]) {
                int l = sortedIntervals[j][0];
                int r = sortedIntervals[j][1];
                int idx = sortedIntervals[j][2];
                sortedRes[idx] = r - l + 1;
                pq[pqSize++] = r - l + 1;
                for (int k = pqSize - 1; k > 0; k--) {
                    if (pq[k] < pq[k - 1]) {
                        int t = pq[k];
                        pq[k] = pq[k - 1];
                        pq[k - 1] = t;
                    } else {
                        break;
                    }
                }
                j++;
            }
            while (pqSize > 0 && sortedIntervals[pq[0]][1] < sortedQueries[i]) {
                for (int k = 0; k < pqSize - 1; k++) {
                    pq[k] = pq[k + 1];
                }
                pqSize--;
            }
            if (pqSize == 0) {
                res[idx[i]] = -1;
            } else {
                res[idx[i]] = pq[0];
            }
        }
        for (int i = 0; i < intervalsSize; i++) {
            free(sortedIntervals[i]);
        }
        free(sortedQueries);
        free(sortedRes);
        free(pq);
        free(idx);
        return res; 
}