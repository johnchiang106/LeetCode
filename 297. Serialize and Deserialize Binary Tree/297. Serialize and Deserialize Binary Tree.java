public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String ans = "";
        if(root == null)    return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        ans += Integer.toString(root.val);
        while(!q.isEmpty()){
            String str = "";
            int level = q.size();
            int count = 0;
            for(int i = 0; i < level; ++i){
                TreeNode curr = q.poll();
                if(curr.left != null){
                    q.offer(curr.left);
                    str += "," + Integer.toString(curr.left.val);
                }
                else{
                    str += ",null";
                    ++count;
                }
                if(curr.right != null){
                    q.offer(curr.right);
                    str += "," + Integer.toString(curr.right.val);
                }
                else{
                    str += ",null";
                    ++count;
                }
            }
            if(count != 2*level){
                ans += str;
            }
        }
        // System.out.println(ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data == "")  return null;
        String[] arr = data.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(arr[0]));
        Queue<TreeNode> q = new LinkedList<>();

        q.offer(root);
        int i = 0;
        while(!q.isEmpty() && i < arr.length-1){
            TreeNode curr = q.poll();
            if(!arr[++i].equals("null")){
                TreeNode left = new TreeNode(Integer.valueOf(arr[i]));
                curr.left = left;
                q.offer(left);
            }
            if(!arr[++i].equals("null")){
                TreeNode right = new TreeNode(Integer.valueOf(arr[i]));
                curr.right = right;
                q.offer(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));