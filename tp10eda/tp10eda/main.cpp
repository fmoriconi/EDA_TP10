#include<cstdio>
#include<windows.h>
#include <chrono>
#include <iostream>
#include <string>

#define FTD2XX_EXPORTS
#include "ftd2xx.h"
#include "Hitachi.h"
#include "curses.h"
#include "Feed.h"

//EJEMPLO PARA USAR LA LIBRERIA HITACHI MADE BY GRUPO 3

#define DEFAULT_REFRESH_TIME 100
#define MY_LCD_DESCRIPTION "EDA LCD 3 B"

void welcomeMsg(unsigned&, WINDOW*, char**);
void error1(unsigned&, std::string);
void error2(unsigned&);

int main(int argc, char** argv)
{
	if (argc == 2) {

		WINDOW* display = NULL;

		if ((display = initscr()) != NULL)
		{
			unsigned lineNumber = 0;
			welcomeMsg(lineNumber, display, argv);

			//std::string rss = getRss(argv[1]); ///HACER NETWORKING
			//if (rss != "") {
			//mvprintw(lineNumber++, 0, "Presione R para repetir noticia, S para saltar noticia, A para ver la noticia anterior");
			//mvprintw(lineNumber++, 0, "Q para salir, + o - para aumentar o disminuir la velocidad.");
			//lineNumber++;
			//	Feed feed;
			//	XML xml; ///HACER EXPAT
			//	xml.parse(feed, rss); ///HACER FSM Y QUE ANDE ESTO
			//}
			//else {
				std::string host = argv[1];
				error1(lineNumber, host);
			//}

			Hitachi hitachi(MY_LCD_DESCRIPTION);
			if (hitachi.lcdInitOk()) {
				Timer refresh(DEFAULT_REFRESH_TIME);
				unsigned i = 0;
				

			}
			else {
				error2(lineNumber);
			}
			endwin();
		}
	}
	return 0;
}

void welcomeMsg(unsigned& lineNumber, WINDOW* display, char** argv) {
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	color_set(1, NULL);

	immedok(display, true);
	noecho();
	clear();
	std::string welcomemsg = "Se estan recopilando las ultimas noticias de ";
	std::string host = argv[1];
	mvprintw(lineNumber, 0, (welcomemsg).c_str());
	color_set(2, NULL);
	mvprintw(lineNumber++, welcomemsg.size(), (host).c_str());
	color_set(1, NULL);
	lineNumber++;
}

void error1(unsigned& lineNumber, std::string host) {
	color_set(2, NULL);
	std::string loaderr1 = "Could not load RSS from host: ";
	std::string loaderr2 = "Check if the host is correct, or if you are connected to the internet.";
	std::string loaderr3 = "Press any key to continue..";
	mvprintw(lineNumber++, 0, (loaderr1 + host).c_str());
	color_set(1, NULL);
	mvprintw(lineNumber++, 0, (loaderr2).c_str());
	mvprintw(lineNumber++, 0, loaderr3.c_str());
	lineNumber++;
	getchar();
}

void error2(unsigned& lineNumber) {
	color_set(2, NULL);
	std::string hiterror1 = "Could not load LCD Hitachi: ";
	std::string hiterror2 = "Check if the LCD description is right, or if the LCD is plugged in.";
	std::string hiterror3 = "Press any key to continue..";
	mvprintw(lineNumber, 0, hiterror1.c_str());
	mvprintw(lineNumber++, hiterror1.size(), MY_LCD_DESCRIPTION);
	color_set(1, NULL);
	mvprintw(lineNumber++, 0, hiterror2.c_str());
	mvprintw(lineNumber++, 0, hiterror3.c_str());
	getchar();
}