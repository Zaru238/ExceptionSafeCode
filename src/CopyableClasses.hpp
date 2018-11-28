#pragma once
#include <cstddef>

class MayThrowOnCopy {
 public:
  MayThrowOnCopy(bool throwOnCopy);
  MayThrowOnCopy(const MayThrowOnCopy&);

  MayThrowOnCopy& operator=(const MayThrowOnCopy& other);

 private:
  bool mThrowOnCopy;
};
