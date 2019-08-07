#pragma once

#include <string>
#include <equal/core/types.hpp>

namespace eq {

namespace ui {
class Canvas;
}

/**
 * @ingroup helpers
 * @brief Parser UI file and generate GUI elements
 * 
 * @param filename const std::string &
 * @param actions const eq::Parser::Actions &
 * @return ui::Canvas* 
 */
ui::Canvas *ParserUI(const std::string &filename, const eq::Parser::Actions &actions);

} // namespace eq
