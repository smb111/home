#include "BasicContext.h"

using namespace std;
using namespace tars;

BasicContext::BasicContext(tars::TarsCurrentPtr &current) : m_current(current),
	m_bNeedLog(true)
{
	// Set the Start Time
	TC_TimeProvider::getInstance()->getNow(&m_startTime);
	
	char buf[20];
	buf[19] = 0;
	tm tt;
	time_t now = TC_TimeProvider::getInstance()->getNow();
	localtime_r(&now, &tt);
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tt);
	m_logger << "|" << buf << "|BasicContext|";
}

BasicContext::~BasicContext() {
	TLOGDEBUG("context") << "|total_cost=" << getCostTimeMs() << "|" << m_logger.str() << endl;
}

int BasicContext::getNow() {
	return TC_TimeProvider::getInstance()->getNow();
}

int BasicContext::getCostTimeMs() {
	timeval now;
	TC_TimeProvider::getInstance()->getNow(&now);
	return abs (abs(now.tv_sec - m_startTime.tv_sec) * 1000 + abs(now.tv_usec - m_startTime.tv_usec) / 1000);
}

ostream & BasicContext::getLogger() {
	return m_logger;
}
