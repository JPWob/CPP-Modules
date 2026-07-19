#include "PMerge.hpp"

int main(int argc, char **argv){

    if(argc < 2){
        std::cerr << "Error: No arguments" << std::endl;
    }

    if(!sort_vector(argv, argc - 1)){
        return -1;
    };

    //sort_deque(argv);

}

int sort_vector(char **argv, int argc ){

    std::string number;
    std::vector<int> vector = create_container(char **argv, int argc); //array of integers

    std::vector<int>::const_iterator it;
    for(int i = 0; i < argc; ++i ){
        int num = std::atoi(argv[i]);

        if (num < 0) {
            std::cerr << "Error: Negative numbers are not allowed." << std::endl;
            return -1;
        }

        vector.push_back(num);

}

template <typename container>


void sort_deque(char** argv){

}