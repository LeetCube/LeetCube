/**
 * @param {number} millis
 */
// Promise resolves after timeout
async function sleep(millis) {
    return new Promise((resolve) => setTimeout(resolve, millis));
}

module.exports = { sleep };
