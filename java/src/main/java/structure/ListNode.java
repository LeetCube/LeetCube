package structure;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {
    }

    public ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }


    public static ListNode fromList(List<Integer> list) {
        if (list.isEmpty()) return null;
        if (list.size() == 1) return new ListNode(list.get(0));
        var head = new ListNode(list.get(0));
        var curr = head;
        for (int i = 1; i < list.size(); i++) {
            curr.next = new ListNode(list.get(i));
            curr = curr.next;
        }
        return head;
    }

    public static ListNode fromArray(int[] arr) {
        if (arr == null || arr.length == 0) return null;
        var head = new ListNode(arr[0]);
        var curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new ListNode(arr[i]);
            curr = curr.next;
        }
        return head;
    }

    public static int[] toArray(ListNode listNode) {
        if (listNode == null) {
            return new int[0];
        }

        List<Integer> list = new ArrayList<>();
        while (listNode != null) {
            list.add(listNode.val);
            listNode = listNode.next;
        }

        return list.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListNode listNode = (ListNode) o;
        return val == listNode.val && Objects.equals(next, listNode.next);
    }

    @Override
    public int hashCode() {
        return Objects.hash(val, next);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        sb.append("ListNode=[");
        var curr = this;
        while (curr != null) {
            sb.append(" ");
            sb.append(curr.val);
            sb.append(",");
            curr = curr.next;
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append(" ]");
        return sb.toString();
    }
}