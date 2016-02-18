#include "Auto.h"
#include "Main.h"

Auto::Auto(){}

void Auto::Initialize() { Requires(&Main::getDrive()); }

void Auto::Execute() {}

bool Auto::IsFinished() { return false; }

void Auto::End() {}

void Auto::Interrupted() {}
