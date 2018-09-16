#include <gtest/gtest.h>

#include <memory>

#include <CopyableClasses.hpp>

template <class T, class U, class V>
class Aggregator {
 public:
  Aggregator()
      : m_t(std::make_unique<T>(T{})),
        m_u(std::make_unique<U>(U{})),
        m_v(std::make_unique<V>(V{})) {}

  Aggregator(const Aggregator& other)
      : m_t(std::make_unique<T>(*other.m_t.get())),
        m_u(std::make_unique<U>(*other.m_u.get())),
        m_v(std::make_unique<V>(*other.m_v.get())) {}

 private:
  std::unique_ptr<T> m_t;
  std::unique_ptr<U> m_u;
  std::unique_ptr<V> m_v;
};

TEST(ValgrindTest, MemoryLeak) { size_t* leakedPointer = new size_t(0); }

TEST(MemoryLeakOnDeepCopy, ThrowOnFirstCopy) {
  try {
    using SpecializedAggregator =
        Aggregator<ThrowOnCopyResource, NonThrowOnCopyResource, NonThrowOnCopy>;
    SpecializedAggregator first;
    SpecializedAggregator second(first);
  } catch (...) {
  }
}

TEST(MemoryLeakOnDeepCopy, ThrowOnSecondCopy) {
  try {
    using SpecializedAggregator =
        Aggregator<NonThrowOnCopyResource, ThrowOnCopyResource, NonThrowOnCopy>;
    SpecializedAggregator first;
    SpecializedAggregator second(first);
  } catch (...) {
  }
}

TEST(MemoryLeakOnDeepCopy, ThrowAfterTwoCopies) {
  try {
    using SpecializedAggregator =
        Aggregator<NonThrowOnCopyResource, NonThrowOnCopyResource, ThrowOnCopy>;
    SpecializedAggregator first;
    SpecializedAggregator second(first);
  } catch (...) {
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
