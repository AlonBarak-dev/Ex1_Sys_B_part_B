/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Alon Barak>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	/* Add more test here */

    CHECK(nospaces(mat(5, 7, '-', ',')) == nospaces("-----\n-,,,-\n-,-,-\n-,-,-\n-,-,-\n-,,,-\n-----"));

    CHECK(nospaces(mat(3, 3, '3', '1')) == nospaces("333\n313\n333"));

    CHECK(nospaces(mat(1, 11, '+', '$')) == nospaces("+\n+\n+\n+\n+\n+\n+\n+\n+\n+\n+"));

    CHECK(nospaces(mat(5, 3, 'a', 'b')) == nospaces("aaaaa\nabbba\naaaaa"));

    CHECK(nospaces(mat(11, 3, ' ', ' ')) == nospaces("           \n           \n           "));

    CHECK(nospaces(mat(5, 1, '(', '~')) == nospaces("((((("));

    CHECK(nospaces(mat(1, 1, '-', '^')) == nospaces("-"));

    CHECK(nospaces(mat(31, 51, ' ', '-')) == nospaces("                               \n ----------------------------- \n -                           - \n - ------------------------- - \n - -                       - - \n - - --------------------- - - \n - - -                   - - - \n - - - ----------------- - - - \n - - - -               - - - - \n - - - - ------------- - - - - \n - - - - -           - - - - - \n - - - - - --------- - - - - - \n - - - - - -       - - - - - - \n - - - - - - ----- - - - - - - \n - - - - - - -   - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - - - - - - - - - - \n - - - - - - -   - - - - - - - \n - - - - - - ----- - - - - - - \n - - - - - -       - - - - - - \n - - - - - --------- - - - - - \n - - - - -           - - - - - \n - - - - ------------- - - - - \n - - - -               - - - - \n - - - ----------------- - - - \n - - -                   - - - \n - - --------------------- - - \n - -                       - - \n - ------------------------- - \n -                           - \n ----------------------------- \n                               "));

    CHECK(nospaces(mat(5, 5, '/', '/')) == nospaces("/////\n/////\n/////\n/////\n/////"));

    CHECK(nospaces(mat(9, 3, '[', '1')) == nospaces("[[[[[[[[[\n[1111111[\n[[[[[[[[["));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */

    CHECK_THROWS(mat(2, 2 , '-', '-'));

    CHECK_THROWS(mat(0, 0, ' ', ' '));

    CHECK_THROWS(mat(9, 4, '0', '#'));

    CHECK_THROWS(mat(4, 7, '-', '='));

    CHECK_THROWS(mat(10, 0, '*', '*'));

    CHECK_THROWS(mat(50, 25, '2', '2'));

    CHECK_THROWS(mat(7, 6, '!', '%'));

    CHECK_THROWS(mat(3, 8, 'r', 'a'));

    CHECK_THROWS(mat(1, 4, '*', '+'));

    CHECK_THROWS(mat(101, 88, '~', '~'));

    CHECK_THROWS(mat(-9, 9, '9', '9'));

    CHECK_THROWS(mat(4, -1, '$', '$'));

    CHECK_THROWS(mat(-5, -5, ' ', ' '));

    CHECK_THROWS(mat(-3, -1, '3', '1'));
}
