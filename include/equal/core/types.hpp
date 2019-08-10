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

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <glm/glm.hpp>
#include <boost/signals2/signal.hpp>

/**
 * @defgroup types Types
 * @ingroup core
 * @brief Types, enums and data structures.
 */

namespace eq {

/**
 * @ingroup types
 *
 * Function to call on perform action
 */
typedef std::function<void()> ActionPerform;

/**
 * @ingroup types
 *
 * Color struct composed of 4 components:
 * @li Red
 * @li Green
 * @li Blue
 * @li Alpha (opacity)
 *
 * Each component is a public member, an **uint8_t** in the range [0, 255]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::Color color{255, 0, 0, 255} // red color
 * color.r = 0; // black color
 * color.g = 255; // green color
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00721.html#ga20779a61de2fd526a17f12fe53ec46b1
 */
typedef glm::u8vec4 Color;

/**
 * @ingroup types
 *
 * Position struct composed of 2 components:
 * @li x
 * @li y
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::Position pos{1,2} // x = 1, y = 2
 * pos.x = 0; // x = 0, y = 2
 * pos.y = 0; // x = 0, y = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga6f9269106d91b2d2b91bcf27cd5f5560
 */
typedef glm::ivec2 Position;

/**
 * @ingroup types
 *
 * Rotation struct composed of 2 components:
 * @li x
 * @li y
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::Rotation rot{1,2} // x = 1, y = 2
 * rot.x = 0; // x = 0, y = 2
 * rot.y = 0; // x = 0, y = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga6f9269106d91b2d2b91bcf27cd5f5560
 */
typedef glm::ivec2 Rotation;

/**
 * @ingroup types
 *
 * Scale struct composed of 2 components:
 * @li x
 * @li y
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::Scale scale{1,2} // x = 1, y = 2
 * scale.x = 0; // x = 0, y = 2
 * scale.y = 0; // x = 0, y = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga6f9269106d91b2d2b91bcf27cd5f5560
 */
typedef glm::ivec2 Scale;

/**
 * @ingroup types
 *
 * Size struct composed of 2 components:
 * @li x
 * @li y
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::Size size{1,2} // x = 1, y = 2
 * size.x = 0; // x = 0, y = 2
 * size.y = 0; // x = 0, y = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga2f6d9ec3ae14813ade37d6aee3715fdb
 */
typedef glm::uvec2 Size;

/**
 * @ingroup types
 *
 * fSize struct composed of 2 components:
 * @li x
 * @li y
 *
 * Each component is a public member, an **float** in the range [1.175494351e-38F, 3.402823466e+38F]. Can be constructed
 * and manipulated very easily:
 *
 * @code
 * eq::fSize size{1,2} // x = 1, y = 2
 * size.x = 0; // x = 0, y = 2
 * size.y = 0; // x = 0, y = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00721.html#ga24273aa02abaecaab7f160bac437a339
 */
typedef glm::fvec2 fSize;

/**
 * @ingroup types
 *
 * Origin struct composed of 2 components:
 * @li x
 * @li y
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::Origin origin{1,2} // x = 1, y = 2
 * origin.x = 0; // x = 0, y = 2
 * origin.y = 0; // x = 0, y = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga6f9269106d91b2d2b91bcf27cd5f5560
 */
typedef glm::ivec2 Origin;

/**
 * @ingroup types
 *
 * BoundingBox struct composed of 4 components:
 * @li x
 * @li y
 * @li z
 * @li w
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::BoundingBox bb{1, 2, 3, 4} // x = 1, y = 2, z = 3, w = 4
 * bb.x = 0; // x = 0, y = 2, z = 3, w = 4
 * bb.w = 0;  // x = 0, y = 2, z = 3, w = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga5abb4603dae0ce58c595e66d9123d812
 */
typedef glm::ivec4 BoundingBox;

/**
 * @ingroup types
 *
 * fBoundingBox struct composed of 4 components:
 * @li x
 * @li y
 * @li z
 * @li w
 *
 * Each component is a public member, an **float** in the range [1.175494351e-38F, 3.402823466e+38F]. Can be constructed
 * and manipulated very easily:
 *
 * @code
 * eq::BoundingBox bb{1, 2, 3, 4} // x = 1, y = 2, z = 3, w = 4
 * bb.x = 0; // x = 0, y = 2, z = 3, w = 4
 * bb.w = 0;  // x = 0, y = 2, z = 3, w = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00721.html#ga713c796c54875cf4092d42ff9d9096b0
 */
typedef glm::fvec4 fBoundingBox;

/**
 * @ingroup types
 *
 * QuadRender struct composed of 4 components:
 * @li x
 * @li y
 * @li z
 * @li w
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::QuadRender qr{1, 2, 3, 4} // x = 1, y = 2, z = 3, w = 4
 * qr.x = 0; // x = 0, y = 2, z = 3, w = 4
 * qr.w = 0;  // x = 0, y = 2, z = 3, w = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga5abb4603dae0ce58c595e66d9123d812
 */
typedef glm::ivec4 QuadRender;

/**
 * @ingroup types
 *
 * TextureCrop struct composed of 4 components:
 * @li x
 * @li y
 * @li z
 * @li w
 *
 * Each component is a public member, an **int** in the range [-2147483648, 2147483647]. Can be constructed and
 * manipulated very easily:
 *
 * @code
 * eq::TextureCrop tc{1, 2, 3, 4} // x = 1, y = 2, z = 3, w = 4
 * tc.x = 0; // x = 0, y = 2, z = 3, w = 4
 * tc.w = 0;  // x = 0, y = 2, z = 3, w = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00699.html#ga5abb4603dae0ce58c595e66d9123d812
 */
typedef glm::ivec4 TextureCrop;

/**
 * @ingroup types
 *
 * VertexPoint struct composed of 4 components:
 * @li x
 * @li y
 * @li z
 * @li w
 *
 * Each component is a public member, an **float** in the range [1.175494351e-38F, 3.402823466e+38F]. Can be constructed
 * and manipulated very easily:
 *
 * @code
 * eq::VertexPoint vp{1, 2, 3, 4} // x = 1, y = 2, z = 3, w = 4
 * vp.x = 0; // x = 0, y = 2, z = 3, w = 4
 * vp.w = 0;  // x = 0, y = 2, z = 3, w = 0
 * @endcode
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00721.html#ga713c796c54875cf4092d42ff9d9096b0
 */
typedef glm::fvec4 VertexPoint;

/**
 * @ingroup types
 *
 * @see https://glm.g-truc.net/0.9.9/api/a00721.html#ga681381f19f11c9e5ee45cda2c56937ff
 */
typedef glm::fmat2x4 Vertex;

/**
 * @ingroup types
 */
typedef std::vector<Vertex> VertexArray;

/**
 * @ingroup types
 * @brief Make generic friend class
 */
template <class T>
struct FriendMaker {
  typedef T Type;
};

/**
 * @ingroup types
 * @brief Make property read-only
 *
 * @tparam T
 * @tparam C
 */
template <class T, class C>
class ReadOnly {
  friend class FriendMaker<C>::Type;

private:
  T data;

