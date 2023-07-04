function equalPairs(grid: number[][]): number {
    let n = grid.length;
    let gridTranspose: number[][] = [];

    // Create another grid where each array element represents a column.
    for (let i = 0; i < n; i++) {
        let column: number[] = [];

        for (let j = 0; j < n; j++) {
            column.push(grid[j][i]);
        }

        gridTranspose.push(column);
    }

    let totalPairs = 0;

    for (let row of grid) {
        for (let column of gridTranspose) {
            for (let i = 0; i < n; i++) {
                if (row[i] !== column[i]) {
                    break;
                }

                if (i === n - 1) {
                    totalPairs++;
                }
            }
        }
    }

    return totalPairs;
}
