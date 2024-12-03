#include "src/Adapter.h"

int main()
{
	AdapteeImpl adaptee;

	adaptee.play(0,"篮球");
	adaptee.play(1,"写作业");
	adaptee.play(2,"玩");

	return 0;
}