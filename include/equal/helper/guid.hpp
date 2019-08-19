/*
 * Copyright 2019 Equal Games
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>
#ifdef EQ_LINUX
#include <uuid/uuid.h> // FIXME: Need review
#elif EQ_WINDOWS
#include <Rpcdce.h>
#include <Windows.h>
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
