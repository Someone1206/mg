// mg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <print.h>
#include <print_msg.h>
#include <string>
#include <string.h>

#include <vector>

#include <fstream>

#include <bitset>

int main(int argc, char* argv[]) {
	std::vector<std::string>fileNames;

	std::bitset<8> flags;

	size_t fileNumCap = 10;

	fileNames.reserve(fileNumCap);

	for (int i = 1; i < argc; i++) {
		switch (**(argv + i))
		{
		case '-':
		{
			switch (*(*(argv + i) + 1))
			{
			case 'h':
				PrintHelp();
				break;
			case 'v':
				PrintVersion();
				break;
			case 'T':
			___SHORTEN_TABS:
				flags[0] = true;
				break;
			case 'f':
				i++;
				goto ___ADD_FILE;
				break;
			case 'n':
			___FORCE_NEWLINE:
				flags[1] = true;
				break;
			case 'l':
			___NEWLINE_IF_REQ:
				flags[2] = true;
				break;
			case 'N':
			___NO_NEWLINE:
				flags[3] = true;
				break;
			case 'w':
			___SHOW_WIN_ENDS:
				flags[6] = true;
			case 'E':
			___SHOW_ENDS:
				flags[4] = true;
				break;

			case 'V':
			___SHOW_NP:
				flags[5] = true;
				break;

			case '-':
			{
				if (strcmp("--version", *(argv + i)) == 0) {
					PrintVersion();
				}
				else if (strcmp("--help", *(argv + i)) == 0) {
					PrintHelp();
				}
				else if (strcmp("--show-tabs", *(argv + i)) == 0) {
					goto ___SHORTEN_TABS;
				}
				else if (strcmp("--new-line", *(argv + i)) == 0) {
					goto ___FORCE_NEWLINE;
				}
				else if (strcmp("--new-line-if", *(argv + i)) == 0) {
					goto ___NEWLINE_IF_REQ;
				}
				else if (strcmp("--no-new-line", *(argv + i)) == 0) {
					goto ___NO_NEWLINE;
				}
				else if (strcmp("--show-ends", *(argv + i)) == 0) {
					goto ___SHOW_ENDS;
				}
				else if (strcmp("--show-nonprinting", *(argv + i)) == 0) {
					goto ___SHOW_NP;
				}
				else if (strcmp("--show-win-e", *(argv + i)) == 0) {
					goto ___SHOW_WIN_ENDS;
				}
				else {
					std::string argStr(*(argv + i));
					if (argStr.find("--file=") == 0) {
						fileNames.push_back(argStr.substr(7));
						goto ___ADJ_SZ;
					}
					else {
						std::cerr << "md: unknown option - " << argStr << std::endl;
					}
				}
				break;
			}
			default:
				std::cerr << "md: unknown option - " << *(argv + i) << std::endl;
			}
			break;
		}
		default:
			___ADD_FILE:
			if (i < argc) {
				fileNames.push_back(*(argv + i));
				___ADJ_SZ:
				if (fileNames.size() >= fileNumCap) {
					fileNumCap += 10;
					fileNames.reserve(fileNumCap);
				}
			}
		}

	}

	fileNumCap = fileNames.size();
	std::ifstream fileToOpen;
	char* file_buffer;
	size_t fileBufSz = 0;

	for (size_t i = 0; i < fileNumCap; i++) {
		fileToOpen.open(fileNames[i], std::ifstream::binary);

		if (fileToOpen.bad() || !fileToOpen.is_open()) {
			pl("Error! Unable to open:  " << fileNames[i]);
			continue;
		}

		fileToOpen.seekg(0, fileToOpen.end);
		fileBufSz = fileToOpen.tellg();
		fileToOpen.seekg(0, fileToOpen.beg);

		file_buffer = new char[fileBufSz + 1];

		fileToOpen.read(file_buffer, fileBufSz);
		file_buffer[fileBufSz] = 0;

		printBuffer(flags, file_buffer, fileBufSz);

		delete[] file_buffer;
		fileToOpen.close();
	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
