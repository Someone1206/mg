// mg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <print.h>
#include <print_msg.h>
#include <string>
#include <string.h>

#include <vector>

#include <fstream>

int main(int argc, char* argv[]) {
	std::vector<std::string>fileNames;

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

			case '-':
			{
				if (strcmp("--version", *(argv + i)) == 0) {
					PrintVersion();
				}
				else if (strcmp("--help", *(argv + i)) == 0) {
					PrintHelp();
				}
				else {
					std::string buff = "md: unknown option - " + std::string(*(argv + i));
					PrintHelp(buff.c_str());
				}
				break;
			}
			default:
				std::string buff = "md: unknown option - " + std::string(*(argv + i));
				PrintHelp(buff.c_str());
			}
			break;
		}
		default:
			fileNames.push_back(*(argv + i));

			if (fileNames.size() >= fileNumCap) {
				fileNumCap += 10;
				fileNames.reserve(fileNumCap);
			}
		}

	}

	fileNumCap = fileNames.size();
	std::ifstream fileToOpen;
	char* file_buffer;
	size_t fileBufSz = 0;

	for (size_t i = 0; i < fileNumCap; i++) {
		fileToOpen.open(fileNames[i]);

		if (fileToOpen.bad() || !fileToOpen.is_open()) {
			pl("Error! Unable to open:  " << fileNames[i]);
			continue;
		}

		fileToOpen.seekg(0, fileToOpen.end);
		fileBufSz = fileToOpen.tellg();
		fileToOpen.seekg(0, fileToOpen.beg);

		file_buffer = new char[fileBufSz];

		fileToOpen.read(file_buffer, fileBufSz);
		file_buffer[fileBufSz - 1] = 0;

		pl(file_buffer);

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
