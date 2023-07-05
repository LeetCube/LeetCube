/**
 * Change multi-line string into single line
 * @param {String} s
 * @returns {String}
 */
function singleLine(s) {
	s = s.replace(/\n/g, "");
	console.log(s);
	return s;
}

function getArgsAndBody(s) {
	r = /\(([^)]+)\)/g;
	args = r.exec(s)[1];
	r = /\{([^}]+)\}/g;
	body = r.exec(s)[1].trim();
	answer = JSON.stringify([args, body]);
	console.log(answer);
}

s = "";
s = singleLine(s);
getArgsAndBody(s);
