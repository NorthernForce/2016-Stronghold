#ifndef READCOMMANDFILE_H

#include <memory>
#include <Commands/CommandGroup.h>

std::shared_ptr<CommandGroup> ReadCommandFromFile(const char* file_name);

#endif
