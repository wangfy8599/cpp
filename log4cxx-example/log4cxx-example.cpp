// log4cxx-example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

int main(int argc, char* argv[])
{
	PropertyConfigurator::configure("./log4cxx.properties");
	LoggerPtr logger = Logger::getLogger("");
	LOG4CXX_INFO(logger, "This is a test");
	return 0;
}

