#include <stdio.h>
#include <windows.h>
#include <../Object.h>
#include <string>
#include <../../Window/WindowParameters.h>

class InputButtonSubmitter : public Object
{
    public:

        int inputbox_xPos, inputbox_yPos;
        InputButtonSubmitter(int inputbox_xPos, int inputbox_yPos)
        {
            this->inputbox_xPos = inputbox_xPos;
            this->inputbox_yPos = inputbox_yPos;
        }
    private:
}