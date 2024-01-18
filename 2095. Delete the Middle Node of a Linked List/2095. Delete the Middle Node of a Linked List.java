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
    public ListNode deleteMiddle(ListNode head) {
        if(head.next == null)   return null;
        ListNode left = head, right = head, prev = head;
        while(right != null && right.next != null){
            prev = left;
            left = left.next;
            right = right.next.next;
        }
        prev.next = left.next;
        return head;
    }
}