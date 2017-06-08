/*********************************************************
 *				Copyright (c) 2017 Jean Vitor de Paulo   *
 *  				Licensed under MIT License			 *
 * 														 *
 *********************************************************/


#include <simpleWMouse/simpleWMouse.hpp>
#include <Windows.h>

namespace simplewmouse{

Mouse::Mouse(){
	x=0;
	y=0;
}

Mouse::~Mouse(){
}

void Mouse::setXYposition(const int positionX,const int positionY){
	/* This function uses <Windows.h>'s  SetCursorPos(x,y) to instantly move the mouse cursor to the desired
	location, based on pixel localization */
	SetCursorPos(positionX,positionY);
}

int Mouse::getX(){
	/* Returns the current X position of the cursor*/
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	return (int)cursorPos.x;
}

int Mouse::getY(){
	/* Returns the current Y position of the cursor*/
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	return (int)cursorPos.y;
}


void moveTo(const int x,const int y){
	/* This function uses <Windows.h>'s SetCursorPos(x,y) to instantly move the mouse cursor to the desired
	location, based on pixel localization */
	SetCursorPos(x,y);
}
void goToTopRight (){
	/* This function uses <Windows.h>'s SetCursorPos(x,y) to instantly move the mouse cursor to the top right position
	based on pixel localization */
	RECT DesktopRect;
	HWND hDesktop=::GetDesktopWindow();
	::GetWindowRect(hDesktop, &DesktopRect);
	SetCursorPos(DesktopRect.right,0);
}

void goToTopLeft (){
	/* This function uses <Windows.h>'s SetCursorPos(x,y) to instantly move the mouse cursor to the top left position
	based on pixel localization */
	RECT DesktopRect;
	HWND hDesktop=::GetDesktopWindow();
	::GetWindowRect(hDesktop, &DesktopRect);
	SetCursorPos(0,0);
}

void goToBottomRight (){
	/* This function uses <Windows.h>'s SetCursorPos(x,y) to instantly move the mouse cursor to the bottom right position
	based on pixel localization */
	RECT DesktopRect;
	HWND hDesktop=::GetDesktopWindow();
	::GetWindowRect(hDesktop, &DesktopRect);
	SetCursorPos(DesktopRect.right,DesktopRect.bottom);
}

void goToBottonLeft (){
	/* This function uses <Windows.h>'s SetCursorPos(x,y) to instantly move the mouse cursor to the bottom left position
	based on pixel localization */
	RECT DesktopRect;
	HWND hDesktop=::GetDesktopWindow();
	::GetWindowRect(hDesktop, &DesktopRect);
	SetCursorPos(0,DesktopRect.bottom);
}

void goToCenter (){
	/* This function uses <Windows.h>'s SetCursorPos(x,y) to instantly move the mouse cursor to center of the screen
	based on pixel localization */
	RECT DesktopRect;
	HWND hDesktop=::GetDesktopWindow();
	::GetWindowRect(hDesktop, &DesktopRect);
	SetCursorPos(DesktopRect.right/2,DesktopRect.bottom/2);
}

int currentXPosition(){
	/* Returns the current X position of the cursor*/
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	float currentXPos = cursorPos.x;
	return (int)currentXPos;
}
int currentYPosition(){
	/* Returns the current Y position of the cursor*/
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	float currentYPos = cursorPos.y;
	return (int)currentYPos;
}

bool CheckLeftMouseButtonStatus()
{
	/* Verify if the left mouse button is being pressed */
   if ((GetKeyState(VK_LBUTTON) & 0x80) != 0){
      return true;
   }else return false;
}

bool CheckRightMouseButtonStatus()
{
	/* Verify if the right mouse button is being pressed */
   if ((GetKeyState(VK_RBUTTON) & 0x80) != 0)
      return true;
   else return false;
}

bool CheckWheeltMouseButtonStatus()
{
	/* Verify if the Wheel mouse button is being pressed */
   if ((GetKeyState(VK_MBUTTON) & 0x80) != 0)
      return true;
   else return false;
}

void LeftClick()
{
	/* Simulate the left click action */
	INPUT In={0};										

	In.type        = INPUT_MOUSE;								
	In.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;								//setting left mouse button down.
	SendInput( 1, &In, sizeof(INPUT) );								// Send the input.

	ZeroMemory(&In,sizeof(INPUT));									// Fills a block of memory with zeros.
	In.type        = INPUT_MOUSE;									
	In.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								// setting left mouse button up.
	SendInput( 1, &In, sizeof(INPUT) );								// Send the input.
}

void RightClick()
{
	/* Simulate the right click action */
	INPUT    In={0};								

	In.type        = INPUT_MOUSE;									
	In.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;								// setting right mouse button down.
	SendInput( 1, &In, sizeof(INPUT) );								// Send the input.

	ZeroMemory(&In,sizeof(INPUT));									// Fills a block of memory with zeros.
	In.type        = INPUT_MOUSE;									
	In.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;								//setting right mouse button up.
	SendInput( 1, &In, sizeof(INPUT) );								// Send the input.
}

void WheelClick()
{
	/* Simulate the Wheelbutton click action */
	INPUT In={0};											

	In.type        = INPUT_MOUSE;									
	In.mi.dwFlags  = MOUSEEVENTF_MIDDLEDOWN;							// setting wheel mouse button down.
	SendInput( 1, &In, sizeof(INPUT) );								// Send the input.

	ZeroMemory(&In,sizeof(INPUT));									// Fills a block of memory with zeros.
	In.type        = INPUT_MOUSE;									
	In.mi.dwFlags  = MOUSEEVENTF_MIDDLEUP;								//setting wheel mouse button up.
	SendInput( 1, &In, sizeof(INPUT) );								// Send the input.
}

//==================================
void smoothXMovement(const int x,const int smoothness){
	/* A smooth vertical movement from the current X position to the new x position */
	POINT cursorPos;
	int totalMovementX;
	GetCursorPos(&cursorPos);
	float currentXPos = cursorPos.x;
	float currentYPos = cursorPos.y;
	totalMovementX=x-currentXPos;
	 if (totalMovementX>0)
		 for (int i=0;i<=totalMovementX;i++){
			 Sleep(smoothness);
			 SetCursorPos(currentXPos++,currentYPos);
		 }
	 else for(int i=totalMovementX;i!=0;i++){
		 Sleep(smoothness);
		 SetCursorPos(currentXPos--,currentYPos);
	 }
}

void smoothYMovement(const int y, const int smoothness){
	/* A smooth horizontal movement from the current Y position to the new y position */
	POINT cursorPos;
	int totalMovementY;
	GetCursorPos(&cursorPos);
	float currentXPos = cursorPos.x;
	float currentYPos = cursorPos.y;
	totalMovementY=y-currentYPos;
	if (totalMovementY>0)
		 	for (int i=0;i<=totalMovementY;i++){
		 		Sleep(smoothness);
		 			 SetCursorPos(currentXPos,currentYPos++);
		 	}
	else for (int i=totalMovementY;i!=0;i++){
		Sleep(smoothness);
		 		 SetCursorPos(currentXPos,currentYPos--);
		  }
}
}
