#pragma once
#include <string.h>
#include <stdint.h>
#include "types.h"

inline constexpr const char* YTURL_FULL = "https://www.youtube.com/watch?v=";
inline constexpr const char* YTURL_SHORT = "https://youtu.be/";
inline constexpr const char* YTURL_FEED = "http://www.youtube.com/feeds/videos.xml?channel_id=";
inline constexpr const char * YTFVERSION = "1.1.0";
constexpr uint32_t DEFAULT_LIMIT_CONSOLE = 20;
constexpr uint32_t DEFAULT_LIMIT_FEED = 30;
constexpr int DEFAULT_WIDTH_CONSOLE = 150;
constexpr int FALLBACK_WIDTH_CONSOLE = 80;
constexpr size_t ENTRY_BUFFER_SIZE = 65536;


//static const std::regex CHANNEL_ID_REGEX("^UC[A-Za-z0-9_-]{22}$");
// static const std::regex specials("(\xe2\x80\x98|\xe2\x80\x99|\xe2\x80\x9c|\xe2\x80\x9d)");

              