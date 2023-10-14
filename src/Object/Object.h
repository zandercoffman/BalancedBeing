//The object class will store values that extend off of this
//and all items on the screen will have these functions
//EX. An X, Y coordinate system, width and length
//Function to resize it when the program has called to 
class Object 
{
    private:
       int xPosition, yPosition, width, length;
    public:

        Object(int xPosition, int yPosition, int width, int length)
        {
            this->xPosition = xPosition;
            this->yPosition = yPosition;
            this->width = width;
            this->length = length;
        }

        void int setX(int xPosition) {this->xPosition = xPosition;}
        void int setY(int yPosition) {this->yPosition = yPosition;}
        void int setWidth(int width) {this->width = width;}
        void int setLength(int length) {this->length = length;}

        int returnX() {return xPosition;}
        int returnY() {return yPosition;}
        int returnWidth() {return width;}
        int returnLength() {return length;}

        
}