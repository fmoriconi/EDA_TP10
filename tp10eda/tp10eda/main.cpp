#include<cstdio>
#include<windows.h>
#include <chrono>
#include <iostream>
#include <string>

#define FTD2XX_EXPORTS
#include "ftd2xx.h"
#include "Hitachi.h"
#include "Feed.h"

//EJEMPLO PARA USAR LA LIBRERIA HITACHI MADE BY GRUPO 3

#define DEFAULT_REFRESH_TIME 100
#define MY_LCD_DESCRIPTION "EDA LCD 3 B"

int main(int argc, char** argv)
{
	if (argc == 2) {

		std::string rss = getRss(argv[1]); ///HACER NETWORKING
		if (rss != "") {
			Feed feed;
			XML xml; ///HACER EXPAT
			xml.parse(feed, rss); ///HACER FSM Y QUE ANDE ESTO
		}
		else {
			std::cout << "Could not load RSS from host: " << argv[1] << std::endl;
			std::cout << "Check if the host is correct, or if you are connected to the internet." << std::endl;
			getchar();
		}
		
		Hitachi hitachi(MY_LCD_DESCRIPTION);
		if (hitachi.lcdInitOk()) {
			Timer refresh(DEFAULT_REFRESH_TIME);
			unsigned i = 0;
			feed.
			
		}
		else {
			std::cout << "Could not load LCD Hitachi: " << MY_LCD_DESCRIPTION << std::endl;
			std::cout << "Check if the LCD description is right, or if the LCD is plugged in." << std::endl;
			getchar();
		}
		return 0;
	}
}