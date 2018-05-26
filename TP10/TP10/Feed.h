#pragma once

#include <vector>

#include "XML_Event.h"
#include "News.h"
#include "FSM.h"

const unsigned events = 11;
const unsigned states = 8;

class Feed
{
public:
	Feed();
	~Feed();
	const std::string getFeedTitle() { return this->source; }
	const News* getNextTitle() { newsindex++; return (news[newsindex]); }
	const News* getPreviousTitle() { newsindex--; return (news[newsindex]); }

	void runFilter(XML_Event xml_event); //invocada por XML_STARTTAG_HANDLER, XML_ENDTAG_HANDLER y XML_CHARACTERDATA_HANDLER

private:
	std::string source;
	News* currentNews;
	unsigned newsindex = 0;
	News auxnews;
	std::vector<News*> news;
	const FSM_CELL filter[events][states] = {//INIT						//CH						//CH_TITLE						//CH_OTHER					//ITEM							//ITEM_OTHER					//ITEM_TITLE						//ITEM_PUBDATE
						/*CH tag*/			{ { state::CH, &rest },		{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*title tag*/		{ { state::INIT, &rest },	{ state::CH_TITLE, &rest },	{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM_TITLE, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*item tag*/		{ { state::INIT, &rest },	{ state::ITEM, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*pubdate tag*/		{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM_PUBDATE, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*other tag*/		{ { state::INIT, &rest },	{ state::CH_OTHER, &rest },	{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*CH endtag*/		{ { state::INIT, &rest },	{ state::INIT, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*title endtag*/	{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH, &rest },		    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM, &rest },				{ state::ITEM_PUBDATE, &rest },},
						/*item endtag*/		{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::CH, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*pubdate endtag*/	{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &rest },		{ state::ITEM, &rest },		   },
						/*other endtag*/	{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &rest },	    { state::CH, &rest },		{ state::ITEM, &rest },			{ state::ITEM, &rest },			{ state::ITEM_TITLE, &rest },		{ state::ITEM_PUBDATE, &rest },},
						/*char data*/		{ { state::INIT, &rest },	{ state::CH, &rest },		{ state::CH_TITLE, &getSource },{ state::CH_OTHER, &rest },	{ state::ITEM, &rest },			{ state::ITEM_OTHER, &rest },	{ state::ITEM_TITLE, &getTitle },	{ state::ITEM_PUBDATE,&getPubDate },}
											};
	state state;
	xmlev lastevent;
	xmlev currevent;
};

