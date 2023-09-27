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

class ptr_counter
{
private:

    int count;

public:

    ptr_counter()
    {
        count = 0;
    }

    int getCount()
    {
        return count;
    }

    void addCount()
    {
        count++;
    }

    void deCount()
    {
        count--;
    }
};

class smart_ptr_toy
{
private:

    Toy* obj;
    ptr_counter* counter;
    
public:

    smart_ptr_toy(std::string inName)
    {
        obj = new Toy(inName);
        counter = new ptr_counter();
        counter->addCount();
    }

    smart_ptr_toy(const smart_ptr_toy& other)
    {
        obj = new Toy(*other.obj);
        counter = other.counter;
        counter->addCount();
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
        counter->deCount();

        if (counter->getCount() == 0)
        {
            delete counter;
            delete obj;
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
    
    
}