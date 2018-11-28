#include "CopyableClasses.hpp"

#include <exception>

MayThrowOnCopy::MayThrowOnCopy(bool throwOnCopy) : mThrowOnCopy(throwOnCopy) {}

MayThrowOnCopy::MayThrowOnCopy(const MayThrowOnCopy& other)
    : mThrowOnCopy(other.mThrowOnCopy) {
  if (mThrowOnCopy) {
    throw std::exception();
  }
}

MayThrowOnCopy& MayThrowOnCopy::operator=(const MayThrowOnCopy& other) {
  if (other.mThrowOnCopy) {
    throw std::exception();
  }
  mThrowOnCopy = other.mThrowOnCopy;
}
