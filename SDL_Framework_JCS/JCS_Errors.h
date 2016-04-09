/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_ERRORS_H__
#define __JCS_ERRORS_H__

#include <iostream>

#include "SDL_StdAfx.h"
#include "SDL\include\SDL.h"

namespace JCS_SDL_Engine
{
	//Prints out an error message and exits the game
	inline void fatalError(std::string errorString) 
    {
		std::cout << errorString << std::endl;
		std::cout << "Enter any key to quit...";
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(69);
	}
}

#endif // __ERRORS_H__

