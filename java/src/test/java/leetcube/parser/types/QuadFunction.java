package leetcube.parser.types;

import com.google.gson.annotations.SerializedName;

public record QuadFunction<Arg1, Arg2, Arg3, Arg4, Output>(
        String contributor,

        Input<Arg1, Arg2, Arg3, Arg4> input,

        Output output
) {

    public record Input<Arg1, Arg2, Arg3, Arg4>(
            @SerializedName(value = "image", alternate = {}) Arg1 arg1,
            @SerializedName(value = "sr", alternate = {}) Arg2 arg2,
            @SerializedName(value = "sc", alternate = {}) Arg3 arg3,
            @SerializedName(value = "color", alternate = {}) Arg4 arg4) {
    }
}