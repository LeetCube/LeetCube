/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function (fn) {
	const dict = {};
	for (const item of this) {
		const key = fn(item);
		key in dict ? dict[key].push(item) : (dict[key] = [item]);
	}

	return dict;
};

f = (array, fn) => array.groupBy(fn);

module.exports = { f };
