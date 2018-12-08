#include "Aggregator.hpp"

#include <utility>

Aggregator::Aggregator(bool throwOnCopyPointerFirst,
                       bool throwOnCopyPointerSecond, bool throwAfterCopy)
    : mMayThrowPointerFirst(nullptr),
      mMayThrowPointerSecond(nullptr),
      mMayThrowAfterCopy(throwAfterCopy) {
  try {
    mMayThrowPointerFirst = new MayThrowOnCopy(throwOnCopyPointerFirst);
    mMayThrowPointerSecond = new MayThrowOnCopy(throwOnCopyPointerSecond);
  } catch (...) {
    freeResources();
    throw;
  }
}

Aggregator::Aggregator(const Aggregator& other)
    : mMayThrowPointerFirst(nullptr),
      mMayThrowPointerSecond(nullptr),
      mMayThrowAfterCopy(false) {
  try {
    mMayThrowPointerFirst = new MayThrowOnCopy(*other.mMayThrowPointerFirst);
    mMayThrowPointerSecond = new MayThrowOnCopy(*other.mMayThrowPointerSecond);
    mMayThrowAfterCopy = other.mMayThrowAfterCopy;
  } catch (...) {
    freeResources();
    throw;
  }
}

Aggregator& Aggregator::operator=(const Aggregator& other) {
  Aggregator temp{other};
  *this = std::move(temp);

  return *this;
}

Aggregator::~Aggregator() { freeResources(); }

void Aggregator::freeResources() {
  if (mMayThrowPointerFirst) {
    delete mMayThrowPointerFirst;
  }
  if (mMayThrowPointerSecond) {
    delete mMayThrowPointerSecond;
  }
}
