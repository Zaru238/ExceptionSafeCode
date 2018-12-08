#include <gtest/gtest.h>

#include <Aggregator.hpp>

TEST(MemoryLeakOnDeepCopy, ThrowOnFirstCopyConstructor) {
  Aggregator first(true, false, false);
  ASSERT_ANY_THROW(Aggregator second(first));
}

TEST(MemoryLeakOnDeepCopy, ThrowOnSecondCopyConstructor) {
  Aggregator first(false, true, false);
  ASSERT_ANY_THROW(Aggregator second(first));
}

TEST(MemoryLeakOnDeepCopy, ThrowAfterTwoCopiesConstructor) {
  Aggregator first(false, false, true);
  ASSERT_ANY_THROW(Aggregator second(first));
}

TEST(MemoryLeakOnDeepCopy, ThrowOnFirstCopyAssignment) {
  Aggregator first(true, false, false);
  Aggregator second(true, false, false);
  ASSERT_ANY_THROW(second = first);
}

TEST(MemoryLeakOnDeepCopy, ThrowOnSecondCopyAssignment) {
  Aggregator first(false, true, false);
  Aggregator second(false, true, false);
  ASSERT_ANY_THROW(second = first);
}

TEST(MemoryLeakOnDeepCopy, ThrowAfterTwoCopiesAssignment) {
  Aggregator first(false, false, true);
  Aggregator second(false, false, true);
  ASSERT_ANY_THROW(second = first);
}
