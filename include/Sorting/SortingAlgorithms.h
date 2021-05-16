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

#include <iostream>
#include "Sorting.h"

namespace Algorithms {
    class SelectionSort : public SortingStrategy {
    public:
        void sort(std::vector<int> &vec) override {

            int size = vec.size();
            int min;

            for (int i = 0; i < size - 1; ++i) {
                min = i;
                for (int j = i; j < size; ++j) {
                    if (vec.at(j) < vec.at(min))
                        min = j;
                }
                std::swap(vec[i], vec[min]);
            }
        }
    };

    class BubbleSort : public SortingStrategy {
    public:
        void sort(std::vector<int> &vec) override {
            int size = vec.size();

            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (vec[j] > vec[j + 1])
                        std::swap(vec[j], vec[j + 1]);
                }
            }
        }
    };

    class InsertionSort : public SortingStrategy {
    public:
        void sort(std::vector<int> &vec) override {
            int size = vec.size();

            for (int i = 1; i < size; ++i) {
                int key = vec[i];
                int j = i - 1;

                while (j >= 0 && vec[j] > key) {
                    vec[j+1] = vec[j];
                    j -= 1;
                }
                vec[j+1] = key;
            }
        }
    };
}
