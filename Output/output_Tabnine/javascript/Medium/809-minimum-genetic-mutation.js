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
/**
 * @param {string} startGene
 * @param {string} endGene
 * @param {string[]} bank
 * @return {number}
 */
var minMutation = function(startGene, endGene, bank) {
    const bankSet = new Set(bank);
    if (!bankSet.has(endGene)) return -1;
    
    const directions = [[-1, 0, 0], [1, 0, 0], [0, -1, 0], [0, 1, 0], [0, 0, -1], [0, 0, 1]];
    const queue = [[startGene, 0]];
    const visited = new Set([startGene]);
    
    while (queue.length) {
        const [gene, steps] = queue.shift();
        
        if (gene === endGene) return steps;
        
        for (let i = 0; i < 8; i++) {
            let nextGene = '';
            for (let j = 0; j < 8; j++) {
                if (gene[j] === endGene[j]) nextGene += gene[j];
                else if (bankSet.has(gene.substr(0, j) + endGene[j] + gene.substr(j + 1))) nextGene += gene[j];
            }
            
            if (visited.has(nextGene)) continue;
            visited.add(nextGene);
            queue.push([nextGene, steps + 1]);
        }

        directions.forEach(([dx, dy, dz]) => {
            const nextX = startGene[0] + dx;
            const nextY = startGene[1] + dy;
            const nextZ = startGene[2] + dz;
            
            if (nextX < 0 || nextX >= 8 || nextY < 0 || nextY >= 8 || nextZ < 0 || nextZ >= 8) return;
            
            const nextGene = startGene.substr(0, 1) + String.fromCharCode(nextX + 65) + startGene.substr(2, 5);
            
            if (visited.has(nextGene)) return;
            visited.add(nextGene);
            queue.push([nextGene, steps + 1]);
        });
    }
    
    return -1;
    
};