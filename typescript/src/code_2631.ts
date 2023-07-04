declare global {
	interface Array<T> {
		groupBy(fn: (item: T) => string): Record<string, T[]>;
	}
}

Array.prototype.groupBy = function (fn) {
	const dict: any = {};
	for (const item of this) {
		const key = fn(item);
		key in dict ? dict[key].push(item) : (dict[key] = [item]);
	}

	return dict;
};

const f = (array: any, fn: any) => array.groupBy(fn);

export { f };
