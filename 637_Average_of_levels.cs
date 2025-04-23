/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public Dictionary<int, (long s, int q)> data = new Dictionary<int,(long s,int q)>();
    public void recursion (TreeNode node, int level) {
        if (node == null) return;
        var val = node.val;
        if (!data.ContainsKey(level)) {
            data[level] = (val, 1);
        }else{
            var old = data[level];
            data[level] = (old.s + val, old.q + 1);
        }
        recursion(node.left, level + 1);
        recursion(node.right, level + 1);
    }
    public IList<double> AverageOfLevels(TreeNode root) {
        recursion(root, 0);
        var ans = new List<double>();
        foreach (var elem in data) {
            ans.Add((double)elem.Value.s / elem.Value.q);
        }
        return ans;
    }
}