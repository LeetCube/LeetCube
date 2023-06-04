/**
 * @return {Function}
 */
// Arrow syntax
var createHelloWorld = function () {
  return () => "Hello World";
};
// Function syntax
// var createHelloWorld = function () {
//   return function () {
//     return "Hello World";
//   };
// };

module.exports = { createHelloWorld };
