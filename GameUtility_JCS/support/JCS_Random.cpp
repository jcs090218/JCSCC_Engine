/**
 * $File: JCS_Random.cpp $
 * $Date: 2016-12-10 17:52:01 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../GameUtility_JCS.h"


namespace JCS_GameUtil
{
    std::mt19937 &RandomHelper::GetEngine()
    {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        return engine;
    }
}
