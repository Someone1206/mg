#include <print.h>

void printBuffer(std::bitset<8>& flags, char* fileBuffer, size_t fileBuffSz)
{
	char ch = 0;
	while (true) {
		ch = *fileBuffer;
		if (flags[5]) { // --show-tabs
			if (ch == '\r') {
				p("M^");
				fileBuffer++;
			}
		}
		else if (flags[0]) {
			if (ch == '\t') {
				p("^I");
				fileBuffer++;
			}
		}

		if (flags[6]) {
			if (ch == '\r' && *(fileBuffer + 1) == '\n') {
				p("$\n");
				fileBuffer += 2;
			}
		}
		if (flags[4]) {
			if (ch == '\n') {
				p("$\n");
				fileBuffer++;
			}
		}

		if (*fileBuffer == 0)
			break;
		p(*fileBuffer);
		fileBuffer++;
	}

	ch = *(fileBuffer - (1 * (bool)fileBuffSz));

	if (flags[1]) {
		p("\n");
	}
	else if (flags[2] && ch != '\n') {
		p("\n");
	}
	// TODO: Fix this...
	else if (flags[3] && ch == '\n') {
		p("\b");
	}
}
