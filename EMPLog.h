#pragma once
#include "clog.h"

#ifndef MoudleName
#define MoudleName "EMPFaceAntiProof"
#endif

#if EMPWITHLOG

CLOG_DEFINE_LOG_INFO(EMPLogInfo, MoudleName, CLOG_INFO);
CLOG_DEFINE_LOG_DEBUG(EMPLogDebug, MoudleName, CLOG_DEBUG);
CLOG_DEFINE_LOG_ERROR(EMPLogError, MoudleName, CLOG_ERROR);
CLOG_DEFINE_LOG_FATAL(EMPLogFatal, MoudleName, CLOG_FATAL);

#else
inline static void EMPLogInfo(const char* format, ...) {};
inline static void EMPLogDebug(const char* format, ...) {};
inline static void EMPLogError(const char* format, ...) {};
inline static void EMPLogFatal(const char* format, ...) {};
#endif
