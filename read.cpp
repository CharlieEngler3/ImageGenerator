#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
	std::string inputFile;

	std::cin >> inputFile;

	std::ifstream input(inputFile);

	const int readLength = 24;

	if(input)
	{
		std::string s(readLength, '\0');

		if(input.read(&s[0], readLength))
		{
			for(int i = 0; i < readLength; i++)
			{
				std::cout << "Byte " << std::to_string(i + 1) << ": " << std::hex << (int)s[i] << std::endl;
			}
		}
		else
		{
			std::cerr << "Couldn't read from file." << std::endl;
		}
	}
	else
	{
		std::cerr << "Couldn't open file." << std::endl;
	}

	input.close();

	return 0;
}
