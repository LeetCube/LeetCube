package leetcube.parser.types;

import com.google.gson.annotations.SerializedName;

public record BiFunction<Arg1, Arg2, Output>(
        String contributor,

        Input<Arg1, Arg2> input,

        Output output
) {

    public record Input<Arg1, Arg2>(
            @SerializedName(value = "nums", alternate = {"l1"}) Arg1 arg1,
            @SerializedName(value = "target", alternate = {"l2"}) Arg2 arg2) {
    }
}
