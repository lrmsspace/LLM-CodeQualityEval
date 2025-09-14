/**https://leetcode.com/problems/invalid-transactions/ */
//A transaction is possibly invalid if:
//	the amount exceeds $1000, or;
//	if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
//You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
//Return a list of transactions that are possibly invalid. You may return the answer in any order.
// 
//Example 1:
//Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
//Output: ["alice,20,800,mtv","alice,50,100,beijing"]
//Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
//Example 2:
//Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
//Output: ["alice,50,1200,mtv"]
//Example 3:
//Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
//Output: ["bob,50,1200,mtv"]
// 
//Constraints:
//	transactions.length <= 1000
//	Each transactions[i] takes the form "{name},{time},{amount},{city}"
//	Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
//	Each {time} consist of digits, and represent an integer between 0 and 1000.
//	Each {amount} consist of digits, and represent an integer between 0 and 2000.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** invalidTransactions(char** transactions, int transactionsSize, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *flag = (int *)malloc(sizeof(int) * transactionsSize);
    char **res = (char **)malloc(sizeof(char *) * transactionsSize);
    for (i = 0; i < transactionsSize; i++) {
        flag[i] = 0;
        res[i] = (char *)malloc(sizeof(char) * 100);
    }
    *returnSize = 0;
    for (i = 0; i < transactionsSize; i++) {
        char *name1 = (char *)malloc(sizeof(char) * 100);
        char *time1 = (char *)malloc(sizeof(char) * 100);
        char *amount1 = (char *)malloc(sizeof(char) * 100);
        char *city1 = (char *)malloc(sizeof(char) * 100);
        j = 0;
        while (transactions[i][j] != ',') {
            name1[j] = transactions[i][j];
            j++;
        }
        name1[j] = '\0';
        j++;
        k = 0;
        while (transactions[i][j] != ',') {
            time1[k] = transactions[i][j];
            j++;
            k++;
        }
        time1[k] = '\0';
        j++;
        k = 0;
        while (transactions[i][j] != ',') {
            amount1[k] = transactions[i][j];
            j++;
            k++;
        }
        amount1[k] = '\0';
        j++;
        k = 0;
        while (transactions[i][j] != '\0') {
            city1[k] = transactions[i][j];
            j++;
            k++;
        }
        city1[k] = '\0';
        if (atoi(amount1) > 1000) {
            flag[i] = 1;
        }
        for (j = 0; j < transactionsSize; j++) {
            if (j == i) {
                continue;
            }
            char *name2 = (char *)malloc(sizeof(char) * 100);
            char *time2 = (char *)malloc(sizeof(char) * 100);
            char *amount2 = (char *)malloc(sizeof(char) * 100);
            char *city2 = (char *)malloc(sizeof(char) * 100);
            k = 0;
            while (transactions[j][k] != ',') {
                name2[k] = transactions[j][k];
                k++;
            }
            name2[k] = '\0';
            k++;
            l = 0;
            while (transactions[j][k] != ',') {
                time2[l] = transactions[j][k];
                k++;
                l++;
            }
            time2[l] = '\0';
            k++;
            l = 0;
            while (transactions[j][k] != ',') {
                amount2[l] = transactions[j][k];
                k++;
                l++;
            }
            amount2[l] = '\0';
            k++;
            l = 0;
            while (transactions[j][k] != '\0') {
                city2[l] = transactions[j][k];
                k++;
                l++;
            }
            city2[l] = '\0';
            if (strcmp(name1, name2) == 0 && strcmp(city1, city2) != 0 && abs(atoi(time1) - atoi(time2)) <= 60) {
                flag[i] = 1;
            }
        }
        free(name1);    
        free(time1);
        free(amount1);
        free(city1);

            

}