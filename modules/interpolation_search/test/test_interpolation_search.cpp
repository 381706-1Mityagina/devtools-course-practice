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

TEST_F(MityaginaInterpolationSearch, test8) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> in = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = interpolation_search(&in, in[4]));
}

TEST_F(MityaginaInterpolationSearch, test1) {
  // Arrange

  // Act

  // Assert
}

TEST_F(MityaginaInterpolationSearch, test9) {
  // Arrange

  // Act

  // Assert
}

TEST_F(MityaginaInterpolationSearch, test10) {
  // Arrange

  // Act

  // Assert
}

TEST_F(MityaginaInterpolationSearch, test11) {
  // Arrange

  // Act

  // Assert
}

TEST_F(MityaginaInterpolationSearch, test12) {
  // Arrange

  // Act

  // Assert
}
