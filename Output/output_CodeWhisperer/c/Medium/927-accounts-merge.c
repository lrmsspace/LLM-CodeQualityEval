/**https://leetcode.com/problems/accounts-merge/ */
//Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
// 
//Example 1:
//Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
//Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
//Explanation:
//The first and second John's are the same person as they have the common email "johnsmith@mail.com".
//The third John and Mary are different people as none of their email addresses are used by other accounts.
//We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
//['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
//Example 2:
//Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
//Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
// 
//Constraints:
//	1 <= accounts.length <= 1000
//	2 <= accounts[i].length <= 10
//	1 <= accounts[i][j].length <= 30
//	accounts[i][0] consists of English letters.
//	accounts[i][j] (for j > 0) is a valid email.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */ 
char*** accountsMerge(char*** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes) {
    // Step 1: Count total number of emails
    int totalEmails = 0;
    for (int i = 0; i < accountsSize; i++) {
        totalEmails += accountsColSize[i] - 1;  // Subtract 1 for the name
    }
    
    // Step 2: Create a mapping from email to index
    char** allEmails = (char**)malloc(totalEmails * sizeof(char*));
    int emailCount = 0;
    
    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            allEmails[emailCount++] = strdup(accounts[i][j]);
        }
    }
    
    // Sort emails to remove duplicates
    qsort(allEmails, emailCount, sizeof(char*), compareStrings);
    
    // Remove duplicates
    int uniqueCount = 0;
    for (int i = 1; i < emailCount; i++) {
        if (strcmp(allEmails[i], allEmails[uniqueCount]) != 0) {
            allEmails[++uniqueCount] = allEmails[i];
        } else {
            free(allEmails[i]);  // Free duplicate email
        }
    }
    uniqueCount++;  // Adjust count
    
    // Create a map from email to index
    char** emailToIndex = (char**)malloc(uniqueCount * sizeof(char*));
    for (int i = 0; i < uniqueCount; i++) {
        emailToIndex[i] = allEmails[i];
    }
    
    // Step 3: Build the disjoint set
    DisjointSet* ds = createDisjointSet(uniqueCount);
    
    // Step 4: Union emails that belong to the same account
    for (int i = 0; i < accountsSize; i++) {
        int firstEmailIdx = -1;
        
        // Find the first email's index
        for (int k = 0; k < uniqueCount; k++) {
            if (strcmp(accounts[i][1], emailToIndex[k]) == 0) {
                firstEmailIdx = k;
                break;
            }
        }
        
        // Union all emails in this account
        for (int j = 2; j < accountsColSize[i]; j++) {
            int currentEmailIdx = -1;
            
            // Find current email's index
            for (int k = 0; k < uniqueCount; k++) {
                if (strcmp(accounts[i][j], emailToIndex[k]) == 0) {
                    currentEmailIdx = k;
                    break;
                }
            }
            
            if (currentEmailIdx != -1 && firstEmailIdx != -1) {
                unionSets(ds, firstEmailIdx, currentEmailIdx);
            }
        }
    }
    
    // Step 5: Group emails by their connected component
    char*** emailGroups = (char***)malloc(uniqueCount * sizeof(char**));
    int* groupSizes = (int*)calloc(uniqueCount, sizeof(int));
    char** nameForGroup = (char**)malloc(uniqueCount * sizeof(char*));
    
    // Initialize email groups
    for (int i = 0; i < uniqueCount; i++) {
        emailGroups[i] = (char**)malloc(uniqueCount * sizeof(char*));
        nameForGroup[i] = NULL;
    }
    
    // Group emails by their root
    for (int i = 0; i < uniqueCount; i++) {
        int root = find(ds, i);
        emailGroups[root][groupSizes[root]++] = strdup(emailToIndex[i]);
    }
    
    // Find the name for each group
    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            int emailIdx = -1;
            
            // Find the email's index
            for (int k = 0; k < uniqueCount; k++) {
                if (strcmp(accounts[i][j], emailToIndex[k]) == 0) {
                    emailIdx = k;
                    break;
                }
            }
            
            if (emailIdx != -1) {
                int root = find(ds, emailIdx);
                if (nameForGroup[root] == NULL) {
                    nameForGroup[root] = strdup(accounts[i][0]);
                }
            }
        }
    }
    
    // Step 6: Prepare the result
    int resultCount = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (groupSizes[i] > 0 && find(ds, i) == i) {
            resultCount++;
        }
    }
    
    char*** result = (char***)malloc(resultCount * sizeof(char**));
    *returnColumnSizes = (int*)malloc(resultCount * sizeof(int));
    *returnSize = resultCount;
    
    int resultIdx = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (groupSizes[i] > 0 && find(ds, i) == i) {
            // Sort emails in this group
            qsort(emailGroups[i], groupSizes[i], sizeof(char*), compareStrings);
            
            // Allocate space for name + emails
            (*returnColumnSizes)[resultIdx] = groupSizes[i] + 1;
            result[resultIdx] = (char**)malloc((groupSizes[i] + 1) * sizeof(char*));
            
            // Add name
            result[resultIdx][0] = nameForGroup[i];
            
            // Add emails
            for (int j = 0; j < groupSizes[i]; j++) {
                result[resultIdx][j + 1] = emailGroups[i][j];
            }
            
            resultIdx++;
        }
    }
    
    // Clean up
    for (int i = 0; i < uniqueCount; i++) {
        if (find(ds, i) != i) {
            free(nameForGroup[i]);
        }
        free(emailGroups[i]);
    }
    
    free(emailGroups);
    free(groupSizes);
    free(nameForGroup);
    free(emailToIndex);
    freeDisjointSet(ds);
    
    return result;
}
