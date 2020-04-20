// Copyright 2020 Mityagina Daria

#include <iostream>
#include <vector>

std::vector<int> getRandomVector(int size) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  std::vector<int> _vector = std::vector<int>(size, 0);
  for (int i = 0; i < size; ++i) {
    _vector[i] = gen() % (100 - 4);
  }
  return _vector;
}

int partition(std::vector<int> *in, int left, int right) {
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

void quickSort(std::vector<int> *in, int size) {
  quickSort(in, 0, size - 1);
}

int interpolation_search(std::vector<int> *in, int val) {
  bool found; // True if the val is found
  int size = static_cast<int>(in.size());
  int cur_pos = 0, left = 0;
  int right = size - 1;

  quickSort(in, size);
  // Array search loop until the val is found or the search limits still exist
  for (found = false; (in[left] < val) && (in[right] > val) && !found; ) {
    // Calculation by interpolation of the next element, which will be compared with the desired
    cur_pos = left;
    cur_pos += ((val - in[left]) * (right - left)) / (in[right] - in[left]);
    // Obtaining new boundaries of the region if the desired is not found
    if (in[cur_pos] < val) {
      left = cur_pos + 1;
	} else if (in[cur_pos] > val) {
	  right = cur_pos - 1;
	} else {
	  found = true;
	}
  }
  // returns index of a found element
  if (in[left] == val) {
    return left;
  } else if (in[right] == val) {
	return right;
  } else {
	return -1;
  }
}
