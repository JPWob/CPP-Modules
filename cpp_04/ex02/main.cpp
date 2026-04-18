#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // 1. Test Instantiation (This would cause a compiler error)
    // AAnimal* test = new AAnimal(); 


    std::cout << "--- Creating a Dog and a Cat ---" << std::endl;
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    std::cout << "\n--- Testing Types and Sounds ---" << std::endl;
    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    
    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I want a treat");
    
    Dog copyDog = originalDog;
    originalDog.getBrain()->setIdea(0, "I want to sleep");

    std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog Idea 0: " << copyDog.getBrain()->getIdea(0) << " (Deep copy check!)" << std::endl;

    std::cout << "\n--- Cleaning Up ---" << std::endl;
    delete dog;
    delete cat;

    return 0;
}