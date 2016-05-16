//http://zh.wikipedia.org/wiki/虚函数_(程序语言)
# include <iostream>
# include <vector>
 
using namespace std;
class Animal
{
public:
    virtual void eat() const { cout << "I eat like a generic Animal." << endl; }
    virtual ~Animal() {}
};
 
class Wolf : public Animal
{
public:
    void eat() const { cout << "I eat like a wolf!" << endl; }
};
 
class Fish : public Animal
{
public:
    void eat() const { cout << "I eat like a fish!" << endl; }
};
 
class GoldFish : public Fish
{
public:
    void eat() const { cout << "I eat like a goldfish!" << endl; }
};
 
 
class OtherAnimal : public Animal
{
};
 
int main()
{
    std::vector<Animal*> animals;
    animals.push_back( new Animal() );
    animals.push_back( new Wolf() );
    animals.push_back( new Fish() );
    animals.push_back( new GoldFish() );
    animals.push_back( new OtherAnimal() );
 
    for( std::vector<Animal*>::const_iterator it = animals.begin();
       it != animals.end(); ++it) 
    {
        (*it)->eat();
        delete *it;
    }
 
   return 0;
}
