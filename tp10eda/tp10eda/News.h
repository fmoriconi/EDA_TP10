#pragma once


#include <string>

class News
{
public:

	News();

	char * getTitle();
	char * getDate();
	void updateTitle(char * s, int length);
	void updateDate(char * s, int length);
	void createTitle(char * s, int length);
	void createDate(char * s, int length);
	int getTitleSize();
	int getDateSize();

private:
	std::string title;
	std::string date;

};

