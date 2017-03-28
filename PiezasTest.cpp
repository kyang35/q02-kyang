/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
};

TEST(PiezasTest, BOARD_ROWS){
	ASSERT_EQ(3, BOARD_ROWS);
};

TEST(PiezasTest, BOARD_COLS){
	ASSERT_EQ(4, BOARD_COLS);
};
/*
TEST(PiezasTest, dropPiece){
	Piezas board;
	ASSERT_EQ(board.dropPiece(2), -1);

};

TEST(PiezasTest, pieceAt){
	Piezas Board;
	int column = 2;
	Board.dropPiece(column);
	ASSERT_EQ(Board.pieceAt(0,2), Blank);
};
*/ 
