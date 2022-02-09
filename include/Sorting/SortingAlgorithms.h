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
#include <vector>

namespace Algorithms {

    ///using simple strategy pattern to manage sorting algorithms
    class SortingStrategy{
    public:
        virtual ~SortingStrategy()  = default;
        //TODO: add meta programming to take first/last iterator and optional compare function
        virtual void sort(std::vector<int> &vec) = 0;
    };

    ///Sorting algorithms must inheritance SortingStrategy class,
    ///so that it would be possible to transmit sorting algorithm to Sorting class
    class SelectionSort : public SortingStrategy {
    public:
        ///https://www.geeksforgeeks.org/selection-sort/
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
        ///https://www.geeksforgeeks.org/bubble-sort/
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
        ///https://www.geeksforgeeks.org/insertion-sort/
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

    class Quicksort :public SortingStrategy {
    public:
        ///https://www.geeksforgeeks.org/quick-sort/
        void sort(std::vector<int> &vec) override {
            qSort(vec, 0, static_cast<int>(vec.size()) - 1);
        }
    private:
        void qSort(std::vector<int> &vector, int l, int r){
            if(l < r) {
                auto p = partiotion(vector, l, r);
                qSort(vector, l, p - 1);
                qSort(vector, p + 1, r);
            }
        }

        static int partiotion(std::vector<int> &vector, int l, int r) {
            auto p = vector[r];
            auto i = l;
            for(int j = l; j < r; ++j){
                if(vector[j] < p){
                    std::swap(vector[i],vector[j]);
                    ++i;
                }
            }
            std::swap(vector[i], vector[r]);
            return i;
        }
    };
}
