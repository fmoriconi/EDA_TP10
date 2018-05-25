#pragma once
#include "XML_Event.h"
typedef void(*fpointer)(void* userData);

enum class state{INIT,
				CH,
				CH_TITLE,
				CH_OTHER,
				ITEM,
				ITEM_TITLE,
				ITEM_PUBDATE,
				ITEM_OTHER,
				IDLE
				};

void rest(void* userData);
void exit(void* userData);
void getSource(void* userData);
void getPubDate(void* userData);
void getTitle(void* userData);

typedef struct{
	state nextState;
	fpointer action;
}FSM_CELL;