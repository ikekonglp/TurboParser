// Copyright (c) 2012-2013 Andre Martins
// All Rights Reserved.
//
// This file is part of TurboParser 2.1.
//
// TurboParser 2.1 is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// TurboParser 2.1 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with TurboParser 2.1.  If not, see <http://www.gnu.org/licenses/>.

#include "EntityPipe.h"
#include <iostream>
#include <sstream>
#include <vector>
#ifdef _WIN32
#include <gettimeofday.h>
#else
#include <sys/time.h>
#endif

void EntityPipe::PreprocessData() {
  delete token_dictionary_;
  CreateTokenDictionary();
  static_cast<SequenceDictionary*>(dictionary_)->
    SetTokenDictionary(token_dictionary_);
  // To get the right reader (instead of the default sequence reader).
  token_dictionary_->InitializeFromEntityReader(GetEntityReader());
  static_cast<SequenceDictionary*>(dictionary_)->
    CreateTagDictionary(GetSequenceReader());
}

