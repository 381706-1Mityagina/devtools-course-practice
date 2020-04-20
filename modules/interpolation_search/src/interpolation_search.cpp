// Copyright 2020 Mityagina Daria

#include "include/interpolation_search.h"
#include <random>
#include <iostream>
#include <vector>

std::vector<int> generateRandomVector(int size) {
  if (size <= 0) {
    throw "Invalid vector size";
  }
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  std::vector<int> _vector = std::vector<int>(size, 0);
  for (int i = 0; i < size; ++i) {
    _vector[i] = gen() % (100 - 4);
  }
  return _vector;
}

int partition(std::vector<int> *in, int left, int right) {
  if (left > right) {
    throw "Right should be greater then left";
  }
  if (left < 0 || right < 0) {
    throw "Right & left should be >= 0";
  }
  int pivot = (*in)[right];
  int count = left;
  for (int j = left; j < right; j++) {
    if ((*in)[j] <= pivot) {
      int temp = (*in)[j];
      (*in)[j] = (*in)[count];
      (*in)[count] = temp;
      count += 1;
    }
  }
  (*in)[right] = (*in)[count];
  (*in)[count] = pivot;

  return count;
}

void quickSort(std::vector<int> *in, int left, int right) {
  if (left < right) {
    int pivot = partition(in, left, right);
    quickSort(in, left, pivot - 1);
    quickSort(in, pivot + 1, right);
  }
}

int interpolation_search(std::vector<int> *in, int val) {
  int mid;
  int left = 0;
  int size = static_cast<int>((*in).size());
  int right = size - 1;

  if ((*in)[right] == (*in)[left]) {
    if ((*in)[right] == val) {
      return right;
    } else {
      return -1;
    }
  }

  quickSort(in, 0, size - 1);

  while ((*in)[left] < val && (*in)[right] > val) {
      int first = ((val - (*in)[left]) * (right - left));
      mid = left + first / ((*in)[right] - (*in)[left]);

      if ((*in)[mid] < val) {
          left = mid + 1;
      } else if ((*in)[mid] > val) {
          right = mid - 1;
      } else {
          return mid;
      }
    }

  if ((*in)[left] == val) {
      return left;
  }
  if ((*in)[right] == val) {
      return right;
  }

  return -1;  // Not found
}
