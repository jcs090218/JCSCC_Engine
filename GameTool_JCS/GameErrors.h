#ifndef __GAMEERRORS_H__
#define __GAMEERRORS_H__

#include <string>
#include <JayCeS_JCS\JayCeS.h>

namespace JCS_GameTool
{
    //------------------------------------------------------------------------------------
    // Name : GameError 
    //
    // Desc : This code is slow, using dynamic memory, but since we only use them
    //        when something Really Bad happens, the user won't notice that their
    //        application exits abmornally a few nanoseconds slower than usual
    //------------------------------------------------------------------------------------
    class GameError
    {
    private:
        std::wstring m_errorText;

    public:
        GameError(const TCHAR* errorText)
        {
            JCS_Print1(L"***\n*** [ERROR] GameError thrown! text: [%s]\n***\n", errorText);
            m_errorText = std::wstring(errorText);
        }

        // getter
        const TCHAR* getText()
        {
            return m_errorText.c_str();
        }
    };

    //==========--------------------------  

    enum eResult
    {
        resAllGood = 0,                 // function passed with flying colors
        resFalse = 1,                   // function worked and returns value 'false'
        resFailed = -1,                 // function failed miserably
        resNotImpl = -2,                // function has not been implemented
        resForceDWord = 0x7FFFFFFF
    };

    inline bool Succeeded(eResult in)
    {
        if (in >= 0)
            return true;
        return false;
    }

    inline bool Failed(eResult in)
    {
        if (in < 0)
            return true;
        return false;
    }
}

typedef JCS_GameTool::GameError GameError;

#endif // __GAMEERRORS_H__

