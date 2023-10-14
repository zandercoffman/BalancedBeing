#include <windows.h>
class CustomizationParameters
{
    public:
        bool checkForDarkMode()
        {
            //DETECTS FOR DARK MODE
            // Get the current system mode.
            WORD systemMode = GetSystemMetrics(SM_CMONITORS);

            // Check if the current system mode is dark mode.
            if (systemMode == SM_MODE_DARK) {
                return true;
            } else {
                return false;
            }
        }
}