#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <sstream>

std::string png_header = "89504e470d0a1a0a";

std::string ihdr_text = "0000000d49484452";

std::string ihdr_width = "0002";
std::string ihdr_height = "0002";
std::string ihdr_bit_depth = "10";
std::string ihdr_color_type = "02";
std::string ihdr_compression_method = "00";
std::string ihdr_filter_method = "00";
std::string ihdr_interlace_method = "00";

std::string create_binary(std::string str, int size)
{
	std::basic_string<uint8_t> bytes;

	for(size_t i = 0; i < str.length(); i += 2)
	{
		uint16_t byte;

		std::string nextByte = str.substr(i, 2);
		std::istringstream(nextByte) >> std::hex >> byte;
		bytes.push_back(static_cast<uint8_t>(byte));
	}
	
	std::string final_string(begin(bytes), end(bytes));

	return final_string;
}

int main()
{
	std::ofstream output("output.png", std::ios::binary | std::ios::out);

	if(output.is_open())
	{
		output << create_binary(png_header, 2);
		output << create_binary(ihdr_text, 2);
		output << create_binary(ihdr_width, 4);
		output << create_binary(ihdr_height, 4);
		output << create_binary(ihdr_bit_depth, 2);
		output << create_binary(ihdr_color_type, 2);
		output << create_binary(ihdr_compression_method, 2);
		output << create_binary(ihdr_filter_method, 2);
		output << create_binary(ihdr_interlace_method, 2);
		output.close();
	}
	else
	{
		std::cerr << "Couldn't open file." << std::endl;
	}

	return 0;
}
