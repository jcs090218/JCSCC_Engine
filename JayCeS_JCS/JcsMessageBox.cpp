#include "JcsMessageBox.h"

#include <SDL_Framework_JCS\SDL\include\SDL.h>


namespace JayCeS
{

#ifdef _WIN32
    // Unicode Character Set
#ifdef _UNICODE 
    int32 JcsMessageBox::JCS_MessageBox(const LPCWSTR title, const LPCWSTR message, uint32 flags)
    {
        return MessageBox(NULL, message, title, flags);
    }
#else
    // ASCII Character Set
    int32 JcsMessageBox::JCS_MessageBox(const LPCSTR title, const LPCSTR message, uint32 flags)
    {
        return MessageBox(NULL, message, title, flags);
    }
#endif // _UNICODE

#elif _OSX

#else   // Linux
    // Cross OS
    int32 JcsMessageBox::JCS_MessageBox(const char* title, const char* message, uint32 flags)
    {
        return SDL_ShowSimpleMessageBox(flags, title, message, NULL);
    }
#endif 
}

