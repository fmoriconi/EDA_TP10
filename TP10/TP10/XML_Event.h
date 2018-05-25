#pragma once

#include <string>

enum class xml_event_type {
	START_TAG_CHANNEL,
	START_TAG_TITLE,
	START_TAG_PUBDATE,
	START_TAG_OTHER,

	END_TAG_CHANNEL,
	END_TAG_TITLE,
	END_TAG_PUBDATE,
	END_TAG_OTHER,

	CHARACTER_DATA
};

class XML_Event
{
public:
	XML_Event(xml_event_type event_type_, std::string data_) : event_type(event_type_), data(data_) {}
	~XML_Event();
	std::string getData() { return this->data; }
	xml_event_type getEventType() { return this->event_type; }
private:
	xml_event_type event_type;
	std::string data;
};

