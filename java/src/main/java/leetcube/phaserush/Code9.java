package leetcube.phaserush;

public class Code9 {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;

        int xOriginal = x;
        int reverse = 0;
        while (x > 0) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == xOriginal || reverse / 10 == xOriginal;
    }

}
