#include "cPiece.h"
#include <cstdlib>

extern void colorPiece(int);
extern void clearLines();
void copyPiece(int to[ph][pw], int from[ph][pw])
/*
  Function: Copy Piece to current piece array.
*/
{
  for(int h=0; h<ph; ++h)
    for(int w=0; w<pw; ++w)
      to[h][w] = from[h][w];
}

bool checkCollision(int shape[ph][pw], const int &x, const int &y)
/*
  Fuction: Check if a collision has occured.
  Return: True or false.
*/
{   

  for(int w=0; w<pw; ++w)
    {
      if(board[ (y+1+shape[1][w]) ][ (x+1+shape[0][w]) ] > 0)
	return true;
    }
  return false;
}

int p1[ph][pw] = {
  { -1,  0,  0,  1 }, /* X cordnents*/
  {  1,  1,  0,  0 }  /* Y cordnents*/
};

int p2[ph][pw] = {
  { -1,  0,  0,  1 },
  {  0,  1,  0,  0 }
};

int p3[ph][pw] = {
  { -1,  0,  0,  1 },
  {  0,  0,  1,  1 }
};
int p4[ph][pw] = {
  { -2, -1,  0,  1 },
  {  0,  0,  0,  0 }
};
int p5[ph][pw] = {
  { -1, -1,  0,  1 },
  { -1,  0,  0,  0 }
};
int p6[ph][pw] = {
  { -1,  0,  1,  1 },
  {  0,  0,  0, -1 }
};
int p7[ph][pw] = {
  {  0,  1,  0,  1 },
  {  1,  1,  0,  0 }
};

void cPiece::setType(int  ntype)
{
  gPType = ntype;
}

void cPiece::setPosition(int  nx, int ny)
{
  x = nx;
  y = ny;
}

void cPiece::initPosition()
{
  switch(gPType)
    {
    case 1:
      x = 4; y = bh-4;
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      x = 5; y = bh-4;
      break;
    }
}


void cPiece::selType()
/*
  Randomly selects a piece.
*/
{
  gPType  = (rand()%7)+1;
}

void cPiece::initPiece()
{
  switch (gPType) {
  case 1: copyPiece(gPiece,p1);
    break;
  case 2: copyPiece(gPiece,p2);
    break;
  case 3: copyPiece(gPiece,p3);
    break;
  case 4: copyPiece(gPiece,p4);
    break;
  case 5: copyPiece(gPiece,p5);
    break;
  case 6: copyPiece(gPiece,p6);
    break;
  case 7: copyPiece(gPiece,p7);
    break;
  }
}


void cPiece::rotateRight()
/*
  Function: Rotate piece aray Right. !!DEFAULT ROTATION!!
  Note: Because we know the array is a fixed 2x4 this is ok to do, to my current knowladge.
*/
{
  for(int i=0; i<pw;++i) {
    if(gPType == 4) {
      if (gPiece[0][i] == -2 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = 2;
      } else if (gPiece[0][i] == 0 && gPiece[1][i] == 2) {
	gPiece[0][i] = 2; gPiece[1][i] = 0;
      } else if (gPiece[0][i] == 2 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = -2;
      } else if (gPiece[0][i] == 0 && gPiece[1][i] == -2) {
	gPiece[0][i] = -2; gPiece[1][i] = 0;
      }
    }
    if(gPType != 7) {
      if (gPiece[0][i] == 0 && gPiece[1][i] == 1) {
	gPiece[0][i] = 1; gPiece[1][i] = 0;
      } else if (gPiece[0][i] == 1 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = -1;
      } else if (gPiece[0][i] == 0 && gPiece[1][i] == -1) {
	gPiece[0][i] = -1; gPiece[1][i] = 0;
      } else if (gPiece[0][i] == -1 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece [1][i]= 1;
      } else if (gPiece[0][i] == -1 && gPiece[1][i] == 1) {
	gPiece[0][i] = 1; gPiece [1][i]= 1;
      } else if (gPiece[0][i] == 1 && gPiece[1][i] == 1) {
	gPiece[0][i] = 1; gPiece[1][i] = -1;
      } else if (gPiece[0][i] == 1 && gPiece[1][i] == -1) {
	gPiece[0][i] = -1; gPiece[1][i] = -1;
      } else if (gPiece[0][i] == -1 && gPiece[1][i] == -1) {
	gPiece[0][i] = -1; gPiece[1][i] = 1;
      }
    } /* if */
  } /* for */
  if(checkCollision(gPiece,x,y))
    rotateLeft();
} /* function */

