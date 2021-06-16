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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>
#include <Sorting.h>

using namespace Algorithms;

struct SortingTestcase {
    std::string name;
    std::vector<int> unsort;
    std::vector<int> sorted;
};

TEST_CASE("SortingTests", "[Sort]") {
    std::vector<std::pair<SortingStrategy*, std::string>> strategies{
            {new SelectionSort()  , "SelectionSort"   }
           ,{new BubbleSort()     , "BubbleSort"      }
           ,{new InsertionSort()  , "InsertionSort"   }
           ,{new Quicksort()      , "Quicksort"       }
           ,{nullptr              , "nullptr"}
    };

    std::vector<SortingTestcase> testcases {
        {
            "Sorted vector"
            ,std::vector<int>{1,2,3,4,5}
            ,std::vector<int>{1,2,3,4,5}
        },
        {
            "Unsorted vector"
            ,std::vector<int>{5,4,3,2,1}
            ,std::vector<int>{1,2,3,4,5}
        },
        {
            "Vector of negative values"
            ,std::vector<int>{-1,-2,-3,-4,-5}
            ,std::vector<int>{-5,-4,-3,-2,-1}
        },
        {
            "Vector of same numbre"
            ,std::vector<int>{1,1,1,1,1,1}
            ,std::vector<int>{1,1,1,1,1,1}
        },
        {
            "Vector of two repetable numbers"
                ,std::vector<int>{1,0,1,0,1,0}
                ,std::vector<int>{0,0,0,1,1,1}
        }
    };

    for(auto [strategy, name] : strategies) {
        Sorting mySort(strategy);
        mySort.setStrategy(strategy);

        SECTION(name) {
            for(auto [_case, unsorted, sorted] : testcases) {
                SECTION(_case){
                    mySort.sort(unsorted);

                    REQUIRE(unsorted == sorted);
                }
            }
        }
    }
}