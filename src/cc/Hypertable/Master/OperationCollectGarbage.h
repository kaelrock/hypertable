/** -*- c++ -*-
 * Copyright (C) 2011 Hypertable, Inc.
 *
 * This file is part of Hypertable.
 *
 * Hypertable is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of the
 * License, or any later version.
 *
 * Hypertable is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef HYPERTABLE_OPERATIONCOLLECTGARBAGE_H
#define HYPERTABLE_OPERATIONCOLLECTGARBAGE_H

#include "Operation.h"
#include "RangeServerConnection.h"

namespace Hypertable {

  class OperationCollectGarbage : public Operation {
  public:
    OperationCollectGarbage(ContextPtr &context);
    virtual ~OperationCollectGarbage() { }

    virtual void execute();
    virtual const String name();
    virtual const String label();
    virtual bool exclusive() { return true; }

    virtual void display_state(std::ostream &os) { }
    virtual size_t encoded_state_length() const { return 0; }
    virtual void encode_state(uint8_t **bufp) const { }
    virtual void decode_state(const uint8_t **bufp, size_t *remainp) { }
    virtual void decode_request(const uint8_t **bufp, size_t *remainp) { }
  };
  typedef intrusive_ptr<OperationCollectGarbage> OperationCollectGarbagePtr;

} // namespace Hypertable

#endif // HYPERTABLE_OPERATIONCOLLECTGARBAGE_H
