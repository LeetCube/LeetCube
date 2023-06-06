package leetcube.aaryan_rampal;

import structure.ListNode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Code817 {
    public int numComponents(ListNode head, int[] nums) {
        int length = nums.length;

        Map<Integer, Integer> coords = new HashMap<>();
        for (ListNode i = head; i != null; i = i.next) {
            if (i.next != null) {
                coords.put(i.val, i.next.val);
            } else {
                coords.put(i.val, null);
            }
        }

        Set<Integer> setNums = new HashSet<>();
        for (int i = 0; i < length; i++) {
            setNums.add(nums[i]);
        }

        for (int i = 0; i < nums.length; i++) {
            Integer iNext = coords.get(nums[i]);
            if (setNums.contains(iNext) && iNext != null) {
                length--;
            }
        }

        return length;

    }
}
