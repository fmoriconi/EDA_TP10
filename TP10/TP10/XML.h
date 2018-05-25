#pragma once

#include "expat.h"
#include <iostream>

class XML
{
public:
	XML();
	~XML();

	XML_Parser p;
	XML_CharacterDataHandler chardata;
	XML_Status status;
	myUserData UD;
	FILE * fp;
	

};

