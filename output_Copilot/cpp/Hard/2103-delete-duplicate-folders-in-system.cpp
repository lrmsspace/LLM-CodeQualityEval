/**https://leetcode.com/problems/delete-duplicate-folders-in-system/ */
//Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
//	For example, ["one", "two", "three"] represents the path "/one/two/three".
//Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
//	For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
//	
//		/a
//		/a/x
//		/a/x/y
//		/a/z
//		/b
//		/b/x
//		/b/x/y
//		/b/z
//	
//	
//	However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
//Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
//Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.
// 
//Example 1:
//Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
//Output: [["d"],["d","a"]]
//Explanation: The file structure is as shown.
//Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
//folder named "b".
//Example 2:
//Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
//Output: [["c"],["c","b"],["a"],["a","b"]]
//Explanation: The file structure is as shown. 
//Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because they both contain an empty folder named "y".
//Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted because they were not marked beforehand.
//Example 3:
//Input: paths = [["a","b"],["c","d"],["c"],["a"]]
//Output: [["c"],["c","d"],["a"],["a","b"]]
//Explanation: All folders are unique in the file system.
//Note that the returned array can be in a different order as the order does not matter.
// 
//Constraints:
//	1 <= paths.length <= 2 * 104
//	1 <= paths[i].length <= 500
//	1 <= paths[i][j].length <= 10
//	1 <= sum(paths[i][j].length) <= 2 * 105
//	path[i][j] consists of lowercase English letters.
//	No two paths lead to the same folder.
//	For any folder not at the root level, its parent folder will also be in the input.
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
            struct TrieNode {
                unordered_map<string, TrieNode*> children;
                string hash;
                bool toDelete = false;
            };

            TrieNode* buildTrie(const vector<vector<string>>& paths) {
                TrieNode* root = new TrieNode();
                for (const auto& path : paths) {
                    TrieNode* node = root;
                    for (const auto& folder : path) {
                        if (!node->children.count(folder)) {
                            node->children[folder] = new TrieNode();
                        }
                        node = node->children[folder];
                    }
                }
                return root;
            }

            string serialize(TrieNode* node, unordered_map<string, vector<TrieNode*>>& hashMap) {
                string serialized;
                for (auto& [folder, child] : node->children) {
                    serialized += "(" + folder + serialize(child, hashMap) + ")";
                }
                node->hash = serialized;
                hashMap[serialized].push_back(node);
                return serialized;
            }

            void markForDeletion(TrieNode* node) {
                for (auto& [folder, child] : node->children) {
                    if (child->toDelete) {
                        delete child;
                    } else {
                        markForDeletion(child);
                    }
                }
            }

            void collectPaths(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
                if (node->toDelete) return;
                if (!currentPath.empty()) result.push_back(currentPath);
                for (auto& [folder, child] : node->children) {
                    currentPath.push_back(folder);
                    collectPaths(child, currentPath, result);
                    currentPath.pop_back();
                }
            }   

            vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
                TrieNode* root = buildTrie(paths);
                unordered_map<string, vector<TrieNode*>> hashMap;
                serialize(root, hashMap);

                for (auto& [hash, nodes] : hashMap) {
                    if (nodes.size() > 1) {
                        for (auto* node : nodes) {
                            node->toDelete = true;
                        }
                    }
                }

                markForDeletion(root);

                vector<vector<string>> result;
                vector<string> currentPath;
                collectPaths(root, currentPath, result);

                return result;
            }
    }
};