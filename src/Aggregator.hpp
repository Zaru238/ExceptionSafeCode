#include "CopyableClasses.hpp"

class Aggregator {
 public:
  Aggregator(bool throwOnCopyPointerFirst, bool throwOnCopyPointerSecond,
             bool throwAfterCopy);
  Aggregator(const Aggregator& other);
  ~Aggregator();

 private:
  void freeResources();

  MayThrowOnCopy* mMayThrowPointerFirst;
  MayThrowOnCopy* mMayThrowPointerSecond;
  MayThrowOnCopy mMayThrowAfterCopy;
};
