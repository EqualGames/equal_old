#include <equal/core/types.hpp>
#include <equal/core/logger.hpp>
#include <equal/helper/error.hpp>

namespace eq {

// ---------- Transform ----------
Transform::Anchor Transform::AnchorFromString(const std::string &anchor) {
  if (anchor == "TL") {
    return Anchor::TL;
  } else if (anchor == "TC") {
    return Anchor::TC;
  } else if (anchor == "TR") {
    return Anchor::TR;
  } else if (anchor == "CL") {
    return Anchor::CL;
  } else if (anchor == "CC") {
    return Anchor::CC;
  } else if (anchor == "CR") {
    return Anchor::CR;
  } else if (anchor == "BL") {
    return Anchor::BL;
  } else if (anchor == "BC") {
    return Anchor::BC;
  } else if (anchor == "BR") {
    return Anchor::BR;
  } else {
    return Anchor::TL;
  }
}

// ---------- Texture ----------
const std::string &Texture::name() const { return m_name; }

void Texture::name(const std::string &name) { m_name = name; }

const Size &Texture::size() const { return m_size; }

void Texture::size(const Size &size) { m_size = size; }

Texture::~Texture() {}

void *Texture::data() { return m_data; }

void Texture::data(void *data) { m_data = data; }

// ---------- Font ----------
const std::string &Font::name() const { return m_name; }

void Font::name(const std::string &name) { m_name = name; }

Font::~Font() {}

void *Font::data() { return m_data; }

void Font::data(void *data) { m_data = data; }

// ---------- Parser ----------
void Parser::Actions::emplace_error(const std::string &key, const std::function<void()> &value) {
  auto r = try_emplace(key, value);
  if (!r.second) {
    EQ_THROW("Error on attach new action({}) to UI", key);
  }
}

} // namespace eq