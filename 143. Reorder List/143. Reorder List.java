/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        ListNode left = head, right = head, prev;
        while(right != null && right.next != null){
            left = left.next;
            right = right.next.next;
        }
        prev = left;
        left = left.next;
        prev.next = null;
        while(left != null){
            right = left.next;
            left.next = prev;
            prev = left;
            left = right;
        }
        right = head;
        left = prev;
        while(left.next != null){
            prev = right.next;
            right.next = left;
            left = prev;
            right = right.next;
        }
    }
}