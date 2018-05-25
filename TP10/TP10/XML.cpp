#include "XML.h"
#include "XML_Event.h"

XML::XML()
{
	this->p = XML_ParserCreate(NULL);
	XML_SetElementHandler(this->p, StartTag, EndTag);
	XML_SetCharacterData(this->p, this->chardata);
	XML_SetUserData(this->p, &this->UD);
	FILE * fp = fopen("ejemplo.xml","rb");
	if()

}


XML::~XML()
{
}
