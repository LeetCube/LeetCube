package leetcube.aaryan_rampal;

class Code733 {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int newColor = image[sr][sc];
        if (color != newColor) floodFillHelper(image, sr, sc, color, newColor);
        return image;
    }

    public int[][] floodFillHelper(int[][] image, int sr, int sc, int color, int currentColor) {
        if (image[sr][sc] == currentColor) {
            image[sr][sc] = color;

            if (sr - 1 >= 0) floodFillHelper(image, sr - 1, sc, color, currentColor);
            if (sc - 1 >= 0) floodFillHelper(image, sr, sc - 1, color, currentColor);
            if (sr + 1 < image.length) floodFillHelper(image, sr + 1, sc, color, currentColor);
            if (sc + 1 < image[0].length) floodFillHelper(image, sr, sc + 1, color, currentColor);
        }
        return image;
    }

}