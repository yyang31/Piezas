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

// dropPiece
TEST(PiezasTest, dropPieceOnce)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(1), X);
}

TEST(PiezasTest, dropPieceTwice)
{
	Piezas board;
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(2), O);
}

TEST(PiezasTest, dropPieceTwiceOnSameColumn)
{
	Piezas board;
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), O);
}

TEST(PiezasTest, dropPiecePositiveOutOfBound)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceNegativeOutOfBound)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceFull)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), Blank);
}

// pieceAt
TEST(PiezasTest, pieceAtOutOfBound)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(-1, 5), Invalid);
}

TEST(PiezasTest, pieceAtNegativeOutOfBound)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(-1, -3), Invalid);
}

TEST(PiezasTest, pieceAtPositiveOutOfBound)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(4, 5), Invalid);
}

TEST(PiezasTest, pieceAtEmpty)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(2, 1), Blank);
}

TEST(PiezasTest, pieceAtEmptyWithOneDropped)
{
	Piezas board;
	board.dropPiece(1);
	ASSERT_EQ(board.pieceAt(2, 1), Blank);
}

TEST(PiezasTest, pieceAtOneOne)
{
	Piezas board;
	board.dropPiece(1);
	ASSERT_EQ(board.pieceAt(0, 1), X);
}

TEST(PiezasTest, pieceAtTwoTwo)
{
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(2);
	ASSERT_EQ(board.pieceAt(0, 2), O);
}

TEST(PiezasTest, pieceAtColumnTwo)
{
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_EQ(board.pieceAt(1, 2), O);
}

// gameState
TEST(PiezasTest, gameStateEmptyBoard)
{
	Piezas board;
	ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest, gameStatePartialyEmptyBoard)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest, gameStateRowXWon)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);
	ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, gameStateXColumnWon)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, gameStateOColumnWon)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_EQ(board.gameState(), O);
}

TEST(PiezasTest, gameStateNoWinner)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	ASSERT_EQ(board.gameState(), Blank);
}

// reset
TEST(PiezasTest, gameStateResetOnEmptyBoard)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, gameStateResetOnPartiallyFullBoard)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.reset();
	ASSERT_EQ(board.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, gameStateResetOnFullBoard)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);
	board.reset();
	ASSERT_EQ(board.pieceAt(0, 0), Blank);
}