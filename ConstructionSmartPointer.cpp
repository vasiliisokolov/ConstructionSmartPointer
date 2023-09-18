#include <iostream>

class Toy {

private:

    std::string name;

public:

    Toy(const std::string& inName)
    {
        name = inName;
    }

    std::string getName()
    {
        return name;
    }

    ~Toy()
    {
        std::cout << "Toy " << name << " was dropped " << std::endl;
    }

};

class smart_ptr_toy
{
private:

    Toy* obj;
    int useCount;

public:

    smart_ptr_toy(std::string inName)
    {
        obj = new Toy(inName);
        useCount++;
    }

    smart_ptr_toy(const smart_ptr_toy& other)
    {
        obj = new Toy(*other.obj);
    }

    smart_ptr_toy& operator=(const smart_ptr_toy& other)
    {
        if (this == &other)
            return *this;
        if (obj != nullptr)
            delete obj;
        obj = new Toy(*other.obj);
        return *this;
    }

    ~smart_ptr_toy()
    {
        if (useCount == 0)
        {
            delete obj;
        }
        else
        {
            useCount--;
        }
    }
};

class Dog
{
private:
    std::string name;
    int age;
    smart_ptr_toy lovelyToy;

public:

    Dog(std::string inName, std::string toyName, int inAge) : name(inName), lovelyToy(toyName)
    {
        if (inAge > 0 && inAge < 30)
            age = inAge;
        else age = 30;
        
    }

    Dog() : Dog("Beethoven", "SomeToy", 1) {};
    Dog(std::string inName) : Dog(inName, "SomeToy", 1) {};
    Dog(int inAge) : Dog("Beethoven", "SomeToy", inAge) {};

    
};

int main()
{
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

    std::shared_ptr<Dog> b = std::make_shared<Dog>();
    std::shared_ptr<Dog> k = std::make_shared<Dog>("Korgi");
    
}