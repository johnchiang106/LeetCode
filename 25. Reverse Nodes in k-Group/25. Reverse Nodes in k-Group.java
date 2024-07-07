class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode newHead = head, last = head, temp, prev = null, ans;
        int count = 0;
        while(newHead != null){
            newHead = newHead.next;
            ++count;
        }
        for(int j = 0; j < k; ++j){
            temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        ans = prev;
        for(int i = count/k; i > 1; --i){
            newHead = head;
            for(int j = 0; j < k; ++j){
                temp = head.next;
                head.next = prev;
                prev = head;
                head = temp;
            }
            last.next = prev;
            last = newHead;
        }
        last.next = head;
        return ans;
    }
}