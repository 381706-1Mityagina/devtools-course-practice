// Copyright 2020 Mityagina Daria

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

#include <stdlib.h>
#include <stdio.h>
#include <vector>

std::vector<int> generateRandomVector(int size);
int partition(std::vector<int> *in, int left, int right);
int interpolation_search(std::vector<int> *in, int val);
void quickSort(std::vector<int> *in, int left, int right);

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
