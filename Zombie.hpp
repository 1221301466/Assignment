
class Zombie
{
private:
    int x_, y_;
public:
    Zombie();
    void land(Mars &mars);
    int getX() const;
    int getY() const;
    void move(Mars &mars);
    void turnRight(Mars &mars);
    void turnLeft(Mars &mars);
};

