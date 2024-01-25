class Solution {
    private int maxSum = -1000;
    public int maxPathSum(TreeNode root) {
        return Math.max(subMax(root), maxSum);
    }
    public int subMax(TreeNode curr){
        int leftMax = -1000, rightMax = -1000;
        if(curr.left != null){
            leftMax = subMax(curr.left);
        }
        if(curr.right != null){
            rightMax = subMax(curr.right);
        }
        // int result1 = Stream.of(0, leftMax, rightMax).max(Integer::compare).orElse(0);
        // maxSum = Stream.of(maxSum, curr.val + result1, curr.val + leftMax + rightMax).max(Integer::compare).orElse(0);
        int result1 = Math.max(0, leftMax);
        result1 = Math.max(result1, rightMax);
        maxSum = Math.max(maxSum, curr.val + result1);
        maxSum = Math.max(maxSum, curr.val + leftMax + rightMax);
        return curr.val + result1;
    }
}