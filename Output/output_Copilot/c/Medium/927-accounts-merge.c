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
        
        // Initialize variables
        int* parent = (int*)malloc(10001 * sizeof(int));
        int* rank = (int*)malloc(10001 * sizeof(int));
        for (int i = 0; i < 10001; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        char*** result = (char***)malloc(1000 * sizeof(char**));
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
        int* pathLengths = (int*)malloc(1000 * sizeof(int));
        char** path = (char**)malloc(1000 * sizeof(char*));
        int* emailToId = (int*)malloc(10001 * sizeof(int));
        for (int i = 0; i < 10001; i++) {
            emailToId[i] = -1;
        }
        
        // Find all accounts that can be merged
        for (int i = 0; i < accountsSize; i++) {
            int root = -1;
            for (int j = 1; j < accountsColSize[i]; j++) {
                int id = emailToId[accounts[i][j]];
                if (id == -1) {
                    emailToId[accounts[i][j]] = i;
                } else {
                    if (root == -1) {
                        root = id;
                    } else {
                        int root1 = id;
                        int root2 = root;
                        while (root1 != parent[root1]) {
                            root1 = parent[root1];
                        }
                        while (root2 != parent[root2]) {
                            root2 = parent[root2];
                        }
                        if (root1 != root2) {
                            if (rank[root1] > rank[root2]) {
                                parent[root2] = root1;
                            } else if (rank[root1] < rank[root2]) {
                                parent[root1] = root2;
                            } else {
                                parent[root2] = root1;
                                rank[root1]++;
                            }
                        }
                    }
                }
            }
        }
        
        // Find all merged accounts
        for (int i = 0; i < accountsSize; i++) {
            int root = i;
            while (root != parent[root]) {
                root = parent[root];
            }
            if (root == i) {
                path[0] = accounts[i][0];
                pathLengths[0] = 1;
                for (int j = 1; j < accountsColSize[i]; j++) {
                    if (emailToId[accounts[i][j]] == i) {
                        path[pathLengths[0]++] = accounts[i][j];
                    }
                }
                for (int j = 0; j < accountsSize; j++) {
                    if (parent[j] == i) {
                        for (int k = 1; k < accountsColSize[j]; k++) {
                            if (emailToId[accounts[j][k]] == j) {
                                path[pathLengths[0]++] = accounts[j][k];
                            }
                        }
                    }
                }
                result[*returnSize] = (char**)malloc(pathLengths[0] * sizeof(char*));
                (*returnColumnSizes)[*returnSize] = pathLengths[0];
                for (int j = 0; j < pathLengths[0]; j++) {
                    result[*returnSize][j] = (char*)malloc((strlen(path[j]) + 1) * sizeof(char));
                    strcpy(result[*returnSize][j], path[j]);
                }
                (*returnSize)++;
            }
        }
        return result;
}