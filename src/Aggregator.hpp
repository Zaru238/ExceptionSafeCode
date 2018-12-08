#include "CopyableClasses.hpp"

class Aggregator {
 public:
  Aggregator(bool throwOnCopyPointerFirst, bool throwOnCopyPointerSecond,
             bool throwAfterCopy);
  Aggregator(const Aggregator&);
  Aggregator(Aggregator&&) noexcept = default;

  Aggregator& operator=(const Aggregator&);
  Aggregator& operator=(Aggregator&&) noexcept = default;

  ~Aggregator();

 private:
  void freeResources();

  MayThrowOnCopy* mMayThrowPointerFirst;
  MayThrowOnCopy* mMayThrowPointerSecond;
  MayThrowOnCopy mMayThrowAfterCopy;
};
