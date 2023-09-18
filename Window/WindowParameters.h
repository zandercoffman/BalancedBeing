#pragma once // Include guard to prevent multiple inclusion

class WindowParameters 
{
    public:

        WindowParameters()
        {
            x = width / 1.55;
            y = height / 1.55;
        }
        int returnX() {
            return x; // Set your initial X dimension here
        }

        int returnY() {
            return y; // Set your initial Y dimension here
        }

    private:
        int x;
        int y;
        int width = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);
};
