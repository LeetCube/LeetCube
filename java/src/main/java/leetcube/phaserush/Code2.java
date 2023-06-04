package leetcube.phaserush;

import structure.ListNode;

public final class Code2 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        var res = new ListNode();
        var head = res;

        while (l1 != null || l2 != null) {
            var curr1 = l1 != null ? l1.val : 0;
            var curr2 = l2 != null ? l2.val : 0;
            var sum = curr1 + curr2 + carry;
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.next = new ListNode(sum);
            res = res.next;
            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
        }

        if (carry != 0) {
            res.next = new ListNode(1);
        }

        return head.next;
    }
}
