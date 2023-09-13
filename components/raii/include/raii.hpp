#pragma once

#include "esp_log.h"
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
  RAII()
  {
    ESP_LOGI(TAG, "Constructor");
  }

  // Copy constructor and assignment operator are deleted.
  RAII(const RAII& other) = delete;

  RAII& operator=(const RAII& other) = delete;

  // Move constructor and assignment operator
  RAII(RAII&& other)
  {
    ESP_LOGI(TAG, "Move constructor");
    other.shouldDeinit = false;
  }

  RAII& operator=(RAII&& other)
  {
    ESP_LOGI(TAG, "Move assign operator");
    other.shouldDeinit = false;
    return *this;
  }

  // Destructor releases resource
  ~RAII()
  {
    
    if (shouldDeinit) {
      ESP_LOGI(TAG, "Destructor frees resource");
      resourceState = ResourceState::FREE;
    } else {
      ESP_LOGI(TAG, "Destructor doesn't free resource");
    }
  }

  static constexpr const char* TAG = "RAII";
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