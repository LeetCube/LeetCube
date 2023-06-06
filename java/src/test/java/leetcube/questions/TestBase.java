package leetcube.questions;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import leetcube.aaryan_rampal.Code733;
import leetcube.aaryan_rampal.Code817;
import leetcube.parser.Shape;
import leetcube.parser.types.BiFunction;
import leetcube.parser.types.MonoFunction;
import leetcube.parser.types.QuadFunction;
import leetcube.parser.types.generics.GenericBiFunction;
import leetcube.phaserush.Code1;
import leetcube.phaserush.Code2;
import leetcube.phaserush.Code9;
import org.testng.annotations.Test;
import structure.ListNode;

import java.io.IOException;
import java.lang.reflect.Type;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.assertThat;

public class TestBase {

    private static final Gson gson = new Gson();
    private static final Map<Integer, Shape> jsonShapes = Map.of(
            1, Shape.INT1D_INT_INT1D,
            2, Shape.INT1D_INT1D_INT1D,
            9, Shape.INT_BOOLEAN,
            733, Shape.INT2D_INT_INT_INT_INT2D
    );


    private String readJson(final int testNumber) {
        final String json;
        try {
            json = String.join("", Files.readAllLines(
                    Paths.get("../data/testcases/test_" + testNumber + ".json")));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return json;
    }

    private <T> T loadJson(final int testNumber) {
        return loadJson(testNumber, jsonShapes.get(testNumber).getType());
    }

    private <T> T loadJson(final int testNumber, final Type customType) {
        final String json = readJson(testNumber);
        return gson.fromJson(json, customType);
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

    @Test
    public void test733_floodFill_aaryan_rampal() {
        final List<QuadFunction<int[][], Integer, Integer, Integer, int[][]>> testCases = loadJson(733);

        final Code733 sut = new Code733();
        testCases.forEach(test -> {
            final var i = test.input();
            final var output = sut.floodFill(i.arg1(), i.arg2(), i.arg3(), i.arg4());

            assertThat(output).isDeepEqualTo(test.output());
        });
    }

    @Test
    public void test817_linkedListComponents_aaryan_rampal() {
        record Input(int[] head, int[] nums) {
        }

        final Type customType = new TypeToken<List<GenericBiFunction<Input, Integer>>>() {
        }.getType();


        final List<GenericBiFunction<Input, Integer>> testCases = loadJson(817, customType);

        final Code817 sut = new Code817();
        testCases.forEach(test -> {
            final var head = ListNode.fromArray(test.input().head());

            final var output = sut.numComponents(head, test.input().nums());

            assertThat(output).isEqualTo(test.output());
        });
    }

}
