package leetcube.questions;

import com.google.gson.Gson;
import leetcube.parser.Shape;
import leetcube.parser.types.BiFunction;
import leetcube.parser.types.MonoFunction;
import leetcube.phaserush.Code1;
import leetcube.phaserush.Code2;
import leetcube.phaserush.Code9;
import org.testng.annotations.Test;
import structure.ListNode;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.assertThat;

public class TestBase {

    private static final Gson gson = new Gson();
    private static final Map<Integer, Shape> jsonShapes = Map.of(
            1, Shape.INTARR_INT_INTARR,
            2, Shape.INTARR_INTARR_INTARR,
            9, Shape.INT_BOOLEAN
    );

    private <T> T loadJson(final int testNumber) {
        final String json;
        try {
            json = String.join("", Files.readAllLines(
                    Paths.get("../data/testcases/test_" + testNumber + ".json")));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        return gson.fromJson(json, jsonShapes.get(testNumber).getType());
    }

    @Test
    public void test1_twoSum_phaserush() {
        final List<BiFunction<int[], Integer, int[]>> testCases = loadJson(1);

        final Code1 sut = new Code1();
        testCases.forEach(test -> {
            final var output = sut.twoSum(test.input().arg1(), test.input().arg2());
            assertThat(output).containsExactlyInAnyOrder(test.output());
        });
    }


    @Test
    public void test2_addTwoNumbers_phaserush() {
        final List<BiFunction<int[], int[], int[]>> testCases = loadJson(2);

        final Code2 sut = new Code2();
        testCases.forEach(test -> {
            final var list1 = ListNode.fromArray(test.input().arg1());
            final var list2 = ListNode.fromArray(test.input().arg2());
            final var answer = ListNode.fromArray(test.output());

            final var output = sut.addTwoNumbers(list1, list2);

            assertThat(output).isEqualTo(answer);
        });
    }

    @Test
    public void test9_isPallindrome_phaserush() {
        final List<MonoFunction<Integer, Boolean>> testCases = loadJson(9);

        final Code9 sut = new Code9();
        testCases.forEach(test -> {
            final var output = sut.isPalindrome(test.input().arg1());
            assertThat(output).isEqualTo(test.output().booleanValue());
        });
    }

}
