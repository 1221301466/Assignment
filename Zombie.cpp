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

Zombie::Zombie()
{
}
void Zombie::land(Mars &mars)
{
    x_ = rand() % mars.getDimX() + 1;
    y_ = rand() % mars.getDimY() + 1;
    mars.setObject(x_, y_, '1');
}
int Zombie::getX() const
{
    return x_;
}
int Zombie::getY() const
{
    return y_;
}

void Zombie::turnLeft(Mars &mars)
{
    mars.setObject(x_, y_, ' '); // clear current position
    if (mars.isInsideMap(x_, y_+1)) {
        y_++;
    } else {
        y_ = 1;
    }
    mars.setObject(x_, y_, '1'); // set new position
}

void Zombie::turnRight(Mars &mars)
{
    mars.setObject(x_, y_, ' '); // clear current position
    if (mars.isInsideMap(x_, y_-1)) {
        y_--;
    } else {
        y_ = mars.getDimY();
    }
    mars.setObject(x_, y_, '1'); // set new position
}

void Zombie::move(Mars &mars)
{
    mars.setObject(x_, y_, ' '); // clear current position
    if (mars.isInsideMap(x_+1, y_)) {
        x_++;
    } else {
        x_ = 1;
    }
    mars.setObject(x_, y_, '1'); // set new position
}
