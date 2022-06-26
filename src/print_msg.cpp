#include <print_msg.h>
#include <print.h>

void PrintHelp()
{
	pl("This is the help prompt for mg.");
	pl("-h, --help         To show this help prompt.");
	pl("-v, --version      To show version.");
}

void PrintHelp(const char* errMsg)
{
	pl(errMsg);

	PrintHelp();
}

void PrintVersion()
{
	pl("md version 0.0.0-beta");
}
