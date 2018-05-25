#pragma once

#include "expat.h"
#include <iostream>
#include <string>
#include "Feed.h"

typedef struct{
	uint32_t depth;
	std::string * parElement; ///Este no se si esta bien.
	char * buffer;
}myUserData;

class XML
{
public:
	XML();
	~XML();

	void parse(Feed feed_, std::string rss_ );


	XML_Parser p;
	XML_CharacterDataHandler chardata;
	XML_Status status;
	myUserData UD;
	FILE * fp;

private:

};

