#include <gtest/gtest.h>

#include <Aggregator.hpp>

TEST(MemoryLeakOnDeepCopy, ThrowOnFirstCopy) {
  try {
    Aggregator first(true, false, false);
    Aggregator second(first);
  } catch (...) {
  }
}

TEST(MemoryLeakOnDeepCopy, ThrowOnSecondCopy) {
  try {
    Aggregator first(false, true, false);
    Aggregator second(first);
  } catch (...) {
  }
}

TEST(MemoryLeakOnDeepCopy, ThrowAfterTwoCopies) {
  try {
    Aggregator first(false, false, true);
    Aggregator second(first);
  } catch (...) {
  }
}
