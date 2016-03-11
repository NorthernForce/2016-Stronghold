

#include "ReadCommandFile.hpp"
#include "Commands/ShootBall.hpp"
#include "Commands/AutonomousDrive.hpp"
#include "Main.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace
{
class CommandGroupFromFile : public CommandGroup
{
public:
	void AppendCommand(std::unique_ptr<Command>&& cmd)
	{
		AddSequential(cmd.get());
		commands.emplace_back(std::move(cmd));
	}

private:
	std::vector<std::unique_ptr<Command>> commands;
};

void ReportBadFileName(const char* file_name)
{
	std::clog << "Auto command file failed to open:" << file_name << std::endl;
}

void ReportBadCommand(const std::string& command)
{
	std::clog << "Invalid command line:" << command << std::endl;
}

std::unique_ptr<Command> BuildDriveCommand(char* s)
{
	const float duration = std::strtof(++s, &s);
	const float x = std::strtof(++s, &s);
	const float y = std::strtof(++s, &s);
	const float z = std::strtof(++s, &s);
	return std::unique_ptr<Command>(new AutonomousDrive<DriveStraight>(duration, x, y, z));
}

std::unique_ptr<Command> BuildShootCommand(char*)
{
	return std::unique_ptr<Command>(new ShootBall());
}

std::unique_ptr<Command> GetCommand(const std::string& line)
{
	if(line.empty())
	{
		return nullptr;
	}

	char* s = const_cast<char*>(line.c_str());
	switch(std::tolower(*s++))
	{
	case 'd': // Drive
		return BuildDriveCommand(s);

	case 's': // Shoot
		return BuildShootCommand(s);

	case '#': // Comment
		break;

	default:
		ReportBadCommand(line);
	}

	return nullptr;
}

std::shared_ptr<CommandGroup> LoadCommandGroupFromFile(std::istream& is)
{
	auto cmd_group = std::make_shared<CommandGroupFromFile>();
	std::string line;
	while (std::getline(is, line))
	{
		if(auto cmd = GetCommand(line))
			cmd_group->AppendCommand(std::move(cmd));
	}

	return cmd_group;
}

}

std::shared_ptr<CommandGroup> ReadCommandFromFile(const char* file_name)
{
	std::ifstream file;
	file.open(file_name);
	if (!file.fail())
	{
		return LoadCommandGroupFromFile(file);
	}

	ReportBadFileName(file_name);
	return nullptr;
}


