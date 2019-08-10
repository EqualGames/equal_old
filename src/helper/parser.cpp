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
#include <fstream>
#include <chrono>
#include <equal/core/logger.hpp>
#include <equal/core/window.hpp>
#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/system.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/parser.hpp>
#include <equal/helper/timer.hpp>
#include <equal/prefab/ui/ui.hpp>

namespace eq {

ui::Canvas *ParserUI(const std::string &filename, const Parser::Actions &actions) {
  try {
    eq::Timer timer("Parsing UI");
    ui::Canvas *canvas = new ui::Canvas(Position{0, 0}, GetWindow()->size());

    std::ifstream ui_file(filename);
    std::string line;

    GameObject *object = nullptr;

    while (std::getline(ui_file, line)) {
      std::istringstream iss(line);
      if (iss.eof()) {
        break;
      } else if (iss.bad() || iss.fail()) {
        std::throw_with_nested(iss.exceptions());
      } else if (line.empty() || str::trim_copy(line).empty()) {
        continue;
      }

      // Detect who is parent of who
      int level_child = 0;
      std::for_each(line.begin(), line.end(), [&level_child](const char c) -> void {
        if (std::isspace(c)) {
          level_child += 1;
        }
      });
      level_child /= 2;

      std::string word;
      iss >> word;

      // Ignore commented line
      if (word == "--") {
        continue;
      }

      // Get name of object type or property
      if (std::isupper(word.at(0))) { // Is object type
        std::pair<std::string, std::string> p = str::split_pair(word, '#');
        std::string type = p.first;
        std::string id = p.second;

        GameObject *parent{nullptr};

        if (level_child == 0) {
          parent = canvas;
        } else {
          parent = canvas->GetComponent<TransformComponent>()->children().back();
          for (int level = 1; level < level_child; ++level) {
            parent = parent->GetComponent<TransformComponent>()->children().back();
          }
        }

        if (type == "Image") {
          object = parent->CreateObject<ui::Image>(id);
        } else if (type == "Container") {
          object = parent->CreateObject<ui::Container>(id);
        } else if (type == "Text") {
          object = parent->CreateObject<ui::Text>(id);
        } else if (type == "Button") {
          object = parent->CreateObject<ui::Button>(id);
        } else if (type == "Window") {
          object = parent->CreateObject<ui::Window>(id);
        } else if (type == "TextInput") {
          object = parent->CreateObject<ui::TextInput>(id);
        } else if (type == "ProgressBar") {
          object = parent->CreateObject<ui::ProgressBar>(id);
        }

      } else if (std::find(line.begin(), line.end(), ':') != line.end()) { // Is Property
        std::pair<std::string, std::string> p = str::split_pair(line, ':');
        std::string attr = p.first;
        std::string value = p.second;

        if (attr == "position") {
          std::pair<std::string, std::string> p = str::split_pair(value, ' ');
          int x = std::atoi(p.first.c_str());
          int y = std::atoi(p.second.c_str());
          object->GetComponent<TransformComponent>()->position(Position{x, y});
        } else if (attr == "size") {
          std::pair<std::string, std::string> p = str::split_pair(value, ' ');
          int x = std::atoi(p.first.c_str());
          int y = std::atoi(p.second.c_str());
          object->GetComponent<TransformComponent>()->size(Size{x, y});
        } else if (attr == "anchor") {
          object->GetComponent<TransformComponent>()->anchor(Transform::AnchorFromString(value));
        } else if (attr == "visible") {
          object->visible(value == "true" ? true : false);
        } else if (object->name() == "Image") {

        } else if (object->name() == "Container") {

        } else if (object->name() == "Text") {
          ui::Text *obj = static_cast<ui::Text *>(object);

          if (attr == "text") {
            obj->text(value);
          }
        } else if (object->name() == "Button") {
          ui::Button *obj = static_cast<ui::Button *>(object);

          if (attr == "text") {
            obj->text(value);
          } else if (attr == "@action") {
            auto action = actions.find(value);
            if (action != actions.end()) {
              obj->action(action->second);
            } else {
              auto action = actions.find("*");
              if (action != actions.end()) {
                obj->action(action->second);
              } else {
                EQ_CORE_WARN("Can't associate action({}) to button({})", value, obj->id());
              }
            }
          }
        } else if (object->name() == "Window") {
          ui::Window *obj = static_cast<ui::Window *>(object);

          if (attr == "title") {
            obj->title(value);
          }
        } else if (object->name() == "TextInput") {
          ui::TextInput *obj = static_cast<ui::TextInput *>(object);

          if (attr == "masked") {
            obj->masked(value == "true" ? true : false);
          } else if (attr == "text") {
            obj->text(value);
          }
        } else if (object->name() == "ProgressBar") {
          ui::ProgressBar *obj = static_cast<ui::ProgressBar *>(object);

          if (attr == "value") {
            obj->value(std::atof(value.c_str()));
          } else if (attr == "max_value") {
            obj->max_value(std::atof(value.c_str()));
          }
        }
      }
    }

    return canvas;
  } catch (...) {
    EQ_THROW("Error on parse: {}", filename);
  }
}

} // namespace eq
