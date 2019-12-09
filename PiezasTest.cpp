/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
protected:
	PiezasTest() {}			   //constructor runs before each test
	virtual ~PiezasTest() {}   //destructor cleans up after tests
	virtual void SetUp() {}	//sets up before each test (after constructor)
	virtual void TearDown() {} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// DropPiece
TEST(PiezasTest, dropPieceOnce)
{
	PiezasTest board;
	ASSERT_EQ(board.dropPiece(1), X);
}

TEST(PiezasTest, dropPieceTwice)
{
	PiezasTest board;
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(2), O);
}

TEST(PiezasTest, dropPieceTwiceOnSameColumn)
{
	PiezasTest board;
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), O);
}

TEST(PiezasTest, dropPiecePositiveOutOfBound)
{
	PiezasTest board;
	ASSERT_EQ(board.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceNegativeOutOfBound)
{
	PiezasTest board;
	ASSERT_EQ(board.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceFull)
{
	PiezasTest board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), Blank);
}