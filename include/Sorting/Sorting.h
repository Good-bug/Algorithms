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
#include "SortingAlgorithms.h"

namespace Algorithms{

///init Sorting and set Sorting Algorithm,
///the call Sorting::sort(vector<int>, SortingStrategy(optional)) to sort vector
class Sorting{
public:
    explicit Sorting(SortingStrategy *s): strategy(s){
        if (isEmpty(s)){
            strategy = new SelectionSort;
        }
    };

    ~Sorting(){
        delete this->strategy;
    }

    void setStrategy(SortingStrategy *s){
        if (!isEmpty(s) && s != strategy){
            delete this->strategy;
            std::swap(strategy, s);
        }
    }

    static void sort(std::vector<int> &vec, SortingStrategy *s = new SelectionSort) {
        Sorting sorting(s);
        sorting._sort(vec);
    }

private:
    void _sort(std::vector<int> &vec){
        strategy->sort(vec);
    };

    constexpr bool isEmpty(SortingStrategy *s){
        if(s != nullptr){
            return false;
        } else {
            std::clog << "Algorithms::Sorting::isEmpty(SortingStrategy *s):\n\tSortingStrategy *strategy: can't by nullptr\n";
            return true;
        }
    }

    SortingStrategy *strategy;
};
}