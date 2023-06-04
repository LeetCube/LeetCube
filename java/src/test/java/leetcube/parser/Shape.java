package leetcube.parser;

import com.google.gson.reflect.TypeToken;
import leetcube.parser.types.BiFunction;
import leetcube.parser.types.MonoFunction;

import java.lang.reflect.Type;
import java.util.ArrayList;

public enum Shape {
    INTARR_INT_INTARR(
            new TypeToken<ArrayList<BiFunction<int[], Integer, int[]>>>() {
            }.getType()),
    INTARR_INTARR_INTARR(
            new TypeToken<ArrayList<BiFunction<int[], int[], int[]>>>() {
            }.getType()),

    INT_BOOLEAN(
            new TypeToken<ArrayList<MonoFunction<Integer, Boolean>>>() {
            }.getType());

    final Type type;

    Shape(Type type) {

        this.type = type;
    }

    public Type getType() {
        return type;
    }
}
