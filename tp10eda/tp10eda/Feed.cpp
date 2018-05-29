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

void rest(void* ud, std::string data) {

}

void getSource(void* ud, std::string data) {
	Feed* feed = (Feed*)ud;
	feed->setSource(data);
}

void getPubDate(void* ud, std::string data) {
	Feed* feed = (Feed*)ud;
	feed->createDate(data);
}

void getTitle(void* ud, std::string data) {
	Feed* feed = (Feed*)ud;
	feed->createTitle(data);
}

void createNews(void* ud, std::string data) {
	Feed* feed = (Feed*)ud;
	feed->createNewNews();
}

void pushbackNews(void* ud, std::string data) {
	Feed* feed = (Feed*)ud;
	feed->pushCurrentNews();
}