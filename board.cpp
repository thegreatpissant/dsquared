#include "board.h"
#include "dSquared.h"
extern int board[bh][bw];
extern int Level_lines, CurLevel, TotalScore;
extern void dSolidBlock();

void initBoard()
/*
  Function: Initialize board to empty.
*/
{
  for(int h=0; h < bh; ++h) {
    for(int w=0; w < bw; ++w) {
      board[h][w] = 1;
    }
  }
  for(int h=1; h < bh; ++h) {
    for(int w=1; w<(bw-1); ++w) {
      board[h][w] = 0;
    }
  }
	
}

void clearLines() {
  /*
    Function: Find lines that have been filled in board array.
    Clear the lines.
    add user score up.
  */
  bool lines[bh-2] = {false};
  bool full = true;
  bool goahead = false;
  int NumLines = 0;

  //  Find lines that are full.
  for(int h=1; h<bh-1; ++h) {
    full = true;
    for(int w=1; w<bw-1; ++w) {
      if (!board[h][w]) {
	full = false;
	w=bw;
      }
    }
    if(full) {
      lines[h-1] = true;
      ++NumLines;
      goahead = true;
    }
  }

  if(goahead) {
    //  Clear lines that are full.
    for(int h=0; h<bh; ++h)
      {
	if(lines[h])
	  {
	    for(int w=1; w<bw-1; ++w)
	      {
		board[h+1][w] = 0;
	      }
	  }
      }
    //  HighLite and Pause the Display

    //  Move the board down after lines are deleted.
    for(int h=bh-2; h>=0; --h)
      {
	if(lines[h])
	  {
	    for(int hz=h; hz<bh-1; ++hz)
	      {
		for(int w=1; w<bw-1; ++w)
		  {
		    board[hz+1][w]=board[hz+2][w];
		  }
	      }
	  } /* if(lines[h]) */
      }
    //  Add up the score.
    Level_lines += NumLines;
    TotalScore += NumLines * (CurLevel+1) * 10;
    if(Level_lines >= 10)	{
      ++CurLevel;
      Level_lines = 0;
      if(CurLevel == 11)
	CurLevel = 10;
      setLevel_delay();	// For Piece Movement.
    }


  }/* if(goahead) */

}
void drawBoard()
/*
  Function: Draw board.
  Version # 1 from main.cpp
*/
{
  // Outline of board.
  float dbh = bh - 2.0f - 0.4f;
  float dbw = bw - 2.0f - 0.4f -.0375f;
  float org = -0.6f + 0.0375f;

  glBegin(GL_LINES);
  glPushMatrix();
  colorPiece(0);
  glVertex2f(org,org); glVertex2f(org,dbh);
  glVertex2f(org,dbh); glVertex2f(dbw,dbh);
  glVertex2f(dbw,dbh); glVertex2f(dbw,org);
  glVertex2f(dbw,org); glVertex2f(org,org);
  glPopMatrix();
  glEnd();

  //  Pieces on the board.
  for(int h=1; h<bh-1; ++h)
    for(int w=1; w<bw-1; ++w)
      {
	if(board[h][w])
	  {
	    glPushMatrix();
	    glTranslatef(w-1.0f,h-1.0f,0.0f);
	    colorPiece(board[h][w]);
	    dSolidBlock();
	    glPopMatrix();
	  }
      }
}


