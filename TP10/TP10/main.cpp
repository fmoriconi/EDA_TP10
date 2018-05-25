#include<cstdio>
#include<windows.h>
#include <chrono>
#include <iostream>
#include <string>

#define FTD2XX_EXPORTS
#include "ftd2xx.h"
#include "Hitachi.h"

//EJEMPLO PARA USAR LA LIBRERIA HITACHI MADE BY GRUPO 3

#define MY_LCD_DESCRIPTION "EDA LCD 3 B"

int main(int argc, char** argv)
{
	if (argc == 2) {

		std::string rss = getRss(argv[1]);
		if (rss != "") {
			Feed feed;
			feed.loadInfo(rss); //aca esta expat y fsm
		}
		else {
			std::cout << "Could not load RSS from host: " << argv[1] << std::endl;
			std::cout << "Check if the host is correct, or if you are connected to the internet." << std::endl;
			getchar();
		}
		Hitachi hitachi(MY_LCD_DESCRIPTION);
		if (hitachi.lcdInitOk()) {
			hitachi.show(); //aca mostramos las cosas
		}
		else {
			std::cout << "Could not load LCD Hitachi: " << MY_LCD_DESCRIPTION << std::endl;
			std::cout << "Check if the LCD description is right, or if the LCD is plugged in." << std::endl;
			getchar();
		}
		return 0;
	}
}


//char ch = NULL;
//while ( (ch = getchar() ) != '}') //Esto es un teclado con el cual podemos probar el display char a char. Con { se limpia la pantalla y con } se cierra el programa.
//{
//	if(ch != '\n')
//		hitachi << ch;

//	if (ch == '{')
//		hitachi.lcdClear();
//}