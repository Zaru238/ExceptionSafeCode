#include "CopyableClasses.hpp"

#include <exception>

ThrowOnCopy::ThrowOnCopy(const ThrowOnCopy&) {
  throw std::exception();
}

NonThrowOnCopyResource::NonThrowOnCopyResource()
    : mResource(std::make_unique<size_t>(0)) {
}

NonThrowOnCopyResource::NonThrowOnCopyResource(const NonThrowOnCopyResource&)
    : mResource(std::make_unique<size_t>(0)) {
}

ThrowOnCopyResource::ThrowOnCopyResource()
    : mResource(std::make_unique<size_t>(0)) {
}

ThrowOnCopyResource::ThrowOnCopyResource(const ThrowOnCopyResource&)
    : mResource(std::make_unique<size_t>(0)) {
  throw std::exception();
}
