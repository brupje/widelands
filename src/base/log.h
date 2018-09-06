/*
 * Copyright (C) 2002-2018 by the Widelands Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef WL_BASE_LOG_H
#define WL_BASE_LOG_H

#include <iostream>
#include "base/macros.h"

// Print a formatted log messages to stdout on most systems and 'stdout.txt' on windows.
void log(const char*, ...) PRINTF_FORMAT(1, 2);

extern bool g_verbose;

#ifdef _WIN32
/** Set the directory that stdout.txt shall be written to.
 *  This should be the same dir where widelands writes its config file. Returns true on success.
 */
bool set_logging_dir(const std::string& homedir);
// Set the directory that stdout.txt shall be written to to the directory the program is started from. Use this only for test cases.
void set_logging_dir();
#endif

#endif  // end of include guard: WL_BASE_LOG_H
