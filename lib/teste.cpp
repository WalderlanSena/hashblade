#include <stdio.h>
#include <stdlib.h>

int main () {
	std::string valores = "DATA : %s HORA: %s\n",__DATE__,__TIME__;
	// printf("DATA : %s HORA: %s\n",__DATE__,__TIME__);
	cout << valores;
	return 0;
}