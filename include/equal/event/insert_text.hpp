#pragma once

#include <string>

namespace eq {

/**
 * @ingroup events
 * @interface IOnInsertText
 * @brief Event interface for insert text
 *
 */
class IOnInsertText {
public:
  /**
   * @brief Method called on insert text
   *
   * @param text const std::wstring&
   */
  virtual void onInsertText(const std::wstring &text) = 0;
};

} // namespace eq
