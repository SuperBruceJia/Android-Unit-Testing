#ifndef HW3_PROBLEM2_H
#define HW3_PROBLEM2_H
#include <stdbool.h>

struct ReverseResult {
    bool success;
    char** reversedStrings;
};

/**
 * Reverses all of the input strings as long as they have an odd number of
 * characters.  If they are all odd, the resulting struct should have
 * success=true and reversedStrings pointing at the resuling array of C-style
 * strings.
 *
 * If any of the strings have an even number of characters, the resulting
 * struct should have success=false and reversedStrings=NULL.
 *
 * NOTE: since we are using C (and not C++) for this assignment, the struct
 * keyword is required when referencing the ReverseResult struct.
 *
 * @param inputStrings an array of input strings of lenfth inputStringsLength
 * @param inputStringsLength number of input strings
 * @return success=true plus reversed strings as long as all srings have an
 * odd number of characters, and
 * success=false plus NULL if any of the strings have an even number of
 * characters.
 */
struct ReverseResult reverseOdd(const char** inputStrings, int inputStringsLength);

#endif //HW3_PROBLEM2_H
