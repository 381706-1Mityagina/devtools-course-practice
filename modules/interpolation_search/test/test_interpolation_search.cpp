// Copyright 2020 Mityagina Daria

#include <gtest/gtest.h>
#include <vector>
#include <list>
#include "include/interpolation_search.h"

class MityaginaInterpolationSearch : public ::testing::Test {
};

TEST_F(MityaginaInterpolationSearch, Can_generate_vector) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in(10);

  // Assert
  ASSERT_NO_THROW(in = generateRandomVector(size));
}

TEST_F(MityaginaInterpolationSearch, Can_handle_invalid_size) {
  // Arrange
  int size = -10;

  // Act && Assert
  ASSERT_ANY_THROW(std::vector<int> in = generateRandomVector(size));
}

TEST_F(MityaginaInterpolationSearch, Can_handle_invalid_size_2) {
  // Arrange
  int size = 0;

  // Act && Assert
  ASSERT_ANY_THROW(std::vector<int> in = generateRandomVector(size));
}

TEST_F(MityaginaInterpolationSearch, Partition_works_as_expected) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = partition(&in, 0, size - 1));
}

TEST_F(MityaginaInterpolationSearch, Wrong_boarders_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&in, -6, -1));
}

TEST_F(MityaginaInterpolationSearch, Wrong_boarders_min_greater_max) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&in, 6, 2));
}

TEST_F(MityaginaInterpolationSearch, Partition_result_is_positive) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_GE(partition(&in, 0, size - 1), 0);
}

TEST_F(MityaginaInterpolationSearch, Interpolation_search_works_fine) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = interpolation_search(&in, in[4]));
}

TEST_F(MityaginaInterpolationSearch, Value_exists) {
  // Arrange
  int size = 20;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_GE(interpolation_search(&in, in[5]), 0);
}

TEST_F(MityaginaInterpolationSearch, Value_does_not_exist) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GT(0, interpolation_search(&in, 909));
}

TEST_F(MityaginaInterpolationSearch, Returns_right) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GT(interpolation_search(&in, 9), 4);
}

TEST_F(MityaginaInterpolationSearch, Returns_left) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GE(4, interpolation_search(&in, 0));
}

TEST_F(MityaginaInterpolationSearch, Returns_left_double_check) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GE(interpolation_search(&in, 0), 0);
}

TEST_F(MityaginaInterpolationSearch, Right_value_changes) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GE(interpolation_search(&in, 7), 0);
}
