#ifndef _BOARD_H_
/*
    board.h
    Contains:
        DrawBoard function.
*/

#include <GL/gl.h>

#define _BOARD_H_ 

/*
extern const int bh;
extern const int bw;
extern int board[][];
*/
extern void colorPiece(int);
extern void setLevel_delay();
void drawBoard();
void initBoard();
void clearLines() ;

/*
void drawBoard()
	//Function: Draw board.
	//version #2 in this file.
{
  glPushMatrix();
    glTranslatef(-18.0,-12.0,0.0);
    // Outline of board.
    float dbh = bh - 2 - 0.4;
    float dbw = bw - 2 - 0.4 -.0375;
    float org = -0.6 + 0.0375;

    glBegin(GL_LINES);
        glPushMatrix();
            colorBoard();
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
                    glTranslatef(w-1,h-1,0.0);
                    colorPiece(board[h][w]);
                    dSolidBlock();
                glPopMatrix();
            }
        }
  glPopMatrix();
}
*/

#endif 
