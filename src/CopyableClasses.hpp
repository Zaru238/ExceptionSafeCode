#pragma once
#include <cstddef>

#include <memory>

class MayThrowOnCopy {
 public:
  MayThrowOnCopy(bool throwOnCopy);
  MayThrowOnCopy(const MayThrowOnCopy&);

 private:
  const bool mThrowOnCopy;
};

class MayThrowOnCopyWithResource {
 public:
  MayThrowOnCopyWithResource(bool throwOnCopy);
  MayThrowOnCopyWithResource(const MayThrowOnCopyWithResource&);

 private:
  const bool mThrowOnCopy;
  std::unique_ptr<size_t> mResource;
};
