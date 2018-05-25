#pragma once

#include "expat.h"
#include <iostream>
#include <string>

typedef myUserData{
	uint32_t depth;
	std::string * parElement; ///Este no se si esta bien.
	char * buffer;
};

class XML
{
public:
	XML();
	~XML();

	bool parse(FEED feed_, std::string rss_ );


	XML_Parser p;
	XML_CharacterDataHandler chardata;
	XML_Status status;
	myUserData UD;
	FILE * fp;

private:

};

