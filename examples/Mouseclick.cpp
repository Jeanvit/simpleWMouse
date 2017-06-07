/*Send the cursor to the center of the screen and then click with the Right Button and show the current position */

#include "include/simpleWMouse.hpp"
#include <iostream>

using namespace simplewmouse;

int main (int argc, const char** argv){

	goToCenter();
	RightClick();
	std::cout<<"Mouse is on X:" <<currentXPosition()<< "Y:"<<currentYPosition()<<std::endl;
}
