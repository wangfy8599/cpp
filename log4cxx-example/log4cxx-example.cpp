// log4cxx-example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

#include <string>

#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

using namespace std;

int main(int argc, char* argv[])
{
	PropertyConfigurator::configure("./log4cxx.properties");
	LoggerPtr logger = Logger::getLogger("");
	string msg("ÏûÏ¢");
	for(int i=0; i<10; ++i)
	{
		LOG4CXX_TRACE(logger, "TRACE" << msg.c_str() << i << ".");
		LOG4CXX_DEBUG(logger, "DEBUG" << msg.c_str() << i << ".");
		LOG4CXX_INFO(logger, "INFO" << msg.c_str() << i << ".");
		LOG4CXX_WARN(logger, "WARN" << msg.c_str() << i << ".");
		LOG4CXX_ERROR(logger, "ERROR" << msg.c_str() << i << ".");
		LOG4CXX_FATAL(logger, "FATAL" << msg.c_str() << i << ".");
	}
	return 0;
}

