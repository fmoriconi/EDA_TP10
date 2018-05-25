#include "Feed.h"



Feed::Feed()
{
	this->state = state::INIT;
}


Feed::~Feed()
{
}

void Feed::runFilter(XML_Event xml_event)
{
	this->lastevent = currevent;
	this->currevent = xml_event.getEventType();
	(this->filter[(unsigned)(xml_event.getEventType())][(unsigned)(this->state)]).action(this, xml_event.getData());
	this->state = (this->filter[(unsigned)(xml_event.getEventType())][(unsigned)(this->state)].nextState);
}
