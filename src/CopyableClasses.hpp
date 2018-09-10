#pragma once

#include <cstddef>

#include <memory>

class NonThrowOnCopy{
public:
  NonThrowOnCopy() = default;
  NonThrowOnCopy(const NonThrowOnCopy&) = default;
};

class ThrowOnCopy{
public:
  ThrowOnCopy() = default;
  ThrowOnCopy(const ThrowOnCopy&);
};

class NonThrowOnCopyResource {
public:
  NonThrowOnCopyResource();
  NonThrowOnCopyResource(const NonThrowOnCopyResource&);
private:
  std::unique_ptr<size_t> mResource;
};

class ThrowOnCopyResource {
public:
  ThrowOnCopyResource();
  ThrowOnCopyResource(const ThrowOnCopyResource&);
private:
  std::unique_ptr<size_t> mResource;
};
