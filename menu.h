/*
  Menu.h
  Includes interface for menu system.
  Main and Pause
*/

#include <GL/gl.h>
#include <GL/glu.h>

/*
  Main Menu interface.
*/

extern int gmState;
char *mML1 = "NEW GAME";

char *mML2 = "SCORES";
char *mML2a = "VIEW";
char *mML2b = "CLEAR";

char *mML3  = "SETTINGS";
char *mML3a = "AUDIO";
char *mML3b = "VOLUME";
char *mML3c = "MIN";
char *mML3d = "MAX";
char *mML3e = "VIDEO";
char *mML3f = "RESOLUTION";
char *mML3g = "FULLSCREEN";
char *mML3h = "KEYBOARD";
char *mML3i = "LEFT";
char *mML3j = "RIGHT";
char *mML3k = "DOWN";

char *mML4 = "QUIT Y?N";

struct s_MenuItem {
  int elements;
  char *name;
  int function;
};
s_MenuItem StartMenuListing[3];
s_MenuItem GameMenuListing[2];

class c_Menu {
  /* Menu class */
  int mx,my;    //  Position.
  int mw,mh;    //  Size.

  c_Menu(int x, int y, int w, int h){
    mx = x; my=y; mw=w; mh=h;
  }
  void display();
};


/*
  Function: diplay YN? quit message. Send the WM_quit message if necescary
*/
void checkForQuit()
{
  //PostQuitMessage(0);
}

void StartMenuFunctions(int function)
{
  switch(function) {
  case 0: {
    gmState = 1;
  } break;
  case 1: {
    gmState = 2;
  } break;
  case 2: {
    checkForQuit();
  } break;
  };
}

void DisplayMenu( s_MenuItem M[] )
{
  int pos = 0;
  float x = 0;
  float y =100 ;
  while(pos < (int)sizeof(M))  {}
}
void dispMarker()
{
}

void dispMMenu()
{
}

void mMenuBackground()
//  Display the Main menu background.
{
}

void mMenu()
{
  mMenuBackground();
  dispMarker();
  dispMMenu();
}



/*
  Pause Menu interface.
*/
void dispPMenu()
{
}

void pMenuBackground()
{
}

void pMenu()
{
  pMenuBackground();
  dispMarker();
  dispPMenu();

}
