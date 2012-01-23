/*
    setColors.h
    Contains functions for the setting of board and piece colors.
*/

#include <GL/gl.h>


extern int CurLevel ;


void colorPiece(int gPtype)
/*
    Function: set color with current scheme.
*/
{
    switch(CurLevel)
    {
        case 0:{ /* level 0 */
                switch(gPtype) {
                    case 0: glColor3f(0.192f ,0.310f , 0.310f);
                            break;
                    case 1: glColor3f(0.412f,0.412f,0.412f);
                            break;
                    case 2: glColor3f(0.439f,0.541f,0.565f);
                            break;
                    case 3: glColor3f(0.467f,0.533f,0.600f);
                            break;
                    case 4: glColor3f(0.745f,0.745f,0.745f);
                            break;
                    case 5: glColor3f(0.827f,0.827f,0.827f);
                            break;
                    case 6: glColor3f(1.0f,0.1f,0.1f);
                            break;
                    case 7: glColor3f(1.0f,1.0f,1.0f);
                            break;
                };
                break;
            }
        case 1:{ /* level 1 */
                switch(gPtype) {
                    case 0: glColor3f(0.5f,0.0f,0.1f);
                            break;
                    case 1: glColor3f(0.5f,0.1f,0.1f);
                            break;
                    case 2: glColor3f(0.5f,0.2f,0.1f);
                            break;
                    case 3: glColor3f(0.5f,0.3f,0.1f);
                            break;
                    case 4: glColor3f(0.5f,0.4f,0.1f);
                            break;
                    case 5: glColor3f(0.5f,0.5f,0.1f);
                            break;
                    case 6: glColor3f(0.5f,0.6f,0.1f);
                            break;
                    case 7: glColor3f(0.5f,0.7f,0.1f);
                            break;
                };
                break;
            }
        case 2:{ /* level 2 */
                switch(gPtype) {
                    case 0: glColor3f(0.7f,0.0f,0.1f);
                            break;
                    case 1: glColor3f(0.7f,0.1f,0.1f);
                            break;
                    case 2: glColor3f(0.7f,0.2f,0.1f);
                            break;
                    case 3: glColor3f(0.7f,0.3f,0.1f);
                            break;
                    case 4: glColor3f(0.7f,0.4f,0.1f);
                            break;
                    case 5: glColor3f(0.7f,0.5f,0.1f);
                            break;
                    case 6: glColor3f(0.7f,0.6f,0.1f);
                            break;
                    case 7: glColor3f(0.7f,0.7f,0.1f);
                            break;
                };
                break;
            }
        case 3:{ /* level 3 */
                switch(gPtype) {
                    case 0: glColor3f(1.0f,0.0f,0.1f);
                            break;
                    case 1: glColor3f(1.0f,0.1f,0.1f);
                            break;
                    case 2: glColor3f(1.0f,0.2f,0.1f);
                            break;
                    case 3: glColor3f(1.0f,0.3f,0.1f);
                            break;
                    case 4: glColor3f(1.0f,0.4f,0.1f);
                            break;
                    case 5: glColor3f(1.0f,0.5f,0.1f);
                            break;
                    case 6: glColor3f(1.0f,0.6f,0.1f);
                            break;
                    case 7: glColor3f(1.0f,0.7f,0.1f);
                            break;
                };
                break;
            }
        case 4:{ /* level 4 */
                switch(gPtype) {
                    case 0: glColor3f(0.0f,0.3f,0.1f);
                            break;
                    case 1: glColor3f(0.1f,0.3f,0.1f);
                            break;
                    case 2: glColor3f(0.2f,0.3f,0.1f);
                            break;
                    case 3: glColor3f(0.3f,0.3f,0.1f);
                            break;
                    case 4: glColor3f(0.4f,0.3f,0.1f);
                            break;
                    case 5: glColor3f(0.5f,0.3f,0.1f);
                            break;
                    case 6: glColor3f(0.6f,0.3f,0.1f);
                            break;
                    case 7: glColor3f(0.7f,0.3f,0.1f);
                            break;
                };
                break;
            }
        case 5:{ /* level 5 */
                switch(gPtype) {
                    case 0: glColor3f(0.0f,0.6f,0.1f);
                            break;
                    case 1: glColor3f(0.1f,0.6f,0.1f);
                            break;
                    case 2: glColor3f(0.2f,0.6f,0.1f);
                            break;
                    case 3: glColor3f(0.3f,0.6f,0.1f);
                            break;
                    case 4: glColor3f(0.4f,0.6f,0.1f);
                            break;
                    case 5: glColor3f(0.5f,0.6f,0.1f);
                            break;
                    case 6: glColor3f(0.6f,0.6f,0.1f);
                            break;
                    case 7: glColor3f(0.7f,0.6f,0.1f);
                            break;
                };
                break;
            }
        case 6:{ /* level 6 */
                switch(gPtype) {
                    case 0: glColor3f(0.0f,0.9f,0.1f);
                            break;
                    case 1: glColor3f(0.1f,0.9f,0.1f);
                            break;
                    case 2: glColor3f(0.2f,0.9f,0.1f);
                            break;
                    case 3: glColor3f(0.3f,0.9f,0.1f);
                            break;
                    case 4: glColor3f(0.4f,0.9f,0.1f);
                            break;
                    case 5: glColor3f(0.5f,0.9f,0.1f);
                            break;
                    case 6: glColor3f(0.6f,0.9f,0.1f);
                            break;
                    case 7: glColor3f(0.7f,0.9f,0.1f);
                            break;
                };
                break;
            }
        case 7:{ /* level 7 */
                switch(gPtype) {
                    case 0: glColor3f(0.3f,0.0f,0.4f);
                            break;
                    case 1: glColor3f(0.3f,0.1f,0.4f);
                            break;
                    case 2: glColor3f(0.3f,0.2f,0.4f);
                            break;
                    case 3: glColor3f(0.3f,0.3f,0.4f);
                            break;
                    case 4: glColor3f(0.3f,0.4f,0.4f);
                            break;
                    case 5: glColor3f(0.3f,0.5f,0.4f);
                            break;
                    case 6: glColor3f(0.3f,0.6f,0.4f);
                            break;
                    case 7: glColor3f(0.3f,0.7f,0.4f);
                            break;
                };
                break;
            }
        case 8:{ /* level 8 */
                switch(gPtype) {
                    case 0: glColor3f(0.7f,0.9f,0.1f);
                            break;
                    case 1: glColor3f(0.6f,0.8f,0.1f);
                            break;
                    case 2: glColor3f(0.5f,0.7f,0.1f);
                            break;
                    case 3: glColor3f(0.4f,0.5f,0.1f);
                            break;
                    case 4: glColor3f(0.3f,0.4f,0.1f);
                            break;
                    case 5: glColor3f(0.2f,0.3f,0.1f);
                            break;
                    case 6: glColor3f(0.1f,0.2f,0.1f);
                            break;
                    case 7: glColor3f(0.0f,1.0f,0.1f);
                            break;
                };
                break;
            }
        case 9:{ /* level 9 */
                switch(gPtype) {
                    case 0: glColor3f(0.0f,0.3f,1.0f);
                            break;
                    case 1: glColor3f(0.1f,0.3f,0.9f);
                            break;
                    case 2: glColor3f(0.2f,0.3f,0.8f);
                            break;
                    case 3: glColor3f(0.3f,0.3f,0.7f);
                            break;
                    case 4: glColor3f(0.4f,0.3f,0.6f);
                            break;
                    case 5: glColor3f(0.5f,0.3f,0.5f);
                            break;
                    case 6: glColor3f(0.6f,0.3f,0.4f);
                            break;
                    case 7: glColor3f(0.7f,0.3f,0.3f);
                            break;
                };
                break;
            }
    };
}

