#pragma once

#include <string>

enum class xmlev {
	START_TAG_CHANNEL,
	START_TAG_ITEM,
	START_TAG_TITLE,
	START_TAG_PUBDATE,
	START_TAG_OTHER,

	END_TAG_CHANNEL,
	END_TAG_ITEM,
	END_TAG_TITLE,
	END_TAG_PUBDATE,
	END_TAG_OTHER,

	CHARACTER_DATA
};

class XML_Event
{
public:
	XML_Event(xmlev event_type_, std::string data_) : event_type(event_type_), data(data_) {}
	std::string getData() { return this->data; }
	xmlev getEventType() { return this->event_type; }

private:
	xmlev event_type;
	std::string data;
};

