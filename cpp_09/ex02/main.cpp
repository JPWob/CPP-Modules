#include "PmergeMe.hpp"


struct Item{
    unsigned int id;
    unsigned int value;

    static size_t comparisons; // Shared counter across all Item comparisons

    Item(unsigned int n = 0, unsigned int id = 0) :  id(id), value(n){};

    bool operator>(const Item& b) const{
        comparisons++;
        return(this->value > b.value);

    }

    bool operator<(const Item& b) const{
        comparisons++;  
        return(this->value < b.value);
    }

    bool operator==(const Item& b) const{
        comparisons++;
        return(this->id == b.id);
    }
};


struct Pair{
    unsigned int winner_id;
    unsigned int loser_id;

    Pair(const unsigned int w, const unsigned int l) : winner_id(w), loser_id(l) {};

};

size_t Item::comparisons = 0;
std::vector<Item>  sort_vector(std::vector<Item>& vec, int argc);

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
        vec_initial_chain.push_back(Item(num, i - 1)); // I give Every Item an ID, to be able to handle duplicate values
        //deq_initial_chain.push_back(Item(num, i));
    }
    
    std::vector<Item> sorted = sort_vector(vec_initial_chain, argc);
    //(void)deq;


    for(size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i].value << " ";

    std::cout << std::endl;

    std::cout << "Number of comparisons: " << Item::comparisons << std::endl;
}


std::vector<Item> sort_vector(std::vector<Item>& chain, int N){

    size_t size = chain.size();
    
    if(size == 1){
        return (chain); // returns the first sorted version of main, not the winner
    }

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

    std::vector<Item> lookup(N);   //losers will get the ID of the winner they lost to. Index can be huge, if Winner ID is 1000, then lookup[1000] = loser. So lookup needs to be size N, because the ID of the winner can be as big as N-1.

    for(size_t i = 0; i < size ; i += 2){
        if (chain[i] > chain[i+1]) {
            winners.push_back(chain[i]);      //This is only the Winners for sending them down
            lookup[chain[i].id] = chain[i+1]; // This is Winner.ID - Loser Pair, for when rec unwinds, to lookup Losers that belong to the elements in sorted main chain
        } else {
            winners.push_back(chain[i+1]);
            lookup[chain[i+1].id] = chain[i];
        }
    }

// std::cout << winners.size() << std::endl;
// //just for testing
// std::cout << "Winners: ";
// for(int i = 0; i < winners.size(); ++i)
//     std::cout << winners[i].value << " ";
// std::cout << std::endl;
// std::cout << "End of printing winners" << std::endl;

// std::cout << "Losers: ";
// for (size_t i = 0; i < winners.size(); ++i) {
//     std::cout << lookup[winners[i].id].value << " ";
// }
// std::cout << std::endl;

    //declare main chain
    std::vector<Item> main;
    
    //Unwidning the recursion, main chain is the sorted version of winners
    main = sort_vector(winners, N); // 5 //2 //1 returns
    main.reserve(size + has_straggler); // give more space in advance


    // declare pend chain
    std::vector<Item> pend;
    pend.reserve(size/2 + has_straggler);

    // fill pend chain
    for(size_t i = 0; i < main.size(); ++i){ 
        pend.push_back(lookup[main[i].id]); 
    }
    
    // 1. Insert Straggler at pend.end()
    if(has_straggler)
        pend.insert(pend.end(), straggler); //append
    
    // number of elements to insert into main
    int pend_size = static_cast<int>(pend.size());
    if(pend_size == 0)
        return main;

    std::cout << "Pend: ";
    
    // 2. Inserting b1 at main.begin()
    // insert pend[0] meaning b1 at the beginning of main (b1,a1,...)
    main.insert(main.begin(), pend[0]); //adding b1 at the beginning of main
    
    if(pend_size == 0) //nothing more to insert back into main
        return main;

    // 3. Start tracking index offset
    // Because b1 was just inserted at index 0, every winner of pend[i] is now at index (i + 1).
    // Winner of pend[0] is now main[1]. Winner of pend[1] is now main[2] ....
    std::vector<size_t> winner_idx(pend.size());
    for (size_t i = 0; i < pend.size(); ++i) {
        winner_idx[i] = i; 
    }

    /* 
        Define the two Jacobsthal numbers, to start the loop at batch 3 to 1.
        J = [0, 1, 1, 3, 5, 11, 21, ...]
        n = [0, 1, 2, 3, 4,  5,  6, ...]
    */
    int j_min = 1;   // this is Jacobsthal[2] = 1, the first non trivial Jacobsthal number. It is the lower bound of the first batch. 
    int j_prev = 1;  // this is Jacobsthal[1] = 1, the previous Jacobsthal number. It was basically used above to insert b1

    // 4. Start inserting the rest of the pend elements in batches defined by Jacobsthal numbers
    while(j_min < pend_size ){ // pend.size() could be 5 (6 losers). Then j_min = 5 (batch 11 to 5) < 6 is correct
       
        // Calculate J index bounds: (3 to 1), (5 to 3), (11 to 5) .... 
        // (3 to 1) means batch_begin at pend element 3 which is pend[2] (Jacbosthal is 1 indexed, pend is 0 indexed)
        // (3 to 1) means batch size = 3 - 1 = 2. 
        // So (3 to 1) means, insert pend[2] and pend[1] ("to 1" means not to include element 1 (pend[0]))

        // Calculate upper bound j_max
        // Insertion order: j_max -> j_min
        int j_max = j_min + 2 * j_prev;     // Calculate upper bound of indexes for the current batch
        
        // Check if pend[j_max] is out of bounds. like jmax 11 but only 8 elements in pend. 
        // if jmax=11 and pend_size=11, see below that j_max gets -1 to adjust to 0 indexing of pend
        if((j_max > pend_size))   // total elements batch_begin counting with 1
            j_max = pend_size;   
        
        // substract 1 from each bound to adjust 0 indexing of pend
        int batch_begin = j_max - 1; //batch begin 3 gets adjusted to 2 -> pend[2]
        int batch_end= j_min - 1; 
        
        // ensures inserting backwards.
        // For loop is for inserting elements of one batch
        for(int i = batch_begin; i > batch_end; --i){    //I want to insert b3 first, which is pend[2]. I need to know the upper bound of b3 which is but b3 is a straggler
            
            std::vector<Item>::iterator winner_pos;
            if (has_straggler && i == pend_size -1 ){
                winner_pos = main.end();
            } else{
                winner_pos = main.begin() + (winner_idx[i]);  
            }

            // Compare and find position
            std::vector<Item>::iterator insert_pos = std::lower_bound(main.begin(), winner_pos, pend[i]);

            //use insert_pos ptr before inserting, otherwise could be invalid
            size_t inserted_at = std::distance(main.begin(), insert_pos);
            //Insert pend[] into main
            main.insert(insert_pos, pend[i]);

            //Check Winner index offset
            for(int j = 0; j < pend_size; ++j){
                if(winner_idx[j] >= inserted_at)  // inserted at pos 3. winner at main[3] is now main[4]
                    winner_idx[j]++;
            }
        }

        //prepare this for next iteration to calculate j_max correctly
        j_prev = j_min;
        j_min  = j_max;

    }

    return main;

}


// void sort_deque(char** argv){

// }