  /**
   * @brief Assingment operator
   *
   * @param value T
   * @return ReadOnly&
   */
  ReadOnly &operator=(const T &value) {
    data = value;
    return *this;
  }

public:
  /**
   * @brief Construct a new ReadOnly object
   *
   * @param value const T&
   */
  ReadOnly(const T &value) : data(value) {}

  /**
   * @brief Get read-only value
   *
   * @return const T&
   */
  operator const T &() const { return data; }
};

/**
 * @ingroup types
 * @brief Texture data
 */
class Texture {
private:
  std::string m_name;
  Size m_size;
  void *m_data{nullptr};

public:
  /**
   * @brief Construct a new Texture object
   */
  Texture() = default;

  /**
   * @brief Destroy the Texture object
   */
  ~Texture();

  /**
   * @brief Get texture name
   *
   * @return const std::string&
   */
  const std::string &name() const;

  /**
   * @brief Set texture name
   *
   * @param name const std::string&
   */
  void name(const std::string &name);

  /**
   * @brief Get texture size
   *
   * @return const eq::Size&
   */
  const Size &size() const;

  /**
   * @brief Set texture size
   *
   * @param size const eq::Size&
   */
  void size(const Size &size);

  /**
   * @brief Get texture data
   *
   * @return void*
   */
  void *data();

