#include "JCS_FileDialogs.h"


namespace JayCeS
{
    JCS_FileDialog::JCS_FileDialog()
    {

    }

    JCS_FileDialog::~JCS_FileDialog()
    {
        
    }

#ifdef _WIN32

#ifdef _UNICODE
    bool JCS_FileDialog::OpenFileDialog(
        const HWND hWnd,
        const LPCWSTR title,
        const LPCWSTR filter,
        const LPCWSTR extension)
    {
        OPENFILENAME ofn;

        // initialize the dynamic memory before we reuse it again
        ZeroMemory(&ofn, sizeof(ofn));

        // Initialize OPENFILENAME
        ofn.lStructSize = sizeof(ofn);
        ofn.lpstrFile = fileName;
        // Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
        // use the contents of szFile to initialize itself.
        ofn.lpstrFile[0] = '\0';
        ofn.hwndOwner = hWnd;
        ofn.lpstrTitle = title;
        ofn.lpstrFilter = filter;
        ofn.lpstrDefExt = extension;
        ofn.nMaxFile = sizeof(fileName);
        ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;

        /** Display the Open dialog box. **/

        if (GetOpenFileName(&ofn))
        {
            JCS_Print1(L"\n\nLoading File:\t%s\n\n", fileName);
            return true;
        }

        JCS_Error(L"[Cancelled] or [Failed] to load the file...");
        return false;
    }
#else
    bool OpenFileDialog(const HWND hWnd, const LPCSTR title,
        const LPCSTR filter, const LPCSTR extension)
    {
        OPENFILENAME ofn;
        char szFileName[MAX_PATH] = "";

        ZeroMemory(&ofn, sizeof(ofn));

        ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
        ofn.hwndOwner = hWnd;
        ofn.lpstrTitle = title;
        ofn.lpstrFilter = filter;
        ofn.lpstrDefExt = extension;
        ofn.lpstrFile = szFileName;
        ofn.nMaxFile = MAX_PATH;
        ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;

        if (GetOpenFileName(&ofn))
        {
            DP1("\n\nLoading File:\t%s\n\n", szFileName);
            return true;
        }

        JCS_Error("[Cancelled] or [Failed] to load the file...");
        return false;
    }

#endif
#endif // _WIN32

}

