/**https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ */
//There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
//Return a sorted list of the items such that:
//	The items that belong to the same group are next to each other in the sorted list.
//	There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
//Return any solution if there is more than one solution and return an empty list if there is no solution.
// 
//Example 1:
//Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
//Output: [6,3,4,1,5,2,0,7]
//Example 2:
//Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
//Output: []
//Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
// 
//Constraints:
//	1 <= m <= n <= 3 * 104
//	group.length == beforeItems.length == n
//	-1 <= group[i] <= m - 1
//	0 <= beforeItems[i].length <= n - 1
//	0 <= beforeItems[i][j] <= n - 1
//	i != beforeItems[i][j]
//	beforeItems[i] does not contain duplicates elements.
class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        // Assign each item to a group if it doesn't belong to one
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        // Create adjacency lists and in-degree arrays for items and groups
        List<List<Integer>> itemGraph = new ArrayList<>();
        List<List<Integer>> groupGraph = new ArrayList<>();
        int[] itemIndegree = new int[n];
        int[] groupIndegree = new int[m];
        
        for (int i = 0; i < n; i++) {
            itemGraph.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            groupGraph.add(new ArrayList<>());
        }

        // Build graphs
        for (int i = 0; i < n; i++) {
            int currentGroup = group[i];
            for (int beforeItem : beforeItems.get(i)) {
                itemGraph.get(beforeItem).add(i);
                itemIndegree[i]++;
                int beforeGroup = group[beforeItem];
                if (beforeGroup != currentGroup) {
                    groupGraph.get(beforeGroup).add(currentGroup);
                    groupIndegree[currentGroup]++;
                }
            }
        }

        // Perform topological sort on groups
        List<Integer> groupOrder = topologicalSort(groupGraph, groupIndegree);
        if (groupOrder.isEmpty()) {
            return new int[0];
        }

        // Perform topological sort on items within each group
        List<Integer> result = new ArrayList<>();
        for (int g : groupOrder) {
            List<Integer> itemsInGroup = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (group[i] == g) {
                    itemsInGroup.add(i);
                }
            }
            List<Integer> itemOrder = topologicalSort(itemGraph, itemIndegree, itemsInGroup);
            if (itemOrder.isEmpty()) {
                return new int[0];
            }
            result.addAll(itemOrder);
        }

        // Convert result to array
        return result.stream().mapToInt(i -> i).toArray();
    }

    private List<Integer> topologicalSort(List<List<Integer>> graph, int[] indegree) {
        List<Integer> order = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
            }
        }
        
        while (!queue.isEmpty()) {
            int node = queue.poll();
            order.add(node);
            for (int neighbor : graph.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        if (order.size() == indegree.length) {
            return order;
        }
        return new ArrayList<>();  // not a DAG
    }

    private List<Integer> topologicalSort(List<List<Integer>> graph, int[] indegree, List<Integer> nodes) {
        List<Integer> order = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        
        for (int node : nodes) {
            if (indegree[node] == 0) {
                queue.add(node);
            }
        }
        
        while (!queue.isEmpty()) {
            int node = queue.poll();
            order.add(node);
            for (int neighbor : graph.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        if (order.size() == nodes.size()) {
            return order;
        }
        return new ArrayList<>();  // not a DAG
    }
        
}