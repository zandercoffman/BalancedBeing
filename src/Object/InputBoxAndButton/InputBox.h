#include <stdio.h>
#include <windows.h>
#include <../Object.h>
#include <string>
#include <../../Window/WindowParameters.h>
#include <InputButtonSubmitter.h>

//Hello everyone
class InputBox: public Object 
{
    public:
        InputButtonSubmitter linkerButton;

        InputBox(int xPos, int yPos, int Width = 300, int Length = 300)
        {
            setX(xPos);
            setY(yPos);

            linkerButton = new InputButtonSubmitter(xPos, yPos);
            setWidth(Width);
            setLength(Length);
        }

        bool canType;
    private:
}