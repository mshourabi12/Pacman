#include <iostream>

using namespace std;

enum MemberType {
    ENEMY = 'E',
    PAC = 'P'
};

class GameMember
{
public:

    enum MemberType memberType;
    uint32_t x = 5;
    uint32_t y = 5;


};

class Frame
{
private:
    uint32_t length = 50;
    uint32_t height = 10;
    uint32_t xStart = 5;
    uint32_t yStart = 2;
    char *framePositions;

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

    uint32_t total_frame_positions()
    {
        return length * height;
    }

    void restart_frame_positions()
    {
        for(auto i = 0; i < this->total_frame_positions(); ++i)
            framePositions[i] = '.';
    }

    void set_frame_position(uint32_t idx, char c)
    {
        framePositions[idx] = c;
    }

    Frame()
    {
        framePositions = (char *) malloc(sizeof(char) * this->total_frame_positions());
        this->restart_frame_positions();
    }

    void draw()
    {
        this->go_to_y_start();
        this->go_to_x_start();

        for (auto i = xStart; i < xStart + length + 1; ++i)
        {
            cout << "#";
        }

        this->go_to_x_start();

        for (auto j = 0; j < height; ++j)
        {
            cout << "#";

            for (auto i = 0; i < length - 1; ++i)
            {
                cout << framePositions[i + (j * length)];
            }

            cout << "#";

            this->go_to_x_start();
        }

        for (auto i = xStart; i < xStart + length + 1; ++i)
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

    GameMember pac;

    pac.memberType = PAC;

    frame.set_frame_position(pac.x, (char) pac.memberType);

    frame.draw();

    return 0;
}