void cPiece::rotateLeft()
/*
  Function: Rotate the piece left.
  Note: Because we know the array is a fixed 2x4 this is ok to do, to my current knowlage.
*/
{

  for(int i=0; i<pw;++i){
    if(gPType == 4) {
      if (gPiece[0][i] == -2 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = -2;
      } else if (gPiece[0][i] == 0 && gPiece[1][i] == -2) {
	gPiece[0][i] = 2; gPiece[1][i] = 0;
      } else if (gPiece[0][i] == 2 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = 2;
      } else if (gPiece[0][i] == 0 && gPiece[1][i] == 2) {
	gPiece[0][i] = -2; gPiece[1][i] = 0;
      }
    }
    if(gPType != 7) {
      if (gPiece[0][i] == 0 && gPiece[1][i] == 1) {
	gPiece[0][i] = -1; gPiece[1][i] = 0;
      } else if (gPiece[0][i] == -1 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = -1;
      } else if (gPiece[0][i] == 0 && gPiece[1][i] == -1) {
	gPiece[0][i] = 1; gPiece[1][i] = 0;
      } else if (gPiece[0][i] == 1 && gPiece[1][i] == 0) {
	gPiece[0][i] = 0; gPiece[1][i] = 1;
      } else if (gPiece[0][i] == -1 && gPiece[1][i] == 1) {
	gPiece[0][i] = -1; gPiece[1][i] = -1;
      } else if (gPiece[0][i] == -1 && gPiece[1][i] == -1) {
	gPiece[0][i] = 1; gPiece[1][i] = -1;
      } else if (gPiece[0][i] == 1 && gPiece[1][i] == -1) {
	gPiece[0][i] = 1; gPiece[1][i] = 1;
      } else if (gPiece[0][i] == 1 && gPiece[1][i] == 1) {
	gPiece[0][i] = -1; gPiece[1][i] = 1;
      }
    } /* if */
  } /* for */
  if(checkCollision(gPiece,x,y))
    rotateRight();

}


int cPiece::moveDown()
/*
  Function: Move the piece down.
  returns : 1 if there is a collision and board is still playable
  2 if there is no collision
  3 if there is a collision and board is not in playable
*/
{
  y-=1;
  if(checkCollision(gPiece,x,y))
    {
      if( (y+=1) == (bh-4) )
	return 2;
      push();
      clearLines();
      return 1;
    }
  return 3;
}

void cPiece::moveLeft()
/*
  Function: Move Piece left.
*/
{
  x -=1;
  if(checkCollision(gPiece,x,y)) {
    x+=1;
  }
}

void cPiece::moveRight()
/*
  Function: Move the piece right.
*/
{
  x +=1;
  if(checkCollision(gPiece,x,y)) {
    x-=1;
  }
}

void cPiece::show()
/*
  Function display piece onto screen.
*/
{
  glScalef(1.0,1.0,1.0);
  colorPiece(gPType);
  glPushMatrix();
  glTranslatef(x,y,0.0f);
  for(int w=0; w<pw ; ++w) {
    glPushMatrix();
    glTranslatef(gPiece[0][w],gPiece[1][w],0.0f);
    dSolidBlock();
    glPopMatrix();
  }

  glPopMatrix();
}

void cPiece::push()
/*
  Function: Push piece onto board.
*/
{
  for(int w=0; w<pw; ++w)
    board[ (y+1+gPiece[1][w]) ][ (x+1+gPiece[0][w]) ]= gPType;


}

