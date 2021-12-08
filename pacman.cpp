#include <iostream>

using namespace std;

class Frame
{
private:
    uint32_t length = 50;
    uint32_t height = 10;
    uint32_t xStart = 5;
    uint32_t yStart = 2;

public:
    void go_to_x_start()
    {
        cout << endl;
        for (auto i = 0; i < xStart; ++i)
            cout << ' ';
    }

    void go_to_y_start()
    {
        for (auto i = 0; i < yStart; ++i)
        {
            cout << endl;
        }
    }

    void draw()
    {
        this->go_to_y_start();
        this->go_to_x_start();

        for (auto i = xStart; i < xStart + length; ++i)
        {
            cout << "#";
        }

        this->go_to_x_start();

        for (auto j = 0; j < height; ++j)
        {
            cout << "#";

            for (auto i = xStart + 1; i < xStart + length - 1; ++i)
            {
                cout << ".";
            }

            cout << "#";

            this->go_to_x_start();
        }

        for (auto i = xStart; i < xStart + length; ++i)
        {
            cout << "#";
        }
    }

    uint32_t getLength()
    {
        return length;
    }
    uint32_t getHeight()
    {
        return height;
    }
};

int main()
{
    Frame frame;

    frame.draw();

    return 0;
}