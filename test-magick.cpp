#include "Magick++/Magick++.h"
#include <string>

int main(int argc, char *argv[])
{
	Magick::InitializeMagick(*argv);
	Magick::CoderInfo info;
	return 0;
}
