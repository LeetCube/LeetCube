/**
 * Change multi-line string into single line
 * @param {String} s
 * @returns {String}
 */
function singleLine(s) {
	s = s.replace(/\n/g, "");

	console.log(s);
}

// put string inside backticks
s = ``;
singleLine(s);
