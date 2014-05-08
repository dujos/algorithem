#include "StringTest.h"

StringTest::StringTest() {}

char StringTest::first_repeating_char(const char* ch) {
	unsigned int histogram[256];
	memset(histogram, 0, sizeof(histogram));
	
	for(size_t i = 0; ch[i] != 0; ++i)
		++histogram[ch[i]];

	for(size_t i = 0; ch[i] != 0; ++i)
		if(histogram[ch[i]] == 1)
			return ch[i];
	return 0;
}