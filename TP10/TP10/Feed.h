#pragma once

#include <deque>

#include "XML_Event.h"
#include "News.h"

const unsigned events = 9;
const unsigned states = 4;

class Feed
{
public:
	Feed();
	~Feed();
	const char* getFeedTitle();
	const News* getNextTitle();
	const News* getPreviousTitle();
	void runFilter(XML_EVENT xml_eventt); //invocada por XML_STARTTAG_HANDLER, XML_ENDTAG_HANDLER y XML_CHARACTERDATA_HANDLER
	void loadInfo(std::string rss);
private:
	std::string source;
	News* currentNews;
	std::deque<News*> news;
	const FSM filter[events][states] = {			/*TABLA*/									}
};

