//
//  RandomSelection.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include <random>
#include <iterator>
#include <vector>

#ifndef RandomSelection_hpp
#define RandomSelection_hpp

// http://stackoverflow.com/a/16421677

template<typename Iter, typename RandomGenerator>
Iter random_in(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, (int)std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter random_in(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return random_in(start, end, gen);
};

template<typename Item>
Item random_in(std::vector<Item> vec) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return *random_in(vec.begin(), vec.end(), gen);
};

template<typename Item>
Item weighted_random(std::vector<int> weights, std::vector<Item> vec) {
    std::discrete_distribution<int> distrib(weights.begin(), weights.end());
    std::random_device rd;
    std::mt19937 gen(rd());
    return vec[distrib(gen)];
}

#endif /* RandomSelection_hpp */
