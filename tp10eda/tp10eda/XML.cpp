#include "XML.h"
#include "XML_Event.h"
#include "general.h"

XML::XML()
{
	this->p = XML_ParserCreate(NULL);						//Creamos el parser
	XML_SetElementHandler(this->p, StartTag, EndTag);		//
	XML_SetCharacterDataHandler(this->p, this->chardata);	//
	XML_SetUserData(this->p, &this->UD);					//



}


XML::~XML()
{
	XML_ParserFree(p);
	fclose(fp);
}

bool XML::parse(FEED feed_, std::string rss_) {

	FILE * fp = fopen(FILENAME, "rb");					//Abrimos el archivo en el cual estan contenido lo obtenido a traves del networking
	bool success = false;

	if (fp != NULL) {
		int filesize = getSize(fp);									//Obtenemos el size del archivo
		char* buffer = (char *)calloc(filesize, sizeof(char));		//Creamos un buffer que pueda contener al archivo.
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