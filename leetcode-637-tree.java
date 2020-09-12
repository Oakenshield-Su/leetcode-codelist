/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 精选题解
 */
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> list = new LinkedList<>();
        list.add(root);
        while (list.size() != 0){
            int len = list.size();
            double sum = 0;
            for (int i = 0; i < len; i++){
                TreeNode node = list.poll();
                sum += node.val;
                if (node.left != null) list.add(node.left);
                if (node.right != null) list.add(node.right);
            }
            res.add(sum/len);
        }
        return res;
    }
}