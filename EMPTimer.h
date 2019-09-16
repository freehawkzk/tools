#pragma once
#include <iostream>
#include <string>

#ifdef EMPWITHLOG
#include "EMPLog.h"
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
#include "windows.h"
#elif defined(__linux__)
#include <sys/time.h>
#elif defined(__ANDROID__)
#include <sys/time.h>
#endif

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

class CEMPTimer
{
public:
    CEMPTimer(const char* pname, bool show)
    {
        strcpy(name, pname);
        bshow = show;
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
        QueryPerformanceFrequency(&nFreq);
        QueryPerformanceCounter(&tstart);
#elif defined(__linux__)
        gettimeofday(&tstart, NULL);
#elif defined(__ANDROID__)
        gettimeofday(&tstart, NULL);
#endif
        if (bshow)
        {
#ifdef EMPWITHLOG
            EMPLogInfo("Create timer: %s \n", name);
#else
            std::cout << "Create timer : " << name << std::endl;
#endif
        }
            
    }
    ~CEMPTimer()
    {
#ifdef EMPWITHLOG
        EMPLogInfo("Destory timer: %s\n", name);
#else
        std::cout << "Destory timer: " << name << std::endl;
#endif
       
    }

    bool Reset()
    {
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
        QueryPerformanceCounter(&tstart);
#elif defined(__linux__)
        gettimeofday(&tstart, NULL);
#elif defined(__ANDROID__)
        gettimeofday(&tstart, NULL);
#endif
        if (bshow)
        {
#ifdef EMPWITHLOG
            EMPLogInfo("Reset timer: %s\n", name);
#else
            std::cout << "Reset timer: " << name << std::endl;
#endif
        }
            
        return 0;
    }
    double Show()
    {
        double dt = GetTime();
        if (bshow)
        {
#ifdef EMPWITHLOG
            EMPLogInfo("Timer: %s is %g ms\n", name, dt);
#else
            std::cout << "Timer: " << name <<" is "<<dt<<" ms"<< std::endl;
#endif
        }
            
        return dt;

    }
    double Stop() 
    {
        double dt = GetTime();
        if (bshow)
        {
#ifdef EMPWITHLOG
            EMPLogInfo("Stop timer: %s at %g ms\n", name, dt);
#else
            std::cout << "Stop timer: " << name << " at " << dt << " ms" << std::endl;
#endif
        }
        Reset();
        return dt;
    }

    double GetTime()
    {
        double dT = 0;
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
        QueryPerformanceCounter(&tstop);
        dT = (tstop.QuadPart - tstart.QuadPart) / (double)nFreq.QuadPart;       
#elif defined(__linux__)
        gettimeofday(&tstop, NULL);
        dT = (tstop.tv_sec - tstart.tv_sec) * 1000 + (tstop.tv_usec - tstart.tv_usec) / 1000;
#elif defined(__ANDROID__)
        gettimeofday(&tstop, NULL);
        dT = (tstop.tv_sec - tstart.tv_sec) * 1000 + (tstop.tv_usec - tstart.tv_usec) / 1000;
#endif
        return dT;
    }
private:
    CEMPTimer() = delete;
    CEMPTimer(const CEMPTimer&) = delete;
    CEMPTimer& operator=(const CEMPTimer&) = delete;
private:
    bool bshow;
    char name[MAX_PATH];
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
    LARGE_INTEGER nFreq;
    LARGE_INTEGER tstart;
    LARGE_INTEGER tstop;
    
#elif defined(__linux__)
    struct timeval tstart;
    struct timeval tstop;
#elif defined(__ANDROID__)
    struct timeval tstart;
    struct timeval tstop;
#endif
};

