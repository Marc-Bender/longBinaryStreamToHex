// intended to Convert a String of the form "10101111" to the corresponding hexadecimal representation as a string ("AF")

#include "stdafx.h"
#include <iostream>
#include <stdint.h>

using namespace std;

int main(unsigned int argc, const char * argv[])
{
	int8_t returnValue = 0;
	if (argc != 2)
	{
		cerr << "Falsche Argumentezahl" << endl;
		returnValue = -3;
	}
	else
	{
		const char * theBinaryString = argv[1];
		if (((sizeof(theBinaryString) / sizeof(char)) % 4 != 0)) return -1;
		while (*theBinaryString != '\0')
		{
			uint8_t helper = 0;
			for (uint8_t j = 0; j < 4; j++)
			{
				if (*theBinaryString != '0' && *theBinaryString != '1')
				{
					cerr << endl << "Keine Binaere Ziffer bei " << (uint64_t)theBinaryString << endl;
					returnValue = -4;
					goto end;
				}
				helper += (uint8_t)(((*theBinaryString) - '0') << (3 - j));
				theBinaryString++;
				if (helper > 15)
				{
					cerr << endl << "Fehler bei " << (uint64_t)theBinaryString << endl;
					returnValue = -2;
					goto end;
				}
			}

			if (helper < 10)helper += '0';
			else if (helper >= 10 && helper < 16)helper += 'A' - 10;
			if (isxdigit(helper))cout << helper;
			helper = 0;
		}
		cout << endl;
	}
end: 
	system("pause");
    return returnValue;
}

