/**
 * Author: chilli
 * License: CC0
 * Source: Own work
 * Description: Read until an end of file.
 * Status: tested on SPOJ INTEST, unit tested
 */

#include <sstream> /** keep-include */
// Recordar cin.ignore() antes de getline()
string line;
while (getline(cin, line)) {
    istringstream is(line);
    int x;
    while (is >> x) {
        // procesar x
    }
}