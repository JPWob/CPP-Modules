#include "Dog.hpp"
#include "Cat.hpp"

int main(){

	Dog dogA;
    dogA.getBrain()->setIdea(0, "I love bones");

    Dog dogB = dogA; // Calls Copy Constructor -> which calls Brain operator=

    std::cout << "DogA idea: " << dogA.getBrain()->getIdea(0) << std::endl;
    std::cout << "DogB idea: " << dogB.getBrain()->getIdea(0) << std::endl;

    dogA.getBrain()->setIdea(0, "I love squirrels");

    std::cout << "--- After changing DogA ---" << std::endl;
    std::cout << "DogA idea: " << dogA.getBrain()->getIdea(0) << std::endl;
    std::cout << "DogB idea: " << dogB.getBrain()->getIdea(0) << " (Should still be bones!)" << std::endl;

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
        std::cout << std::endl;
    }
    delete[] animals;
    std::cout << std::endl;

    std::cout << "__Testing the Copy Construcr " << std::endl;
    std::cout << "1. Create Original Cat" << std::endl;
    Cat cat_ori;
    cat_ori.getBrain()->setIdea(0, "I am the Original Cat");
    std::cout << std::endl;

    std::cout << "2. Create Copy of Original Cat (Cat cat_cpy(cat_ori))" << std::endl;
    Cat cat_cpy(cat_ori);
    std::cout << std::endl;

    std::cout << "3. Print &idea[0] and idea[0] of original and copy " << std::endl;
    std::cout << "Original Cat Idea[0]\t:" << &cat_ori.getBrain()->getIdea(0) << " : "<< cat_ori.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat Idea[0]\t:" << &cat_cpy.getBrain()->getIdea(0) << " : "<< cat_cpy.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "4. Change idea[0] in the cpy and make sure original idea[0] stays the same" << std::endl;
    cat_cpy.getBrain()->setIdea(0, ". I am the Copy Cat");
    std::cout << "Original Cat  Idea[0]\t:" << &cat_ori.getBrain()->getIdea(0) << cat_ori.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat Idea[0]\t:" << &cat_cpy.getBrain()->getIdea(0) << cat_cpy.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "__Testing the Assigmnet Operator. OriginalCat = CopyCat" << std::endl;
    cat_ori = cat_cpy;
    std::cout << std::endl;
    std::cout << "Original Cat  Idea[0]\t:" << &cat_ori.getBrain()->getIdea(0) << cat_ori.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat Idea[0]\t:" << &cat_cpy.getBrain()->getIdea(0) << cat_cpy.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    //delete cat_cpy.getBrain();
    //delete cat_ori.getBrain();

}