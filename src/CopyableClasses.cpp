#include "CopyableClasses.hpp"

#include <exception>

MayThrowOnCopy::MayThrowOnCopy(bool throwOnCopy) : mThrowOnCopy(throwOnCopy) {}

MayThrowOnCopy::MayThrowOnCopy(const MayThrowOnCopy& other)
    : mThrowOnCopy(other.mThrowOnCopy) {
  if (mThrowOnCopy) {
    throw std::exception();
  }
}

MayThrowOnCopyWithResource::MayThrowOnCopyWithResource(bool throwOnCopy)
    : mThrowOnCopy(throwOnCopy), mResource(std::make_unique<size_t>(0)) {}

MayThrowOnCopyWithResource::MayThrowOnCopyWithResource(
    const MayThrowOnCopyWithResource& other)
    : mThrowOnCopy(other.mThrowOnCopy), mResource(std::make_unique<size_t>(0)) {
  if (mThrowOnCopy) {
    throw std::exception();
  }
}
