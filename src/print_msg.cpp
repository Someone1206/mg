#include <print_msg.h>
#include <print.h>

void PrintHelp()
{
	pl("This is the help prompt for mg.");
	pl("-h, --help         To show this help prompt.");
	pl("-v, --version      To show version.");
	pl("-T, --show-tabs    To show tabs as ^I.");
	pl(
		"-f <filename>, --file=<filename>\n" << 
		"    Use the file name after the flag. This does not consider " <<
		"any other flag after it.\n" <<
		"Eg: mg -f -h -- will show the contents of file named \"-h\"."
	);
	pl("-n, --new-line     Forcefully shows a new line after each successive file.");
	pl(
		"-l, --new-line-if  Shows a new line if the file already does not end " <<
		"with a new line."
	);
	pl("-N, --no-new-line   Forcefully removes the last new line from a file.");
	pl("-w, --show-win-e    Show '$' at the end of files with CRLF line endings");
	pl("-E, --show-ends     Show '$' at the end of files with LF line endings");
	pl(
		"-V, --show-nonprinting\n" <<
		"     Show non printing characters as ^M except TABS. (Will Improve later)"
	);
}


void PrintVersion()
{
	pl("md version 0.0.0-beta");
}