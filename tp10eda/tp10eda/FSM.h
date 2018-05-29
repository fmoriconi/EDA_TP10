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

typedef struct{
	state nextState;
	fpointer action;
}FSM_CELL;

