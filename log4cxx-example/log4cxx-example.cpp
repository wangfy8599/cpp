// log4cxx-example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

#include <string>

#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

using namespace std;

int main(int argc, char* argv[])
{
	__int64 x = 9646324351L;
	int y = 0x80000000;
	__int64 z = 0x80000000LL;
	printf("0x%X\n", x);
	printf("0x%X\n", y);
	int a = x & y;
	string s("channel_01=2008-03-05T12:12:09");
	int n;
	char buf[32];
	int ret = sscanf(s.c_str(), "channel_%3d=%s", &n, buf);
	printf("ret=%d, n=%d, buf=%s\n", ret, n, buf);

	srand(time(NULL));
	for(int i=0; i<10; ++i)
	{
		printf("rand=%d\n", rand() % 1000);
		printf("rand=%d\n", rand() % 1000);
	}

	tm tmVal = {};
	sscanf(buf, "%d-%d-%dT%d:%d:%d", &tmVal.tm_year, &tmVal.tm_mon, &tmVal.tm_mday, &tmVal.tm_hour, &tmVal.tm_min, &tmVal.tm_sec);

	PropertyConfigurator::configure("./log4cxx.properties");
	LoggerPtr logger = Logger::getLogger("");
	string msg("ÏûÏ¢");
	for(int i=0; i<0; ++i)
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

