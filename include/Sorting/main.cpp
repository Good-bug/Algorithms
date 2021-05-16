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

#include <iostream>
#include "SortingAlgorithms.h"
#include "version.h"

//exemple of using
int main() {
    std::vector<int> vec{7,8,9,3,4,1,6,2,5};

    std::cout << "Unsorted vector: \n";
    for(int const& i : vec){
        std::cout << i << ' ';
    }
    std::cout <<std::endl;

    Algorithms::Sorting mySort(new Algorithms::InsertionSort());
    mySort.sort(vec);

    std::cout << "\nSorted vector: \n";
    for(int const& i : vec){
        std::cout << i << ' ';
    }
    std::cout <<std::endl;

    std::cout << PROJECT_VERSION_PATCH;

    return 0;
}
