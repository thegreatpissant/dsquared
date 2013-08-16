/*
  James A. Feister		OpenJAF@gmail.com
  D^2 : a *etris clone.
  Notes: First attempt at programing a real game besides tictactoe.
  Will have a sequal D^3 - guess what that will be?
*/

/*
  Includes
*/

#include <GL/gl.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/glut.h>

#include <cstdlib>
#include <cstdio>

#include "cTimer.h"
#include "setColors.h"
#include "board.h"
#include "cPiece.h"
#include "charset.h"
#include "menu.h"

#include "dSquared.h"


cPiece token;				// Current piece in play.
cPiece next_token;			// Piece that shows as next to the player.
int GWH = 480;				// board width and height are the same?
char PGame[]	= "N - NEW GAME ";	       
char VScores[]	= "S - SCORES";
char RResume[]  = "R - RESUME GAME";
char NNew[]     = "N - NEW GAME";
char EQuit[]	= "HIT ESCAPE TO QUIT ";
char Gtitle[]	= "DSQUARED";
char Etitle[]	= "TOP SCORES";
char Sscore[]	= "SCORE";
char Slevel[]	= "LEVEL";
char Snpiece[]	= "NEXT";
char Sgover[]	= "GAME OVER";		
char sHitEscape[] = "HIT ESCAPE TO RETURN";
char sPoints[]  = "POINTS";
char sLevel[]   = "LEVEL";
char Level[16]; 			//  String to print changin level number for display.
char Score[16];				//  String to print changing score for display.
char TopLevel[16];			//  String to print current top score selection.
char TopScore[16];			//  String to print current top level selection.
int CurLevel = 0;			//  Current Level
int TotalScore = 0;			//  Total Player Score.
int Level_lines = 0;			//  Current number of lines cleared in this level.
bool paused = false;			//  Was game paused.
int  all_scores[5][2]; 			//  Top Five scores. and their associated levels.

// Game State //
int gmState = 0;			// 0:MENU SCREEN    
					// 1:PLAYING GAME  
					// 2: End Game Screen.

void init_game();			//  Reset Game.
void init_menu();			//  Initialize the menu call glut functions
void init_end();			//  Initialize the end screen call glut functions.

void PlayGameDisplay();			//  Function that draws the gameplay.
void MainMenuDisplay();			//  Function that draws the Main Menu.
void ViewEndDisplay();			//  Function that draws the End game
void resume_game();			//  Without reseting the game state play.

int board[bh][bw];			//  The actual board.

void dSolidBlock() {			//  How to draw a single solig block.
  glBegin(GL_QUADS);
  glVertex2f(-0.5f,-0.5f);
  glVertex2f(-0.5f,0.5f);
  glVertex2f(0.5f,0.5f);
  glVertex2f(0.5f,-0.5);
  glEnd();
}
/*
 * Scores operations.
 */
void clear_scores()
{
  for( int i = 0; i < 5; ++i )
    {
      all_scores[i][0] = all_scores[i][1] = 0;
    }
}
void add_score()
{
  int i = 0;
  do{
    if (TotalScore > all_scores[i][0])
      {
	for(int index = 4; index > i; index--)	{
	  all_scores[index][0] = all_scores[index-1][0];
	  all_scores[index][1] = all_scores[index-1][1];
	}
	all_scores[i][0] = TotalScore;
	all_scores[i][1] = CurLevel;
	i = 5;
      }
    i++;
  } while (i < 5);
	
}
/*
 * 	Mouse Events.
 * 	included for the hell of it.
 */
void mouse( int button, int state, int x, int y)
{
  switch (button) {
  default:
    break;
  }
}

/*
 * Keyboard Events.
 */
void move_token_down()
/*
 * This functioncall was created because we have the computer moving
 * the piece in the background.  So to avoid redundency
 */
{
  int state = token.moveDown();
  /*      
	  1: Piece is no longer in play get new piece and board is still in play 
	  2: Piece did not move and board is full.
	  3: Piece Moved down.
  */
  if(state == 1) {
    //  Token was pushed into board.
    //  Switch next_token to piece in play.
    token.setType(next_token.get());
    //  initialize the position of the new piece.
    token.initPiece();
    token.initPosition();
    //  Grab a new next token and initialize.
    next_token.selType();
    next_token.initPiece();
  } else if (state == 2)
    //  Full board, end game, show scores.
    {
      gmState = 2;
      add_score();
      glutDisplayFunc(ViewEndDisplay);
      init_end();
    }
}


void keyboard_special (int key, int x, int y)
/*
 * Handles all special key events.
 */
{
  switch(gmState) {
  case 1 : //  Playing the Game.
    switch(key) {
    case GLUT_KEY_DOWN :
      move_token_down();	
      break;
    case GLUT_KEY_UP :
      token.rotateRight();
      break;
      /*       What is the default movement for simplicity sake.
	       case GLUT_KEY_LEFT :
	       token.rotateLeft();
	       break;							*/
    case GLUT_KEY_RIGHT :
      token.moveRight();
      break;
    case GLUT_KEY_LEFT :
      token.moveLeft();
      break;
    }
    break;
  case 0 : // Main Menu
    break;
  case 2 : // Game End screen. 
    break;
  }		
}
void keyboard_char (unsigned char key, int x, int y)
/*
 * Handles all Character key events.
 */
{
  switch(gmState) {
  case 0 : //  GAME_STATE = Main Menu
    switch(key) {
    case 'r':  // Resume Game.
    case 'R':
      gmState = 1;
      glutDisplayFunc(PlayGameDisplay);
      resume_game();
      paused = false;
      break;
    case 'n':  // Play Game.
    case 'N':
      gmState = 1;
      glutDisplayFunc(PlayGameDisplay);
      init_game();
      paused = false;
      break;
    case 's':
    case 'S':
      gmState = 2;
      glutDisplayFunc(ViewEndDisplay);
      init_end();
      break;
    case 27: // ESCape key.
      exit(0);
      break;
    default :
      break;
    }						
    break;
  case 1 : //  GAME_STATE = Playing Game.
    switch(key) {
    case 27 : // ESCape key go back to main menu "PAUSED".
      gmState = 0;
      glutDisplayFunc(MainMenuDisplay);
      init_menu();
      paused = true;
      break;
    default :
      break;
    }
    break;
  case 2 : //  GAME_STATE = Game Over. / View Scores.
    switch(key){
    case 27 : // ESCape key go back to main menu.
      gmState = 0;
      glutDisplayFunc(MainMenuDisplay);
      init_menu();
      break;
    default :
      break;
    }
    break;
  default:
    break;
  }
}


