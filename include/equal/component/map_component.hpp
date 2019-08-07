#pragma once

#include <string>
#include <unordered_map>
#include <equal/core/types.hpp>
#include <equal/core/component.hpp>
#include <equal/world/data.hpp>

namespace eq {

/**
 * @ingroup components
 * @brief 
 */
class MapComponent : public Component {
private:
  Size m_tile_size{64};
  std::unordered_map<std::string, VertexArray> m_layers; // <texture, vertex_array>
  bool m_need_update{true};

public:
  MapComponent();
  virtual ~MapComponent();

  void update(const Timestep& timestep);
  void fixed_update(const Timestep& timestep);
};

} // namespace eq
