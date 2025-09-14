/**https://leetcode.com/problems/minimum-genetic-mutation/ */
//A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
//Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
//	For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
//There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
//Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
//Note that the starting point is assumed to be valid, so it might not be included in the bank.
// 
//Example 1:
//Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
//Output: 1
//Example 2:
//Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
//Output: 2
// 
//Constraints:
//	0 <= bank.length <= 10
//	startGene.length == endGene.length == bank[i].length == 8
//	startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    int i, j, k, n = strlen(startGene), m = strlen(endGene), ans = 0;
    char **visited = (char **)malloc(sizeof(char *) * bankSize);
    for (i = 0; i < bankSize; i++) {
        visited[i] = (char *)malloc(sizeof(char) * 9);
        strcpy(visited[i], bank[i]);
    }
    char *queue[bankSize];
    int front = 0, rear = 0;
    queue[rear++] = startGene;
    while (front < rear) {
        int size = rear - front;
        for (i = 0; i < size; i++) {
            char *cur = queue[front++];
            if (strcmp(cur, endGene) == 0) {
                return ans;
            }
            for (j = 0; j < bankSize; j++) {
                if (visited[j] == NULL) {
                    continue;
                }
                int diff = 0;
                for (k = 0; k < n; k++) {
                    if (cur[k] != visited[j][k]) {
                        diff++;
                    }
                }
                if (diff == 1) {
                    queue[rear++] = visited[j];
                    visited[j] = NULL;
                }
            }
        }
        ans++;
    }
    return -1;    
}