void ViewEndDisplay(void)
/*
 * End of Game Screen display.
 */
{
  glXWaitX();
  glClearColor(0.0,0.0,0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glPushMatrix();
  glColor3f(0.5f, 0.0f, 1.0f);
  printGLSTRING(Etitle,-6.25, 9.25, 0.0, 4.0);
  printGLSTRING(sHitEscape,-6.0,-9.0,0.0,2.0);
  printGLSTRING(sPoints,-5.25, 7.4,0.0,2.0);
  printGLSTRING(sLevel,3.0, 7.4,0.0,2.0);
  float sx = 5.4;
  for (int i = 0; i < 5; i++)
    {
      sprintf(TopScore,"%d", all_scores[i][0] );
      sprintf(TopLevel,"%d", all_scores[i][1] );
      printGLSTRING(TopScore,-5.0,sx,0.0,2.0);
      printGLSTRING(TopLevel,4.5,sx,0.0,2.0);
      sx -= 2.0;
    }
  glPopMatrix();
  glutSwapBuffers();
}

void MainMenuDisplay(void)
/*
 * Main Menu screen.
 */
{
  glXWaitX();
  glClearColor(0.0,0.0,0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glPushMatrix();
  glColor3f(0.5f, 0.0f, 1.0f);
  glLineWidth(2.0f);
  printGLSTRING(Gtitle,-5.0, 9.25, 0.0, 4.0);
  if(paused)
    {
      printGLSTRING(RResume, -4.1,5.0,0.0,2.0);
      printGLSTRING(NNew, -4.1, 3.0, 0.0, 2.0);
      printGLSTRING(VScores, -4.1, 1.0,0.0,2.0);
    }
  else	{
    printGLSTRING(PGame,-3.3,5.0,0.0,2.0);
    printGLSTRING(VScores, -3.3, 3.0, 0.0, 2.0);
  }
  printGLSTRING(EQuit,-5.25,7.4,0.0,2.0);
  glLineWidth(1.0f);
  glPopMatrix();
  glutSwapBuffers();
}
void PlayGameDisplay(void)
/*
  Play the game
*/
{
  glXWaitX();
  glClearColor(0.0,0.0,0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glPushMatrix();
  colorPiece(token.get());
  glColor3f(0.5f, 0.0f, 1.0f);
  printGLSTRING(Gtitle,-5.0,9.25,0.0,4.0);
  printGLSTRING(Slevel,5.0,6.0,0.0,3.0);
  printGLSTRING(Sscore,5.0,2.0,0.0,3.0);
  printGLSTRING(Snpiece,5.5,-2.0,0.0,3.0);
  sprintf(Score,"%d", TotalScore);
  sprintf(Level,"%d", CurLevel);
  printGLSTRING(Score,6.0,0.5,0.0,2.0);
  printGLSTRING(Level,6.0,4.5,0.0,2.0);
  next_token.show();
  glPushMatrix();
  glTranslatef(-8.0,-12.0,0.0);
  glColor3f(1.0,1.0,1.0);
  drawBoard();
  token.show();
  glPopMatrix();
  glPopMatrix();
  glutSwapBuffers();
}



/* Each idle function could contain background special effecs possibly. */
void end_idle(void)
{
  glutPostRedisplay();
}
void init_end(void)
{
  glutIdleFunc(end_idle);
}

void menu_idle(void)
{
  glutPostRedisplay();
}
void init_menu(void)
{
  glutIdleFunc(menu_idle);
}

void game_idle(void)
{
  if (move_piece() )
    {
      move_token_down();
    }
  glutPostRedisplay();
}
void resume_game(void)
{
  glutIdleFunc(game_idle);
  prep_timer(); //Game Piece Movement Timing
}
void init_game(void)
{
  initBoard();
  next_token.selType();
  token.setType(next_token.get());
  token.initPiece();
  token.initPosition();
  next_token.selType();
  next_token.initPiece();
  next_token.setPosition(7, -4);
  glutIdleFunc(game_idle);
  CurLevel = 0;
  TotalScore = 0;
  Level_lines = 0;
  paused = false;
  setLevel_delay();
  prep_timer(); //Game Piece Movement Timing
}

 void init_view(void)
/*
 * Whole view for the entire Window.
 */
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(GWH, GWH);
  glutInitWindowPosition(200, 100);
  glutCreateWindow(argv[0]);
  init_view();
  FontInit(); 
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard_char);
  glutSpecialFunc(keyboard_special);
  init_menu();
  clear_scores();
  glutDisplayFunc(MainMenuDisplay);
  glutMainLoop();
  return 0;
}
