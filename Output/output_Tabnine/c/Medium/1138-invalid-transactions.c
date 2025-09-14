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
    int* invalidCount = malloc(transactionsSize * sizeof(int));
    memset(invalidCount, 0, transactionsSize * sizeof(int));
    
    for (int i = 0; i < transactionsSize; i++) {
        char** fields = split(transactions[i], ',');
        char* name = fields[0];
        int time = atoi(fields[1]);
        int amount = atoi(fields[2]);
        char* city = fields[3];
        
        for (int j = 0; j < transactionsSize; j++) {
            if (i == j) continue;
            
            char** otherFields = split(transactions[j], ',');
            int otherTime = atoi(otherFields[1]);
            int otherAmount = atoi(otherFields[2]);
            char* otherCity = otherFields[3];
            
            if (strcmp(name, otherFields[0]) == 0 &&
                abs(time - otherTime) <= 60 &&
                strcmp(city, otherCity)!= 0 &&
                amount > 1000) {
                invalidCount[i]++;
            }
            
            free(otherFields);
        }
        
        free(fields);
    }
    
    int validCount = transactionsSize - *invalidCount;
    char** validTransactions = malloc(validCount * sizeof(char*));
    int validIndex = 0;
    
    for (int i = 0; i < transactionsSize; i++) {
        if (invalidCount[i] == 0) {
            validTransactions[validIndex++] = transactions[i];
        }
    }
    
    *returnSize = validCount;
    free(invalidCount);
    
    return validTransactions;
    
}