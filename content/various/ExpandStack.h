/**
 * Author: chilli
 * License: CC0
 * Source: Own work
 * Description: Expand the stack size
 * Status: tested on SPOJ INTEST, unit tested
 */

#include <sys/resource.h> /** keep-include */
void expand_stack() {
    rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    rl.rlim_cur = 1024L * 1024L * 256L; // 256MB
    setrlimit(RLIMIT_STACK, &rl);
}