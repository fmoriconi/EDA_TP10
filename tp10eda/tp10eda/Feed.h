#pragma once

#include <deque>

#include "XML_Event.h"
#include "News.h"
#include "FSM.h"

const unsigned events = 11;
const unsigned states = 9;

class Feed
{
public:
	Feed();
	~Feed();
	const char* getFeedTitle();
	const News* getNextTitle();
	const News* getPreviousTitle();
	void runFilter(XML_Event xml_event); //invocada por XML_STARTTAG_HANDLER, XML_ENDTAG_HANDLER y XML_CHARACTERDATA_HANDLER
	void loadInfo(std::string rss);
private:
	std::string source;
	News* currentNews;
	std::deque<News*> news;
	const FSM_CELL filter[events][states] = {//INIT						//CH						//CH_TITLE						//CH_OTHER					//ITEM							//ITEM_OTHER					//ITEM_TITLE						//ITEM_PUBDATE						//ITEM_OTHER
						/*CH tag*/			{ { state::CH, &rest },		{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*title tag*/		{ { state::INIT, &rest },	{ state::CH_TITLE, &rest },	{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM_TITLE, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*item tag*/		{ { state::INIT, &rest },	{ state::ITEM, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*pubdate tag*/		{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM_PUBDATE, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*other tag*/		{ { state::INIT, &rest },	{ state::CH_OTHER, &rest },	{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*CH endtag*/		{ { state::INIT, &rest },	{ state::INIT, &exit },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*title endtag*/	{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH, &rest },		    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM, &rest },				{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*item endtag*/		{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::CH, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM_OTHER, &rest },},
						/*pubdate endtag*/	{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM, &rest },				{ state::ITEM_OTHER, &rest },},
						/*other endtag*/	{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM, &rest },			{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },		{ state::ITEM, &rest },		 },
						/*char data*/		{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &getSource },{ state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &getTitle },	{ state::ITEM_PUBDATE,&getPubDate },{ state::ITEM_OTHER, &rest },}
											};
};

