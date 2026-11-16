#include "PMerge.hpp"


struct Item{
    unsigned int value;
    unsigned int id;

    Item(unsigned int n, unsigned int id ) : value(n), id(id){};

    bool operator>(const Item& b) const{
        return(this->value > b.value);
    }

    bool operator<(const Item& b) const{
        return(this->value < b.value);
    }

    bool operator==(const Item& b) const{
        return(this->id == b.id);
    }
};


struct Pair{
    Item winner;
    Item loser;

    Pair(const Item& w, const Item& l) : winner(w), loser(l) {};

};

std::vector<Item>  sort_vector(std::vector<Item>& vec);

int main(int argc, char **argv){

    if(argc < 2){
        std::cerr << "Error: No arguments" << std::endl;
    }
    std::vector<Item>    vec_initial_chain;
    std::deque<Item>     deq_initial_chain;
    
    vec_initial_chain.reserve(argc - 1);


    for(int i = 1; i < argc; ++i ){
        int num = std::atoi(argv[i]);

        if (num < 0) {
            std::cerr << "Error: Negative numbers are not allowed." << std::endl;
            return -1;
        }
        vec_initial_chain.push_back(Item(num, i)); // I give Every Item an ID, to be able to handle duplicate values
        //deq_initial_chain.push_back(Item(num, i));
    }
    
    std::vector<Item> sorted = sort_vector(vec_initial_chain);
    //(void)deq;

    for(int i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i].value << " ";

    std::cout << std::endl;
}

Pair find_loser(Item& winner, const std::vector<Pair>& lookup){

    for(size_t i = 0; i < lookup.size(); ++i){
        if(lookup[i].winner == winner) // compares IDs only, thats what matters
            return lookup[i];
    }
    std::cout << "STH went wrong. Every Winner should be in lookup"<< std::endl;
    return lookup[0];

}

std::vector<Item> sort_vector(std::vector<Item>& chain){

    size_t size = chain.size();
    
    if(size == 1)
        return (chain); // returns the first sorted version of main, not the winner

    bool has_straggler = false;
    Item straggler(0,0);
    if((size %2) != 0){
        has_straggler = true;
        straggler = chain.back(); // .back() equal to [size - 1]
        chain.pop_back(); 
        size = chain.size();
    }
    //size is guaranteed to be even now

    std::vector<Item> winners;
    winners.reserve(size/2);

    std::vector<Pair> lookup;
    lookup.reserve((size/2) + has_straggler);

    for(int i = 0; i < size ; i += 2){
        if (chain[i] > chain[i+1]) {
            winners.push_back(chain[i]);            //This is only the Winners for sending them down
            lookup.push_back(Pair(chain[i], chain[i+1])); // This is for when rec unwinds, to lookup Losers that belong to the elements in sorted main chain
        } else {
            winners.push_back(chain[i+1]);
            lookup.push_back(Pair(chain[i+1],chain[i]));
        }
    }

    std::cout << "Winners: ";
    for(int i = 0; i < winners.size(); ++i)
        std::cout << winners[i].value << " ";

    std::cout << std::endl;
    std::vector<Item> main;
    main = sort_vector(winners); // 5 //2 //1 returns
    main.reserve(size + has_straggler); // give more space in advance

    std::vector<Pair> pend;
    pend.reserve(size/2 + has_straggler);

    // create a pend of losers that mirros the order of main chain
    // main.size() is size/2
    for(size_t i = 0; i < main.size(); ++i){ 
        pend.push_back(find_loser(main[i], lookup)); 
    }

    //Insert Straggler at the end of pend
    if(has_straggler)
        pend.insert(pend.end(), Pair(Item(0,0), straggler)); //append
   
    //number of elements to insert into main
    int pend_size = static_cast<int>(pend.size());
    if (pend_size == 0)
        return main;
    
    //  adding b1 at the beginning of main
    main.insert(main.begin(), pend[0].loser); //adding b1 at the beginning of main

    // int n = 3;   // starting with the first non trivial J Number + 1 because first element of loser was already inserted
    // batch indexes are defined [j_next, j_curr]
    int j_min = 1;
    int j_prev = 1;  // 

    // While loops is for going through batches
    while(j_min < pend_size ){ // pendsize could be 5, so 6 elements. batch 11 to 5 (j_min) would be ok
        //if(pend_size == 0) //nothing more to insert back into main
           //return main;

        // Calculate J index bounds: (3 to 1), (5 to 3), (11 to 5) .... 
        // (3 to 1) means start at pend element 3 which is pend[2]. "to 1" means not to include 1 (pend[0])
        // instead it means 3 - 1 = batch size 2, starting with pend[2]. So (3 to 1) means, insert pend[2] and pend[1]

        // J = [0, 1, 1, 3, 5, 11, 21, ...]
        // n = [0, 1, 2, 3, 4,  5,  6, ...]

        // Calculate upper bound j_max
        // Insertion order: j_max -> j_min
        int j_max = j_min + 2 * j_prev;     // Calculate upper bound
        
        
        // substract 1 from each bound to adjust 0 indexing of pen
        // meaning to get b3 i need pend[2]
        int start = j_max - 1; 
        int end = j_min - 1; 
        
        // maybe pend[j_max - 1] is out of bounds. like b11 but only b8 elements in pend. Adjust start to max element size if needed
        if((start > pend_size - 1))   // total elements start counting with 1
            start = pend_size - 1;   

        // ensures inserting backwards.
        // For loop is for inserting elements of one batch
        for(int i = start; i > end; --i){    //I want to insert b3 first, which is pend[2]. I need to know the upper bound of b3 which is but b3 is a straggler
            
            std::vector<Item>::iterator winner_pos;
            if (has_straggler && i == pend_size -1 ) {
                winner_pos = main.end();
            }else{
                winner_pos = std::find(main.begin(), main.end(), pend[i].winner);   //find pos of winner in main, get it index
            }

            // find out correct pos for loser to be inserted
            std::vector<Item>::iterator insert_pos = std::lower_bound(main.begin(), winner_pos, pend[i].loser);

            main.insert(insert_pos, pend[i].loser);
        }

        //prepare this for next iteration to calculate j_max correctly
        j_prev = j_min;
        j_min  = j_max;

    }

    return main;

}


// void sort_deque(char** argv){

// }