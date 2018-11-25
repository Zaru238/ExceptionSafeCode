#include "Aggregator.hpp"

Aggregator::Aggregator(bool throwOnCopyRes, bool throwOnCopyRes2,
                       bool throwAfterCopyRes)
    : mResource(std::make_unique<MayThrowOnCopyWithResource>(
          MayThrowOnCopyWithResource{throwOnCopyRes})),
      mResource2(std::make_unique<MayThrowOnCopyWithResource>(
          MayThrowOnCopyWithResource{throwOnCopyRes2})),
      mEmpty(
          std::make_unique<MayThrowOnCopy>(MayThrowOnCopy{throwAfterCopyRes})) {
}

Aggregator::Aggregator(const Aggregator& other)
    : mResource(
          std::make_unique<MayThrowOnCopyWithResource>(*other.mResource.get())),
      mResource2(std::make_unique<MayThrowOnCopyWithResource>(
          *other.mResource2.get())),
      mEmpty(std::make_unique<MayThrowOnCopy>(*other.mEmpty.get())) {}
