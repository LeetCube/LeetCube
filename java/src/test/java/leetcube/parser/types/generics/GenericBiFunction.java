package leetcube.parser.types.generics;

public record GenericBiFunction<Input, Output>(
        String contributor,
        Input input,
        Output output
) {

}
