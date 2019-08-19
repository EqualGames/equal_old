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

#include <csignal>
#include <equal/core/application.hpp>
#include <equal/core/logger.hpp>
#include <equal/core/window.hpp>
#include <equal/factory/create.hpp>
#include <equal/helper/error.hpp>
#include <exception>

#ifdef EQ_LINUX
void handle_signal(int signal) { std::exit(EXIT_FAILURE); }
#elif EQ_WINDOWS
void handle_signal(int signal) { std::system("pause"); }
#endif

/**
 * @defgroup entry Entrypoint
 * @brief Entrypoint definition
 *
 * @param argc Number of strings in array argv
 * @param argv[] Array of command-line argument strings
 * @param envp[] Array of environment variable strings
 * @return int
 */
int main(int argc, char *argv[], char *envp[]) {
  try {
    std::signal(SIGTERM, handle_signal);
    std::signal(SIGSEGV, handle_signal);
    std::signal(SIGINT, handle_signal);
    std::signal(SIGILL, handle_signal);
    std::signal(SIGABRT, handle_signal);
    std::signal(SIGFPE, handle_signal);

#ifdef EQ_LOGGER_TRACE
    EQ_CORE_LEVEL(eq::Logger::Level::TRACE);
    EQ_LEVEL(eq::Logger::Level::TRACE);
#elif EQ_LOGGER_DEBUG
    EQ_CORE_LEVEL(eq::Logger::Level::DEBUG);
    EQ_LEVEL(eq::Logger::Level::DEBUG);
#elif EQ_LOGGER_INFO
    EQ_CORE_LEVEL(eq::Logger::Level::INFO);
    EQ_LEVEL(eq::Logger::Level::INFO);
#elif EQ_LOGGER_WARN
    EQ_CORE_LEVEL(eq::Logger::Level::WARN);
    EQ_LEVEL(eq::Logger::Level::WARN);
#elif EQ_LOGGER_ERROR
    EQ_CORE_LEVEL(eq::Logger::Level::ERROR);
    EQ_LEVEL(eq::Logger::Level::ERROR);
#elif EQ_LOGGER_CRITICAL
    EQ_CORE_LEVEL(eq::Logger::Level::CRITICAL);
    EQ_LEVEL(eq::Logger::Level::CRITICAL);
#else
    EQ_CORE_LEVEL(eq::Logger::Level::INFO);
    EQ_LEVEL(eq::Logger::Level::INFO);
#endif

    eq::create_game();
    eq::Init();

#ifdef EQ_WINDOWS
    system("pause");
#endif

    return EXIT_SUCCESS;
  } catch (const std::exception &ex) {
    if (eq::GetWindow()) {
      eq::GetWindow()->shutdown();
    }
    eq::StackTrace(ex);
    return EXIT_FAILURE;
  }
}
