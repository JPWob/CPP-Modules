#include "Dog.hpp"
#include "Cat.hpp"
//#include "Animal.hpp"
//#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){

    std::cout << "__Declare Animals Array:__" << std::endl;
    Animal** animals = new Animal*[3];
    std::cout << std::endl;

    std::cout << "__Declare Animal:__" << std::endl;
    animals[0] = new Animal;
    std::cout << std::endl;
    
    std::cout << "__Declare Cat:__" << std::endl;
    animals[1] = new Cat;
    std::cout << std::endl;

    std::cout << "__Declare Dog:__" << std::endl;
    animals[2] = new Dog;
    std::cout << std::endl;

    std::cout << "__Getype and Make Sound:__" << std::endl;
    std::cout <<    animals[0]->getType() << " makes ";
                    animals[0]->makeSound();
    std::cout <<    animals[1]->getType() << " makes ";
                    animals[1]->makeSound();
    std::cout <<    animals[2]->getType() << " makes ";
                    animals[2]->makeSound();
    std::cout << std::endl;


    std::cout << "__Destructing__" << std::endl;
    for(int i = 0; i < 3 ; i++){
        delete animals[i];
    }
    delete[] animals;
    std::cout << std::endl;

    std::cout << "__Testing Wrong__" << std::endl;
    WrongAnimal **wrong = new WrongAnimal*[2];
    std::cout << std::endl;
    wrong[0] = new WrongAnimal("Animal");
    wrong[1] = new WrongCat("Cat");
    std::cout << std::endl;

    std::cout << "__Wrong Type and Sound:__" << std::endl;
    std::cout << wrong[0]->getType() << " of WrongAnimal Class makes ";
    wrong[0]->makeSound();
    std::cout << wrong[1]->getType() << " of WrongCatClass makes ";
    wrong[1]->makeSound();
    std::cout << std::endl;

    std::cout << "__Destructing WrongAnimal:__" << std::endl;
    delete wrong[0];
    std::cout << std::endl;
    std::cout << "__Destructing WrongCat:__" << std::endl;
    delete wrong[1];
    std::cout << std::endl;
    delete [] wrong;
}