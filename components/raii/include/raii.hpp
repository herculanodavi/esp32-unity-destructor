#pragma once

#include <optional>

/**
 * @brief A move-only class that reserves some resource.
 */
struct RAII
{
  enum class ResourceState
  {
    FREE,
    RESERVED
  };

  // Default constructor
  RAII() = default;

  // Copy constructor and assignment operator are deleted.
  RAII(const RAII& other) = delete;

  RAII& operator=(const RAII& other) = delete;

  // Move constructor and assignment operator
  RAII(RAII&& other)
  {
    other.shouldDeinit = false;
  }

  RAII& operator=(RAII&& other)
  {
    other.shouldDeinit = false;
    return *this;
  }

  // Destructor releases resource
  ~RAII()
  {
    if (shouldDeinit) {
      resourceState = ResourceState::FREE;
    }
  }

  inline static ResourceState resourceState = ResourceState::FREE;
  bool shouldDeinit = true;
};

std::optional<RAII> GetRAII()
{
  // Fail if resource is reserved
  if (RAII::resourceState == RAII::ResourceState::RESERVED) {
    return std::nullopt;
  }

  // Reserve resource and return RAII if free
  RAII::resourceState = RAII::ResourceState::RESERVED;
  return RAII{};
}