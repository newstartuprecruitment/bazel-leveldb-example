#ifndef STORAGE_LEVELDB_PORT_PORT_H_
#define STORAGE_LEVELDB_PORT_PORT_H_

#include <string.h>

#define LEVELDB_HAS_PORT_CONFIG_H 1

// Include the appropriate platform specific file below.  If you are
// porting to a new platform, see "port_example.h" for documentation
// of what the new port_<platform>.h file must provide.
#include "port/port_stdcxx.h"

#endif // STORAGE_LEVELDB_PORT_PORT_H_