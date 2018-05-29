#pragma once

#include "expat.h"
#include "Feed.h"
#include <iostream>
#include <string>

typedef struct {
	uint32_t depth;
	Feed * feed;
}myUserData;

class XML
{
public:
	XML();
	~XML();

	bool parse(Feed feed_, std::string rss_ , int filesize_);

	XML_Parser p;
	XML_CharacterDataHandler chardata;
	XML_StartElementHandler startElementHandler;
	XML_EndElementHandler endElementHandler;
	XML_Status status;
	myUserData UD;
	FILE * fp;

private:

};

