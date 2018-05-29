#pragma once


#include <string>

class News
{
public:

	const char * getTitle() { return this->title.c_str(); }
	const char * getDate() { return this->date.c_str(); }
	void updateTitle(const char * s, int length) {
		std::string append;
		for (int i = 0; i < length; i++) {
			append += s[i];
		}
		this->title += append;
	}
	void updateDate(const char * s, int length) {
		std::string append;
		for (int i = 0; i < length; i++) {
			append += s[i];
		}
		this->date += append;
	}
	void createTitle(const char * s, int length) {
		std::string title_;
		for (int i = 0; i < length; i++) {
			title_ += s[i];
		}
		this->title = title_;
	}
	void createDate(const char * s, int length) {
		std::string date_;
		for (int i = 0; i < length; i++) {
			date_ += s[i];
		}
		this->title = date_;
	}
	int getTitleSize() { return this->title.size(); }
	int getDateSize() { return this->date.size(); }

private:
	std::string title;
	std::string date;

};

