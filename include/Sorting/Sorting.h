/*
 *  C++ Algorithms Lib
=================================================================================================
 *  Copyright (C) 2021  Good-bug
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
=================================================================================================
 */

#pragma once

#include <vector>

namespace Algorithms{
///using simple strategy pattern to manage sorting algorithms
class SortingStrategy{
public:
    virtual ~SortingStrategy()  = default;
    //TODO: add meta programming to take first/last iterator and optional compare function
    virtual void sort(std::vector<int> &vec) = 0;
};

///init Sorting and set Sorting Algorithm,
///the call sort(vector<int>) to sort vector
class Sorting{
public:
    explicit Sorting(SortingStrategy *s = nullptr): strategy(s){
    };

    ~Sorting(){
        delete this->strategy;
    }

    void setStrategy(SortingStrategy *s){
        delete this->strategy;
        std::swap(strategy, s);
    }

    void sort(std::vector<int> &vec){
        if(strategy)
            strategy->sort(vec);
    };

private:
    SortingStrategy *strategy;
};
}