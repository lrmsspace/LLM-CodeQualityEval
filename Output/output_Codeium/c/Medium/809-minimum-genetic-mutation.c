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
    
    int res = INT_MAX;
    int start = 0;
    int end = 0;
    for (int i = 0; i < bankSize; i++) {
        if (strcmp(bank[i], startGene) == 0) {
            start = i;
        }
        if (strcmp(bank[i], endGene) == 0) {
            end = i;
        }
    }
    if (start == 0 && end == 0) {
        return -1;
    }
    int step[bankSize];
    memset(step, -1, sizeof(step));
    step[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < bankSize; i++) {
            if (step[i] == -1 && bank[cur][0] != bank[i][0]) {
                step[i] = step[cur] + 1;
                q.push(i);
            }
            if (step[end] != -1) {
                break;
            }
        }
    }
    return step[end];
}
