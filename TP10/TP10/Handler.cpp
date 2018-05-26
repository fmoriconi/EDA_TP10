#include "Handler.h"
#include "Feed.h"
#include "XML.h"
#include "XML_Event.h"
#include <string>

void startTagHandler(void * userData, const XML_Char * key, const XML_Char ** value) {

	myUserData  * UD = (myUserData *)userData;
	std::string name = ""; //En name guardo el nombre del tag.
	xmlev evType = xmlev::START_TAG_OTHER; //Si no es un tag de mi interes, directamente sera Other.

	for (int i = 0; key[i] != '/0'; i++)
		name += key[i];

	if (name == "title") { //Asigno el tipo de evento segun el tag.
		evType = xmlev::START_TAG_TITLE;
	}
	else if (name == "item") {
		evType = xmlev::START_TAG_ITEM;
	}
	else if (name == "channel" ) {
		evType = xmlev::START_TAG_CHANNEL;
	}
	else if (name == "pubdate") {
		evType = xmlev::START_TAG_PUBDATE;
	}


	XML_Event xmlEv(evType, name); //Creo la clase que debo pasar a runFilter...
	UD->feed->runFilter(xmlEv); //...Y la paso.
	UD->depth++; //Como abri un tag, aumento la profundidad.
}



void endTagHandler(void * userData, const XML_Char * key) {

	myUserData  * UD = (myUserData *)userData;
	std::string name = ""; //En name guardo el nombre del tag.
	xmlev evType = xmlev::END_TAG_OTHER; //Si no es un tag de mi interes, directamente sera Other.

	for (int i = 0; key[i] != '/0'; i++)
		name += key[i];

	if (name == "title") { //Asigno el tipo de evento segun el tag.
		evType = xmlev::END_TAG_TITLE;
	}
	else if (name == "item") {
		evType = xmlev::END_TAG_ITEM;
	}
	else if (name == "channel") {
		evType = xmlev::END_TAG_CHANNEL;
	}
	else if (name == "pubdate") {
		evType = xmlev::END_TAG_PUBDATE;
	}

	XML_Event xmlEv(evType, name); //Creo la clase que debo pasar a runFilter...
	UD->feed->runFilter(xmlEv); //...Y la paso.
	UD->depth--; //Como cerre un tag, disminuyo la profundidad.
}


void characterDataHandler(void * userData, const XML_Char * key, int len) {


	myUserData  * UD = (myUserData *)userData; //Para ser prolijos y no andar casteando.
	std::string charData = ""; //Creo el string

	for (int i = 0; i < len; i++)
		charData += key[i]; //Le agrego char a char. Como no es Null Terminated, nos valemos de la variable len.

	xmlev evType = xmlev::CHARACTER_DATA; //Esto es fijo, pues siempre sera character data si se llama a este handler.

	XML_Event xmlEv(evType, charData);
	UD->feed->runFilter(xmlEv);

}





