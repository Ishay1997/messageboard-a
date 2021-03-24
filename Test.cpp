#include "Board.hpp"
#include "doctest.h"
using namespace ariel;
using ariel::Direction;
#include <string>
using namespace std;


ariel::Board board;

TEST_CASE("Horizontal case"){

    board.post(10, 10, Direction::Horizontal,"ishay");
    CHECK(board.read(10, 10, Direction::Horizontal, 5) == string("ishay"));
    CHECK(board.read(10, 9, Direction::Horizontal, 5) == string("_isha"));
    CHECK(board.read(10, 9, Direction::Horizontal, 7) == string("_ishay_"));
    
    board.post(20, 20, Direction::Horizontal,"test ");
    CHECK(board.read(20, 20, Direction::Horizontal, 5) == string("test "));
    CHECK(board.read(20, 20, Direction::Horizontal, 6) == string("test _"));
    CHECK(board.read(20, 19, Direction::Horizontal, 5) == string("_test"));
    CHECK(board.read(20, 19, Direction::Horizontal, 6) == string("_test "));

    board.post(50, 50, Direction::Horizontal,"hello world");
    CHECK(board.read(50, 50, Direction::Horizontal, 11) == string("hello world"));
    CHECK(board.read(50, 50, Direction::Horizontal, 5) == string("hello"));
    CHECK(board.read(50, 56, Direction::Horizontal, 5) == string("world"));
    CHECK(board.read(50, 49, Direction::Horizontal, 13) == string("_hellow world_"));

}
    TEST_CASE("Vertically case") {

    board.post(10, 10, Direction::Vertical,"ishay");
    CHECK(board.read(10, 10, Direction::Vertical, 5) == string("ishay"));
    CHECK(board.read(9, 10, Direction::Vertical, 6) == string("_ishay"));
    CHECK(board.read(9, 10, Direction::Vertical, 7) == string("_ishay_"));
    
    board.post(100, 100, Direction::Vertical,"test");
    CHECK(board.read(100, 100, Direction::Vertical, 5) == string("test_"));
    CHECK(board.read(100, 100, Direction::Vertical, 6) == string("test__"));
    CHECK(board.read(99, 100, Direction::Vertical, 5) == string("_test"));
    CHECK(board.read(99, 100, Direction::Vertical, 6) == string("_test_"));

    board.post(150, 150, Direction::Vertical,"hello world");
    CHECK(board.read(150, 150, Direction::Vertical, 11) == string("hello world"));
    CHECK(board.read(150, 150, Direction::Vertical, 5) == string("hello"));
    CHECK(board.read(156, 150, Direction::Vertical, 5) == string("world"));
    CHECK(board.read(149, 150, Direction::Vertical, 13) == string("_hello world_"));
    }
    TEST_CASE("Empty") {
	CHECK(board.read(200, 200, Direction::Vertical, 3) == "___");
	CHECK(board.read(200, 230, Direction::Horizontal, 3) == "___");
}

