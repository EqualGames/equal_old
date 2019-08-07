#pragma once

#include <string>
#ifdef EQ_LINUX
#include <uuid/uuid.h> // FIXME: Need review
#elif EQ_WINDOWS
#include <Windows.h>
#include <Rpcdce.h>
#endif

namespace eq {

/**
 * @ingroup helpers
 * @brief Generate UUID
 *
 * @return std::string
 */
inline std::string GenerateUUID() {
#ifdef EQ_LINUX
  uuid_t guid;
  char *guid_str = new char[36];

  uuid_generate_random(guid);
  uuid_unparse(guid, guid_str);

  return std::string(guid_str);
#elif EQ_WINDOWS
  GUID guid;
  unsigned char *guid_str[36];

  CoCreateGuid(&guid);
  UuidToString(&guid, &guid_str);
  RpcStringFree(&guid_str);

  return std::string(reinterpret_cast<char *>(guid_str));
#endif
}

} // namespace eq
