/**
 * $File: ProgramMain.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#define _JCSVLD
#include <JayCeS_JCS\JayCeS_StdAfx.h>

using namespace std;

#include "JayCeS_OS.h"


int main(int argc, char** argv)
{
    JayCeS_OS os;
    os.Run();

    // ---------------
    cin.get();
    return 0;
}

