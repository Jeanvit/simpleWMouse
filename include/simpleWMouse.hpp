#ifndef __SIMPLEWMOUSE_INCLUDED__
#define __SIMPLEWMOUSE_INCLUDED__

namespace simplewmouse{


void moveTo(int x, int y);

class Mouse{
private:
	int x,y;
	public:
	    void setXYposition (int,int);
	    int getX();
	    int getY();
	    Mouse();
	    ~Mouse();
};


/*===================================================================================*/
void goToTopRight ();

void goToTopLeft ();

void goToBottomRight ();

void goToBottonLeft ();

void goToCenter ();

/*===================================================================================*/

int  currentXPosition();

int  currentYPosition();

/*===================================================================================*/

bool CheckLeftMouseButtonStatus();

bool CheckRightMouseButtonStatus();

bool CheckWheeltMouseButtonStatus();
/*===================================================================================*/

void LeftClick();

void RightClick();

void WheelClick();

/*===================================================================================*/

void smoothXMovement(int x, int smoothness);

void smoothYMovement(int y, int smoothness);

}

#endif
