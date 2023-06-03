declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function(fn) {
    const dict = {};
    for (const i in self) {
        const key = fn(i)
        if (dict[key] === undefined) {
            dict[key] = [i]
        } else {
            dict[key].append(i)
        }
    }

    return dict
}