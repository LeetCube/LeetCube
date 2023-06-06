package leetcube.parser;

import com.google.gson.reflect.TypeToken;
import leetcube.parser.types.BiFunction;
import leetcube.parser.types.MonoFunction;
import leetcube.parser.types.QuadFunction;

import java.lang.reflect.Type;
import java.util.List;

public enum Shape {
    INT1D_INT_INT1D(
            new TypeToken<List<BiFunction<int[], Integer, int[]>>>() {
            }.getType()),
    INT1D_INT1D_INT1D(
            new TypeToken<List<BiFunction<int[], int[], int[]>>>() {
            }.getType()),
    INT1D_INT1D_INT(
            new TypeToken<List<BiFunction<int[], int[], Integer>>>() {
            }.getType()),
    INT_BOOLEAN(
            new TypeToken<List<MonoFunction<Integer, Boolean>>>() {
            }.getType()),

    INT2D_INT_INT_INT_INT2D(
            new TypeToken<List<QuadFunction<int[][], Integer, Integer, Integer, int[][]>>>() {
            }.getType()
    );

    final Type type;

    Shape(Type type) {

        this.type = type;
    }

    public Type getType() {
        return type;
    }
}
