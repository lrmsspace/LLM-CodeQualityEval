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
    let queue = [startGene];
    let visited = new Set();
    let count = 0;
    while(queue.length){
        let next = [];
        for(let i=0;i<queue.length;i++){
            let curr = queue[i];
            if(curr===endGene) return count;
            for(let j=0;j<bank.length;j++){
                let diff = 0;
                for(let k=0;k<8;k++){
                    if(curr[k]!==bank[j][k]) diff++;
                    if(diff>1) break;
                }
                if(diff===1 && !visited.has(bank[j])){
                    next.push(bank[j]);
                    visited.add(bank[j]);
                }
            }
        }
    }
    return -1;
};