  /**
   * @brief Set texture data
   *
   * @param data void*
   */
  void data(void *data);
};

/**
 * @ingroup types
 * @brief Font data
 */
class Font {
private:
  std::string m_name;
  void *m_data{nullptr};

public:
  /**
   * @brief Construct a new Font object
   */
  Font() = default;

  /**
   * @brief Destroy the Font object
   */
  ~Font();

  /**
   * @brief Get texture name
   *
   * @return const std::string&
   */
  const std::string &name() const;

  /**
   * @brief Set texture name
   *
   * @param name const std::string&
   */
  void name(const std::string &name);

  /**
   * @brief Get font data
   *
   * @return void*
   */
  void *data();

  /**
   * @brief Set font data
   *
   * @param data void*
   */
  void data(void *data);
};

/**
 * @ingroup types
 * @brief Structure data of options to initialize a window
 */
struct WindowOptions {
  eq::Size size{800, 600};
  std::string title{"Equal Games Studio - Engine"};
  float scale{1.0f};
  bool vsync{false};
  uint8_t fps_limit{0};

  /**
   * @brief Construct a new Window Options object
   */
  WindowOptions() {}

  /**
   * @brief Construct a new Window Options object
   *
   * @param t_size eq::Size
   * @param t_title std::string
   * @param t_scale float
   * @param t_vsync bool
   * @param t_fps_limit
   */
  WindowOptions(const eq::Size &t_size, const std::string &t_title, float t_scale, bool t_vsync, uint8_t t_fps_limit)
      : size(t_size), title(t_title), scale(t_scale), vsync(t_vsync), fps_limit(t_fps_limit) {}
};

/**
 * @ingroup types
 * @brief Transform types and functions
 */
class Transform {
public:
  /**
   * @brief Transform anchor
   */
  enum Anchor { TL = 0, TC, TR, CL, CC, CR, BL, BC, BR };

  /**
   * @brief Transform anchor to string
   *
   * @param anchor const std::string&
   */
  static Anchor AnchorFromString(const std::string &anchor);
};

/**
 * @ingroup types
 * @brief Render options and types
 */
class Render {
public:
  /**
   * @brief Slice edge
   */
  static eq::Size sliced_edge;

  /**
   * @brief Slice border top and bottom
   */
  static eq::Size sliced_border_TB;

  /**
   * @brief Slice border left and right
   */
  static eq::Size sliced_border_LR;

  /**
   * @brief Slice shadown
   */
  static uint8_t sliced_shadow;

  /**
   * @brief Render type
   */
  enum Type { Manual, Simple, Sliced, Tiled, Filled };

  /**
   * @brief Render method
   */
  enum Method { Progress, Radial };

  /**
   * @brief Render origin
   */
  enum Origin { Top, Bottom, Right, Left };
};

/**
 * @ingroup types
 * @brief Text options
 */
class Text {
public:
  /**
   * @brief Text Alignments
   */
  enum Alignment { Left, Center, Right };

  /**
   * @brief Text Styles
   */
  enum Style { Regular, Bold, Italic, Underlined, StrikeThrough };

  /**
   * @brief Text Overflow
   */
  enum Overflow { Hidden, Wrap };
};

/**
 * @ingroup types
 * @brief UI Parser
 */
class Parser {
public:
  /**
   * @brief UI Parser Actions
   */
  class Actions : public std::unordered_map<std::string, ActionPerform> {
  public:
    /**
     * @brief Construct a new Actions object
     */
    Actions() = default;

    /**
     * @brief Destroy the Actions object
     */
    virtual ~Actions() = default;

    /**
     * @brief A throwable emplace in unordered map
     *
     * @param key const std::string&
     * @param value const ActionPerform&
     */
    void emplace_error(const std::string &key, const ActionPerform &value);
  };
};

} // namespace eq

/**
 * @brief A custom structs and functions for ::std
 */
namespace std {

/**
 * @brief A custom std::hash of eq::Position
 */
template <>
struct hash<eq::Position> {
  /**
   * @brief A custom operator of std::hash<eq::Position>
   *
   * @param v eq::Position
   * @return std::size_t
   */
  std::size_t operator()(const eq::Position &v) const {
    // Compute individual hash values for x and y
    // http://stackoverflow.com/a/1646913/126995
    std::size_t res = 17;

    res = res * 31 + std::hash<int>()(v.x);
    res = res * 31 + std::hash<int>()(v.y);

    return res;
  }
};

} // namespace std
