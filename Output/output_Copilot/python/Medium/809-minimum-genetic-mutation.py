#https://leetcode.com/problems/minimum-genetic-mutation/
#A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
#Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
#	For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
#There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
#Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
#Note that the starting point is assumed to be valid, so it might not be included in the bank.
# 
#Example 1:
#Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
#Output: 1
#Example 2:
#Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
#Output: 2
# 
#Constraints:
#	0 <= bank.length <= 10
#	startGene.length == endGene.length == bank[i].length == 8
#	startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
class Solution(object):
    def minMutation(self, startGene, endGene, bank):
        """
        :type startGene: str
        :type endGene: str
        :type bank: List[str]
        :rtype: int
        """
        if endGene not in bank:
            return -1

        queue = [(startGene, 0)]   
        visited = set([startGene])
        gene_set = set(bank)
        gene_set.add(startGene)
        gene_length = len(startGene)
        mutations = ['A', 'C', 'G', 'T']
        while queue:
            current_gene, steps = queue.pop(0)
            if current_gene == endGene:
                return steps
            for i in range(gene_length):
                for mutation in mutations:
                    new_gene = current_gene[:i] + mutation + current_gene[i+1:]
                    if new_gene in gene_set and new_gene not in visited:
                        visited.add(new_gene)
                        queue.append((new_gene, steps + 1))
        return -1     