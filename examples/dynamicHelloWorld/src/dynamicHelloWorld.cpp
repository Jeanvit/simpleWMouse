#include <iostream>
#include <simpleWMouse/simpleWMouse.hpp>

using namespace simplewmouse;
using namespace std;

int main() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	goToCenter(); // move the mouse cursor to the center of the screen
	RightClick(); // Simulate a Right Click
	return 0;
}
