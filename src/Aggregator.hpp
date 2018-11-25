#include <memory>

#include "CopyableClasses.hpp"

class Aggregator {
 public:
  Aggregator(bool throwOnCopyRes, bool throwOnCopyRes2, bool throwAfterCopyRes);
  Aggregator(const Aggregator& other);

 private:
  std::unique_ptr<MayThrowOnCopyWithResource> mResource;
  std::unique_ptr<MayThrowOnCopyWithResource> mResource2;
  std::unique_ptr<MayThrowOnCopy> mEmpty;
};
