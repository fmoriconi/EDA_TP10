#pragma once
#include <string>

typedef void(*fpointer)(void* ud, std::string data);

enum class state{INIT,
				CH,
				CH_TITLE,
				CH_OTHER,
				ITEM,
				ITEM_TITLE,
				ITEM_PUBDATE,
				ITEM_OTHER,
				};

void rest(void* ud, std::string data);
void getSource(void* ud, std::string data);
void getPubDate(void* ud, std::string data);
void getTitle(void* ud, std::string data);

typedef struct{
	state nextState;
	fpointer action;
}FSM_CELL;

void rest(void* ud, std::string data) {

}

void getSource(void* ud, std::string data) {
	
}

void getPubDate(void* ud, std::string data) {

}

void getTitle(void* ud, std::string data) {

}