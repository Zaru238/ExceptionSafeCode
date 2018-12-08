#pragma once
#include <cstddef>

class MayThrowOnCopy {
 public:
  MayThrowOnCopy(bool throwOnCopy);
  MayThrowOnCopy(const MayThrowOnCopy&);
  MayThrowOnCopy(MayThrowOnCopy&&) noexcept = default;

  MayThrowOnCopy& operator=(const MayThrowOnCopy&);
  MayThrowOnCopy& operator=(MayThrowOnCopy&&) noexcept = default;

 private:
  bool mThrowOnCopy;
};
