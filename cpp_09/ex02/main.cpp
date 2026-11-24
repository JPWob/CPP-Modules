#include "PmergeMe.hpp"

size_t  ItemVector::comparisons = 0;
size_t  ItemDeque::comparisons = 0;

int main(int argc, char **argv){

    if(argc < 2){
        std::cerr << "Error: No arguments" << std::endl;
        return 1;
    }
    std::vector<ItemVector>   vec_initial_chain;
    vec_initial_chain.reserve(argc - 1);


    std::deque<ItemDeque>     deq_initial_chain;
    
    for (int i = 1; i < argc; ++i) {
        unsigned int num = 0;
        if (!parse_positive_int(argv[i], num)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec_initial_chain.push_back(ItemVector(num, i - 1));
        deq_initial_chain.push_back(ItemDeque(num, i - 1));
    }

    // Print Initinal Chain
    std::cout << "Before:";
    for (size_t i = 0; i < vec_initial_chain.size(); ++i) {
        std::cout << " " << vec_initial_chain[i].value;
    }
    std::cout << std::endl;

    // Time std::vector
    double vec_start = get_time_us();
    std::vector<ItemVector> sorted_vector = sort_vector(vec_initial_chain, argc);
    double vec_time = get_time_us() - vec_start;

    // Time std::deque
    double deq_start = get_time_us();
    std::deque<ItemDeque> sorted_deque = sort_deque(deq_initial_chain, argc);
    double deq_time = get_time_us() - deq_start;

    // Print After
    std::cout << "After:";
    for (size_t i = 0; i < sorted_vector.size(); ++i) {
        std::cout << " " << sorted_vector[i].value;
        if(sorted_vector[i].value != sorted_deque[i].value) {
            std::cerr << "\nError: Mismatch between vector and deque results at index " << i << std::endl;
            return 1;
        }
    }
    std::cout << std::endl;

    // Print Timings
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << sorted_vector.size()
              << " elements with std::vector : " << vec_time << " us" << std::endl;
    std::cout << "Time to process a range of " << sorted_deque.size()
              << " elements with std::deque  : " << deq_time << " us" << std::endl;

    std::cout << "Number of comparisons Vector: " << ItemVector::comparisons << std::endl;
    std::cout << "Number of comparisons Deque: " << ItemDeque::comparisons << std::endl;
}


std::vector<ItemVector> sort_vector(std::vector<ItemVector>& chain, int N){

    size_t size = chain.size();
    
    if(size == 1){
        return (chain); // returns the first sorted version of main, not the winner
    }

    bool has_straggler = false;
    ItemVector straggler(0,0);
    if((size %2) != 0){
        has_straggler = true;
        straggler = chain.back(); // .back() equal to [size - 1]
        chain.pop_back(); 
        size = chain.size();
    }
    //size is guaranteed to be even now

    std::vector<ItemVector> winners;
    winners.reserve(size/2);

    std::vector<ItemVector> lookup(N);   //losers will get the ID of the winner they lost to. Index can be huge, if Winner ID is 1000, then lookup[1000] = loser. So lookup needs to be size N, because the ID of the winner can be as big as N-1.

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
    std::vector<ItemVector> main;
    
    //Unwidning the recursion, main chain is the sorted version of winners
    main = sort_vector(winners, N); // 5 //2 //1 returns
    main.reserve(size + has_straggler); // give more space in advance


    // declare pend chain
    std::vector<ItemVector> pend;
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
    
    // Pend_size is at least 1
    // 2. Inserting b1 at main.begin()
    // insert pend[0] meaning b1 at the beginning of main (b1,a1,...)
    main.insert(main.begin(), pend[0]); //adding b1 at the beginning of main
    
    if(pend_size == 1) //nothing more to insert back into main
        return main;

    // 3. Start tracking index offset
    // Because b1 was just inserted at index 0, every winner of pend[i] is now at index (i + 1).
    // Winner of pend[0] is now main[1]. Winner of pend[1] is now main[2] ....
    std::vector<size_t> winner_idx(pend.size());
    for (size_t i = 0; i < pend.size(); ++i) {
        winner_idx[i] = i +1;
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
            
            std::vector<ItemVector>::iterator winner_pos;
            if (has_straggler && i == pend_size -1 ){
                winner_pos = main.end();
            } else{
                winner_pos = main.begin() + (winner_idx[i]);  
            }

            // Compare and find position
            std::vector<ItemVector>::iterator insert_pos = std::lower_bound(main.begin(), winner_pos, pend[i]);

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

// std::deque doesn't even have a reserve() method. Because it allocates memory in fixed-size chunks (blocks) linked via an internal pointer array 
//rather than one contiguous buffer, it grows at either end without reallocating or copying existing elements.
std::deque<ItemDeque> sort_deque(std::deque<ItemDeque>& chain, int N) {
    size_t size = chain.size();

    if (size <= 1) {
        return chain;
    }

    bool has_straggler = false;
    ItemDeque straggler(0, 0);
    if ((size % 2) != 0) {
        has_straggler = true;
        straggler = chain.back();
        chain.pop_back();
        size = chain.size();
    }

    std::deque<ItemDeque> winners;
    std::deque<ItemDeque> lookup(N);

    for (size_t i = 0; i < size; i += 2) {
        if (chain[i] > chain[i + 1]) {
            winners.push_back(chain[i]);
            lookup[chain[i].id] = chain[i + 1];
        } else {
            winners.push_back(chain[i + 1]);
            lookup[chain[i + 1].id] = chain[i];
        }
    }

    std::deque<ItemDeque> main = sort_deque(winners, N);
    std::deque<ItemDeque> pend;

    for (size_t i = 0; i < main.size(); ++i) {
        pend.push_back(lookup[main[i].id]);
    }

    if (has_straggler) {
        pend.push_back(straggler);
    }

    int pend_size = static_cast<int>(pend.size());
    if (pend_size == 0) {
        return main;
    }

    // Insert b1 at the front (O(1) on std::deque)
    main.push_front(pend[0]);

    if (pend_size == 1) {
        return main;
    }

    std::deque<size_t> winner_idx(pend.size());
    for (size_t i = 0; i < pend.size(); ++i) {
        winner_idx[i] = i + 1;
    }

    int j_min = 1;
    int j_prev = 1;

    while (j_min < pend_size) {
        int j_max = j_min + 2 * j_prev;
        if (j_max > pend_size) {
            j_max = pend_size;
        }

        int batch_begin = j_max - 1;
        int batch_end = j_min - 1;

        for (int i = batch_begin; i > batch_end; --i) {
            std::deque<ItemDeque>::iterator winner_pos;
            if (has_straggler && i == pend_size - 1) {
                winner_pos = main.end();
            } else {
                winner_pos = main.begin() + winner_idx[i];
            }

            std::deque<ItemDeque>::iterator insert_pos = std::lower_bound(main.begin(), winner_pos, pend[i]);
            size_t inserted_at = std::distance(main.begin(), insert_pos);

            main.insert(insert_pos, pend[i]);

            for (int j = 0; j < pend_size; ++j) {
                if (winner_idx[j] >= inserted_at) {
                    winner_idx[j]++;
                }
            }
        }

        j_prev = j_min;
        j_min = j_max;
    }

    return main;
}