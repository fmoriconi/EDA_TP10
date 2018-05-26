#include "XML.h"
#include "XML_Event.h"
#include "Feed.h"
#include "general.h"
#include "Handler.h"

XML::XML()
{
	this->p = XML_ParserCreate(NULL);						//Creamos el parser
	XML_SetElementHandler(this->p, &startTagHandler, &endTagHandler);		//
	XML_SetCharacterDataHandler(this->p, &characterDataHandler);	//
	XML_SetUserData(this->p, &this->UD);					//



}


XML::~XML()
{
	XML_ParserFree(p);
	fclose(fp);
}

bool XML::parse(Feed feed_, std::string rss_, int filesize_) {

	FILE * fp = fopen(FILENAME, "rb");					//Abrimos el archivo en el cual estan contenido lo obtenido a traves del networking
	bool success = false;

	if (fp != NULL) {			
		char * buffer = (char *)calloc(filesize_, sizeof(char));		///Revisar: ¿Me pasan la cantidad de bytes o la cantidad de elementos?
		if (buffer != NULL) {
			fread(buffer, sizeof(char), filesize, fp);				//Pasamos el archivo a un buffer.
			this->status = XML_Parse(p, buffer, filesize, true);	//Parseamos
			if (status != 0)
				 success = true;										//Si status es 0, hubo un problema parseando
		}
		free(buffer);
	}

	return success;

}