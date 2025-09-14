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
    /**
     * 1. Create a disjoint set to union the accounts with the same email
     * 2. Iterate over the accounts and union the accounts with the same email
     * 3. Iterate over the accounts and add the emails to the disjoint set
     * 4. Iterate over the accounts and add the name to the disjoint set
     * 5. Return the result
     */
    struct DisjointSet *ds = createDisjointSet(accountsSize);
    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            int idx = findEmailIndex(accounts, accountsSize, accountsColSize, accounts[i][j]);
            if (idx != -1) {
                unionSets(ds, i, idx);
            }
        }
    }
    // Add the emails to the disjoint set
    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            addEmailToSet(ds, i, accounts[i][j]);
        }
    }
    // Add the name to the disjoint set
    for (int i = 0; i < accountsSize; i++) {
        addNameToSet(ds, i, accounts[i][0]);
    }
    // Return the result
    *returnSize = ds->size;
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    char*** result = (char***)malloc((*returnSize) * sizeof(char**));
    for (int i = 0; i < ds->size; i++) {
        int size = ds->sets[i]->size;
        (*returnColumnSizes)[i] = size + 1;
        result[i] = (char**)malloc((size + 1) * sizeof(char*));
        result[i][0] = ds->names[i];
        for (int j = 0; j < size; j++) {
            result[i][j + 1] = ds->emails[ds->sets[i]->elements[j]];
        }
    }
    freeDisjointSet(ds);
    return result;
    
}