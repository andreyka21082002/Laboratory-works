#include <iostream>
#include "libbmp.h"

//00b 00g 00r 01b 01g 01r 10b 10g

int main()
{
	setlocale(LC_ALL, "Russian");

	BmpImg img;
	img.read("pic11.bmp");
	const int width = img.get_width() - 1;
	const int height = img.get_height() - 1;
	char text[4000] = {};

	int pos = 0;
	bool isEnd = false;

	for (int y = 0; y <= height; y++) {
		for (int x = 0; x <= width; x++) {

			char rbit = img.red_at(x, y) & 1;
			char gbit = img.green_at(x, y) & 1;
			char bbit = img.blue_at(x, y) & 1;

			text[pos / 8] |= rbit << (7 - (pos % 8));
			pos++;
			if (text[pos / 8] == '\0' && pos % 8 == 7) {
				isEnd = true;
			}

			text[pos / 8] |= gbit << (7 - (pos % 8));
			pos++;
			if (text[pos / 8] == '\0' && pos % 8 == 7) {
				isEnd = true;
			}

			text[pos / 8] |= bbit << (7 - (pos % 8));
			pos++;
			if (text[pos / 8] == '\0' && pos % 8 == 7) {
				isEnd = true;
			}

			if (isEnd) break;
		}
		if (isEnd) break;
	}
	std::cout << text;

	return 0;
}
