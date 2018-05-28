#pragma once

#include "expat.h"

void startTagHandler(void * userData, const XML_Char * key, const XML_Char ** value);
void endTagHandler(void * userData, const XML_Char * key);
void characterDataHandler(void * userData, const XML_Char * key, int len);
 