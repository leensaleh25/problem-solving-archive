#pragma warning(disable :4996)
#include <iostream>

int main()
{
	time_t  t= time(0);//get time now
	tm* now = localtime(&t);

}

