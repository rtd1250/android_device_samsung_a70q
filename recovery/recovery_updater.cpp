/*
 * Copyright (C) 2020, The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/properties.h>

#include "edify/expr.h"
#include "otautil/error_code.h"

Value *VerifyBootloader(const char *name, State *state,
                        const std::vector<std::unique_ptr<Expr>> &argv) {
  int ret = 0;
  std::string bootloader = android::base::GetProperty("ro.boot.bootloader", "");
  if (bootloader.empty()) {
    return ErrorAbort(state, kFileGetPropFailure,
                      "%s() failed to read current bootloader version", name);
  }

  std::string supported_bootloader_arg;
  if (argv.empty() || !Evaluate(state, argv[0], &supported_bootloader_arg)) {
    return ErrorAbort(state, kArgsParsingFailure,
                      "%s() error parsing arguments", name);
  }
  int8_t supported_bootloader = supported_bootloader_arg[0] - '0';

  size_t offset = bootloader.find("A705");
  if (offset == std::string::npos) {
    return ErrorAbort(state, kArgsParsingFailure,
                      "%s() failed to parse current bootloader version", name);
  }

  // First digit after offset + 1 is the bootloader version
  int8_t version = -1;
  for (size_t i = offset + 1; i < bootloader.size(); ++i) {
    if (bootloader[i] >= '0' && bootloader[i] <= '9') {
      version = bootloader[i];
      break;
    }
  }

  if (version < 0 || version > supported_bootloader) {
    ret = 1;
  }

  return StringValue(std::to_string(ret));
}

void Register_librecovery_updater_a70q() {
  RegisterFunction("a70q.verify_bootloader", VerifyBootloader);
}
