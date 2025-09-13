/*
 You are maintaining a project that has n methods numbered from 0 to n - 1.
 You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
 There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
 A group of methods can only be removed if no method outside the group invokes any methods within it.
 Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.
 Example 1:
 Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
 Output: [0,1,2,3]
 Explanation:
 Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.
 Example 2:
 Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
 Output: [3,4]
 Explanation:
 Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.
 Example 3:
 Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
 Output: []
 Explanation:
 All methods are suspicious. We can remove them.
 Constraints:
 1 <= n <= 105
 0 <= k <= n - 1
 0 <= invocations.length <= 2 * 105
 invocations[i] == [ai, bi]
 0 <= ai, bi <= n - 1
 ai != bi
 invocations[i] != invocations[j]
*/

/**
 * @param {number} n
 * @param {number} k
 * @param {number[][]} invocations
 * @return {number[]}
 */
var remainingMethods = function(n, k, invocations) {

    // Create a graph to represent the invocations
    const graph = Array.from({ length: n }, () => new Set());
    for (const [a, b] of invocations) {
        graph[a].add(b);
        graph[b].add(a);
    }
    
    // Create a set to store the suspicious methods
    const suspicious = new Set([k]);
    
    // Helper function to find all the methods that are invoked by the given method
    function findInvokedMethods(method) {
        const invokedMethods = new Set();
        const queue = [...graph[method]];
        
        while (queue.length > 0) {
            const currentMethod = queue.shift();
            
            if (!suspicious.has(currentMethod)) {
                invokedMethods.add(currentMethod);
                queue.push(...graph[currentMethod]);
            }
        }
        
        return invokedMethods;
    }
    
    // Iterate through all the methods
    for (let method = 0; method < n; method++) {
        // If the method is suspicious, find all the methods that are invoked by it
        if (suspicious.has(method)) {
            const invokedMethods = findInvokedMethods(method);
            
            // If any method outside the suspicious group is invoked by the current method, remove it
            for (const invokedMethod of invokedMethods) {
                if (!suspicious.has(invokedMethod)) {
                    suspicious.delete(method);
                    break;
                }
            }
        }
    }
    
    // Create an array containing the remaining methods
    const remainingMethods = [];
    for (let method = 0; method < n; method++) {
        if (!suspicious.has(method)) {
            remainingMethods.push(method);
        }
    }
    
    return remainingMethods;    
    
};