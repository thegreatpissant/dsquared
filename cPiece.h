#ifndef _H_CPIECE_
#include <GL/gl.h>
#include "dSquared.h"
#define _H_CPIECE_
/* TODO:
 *   push should have int board[bh][bw] as a paramater 
 *     to get rid of this extern.
 */

extern int board[bh][bw];
extern void dSolidBlock();

class cPiece {

  int gPiece[ph][pw];
  int gPType;
  int x,y;
 public:
  cPiece() { gPType = 0;x=0;y=0; }
  void selType();
  void setType(int);
  void setPosition(int,int);
  void initPiece();
  void initPosition();
  int  moveDown();
  void moveLeft();
  void moveRight();
  void rotateRight();
  void rotateLeft();
  void show();
  void push();
  int get() {return gPType;}
};


#endif
