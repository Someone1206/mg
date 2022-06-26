#include <print.h>

void printBuffer(std::bitset<8>& flags, char* fileBuffer, size_t fileBuffSz)
{
	while (*fileBuffer != 0) {
		if (flags[0]) { // --show-tabs
			if (*fileBuffer == '\t') {
				p("^I");
				fileBuffer++;
			}
		}
		p(*fileBuffer);
		fileBuffer++;
	}
}
