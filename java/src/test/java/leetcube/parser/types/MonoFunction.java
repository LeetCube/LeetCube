package leetcube.parser.types;

import com.google.gson.annotations.SerializedName;

public record MonoFunction<Arg1, Output>(
        String contributor,
        Input<Arg1> input,
        Output output
) {
    public record Input<Arg1>(
            @SerializedName(value = "x", alternate = {}) Arg1 arg1
    ) {
    }
}
