package leetcube.phaserush;

import java.util.HashMap;
import java.util.Map;

public final class Code1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            int currTarget = target - curr;
            if (seen.containsKey(currTarget)) {
                return new int[]{i, seen.get(currTarget)};
            }
            seen.put(curr, i);
        }
        return null;
    }
}